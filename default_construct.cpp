
//一旦定义了copy构造函数,就不再生成默认无参构造函数了

#include <iostream>
class A{
public:
    A(){};
private:
    int data;
};

class B{
public:
    B(const B& obj){};
private:
    int data;
};

class C{
public:
    C(int parms){};
private:
    int data;
};

int main()
{
    A a0;
    A a1(a0);
    B b0;
    B b1(b0);
    C c0(1);
    C c1(c0);
    return 0;
}