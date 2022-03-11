#include <iostream>
template<class T, typename... Args>
static void generateOp(Args... args)
{
  T* a = new T(args...);
  std::cout << *a << std::endl;
}

int main()
{
  generateOp<int>(3);
  return 0;
}
