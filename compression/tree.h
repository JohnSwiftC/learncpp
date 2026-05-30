#ifndef TREE_H
#define TREE_H

#include <cstddef>
#include <memory>
#include <string>
#include <unordered_map>

struct Tree {
  char m_val{};
  int m_count;
  std::unique_ptr<Tree> left;
  std::unique_ptr<Tree> right;

  Tree(int count);
  Tree(char val, int count);
  Tree(std::unique_ptr<Tree> left, std::unique_ptr<Tree> right);

  void insert(std::unique_ptr<Tree> other);

  bool is_leaf() const;

  friend std::unique_ptr<Tree> merge(std::unique_ptr<Tree> left,
                                     std::unique_ptr<Tree> right);

  friend void print_preorder(Tree *root);

  friend void build_codes(const Tree *root, std::string prefix,
                          std::unordered_map<char, std::string> &codes);
};

std::unordered_map<char, std::string> build_codes(const Tree *root);

#endif
