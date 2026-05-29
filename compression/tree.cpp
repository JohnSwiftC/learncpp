#include "tree.h"
#include <cstddef>

Tree::Tree(std::byte val) : m_val{val} {}
Tree::Tree(std::byte val, int count) : m_val{val}, m_count{count} {}

void Tree::insert(std::unique_ptr<Tree> other) {
  if (!other) {
    return;
  }

  m_count += other->m_count;

  if (other->m_count >= m_count) {
    if (!right) {
      right = std::move(other);
      return;
    }

    return right->insert(std::move(other));
  }

  if (!left) {
    left = std::move(other);
    return;
  }

  return left->insert(std::move(other));
}
