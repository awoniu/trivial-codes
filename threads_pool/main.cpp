#include <iostream>
int test();
int test1();
int main()
{
    int a = test()+test1();
    std::cout << a << std::endl;
    return 0;
}