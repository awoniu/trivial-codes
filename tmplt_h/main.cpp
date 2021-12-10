#include "hello.hpp"
int main()
{
  Hello<double> h;
  h.func(1.f);
  Hello<int> h1;
  h1.func(1.f);
  helloFunc(3);
  helloFunc(3.5);
  return 0;
}