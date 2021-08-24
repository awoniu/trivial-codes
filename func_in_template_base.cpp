//处理模板化基类的名称
#include <iostream>
template<typename T>
class Base{
public:
    virtual void func_v(T parm)
    {
        std::cout << "this is func_v in BaseType:parm=" << parm << std::endl;
    }
    void func_nv(T parm)
    {
        std::cout << "this is func_nv in BaseType:parm=" << parm << std::endl;
    };
};

template<>
class Base<double>{
public:
    virtual void func_v(double parm)
    {
        std::cout << "this is spcieal func_v in BaseType:parm=" << parm << std::endl;
    }
    void func_nv(double parm)
    {
        std::cout << "this is spcieal func_nv in BaseType:parm=" << parm << std::endl;
    };

};

template<typename T>
class Derived:public Base<T>{
public:
    virtual void func_v(T parm)
    {
        std::cout << "this is func_v in Derived:parm=" << parm << std::endl;
    }
};

template<typename T>
class A:public Derived<T>{
public:
    void A_func(){
        
        this->func_v(10);    //加this->让编译器进入到父类里去找函数 ,来自effective c++ 第43条
        this->func_nv(10.1);
    }
};

int main()
{
    A<int> a;
    a.A_func();
    A<double> a1;
    a1.A_func();
    return 0;

}