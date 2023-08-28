#include <iostream>
#include <map>
#include <vector>
class A
{
public:
  A(){std::cout << "A construct" << std::endl;}
  ~A(){std::cout << "A deconstruct" << std::endl;}
  A(int v):m_a(v){std::cout << "A construct(int)" << std::endl;}
  A(const A& obj){std::cout << "A copy construct" << std::endl;}
  A(A&& obj){std::cout << "A move construct" << std::endl;}
  A& operator=(const A& obj){std::cout << "A =" <<std::endl; return *this;}
  A& operator=(A&& obj){std::cout << "A = &&" << std::endl; return *this;}
private:
  int m_a;
};

std::vector<A>  funcVec()
{
  std::vector<A> res(3);
  for(const auto& a:res)
    std::cout << "a:" << &a << std::endl;
  return res;
}

A  funcVal()
{
  A b;
  std::cout << "b:" << &b << std::endl;
  return b;
}

int main()
{
  std::cout << "funcVec" << std::endl;
  const A& a = funcVec()[0];
  std::cout << "a:" << &a << std::endl; /*error: a already deconstruct*/

  std::cout << "funcVal" << std::endl;
  const A& b = funcVal();
  std::cout << "b:" << &b << std::endl; /*ok: b is still reachable*/ 

  return 0;
}

