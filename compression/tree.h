#ifndef TREE_H
#define TREE_H

#include <cstddef>
#include <memory>

struct Tree {
  char m_val;
  int m_count;
  std::unique_ptr<Tree> left;
  std::unique_ptr<Tree> right;

  Tree(int count);
  Tree(char val, int count);

  void insert(std::unique_ptr<Tree> other);

  friend void print_preorder(Tree *root);
};

#endif
