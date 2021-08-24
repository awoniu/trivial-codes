#include <iostream>
//eigen里这么干的，why?
class A
{ 
private:
    int m_a_data;
};

template<typename T>
class B{
public:
    typedef T type;
    typedef A A_type;
private:
    int m_b_data;
};

class C:public B<A>::type
{
private:
    int m_c_data;
};



class D:public C
{
private:
    int m_d_data;
};

template<typename T, typename U=typename B<T>::A_type>
class E
{
public:
    E(){std::cout << "e" << std::endl;};
};

template<typename T>
class E<T, A>
{
public:
    E(){std::cout << "A偏特化" << std::endl;};
};

template<typename T>
class E<T, D>
{
public:
    E(){std::cout << "D偏特化" << std::endl;};
};

int main()
{
    C c;
    D d;
    E<A> e;
    return 0;
}