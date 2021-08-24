// 名字遮掩的两种场景
// 发生名字遮掩时，如果没有应对处理，会导致基类中某些函数无法使用
// 所以尽量避免发生名字遮掩，除非有需要而刻意为之
#include <iostream>

class Base{
public:
    void func(){std::cout << "func in base" << std::endl;};
    void func(int arg){std::cout << "func(int) in base" << std::endl;};
};


//redefine one function, and use the others from the base
class Derived0:public Base{
public:
    using Base::func;  
    void func(){std::cout << "func in derived" << std::endl;};

};

//use only one function from the base, give up all the others
class Derived1:private Base{
public:
    void func(int arg){Base::func(arg);};
};

int main()
{
    Derived0 d0;
    d0.func();
    d0.Base::func();
    d0.func(1);

    Derived1 d1;
    //d1.func();  //this func now is unavailables
    d1.func(1);
}