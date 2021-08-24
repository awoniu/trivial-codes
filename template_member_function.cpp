//泛化复制构造函数，
#include <iostream>
template<typename T>
class A_PTR{
public:
    A_PTR(T* data_ptr){  m_ptr = data_ptr;   }
    A_PTR(const A_PTR& obj):m_ptr(obj.getPtr()){  std::cout << "A_PTR copy constrcut" << std::endl;  }
    T* getPtr() const{  return m_ptr;  }
    template<typename O>
    A_PTR(const A_PTR<O>& other_obj):m_ptr(other_obj.getPtr()){  std::cout << "A_PTR template copy construct" << std::endl;  }
private:
    T* m_ptr;
};

class Base{
public:    
};
class Derived:public Base{
public:
};

int main()
{
    int     *ptr;
    Base    *b_ptr;
    Derived *d_ptr;

    b_ptr = d_ptr;
    //d_ptr = b_ptr;  //base cannot convert to derived

    A_PTR<int> a0(ptr);
    A_PTR<Derived> a1(d_ptr);
    //A_PTR<Derived> a2(b_ptr);    //base cannot convert to derived
    A_PTR<Base> a3(b_ptr);
    A_PTR<Base> a4(d_ptr);
    A_PTR<Base> a5(a1);
    A_PTR<Base> a6(a3), a7(a4);

    return 0;
}
