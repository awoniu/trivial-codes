#include <iostream>
#include <exception>
#include "thread_pool.hpp"


int test()
{
    int a = 3;
    auto b = func(a);
    return b;
}
