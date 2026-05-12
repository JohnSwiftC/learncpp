/*
 * Here, doSomething is defined twice
 * with both an internal and external linkage
 * when linked against its forward declaration in
 * linkage_main.cpp, it will take and use the add
 * version
 */

namespace
{
    int doSomething(int x, int y)
    {
        return x * y;
    }
}

int doSomething(int x, int y)
{
    return x + y;
}