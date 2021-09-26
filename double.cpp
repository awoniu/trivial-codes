#include <iostream>
#include <iomanip>      // std::setprecision
int main()
{
    std::cout << std::fixed;
    std::setprecision(9);
    double a=1.11111111111, b=a;
    std::cout<<a<<":\t";
    std::cout<<b<<std::endl;
    for(size_t i=0; i<1000000; i++)
        a+=100000.0f;
    b+=100000.f*1000000;

    std::cout<<a<<":\t";
    std::cout<<b<<std::endl; 	    
}
