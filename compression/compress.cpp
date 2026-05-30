#include "tree.h"

#include <fstream>
#include <iostream>
#include <memory>

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

  for (int i{0}; i < 256; ++i) {
    std::cout << static_cast<unsigned char>(i) << ": " << counts[i] << '\n';
  }

  return 0;
}
