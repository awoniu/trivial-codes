#include <iostream>
//首先初始化父类，其次按顺序初始化成员，无论初始化列表的顺序是如何写的，都是按此顺序初始化
struct Data{
    Data():d(0)
    {std::cout << "Data construct0" << std::endl;};
    Data(int val):d(val)
    {std::cout << "Data construct1" << std::endl;};
    int d;
};

struct Data1{
    Data1():d(0)
    {std::cout << "Data1 construct0" << std::endl;};
    Data1(int val):d(val)
    {std::cout << "Data1 construct1" << std::endl;};
    int d;
};

struct Data2{
    Data2():d(0)
    {std::cout << "Data2 construct0" << std::endl;};
    Data2(int val):d(val)
    {std::cout << "Data2 construct1" << std::endl;};
    int d;
};

class A{
public:
    A(){std::cout << "A construct0" << std::endl;}
    virtual ~A(){std::cout << "A deconstruct" << std::endl;}
};

class B:public A{
public:
    B(){std::cout << "B construct0" << std::endl;}
    B(int a):m_data1(a), A(), m_data(a){std::cout << "B construct1" << std::endl;}
     ~B(){std::cout << "B deconstruct" << std::endl;}
private:
    Data m_data;
    Data1 m_data1;
};

int main()
{
    B b;
    std::cout << "****" << std::endl;
    B b1(3);
    return 0;
}
