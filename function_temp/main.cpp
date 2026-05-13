#include <iostream>

// Deleting is not very useful here,
// but can be useful later in constructors
// and in templates
int evilFunction() = delete;

// We can also delete
// based on template,
// however functions with defined
// arguments will NOT be deleted
void precedent(int x) {};

template <typename T>
void precedent(T x) = delete;

int main()
{

    // illegal evilFunction();

    return 0;
}