//只有虚函数才会通过虚函数表，被动态调用
//因此不要修改非虚函数
//因此析构函数必须是虚函数
#include <iostream>
class Base{
public:
    virtual void func_v(){std::cout << "Base func_v" << std::endl;}
    void func_nv(){std::cout << "Base func_nv" << std::endl;}
};

class Derive:public Base{
public:
    void func_v(){std::cout << "Derived func_v" << std::endl;}
    void func_nv(){std::cout << "Derived func_nv" << std::endl;}
};

int main()
{
    Base *b = new Derive();
    b->func_v();
    b->func_nv();
    delete b;
}