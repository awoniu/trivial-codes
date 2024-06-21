#include <iostream>
#include "proxy.h"
#include "liba.h"
#include "libb.h"

/*
  the dynamic method maybe slower than static method, 
  but it can be extent to all kind of type in runtime
*/

template<typename RET, typename... ARGS>
struct OpFunc:public FuncType<RET, ARGS...>
{
    template<typename T>
    RET operator()(T* obj, ARGS... arg)
    {
        return obj->func(arg...);
    }
};

void useProxy(const std::vector<Proxy<OpFunc<int, double>>>& vec)
{
    for(const auto&i:vec)
        std::cout << i.run(1.5) << std::endl;
}

int test0()
{
    Tmp p;
    const Tmp1 p1;
    Proxy<OpFunc<int, double>> proxy(&p);
    Proxy<OpFunc<int, double>> proxy1(&p1);
    std::vector<Proxy<OpFunc<int, double>>> vec{proxy, proxy1};
    useProxy(vec);
    return 0;
}

struct OpFunc1:public FuncType<int, double, float>
{
    int operator()(Tmp* obj, double v, float v1)
    {
        return obj->func1(v, v1);
    }
    int operator()(const Tmp1* obj, double v, float v1)
    {
        return obj->func1(v, v1);
    }
};

void useProxy1(const std::vector<Proxy<OpFunc1>>& vec)
{
    for(const auto&i:vec)
        std::cout << i.run(1.5, 2.5) << std::endl;
}

int test1()
{
    Tmp p;
    const Tmp1 p1;
    Proxy<OpFunc1> proxy(&p);
    Proxy<OpFunc1> proxy1(&p1);
    std::vector<Proxy<OpFunc1>> vec{proxy, proxy1};
    useProxy1(vec);
    return 0;
}

int main()
{
    test0();
    test1();
    return 0;
}


