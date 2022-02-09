#include "template.h"
int func0(int a, int b)
{
  return a+b;
}
int main()
{
  tempFunc(func0, wrt(1,2), at(3,4)); 
  return 0;
}
