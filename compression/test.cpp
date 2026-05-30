#include "tree.h"
#include <memory>

int main() {
  Tree root{'a', 1};

  root.insert(std::make_unique<Tree>('b', 2));
  root.insert(std::make_unique<Tree>('z', 10));
  root.insert(std::make_unique<Tree>('x', 1));

  print_preorder(&root);

  return 0;
}
