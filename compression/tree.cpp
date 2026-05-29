#include "tree.h"
#include <iostream>
#include <memory>

Tree::Tree(int count) : m_count{count} {}
Tree::Tree(char val, int count) : m_val{val}, m_count{count} {}
Tree::Tree(std::unique_ptr<Tree> left, std::unique_ptr<Tree> right)
    : m_count{left->m_count + right->m_count}, left{std::move(left)},
      right{std::move(right)} {}

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

bool Tree::is_leaf() const { return (!left && !right); }

std::unique_ptr<Tree> merge(std::unique_ptr<Tree> left,
                            std::unique_ptr<Tree> right) {
  if (left->m_count < right->m_count) {
    return std::make_unique<Tree>(std::move(left), std::move(right));
  }

  return std::make_unique<Tree>(std::move(right), std::move(left));
}

void print_preorder(Tree *root) {
  if (!root) {
    return;
  }

  std::cout << root->m_val;
  print_preorder(root->left.get());
  print_preorder(root->right.get());
}
