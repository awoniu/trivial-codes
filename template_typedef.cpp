#include <vector>
#include <iostream>
template<typename T>
using vec = std::vector<T>;

template<typename T>
class A{
public:
    vec<T> m_data;
};

int main()
{
    vec<int> a{1,2,3};
    return 0;
}