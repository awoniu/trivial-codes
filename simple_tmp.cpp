//简单的模板元编程
#include <iostream>
template<unsigned n>
struct A{
public:
    enum {value = n*A<n-1>::value};
};
template<>
struct A<0>{
enum {value=1};
};
int main()
{
    std::cout << A<10>::value << std::endl;
    return 0;
}