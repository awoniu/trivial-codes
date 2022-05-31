#include <iostream>
class V
{
public:
  V(){std::cout <<"V()" << std::endl;}
  ~V(){std::cout << "~V():m_v=" << m_v << std::endl;}
  V(int v):m_v(v){std::cout << "V(int)" << std::endl;}
  V(const V& obj){std::cout << "V(const V&)" << std::endl; m_v=obj.m_v;}
  V(V&& obj){std::cout << "V(V&&)" << std::endl; m_v=obj.m_v;}
  V& operator=(const V& obj){std::cout << "operator=(const V& obj)" << std::endl;m_v = obj.m_v; return *this;}
  V& operator=(V&& obj){std::cout << "operator=(V&& obj)" << std::endl; m_v = obj.m_v; return *this;}
  int getVal(){return m_v;}
private:
  int m_v;
};
class A
{
public:
  A(){std::cout << "A()" << std::endl;}
  ~A(){std::cout << "~A()" << std::endl;}
  A(int a):m_v(a){std::cout << "A(int)" << std::endl;}
  A(int a,int b):A(a+b){std::cout << "A(int,int)" << std::endl;}
  void print(){std::cout << "print(): m_v=" << m_v.getVal() << std::endl;}
private:
  V m_v;
};


int main()
{
 A a(1,2);
 a.print();
 return 0;
}

