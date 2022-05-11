#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
class A
{
public:
  A(){std::cout << "A() construct" << std::endl;}
  A(int v){std::cout << "A(int v)" << std::endl;}
  ~A(){std::cout << "~A() deconstruct" << std::endl;}
  A(const A& obj){std::cout << "A copy construct" << std::endl;}
  A(A&& obj){std::cout << "A move construct" << std::endl;}
  A& operator=(const A&){std::cout << "A operator=" << std::endl;}
private:
  int m_a;
};

class B
{
public:
  B(){std::cout << "B() construct" << std::endl;}
  B(int v){std::cout << "B(int v)" << std::endl;}
  ~B(){std::cout << "~B() deconstruct" << std::endl;}
  B(const B& obj){std::cout << "B copy construct" << std::endl;}
  B(B&& obj){std::cout << "B move construct" << std::endl;}
  B& operator=(const B&){std::cout << "B operator=" << std::endl;}
private:
  int m_b;
};

int main()
{
  {
    std::cout << "p0" << std::endl;
    std::pair<std::string, A> p("p0",A(2));
  }
  {
    std::cout << "p1" << std::endl;
    std::pair<std::string, A> p("p1",2);
  }
  {
    std::cout << "p2" << std::endl;
    std::pair<std::string, A> p("p2",A());
  }
  {
    std::cout << "p3" << std::endl;
    std::pair<std::string, A> p(std::piecewise_construct, std::forward_as_tuple("p3"), std::forward_as_tuple());
  }
  {
  std::map<std::string, std::pair<A,B>> m;
  m.emplace(std::piecewise_construct, std::forward_as_tuple("m0"),  std::forward_as_tuple(std::piecewise_construct, std::forward_as_tuple(1),std::forward_as_tuple()));
  m.emplace(std::piecewise_construct, std::forward_as_tuple("m1"), std::forward_as_tuple(1,2));
  }
  return 0;
}

