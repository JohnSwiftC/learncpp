#include <iostream>

// The whole point of this file
// is a pattern using const casting
// to stop reusing code between const and
// non const functions.
//
// Also index validation

#include <cassert>
#include <cstddef>
#include <utility>
class MyList {
private:
  int data[5]{1, 2, 3, 4, 5};

public:
  using Index = std::ptrdiff_t;

  // Our const implementation for indexing
  // we dont want to rewrite any complex logic we have
  // in such a const function
  const int &operator[](Index index) const {

    assert(index >= 0 && static_cast<std::size_t>(index) < std::size(data));

    return data[index];
  }

  int &operator[](Index index) {
    // Can use std::as_const to convert *this to const,
    // indexing then uses the already defined operator[] const
    // function, and casts the const int& back to an int&.
    //
    // ALso note, const_cast is just bad practice out of
    // a very select few situtations, this being an acceptable one
    return const_cast<int &>(std::as_const(*this)[index]);
  }
};

int main() {
  const MyList c_list{};
  MyList list{};

  std::cout << c_list[0] << '\n';
  std::cout << list[0] << '\n';

  list[0] = 10;

  std::cout << list[0] << '\n';

  list[10];

  return 0;
}
