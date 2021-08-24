#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <memory>
using namespace std;

struct A
{
    A(int&& n)
    {
        cout << "rvalue overload, n=" << n << endl;
    }
    A(int& n)
    {
        cout << "lvalue overload, n=" << n << endl;
    }
};

class B
{
public:
    template<class T1, class T2, class T3>
    B(T1 && t1, T2 && t2, T3 && t3) :
        a1_(std::forward<T1>(t1)),
        a2_(std::forward<T2>(t2)),
        a3_(std::forward<T3>(t3))
    {

    }
private:
    A a1_, a2_, a3_;
};



int main()
{
    int i=0;
    A a0(2);
    A a1(i);
    B(1,2,3);
    B(1,i,3);
    return 0;
}