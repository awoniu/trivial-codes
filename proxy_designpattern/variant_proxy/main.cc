#include <iostream>
#include <vector>
#include <variant>

/* the disadvantage of this method is:
   we have to know all the type for the defination of the variant
*/

struct Tmp
{
    int func(double v) const{ std::cout << "Tmp func" << std::endl; return v*10;}
};

struct Tmp1
{
    int func(double v) const{ std::cout << "Tmp1 func" << std::endl; return v*100;}
};

struct OpFunc
{
    template <typename T>
    int operator()(const T& obj)
    {
        return obj.func(1.5);
    }
};

int main()
{
    std::vector<std::variant<Tmp, Tmp1>> variants{Tmp{}, Tmp1{}};
    for(auto& i:variants)
    {
        std::visit(OpFunc(), i);
    }
    return 0;
}