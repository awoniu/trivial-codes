#include <iostream>
#include <functional>
void func(int i, int j)
{
    std::cout << i << std::endl;
    std::cout << j << std::endl;
}

int main()
{
    auto f = std::bind(func, 2, std::placeholders::_1);
    f(3);
    return 0;
}