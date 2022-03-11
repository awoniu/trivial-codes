#include <iostream>
#include <map>
#include <functional>
#include <string>
#include <memory>

class A
{
public:
  A(){std::cout << "A construct" << std::endl;}
  A(int a, int b):m_a(a+b){std::cout << "A construct(int,int)" << std::endl;}
  A(int a){std::cout << "A construct(int)" << std::endl;}
  ~A(){std::cout << "A deconstruct" << std::endl;}
private:
  int m_a;
};

template<typename T,typename ...Args>
T* func(Args... args)
{
  void* p = malloc(sizeof(T));
  T*res =  new(p)T(args...);
  std::cout << "  p:" << p  << std::endl;
  std::cout << "res:" << res<< std::endl;
  return res;
}

int main()
{
  void* mem = malloc(sizeof(A));
  void* mem1= malloc(sizeof(A));
  std::cout << "mem:" << mem << std::endl;
  std::cout << "mem1:"<< mem1<< std::endl;
  A* a = new(mem)A;
  A* a1= new(mem1)A(1);
  std::cout << "a:" << a << std::endl;
  std::cout << "a1:"<< a1<< std::endl;
  delete a;
  delete a1;
  A* a2 = func<A>(1,2);
  delete a2;
  return 0;
}

