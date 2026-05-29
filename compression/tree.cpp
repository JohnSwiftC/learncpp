#include "tree.h"
#include <iostream>

Tree::Tree(int count) : m_count{count} {}
Tree::Tree(char val, int count) : m_val{val}, m_count{count} {}

void Tree::insert(std::unique_ptr<Tree> other) {
  if (!other) {
    return;
  }

  int other_count{other->m_count};

  if (other_count >= m_count) {
    m_count += other_count;
    if (!right) {
      right = std::move(other);
      return;
    }

    return right->insert(std::move(other));
  }

  m_count += other_count;
  if (!left) {
    left = std::move(other);
    return;
  }

  return left->insert(std::move(other));
}

void print_preorder(Tree *root) {
  if (!root) {
    return;
  }

  std::cout << root->m_val;
  print_preorder(root->left.get());
  print_preorder(root->right.get());
}
