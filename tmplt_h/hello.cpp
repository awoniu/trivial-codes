#include "hello.hpp"
template<class T>
Hello<T>::Hello()
{}

template<class T>
void Hello<T>::func(T val)
{
    std::cout << val/2 << std::endl;
}

template<class T>
void helloFunc(T val)
{
    std::cout << val*2 << std::endl;  
}

template class Hello<double>;
template class Hello<int>;
template void helloFunc(double val);
template void helloFunc(int val);