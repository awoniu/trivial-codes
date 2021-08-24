#include <iostream>
#include <math.h>
int main()
{
    auto a = NAN;
    auto b = INFINITY;
    //IEEE standard, NaN is guaranteed to be the only value that is not equal to itself!
    std::cout << std::isnan(a) << "::" << (a==a) << std::endl;
    std::cout << std::isinf(b) << std::endl;
    std::cout << std::isfinite(b) << std::endl; 
    std::cout << std::isnormal(b) << std::endl;

}