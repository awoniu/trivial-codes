#include <iostream>
class A{
public:
    int func(){
        std::cout << "not const func" << std::endl;
        return 0;
    }

    const int func() const{
        std::cout << "const func" <<std::endl;
        return 0;
    }

};
int main()
{
    const A a;
    int res = a.func(); //call the const func

    A a1;
    const int res_const = a1.func();   //call the not const func
    return 0;
}