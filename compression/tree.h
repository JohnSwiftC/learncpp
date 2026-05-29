#ifndef TREE_H
#define TREE_H

#include <cstddef>
#include <memory>

struct Tree {
  std::byte m_val;
  int m_count;
  std::unique_ptr<Tree> left;
  std::unique_ptr<Tree> right;

  Tree(std::byte val);
  Tree(std::byte val, int count);

  void insert(std::unique_ptr<Tree> other);
};

#endif
