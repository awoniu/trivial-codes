#include <iostream>
class A{
protected:
  A(){std::cout<<"A ctr"<<std::endl;};
  A(const A&){std::cout<<"A cp ctr"<< std::endl;};
  int m_data;
};

class B:public A{
public:
  B(){};
  B(const B&){};
  int m_data;
};

class C:public A{
public:
  C(){};
  C(const C& obj):A(obj){};
  int m_data;
};

int main()
{
    B b;
    B b1(b);
    C c;
    C c1(c);
    return 0;
}