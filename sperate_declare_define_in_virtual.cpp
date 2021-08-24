//场景1：base类里，纯虚函数声明接口，并把定义实现。声明和定义是分离的
//场景2：base类里，虚函数实现声明接口和定义
//相比之下，场景1的做法，可以避免在多层继承之后，虚函数没有被关注到，导致其他意外行为
#include <iostream>
class Base
{public:
    virtual void func()=0;
};
void Base::func(){}

class Derived:public Base
{
public:
    void func(){Base::func();}
};

int main()
{
    Derived d;
    d.func();
    return 0;
}