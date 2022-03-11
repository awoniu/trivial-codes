#include <iostream>
#include <thread>
#include <chrono>

/* global static val will be init at last, and in an unknown order, even though it was called */
/* func static val will be init when used */
int genVal(int v){
  printf("genVal:v=%d\n",v);
  return v;
}

static int static_val=genVal(2);  
int func()
{
  static int func_static_val=genVal(3);
  return func_static_val;
}

int test()
{
  int a = static_val;
  int b = func();
  printf("test:a=%d\n",a);       /* a's value is unknown, bug may happen in here */
  printf("test:b=%d\n",b);       /* b's value is always correct */
  return 0;
}

__attribute__((constructor)) void runBeforeMain()
{ 
    test();
    printf("run before main\n");    
}

int main()
{
  std::cout<< "main" << std::endl;  /*fourth*/
  return 0;
}