#include <iostream>

int &ub()
{
    int x{100};
    int &u{x};
    return u;
}

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

    // Importantly, it is still just a reference lol.
    // the following is UB for obvious reasons

    int &dangling{ub()};

    std::cout << dangling << '\n';

    // const

    int underlying{12};
    const int &c_ref{underlying};

    // compiler error -> c_ref = 50;

    // the compiler can also screw you
    // a reference to a variable of the wrong
    // type may work due to implicit casts,
    // but the ref secretly makes its own object
    // and no longer refs the original

    // also note the compiler
    // will not let you do this
    // if it is not a const ref
    // because the conversion actually
    // produces an rvalue!!!!

    short some_short{2};
    // illegal -> int &bad_ref{some_short};
    const int &bad_ref{some_short};
    --some_short;

    // will still be 2

    std::cout << bad_ref << " and under is " << some_short << '\n';

    // neuron alert with lifetimes
    // if a const lvalue ref is inited
    // with a temp value, like an rvalue,
    // the ref will extend the lifetime
    // of the temporary value to that of the
    // reference

    // Completely valid, 5 would normally be dropped
    // and leave lifetime as a dangling ref, however
    // c++ wont let me footgun myself that bad
    const int &lifetime{5};

    int some{1};

    // ++some is an lvalue
    int &pre_is_lvalue{++some};

    // while some++ is an rvalue,
    // making this illegal

    // int &post { some++ };

    return 0;
}