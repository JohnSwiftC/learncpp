#include <fstream>
#include <iostream>

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

  return 0;
}
