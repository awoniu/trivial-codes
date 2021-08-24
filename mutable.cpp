#include <iostream>
#include <atomic>
#include <string>
class A{
public:
    void func() const   //with const means no revise datas. but can revise the count to record the number func is called
    {m_count++; std::cout << "func do something" << std::endl;}
    int funcCallCount() const
    {return m_count;}
private:
    int m_data0=0;
    int m_data1=0;
    int m_data2=0;
private:
    mutable int m_count=0; 
};

int main()
{
    A a;
    a.func();
    std::cout << a.funcCallCount() << std::endl;
    return 0;
}