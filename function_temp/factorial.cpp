template <int N>
constexpr int factorial()
{
    static_assert(N >= 0);

    if (N == 0)
    {
        return 1;
    }

    int result{1};
    for (int i{1}; i <= N; i++)
    {
        result *= i;
    }

    return result;
}

// define your factorial() function template here

int main()
{
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    // fails to compile factorial<-3>();

    return 0;
}