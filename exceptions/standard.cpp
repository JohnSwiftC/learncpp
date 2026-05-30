#include <exception>
#include <iostream>

class MyException : public std::exception {
private:
  std::string message;

public:
  MyException(std::string message) : message{message} {}

  // We must override this function
  // from the std::exception template
  const char *what() const noexcept override { return message.c_str(); }
};

// std::exception is useful for many reasons.
// First and foremost, you can catch references
// to a base class, and it will ALSO cover any derived classes
//
// Also, any exception thrown in the standard library
// is derived from std::exception

void throws() { throw MyException{"BAHHHHH"}; }

int main() {

  try {
    throws();
    // Catches every class that derives
    // std::exception, including ours.
    //
    // Im pretty sure java does this same exact thing.
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }

  return 0;
}
