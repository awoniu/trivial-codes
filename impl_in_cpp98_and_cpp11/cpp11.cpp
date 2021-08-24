#include <iostream>
#include "cpp11.hpp"
struct B::Impl{
    std::string m_str = "hello";
    int m_func(){std::cout << "m_func" << std::endl;};
};

void B::func(){
    std::cout << pImpl.get() << std::endl;
    std::cout << pImpl->m_str << std::endl;
    pImpl->m_func();
};

B::B(){pImpl.reset(new Impl);};
B::~B()=default;    //不能在头文件里定义，必须在头文件声明，源文件定义，直接使用default
B::B(const B& lhs)
{
    std::cout << "B copy construct" << std::endl; 
    pImpl.reset(new Impl); pImpl->m_str = lhs.pImpl->m_str;  
}
B& B::operator=(const B& lhs){ pImpl->m_str = lhs.pImpl->m_str;};
B::B(B&& rhs) = default;
B& B::operator=(B&& rhs) = default;
