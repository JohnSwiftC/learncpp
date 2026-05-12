#include <iostream>

int main()
{

    // Alright, this is a c++ feature
    // that actually feels pretty unique.
    // the lvalue reference is NOT a pointer
    // and does not store the memory address
    // of the underlying variable

    int a{2};

    int &ref_to_a{a};

    std::cout << a << ref_to_a << '\n';

    ref_to_a = 3;

    std::cout << a << ref_to_a << '\n';

    return 0;
}