#include <iostream>
#include <experimental/tuple>
#include <utility>
template<typename... Args>
struct At
{
    std::tuple<Args...> args;
};

template<typename... Args>
struct Wrt
{
    std::tuple<Args...> args;
};

template<typename Fun, typename... Args, typename... Vecs>
auto eval(const Fun& f, const At<Args...>& at, const Wrt<Vecs...>& wrt)
{
    auto u = std::apply(f, at.args);
    return u;
}

template<int N=0, typename Fun, typename... Vars, typename... Args>
auto tempFunc(const Fun& f, const Wrt<Vars...>& wrt, const At<Args...>& at)
{
    auto u = eval(f, at, wrt);
    return u;
}

/// The keyword used to denote the variables *with respect to* the derivative is calculated.
template<typename... Args>
auto wrt(Args&&... args)
{
    return Wrt<Args&&...>{ std::forward_as_tuple(std::forward<Args>(args)...) };
}

/// The keyword used to denote the variables *at* which the derivatives are calculated.
template<typename... Args>
auto at(Args&&... args)
{
    return At<Args&&...>{ std::forward_as_tuple(std::forward<Args>(args)...) };
}


