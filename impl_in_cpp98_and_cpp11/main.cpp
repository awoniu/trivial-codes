#include <iostream>
#include "cpp98.hpp"
#include "cpp11.hpp"
int main()
{
    A a0;
    A a1 = a0;
    a0.func();
    a1.func();
    A a2; 
    a2 = a0;
    a2.func();

std::cout << "******" <<std::endl;
//**************//
    B b0;
    B b1 = b0;
    b0.func();
    b1.func();
    B b2;
    b2 = b0;
    b2.func();
    b2 = B();
    b2.func();


    return 0;
}