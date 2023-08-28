#include <iostream>

typedef void(*c_func_ptr)(int, double, void*);
void thirdpartyA_call_print(c_func_ptr func, void* func_data)
{
  int a = 1;             /* decide by thirdpartyA */
  double b = 1.5;        /* decide by thirdpartyA */
  func(a, b, func_data);
}

void thirdpartyB_impl_print(int a, double b, char c)
{
  std::cout << "funcImpl: " 
            << "a:" << a << "; " 
            << "b:" << b << "; "
            << "c:" << c << "; "
            << std::endl;
}

/* how to concat the thirdpartyA_call and thirdpartyB_impl */
void funcAPI(int a, double b)

int main()
{
  thirdparty_call(funcImpl, nullptr);
}