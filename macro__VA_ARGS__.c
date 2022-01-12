#include "stdio.h"
#include "math.h"
#define PR(m, ...) m( __VA_ARGS__)
int test(int i, int j)
{
  printf("i=%d, j=%d\n",i,j);
  return 0;
}
int main()
{
  PR(test, 1, 2);
  return 0;
}
