#include <iostream>
#include <new>

int main() {

  // new allocates memory on the heap
  // like malloc in C with some key differences
  int *val{new int{7}};

  // this will throw an exception if it goes bad
  // so we can make it return a nullptr instead
  // if it failed
  int *val2{new (std::nothrow) int{7}};

  if (val2) {
    std::cout << *val2 << '\n';
  }

  // delete for deallocating / freeing

  delete val;
  delete val2;

  // There are some fun keywords for arrays

  int *arr{new int[10]}; // note the length can be dynamic

  for (auto i{0}; i < 10; ++i) {
    arr[i] = static_cast<int>(i) + 1;
    std::cout << arr[i] << '\n';
  }

  // for deleting, we need the delete[] operator
  delete[] arr;

  return 0;
}
