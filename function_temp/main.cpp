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

// functions in c++ can have defaults
double tax(double value, double rate = 10.0)
{
    return value * rate;
}

template <typename T>
void precedent(T x) = delete;

// a simple max function
// im sure there is more here
// maybe similar to rust generics
// where i can enforce the generic type
// implementing some sort of traitish
// thing

template <typename T>
const T &max(const T &a, const T &b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}

// These can only be declared manually

template <typename T>
bool greater_than(const T &, const T &);

template <>
bool greater_than<int>(const int &a, const int &b)
{
    return a > b;
}

int main()
{

    // illegal evilFunction();

    std::cout << tax(10.0) << tax(10.0, 5.0) << '\n';

    std::cout << max(2, 3) << '\n';
    std::cout << max(10.0, 15.0) << '\n';

    int a{12};
    int b{13};

    std::cout << max(a, b) << '\n';

    // these can also be treated like generics
    // compiler only makes functions of the type
    // for which the template is actually used

    std::cout << max<int>(a, b) << '\n';

    return 0;
}