#include <iostream>
#include <stdio.h>
#include <string_view>

// an std::string can be taken as a string_view
// which is as cheap as a reference. the other way around,
// taking an std::string, requires a full copy to the std::string
void output_string(std::string_view str) { std::cout << str << '\n'; }

int main() {

  // Book isn't too far, but I assume this is a
  // heap allocated type because it is variable
  std::string my_string{"Cpps wonderful string type "};

  std::cout << my_string << '\n';

  // set to lower size

  my_string = "cpp"; // copy assignment?

  /*
   * The big question for me here, which im sure the book will
   * cover as I get past 30 minutes of reading, is if this assignment
   * is actually reallocating heap memory for the new string,
   * or is std::string is a pointer and the initial memory is deallocated
   * especially because the new string literaly does fit in the initial
   * size of the string.
   */

  // compile time error here, appears std::string is not as simple
  // as a char* lmao
  // printf("I love the normal C functions <3: %s\n", my_string);

  // Init like C
  char c_str[] = "Hello World";

  // Init like C++ best practice

  char c_str_cpp[]{"Hello World"};

  printf("First: %s\nSecond: %s\n", c_str, c_str_cpp);

  /*
   * Here we are
   * string views are no copy on init
   * idiomatic String::from???
   * idk lol
   */

  std::string_view my_str_view{"Hello World from str_view"};

  std::cout << my_str_view << '\n';

  /*
   * Alright, saw the word owner
   * in the book and felt all of my neurons
   * start firing. string_view is a viewer
   * into a string, which is the owner
   * rustpilled c++ book
   */

  std::string to_print{"This is my string!!"};

  // I do need to know the mechanism behind
  // this auto-cast
  output_string(to_print);

  return 0;
}
