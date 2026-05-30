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

  print_preorder(final_tree.get());

  return 0;
}
