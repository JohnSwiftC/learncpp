#include <iostream>
#include <optional>

// C++ vs Rust? Rust's enums are def better but we do have the optional template

std::optional<int> some_function(int x)
{
    if (x < 0)
    {
        return {}; // same as std::nullopt
    }

    return x;
}

int main()
{
    std::optional<int> a = some_function(2);

    std::optional<int> b = some_function(-3);

    // These must be checked, deref to get underlying value

    if (a)
    {
        std::cout << *a << '\n';
    }
    else
    {
        std::cout << "Failed\n";
    }

    if (b)
    {
        std::cout << *b << '\n';
    }
    else
    {
        std::cout << "Failed\n";
    }
}