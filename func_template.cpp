#include <iostream>
#include <string>
#include <boost/type_index.hpp>
#include <string>
#include <math.h>
using boost::typeindex::type_id_with_cvr;
#define TYPE_DETECT(T) (type_id_with_cvr<T>().pretty_name())
template<typename T>
void func1(T a)
{
    std::cout << (void*)a << std::endl;
    std::string str = TYPE_DETECT(T);
    std::cout << str << std::endl;
}

template<typename T>
void func2(T& a)
{
    std::cout << (void*)a << std::endl;
    std::string str = TYPE_DETECT(T);
    std::cout << str << std::endl;
}

template<typename T>
void func3(T a)
{
    std::cout << &a << std::endl;
    std::string str = TYPE_DETECT(T);
    std::cout << str << std::endl;
}

template<typename T>
void func4(T& a)
{
    std::cout << &a << std::endl;
    std::string str = TYPE_DETECT(T);
    std::cout << str << std::endl;
}
int func0(){ return 0;}
int func(){ return 0;}
class A{};
int main()
{
    {
    std::cout << (void*)func0 << std::endl;   //全局CODE区，往大增长   
    std::cout << (void*)func  << std::endl;   //全局CODE区，往大增长
    std::cout << "***" << std::endl;
    func1(func);  //类型推导：退化为函数指针
    std::cout << "***" << std::endl;
    func2(func);  //
    std::cout << "***" << std::endl;
    auto f = [](){};
    auto f1 = [](){};  //
    auto f2 = [](){int a =rand(); std::cout << "faadsfda" << std::to_string(a) << std::endl;};  //
    std::cout << &f  << std::endl;       //函数栈区 ，往小增长
    std::cout << &f1 << std::endl;       //函数栈区 ，往小增长
    std::cout << &f2 << std::endl;       //函数栈区 ，往小增长  所占大小只有一个字符   
    std::cout << "***" << std::endl;
    func3(f1);                 
    std::cout << "***" << std::endl;
    func4(f1);
    std::cout << "***" << std::endl;
    A a, &b =a;
    std::cout << &b <<std::endl;
    std::cout << "***" << std::endl;    
    func3(b);
    func4(b);
    }

    {
        int a0=0;
        int a1(0);
        int a2={0};
        int a3{0};

        auto b0=0;
        auto b1(0);
        auto b2={0};
        auto b3{0};
        std::cout << TYPE_DETECT(decltype(a0)) << std::endl;
        std::cout << TYPE_DETECT(decltype(a1)) << std::endl;
        std::cout << TYPE_DETECT(decltype(a2)) << std::endl;
        std::cout << TYPE_DETECT(decltype(a3)) << std::endl;

        std::cout << TYPE_DETECT(decltype(b0)) << std::endl;
        std::cout << TYPE_DETECT(decltype(b1)) << std::endl;
        std::cout << TYPE_DETECT(decltype(b2)) << std::endl;
        std::cout << TYPE_DETECT(decltype(b3)) << std::endl;
    }

    return 0;
}