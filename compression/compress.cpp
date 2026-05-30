#include "tree.h"

#include <cstddef>
#include <fstream>
#include <iostream>
#include <memory>
#include <queue>

struct CompareTree {
  bool operator()(const std::unique_ptr<Tree> &a,
                  const std::unique_ptr<Tree> &b) {
    return a->m_count > b->m_count;
  }
};

class BitWriter {
public:
  BitWriter(std::ostream &out) : m_out{out} {}

  void put_bit(int bit) {
    m_buffer = static_cast<unsigned char>((m_buffer << 1) | (bit & 1));
    if (++m_nbits == 8) {
      m_out.put(static_cast<char>(m_buffer));
      m_buffer = 0;
      m_nbits = 0;
    }
  }

  void flush() {
    if (m_nbits > 0) {
      m_buffer = static_cast<unsigned char>(m_buffer << (8 - m_nbits));
      m_out.put(static_cast<char>(m_buffer));
      m_buffer = 0;
      m_nbits = 0;
    }
  }

private:
  std::ostream &m_out;
  unsigned char m_buffer{0};
  int m_nbits{0};
};

// Preorder tree layout: each internal node is a single 0 bit, each leaf is a
// 1 bit followed by its 8-bit byte value. decompress.cpp reverses this.
void serialize_tree(const Tree *node, BitWriter &writer) {
  if (node->is_leaf()) {
    writer.put_bit(1);
    unsigned char val{static_cast<unsigned char>(node->m_val)};
    for (int i = 7; i >= 0; --i) {
      writer.put_bit((val >> i) & 1);
    }
  } else {
    writer.put_bit(0);
    serialize_tree(node->left.get(), writer);
    serialize_tree(node->right.get(), writer);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: only accepts a file path argument!";
    return 1;
  }

  std::string file_path{argv[1]};
  std::ifstream input(file_path, std::ios::binary);

  if (!input.is_open()) {
    std::cerr << "Failed to open input file: " << file_path << '\n';
    return 1;
  }

  int counts[256]{};

  char byte;
  while (input.get(byte)) {
    counts[static_cast<unsigned char>(byte)]++;
  }

  std::priority_queue<std::unique_ptr<Tree>, std::vector<std::unique_ptr<Tree>>,
                      CompareTree>
      queue;

  for (size_t i{0}; i < 256; ++i) {
    if (counts[i] != 0) {
      queue.push(std::make_unique<Tree>(static_cast<char>(i), counts[i]));
    }
  }

  while (queue.size() != 1) {
    auto first = std::move(const_cast<std::unique_ptr<Tree> &>(queue.top()));
    queue.pop();
    auto second = std::move(const_cast<std::unique_ptr<Tree> &>(queue.top()));
    queue.pop();

    auto merged = merge(std::move(first), std::move(second));

    queue.push(std::move(merged));
  }

  auto final_tree = std::move(const_cast<std::unique_ptr<Tree> &>(queue.top()));
  queue.pop();

  auto codes = build_codes(final_tree.get());

  // Number of symbols in the original file; decompress.cpp decodes exactly
  // this many and ignores any trailing pad bits, so no padding byte is needed.
  unsigned long long symbol_count{0};
  for (size_t i{0}; i < 256; ++i) {
    symbol_count += static_cast<unsigned long long>(counts[i]);
  }

  std::ofstream output(file_path + ".huf", std::ios::binary);
  if (!output.is_open()) {
    std::cerr << "Failed to open output file\n";
    return 1;
  }

  // Header: 8-byte big-endian symbol count.
  for (int i = 7; i >= 0; --i) {
    output.put(static_cast<char>((symbol_count >> (i * 8)) & 0xFF));
  }

  // Then a single bitstream: serialized tree followed by the encoded data.
  BitWriter writer(output);
  serialize_tree(final_tree.get(), writer);

  // Rewind the input and emit each byte's code as packed bits.
  input.clear();
  input.seekg(0);

  while (input.get(byte)) {
    const std::string &code{codes[byte]};
    for (char bit : code) {
      writer.put_bit(bit == '1' ? 1 : 0);
    }
  }
  writer.flush();

  return 0;
}
