#include <iostream>
#include <typeinfo>
template<class T, class... Args>
T getTypeImpl(T(*)(Args...));



int func(int a)
{};
const int* func1(int a)
{
    const int * ptr = nullptr;
    return ptr;
};

void func2(){};

int main()
{
  using ret_t = decltype(getTypeImpl(func));
  ret_t a = 1;
  std::cout << (typeid(a) == typeid(int)) << std::endl;

  using ret_t1 = decltype(getTypeImpl(func1));
  ret_t1 b;
  std::cout << (typeid(b) == typeid(const int*)) << std::endl;

  using ret_t2 = decltype(getTypeImpl(func2));
  //ret_t2 c;  //void

  return 0;
}