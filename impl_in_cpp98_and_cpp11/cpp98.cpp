#include <iostream>
#include "cpp98.hpp"
struct A::Impl{
    std::string m_str = "hello";
    int m_func(){std::cout << "m_func" << std::endl;};
};

void A::func(){
    std::cout << pImpl << std::endl;
    std::cout << pImpl->m_str << std::endl;
    pImpl->m_func();
};

A::A():pImpl(new Impl){};
A::~A(){delete pImpl;};  //必须存在
A::A(const A& lhs):pImpl(new Impl){pImpl->m_str = lhs.pImpl->m_str;};
A& A::operator=(const A& lhs){ pImpl->m_str = lhs.pImpl->m_str;};
