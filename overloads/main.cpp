#include <iostream>
#include <string_view>

enum Animal
{
    dog,
    cat,
    cow,
    gerbil,
    mouse,
};

constexpr std::string_view animalName(Animal a)
{
    switch (a)
    {
    case dog:
        return "dog";
    case cat:
        return "cat";
    case cow:
        return "cow";
    case gerbil:
        return "gerbil";
    case mouse:
        return "mouse";
    default:
        return "???";
    }
}

// Overload the << operator on ostreams

std::ostream &operator<<(std::ostream &out, Animal a)
{
    out << animalName(a);
    return out;
}

int main()
{
    Animal a{dog};

    std::cout << a << '\n';

    return 0;
}