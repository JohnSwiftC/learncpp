#include <iostream>
#include <memory>

// John writes a bad linked list in c++

struct Node {
  int value{};
  std::unique_ptr<Node> next;
  explicit Node(int v) : value{v} {}
};

void insert_node(Node &head, int value) {
  Node *curr = &head;

  while (curr->next) {
    curr = curr->next.get();
  }

  curr->next = std::unique_ptr<Node>(new Node{value});
}

void print_list(Node &head) {
  Node *curr = &head;

  while (curr) {
    std::cout << curr->value << '\n';
    curr = curr->next.get();
  }
}

int main() {

  Node head{1};

  insert_node(head, 2);
  insert_node(head, 3);
  insert_node(head, 4);

  print_list(head);

  return 0;
}
