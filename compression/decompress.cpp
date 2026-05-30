#include "tree.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <string>

class BitReader {
public:
  BitReader(std::istream &in) : m_in{in} {}

  int get_bit() {
    if (m_nbits == 0) {
      int c{m_in.get()};
      if (c == EOF) {
        m_eof = true;
        return 0;
      }
      m_buffer = static_cast<unsigned char>(c);
      m_nbits = 8;
    }
    --m_nbits;
    return (m_buffer >> m_nbits) & 1;
  }

  bool eof() const { return m_eof; }

private:
  std::istream &m_in;
  unsigned char m_buffer{0};
  int m_nbits{0};
  bool m_eof{false};
};

std::unique_ptr<Tree> deserialize_tree(BitReader &reader) {
  if (reader.get_bit() == 1) {
    unsigned char val{0};
    for (int i = 0; i < 8; ++i) {
      val = static_cast<unsigned char>((val << 1) | reader.get_bit());
    }
    return std::make_unique<Tree>(static_cast<char>(val), 0);
  }

  auto left = deserialize_tree(reader);
  auto right = deserialize_tree(reader);
  return std::make_unique<Tree>(std::move(left), std::move(right));
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: only accepts a .huf file path argument!\n";
    return 1;
  }

  std::string file_path{argv[1]};
  std::ifstream input(file_path, std::ios::binary);

  if (!input.is_open()) {
    std::cerr << "Failed to open input file: " << file_path << '\n';
    return 1;
  }

  unsigned long long symbol_count{0};
  for (int i = 0; i < 8; ++i) {
    int c{input.get()};
    if (c == EOF) {
      std::cerr << "Truncated header\n";
      return 1;
    }
    symbol_count = (symbol_count << 8) | static_cast<unsigned long long>(c);
  }

  std::string out_path;
  const std::string suffix{".huf"};
  if (file_path.size() > suffix.size() &&
      file_path.compare(file_path.size() - suffix.size(), suffix.size(),
                        suffix) == 0) {
    out_path = file_path.substr(0, file_path.size() - suffix.size());
  } else {
    out_path = file_path + ".out";
  }

  std::ofstream output(out_path, std::ios::binary);
  if (!output.is_open()) {
    std::cerr << "Failed to open output file: " << out_path << '\n';
    return 1;
  }

  if (symbol_count == 0) {
    return 0;
  }

  BitReader reader(input);
  auto root = deserialize_tree(reader);

  for (unsigned long long i{0}; i < symbol_count; ++i) {
    const Tree *node{root.get()};
    while (!node->is_leaf()) {
      node = (reader.get_bit() == 1) ? node->right.get() : node->left.get();
    }
    output.put(node->m_val);
  }

  return 0;
}
