#include <type_traits>
#include <vector>
#include <functional>

template<typename RET, typename... ARGS>
struct FuncType
{
    using RETTYPE = RET;
    using ARGTPL = std::tuple<ARGS...>;
    using FUNCP = RET(*)(const char*, ARGS...);
};

template<typename OP>
struct Proxy
{
    using RETTYPE = typename OP::RETTYPE;
    using ARGTPL = typename OP::ARGTPL;
    using FUNCP = typename OP::FUNCP;
    template<typename _T, typename... _Args>
    constexpr /*if(cpp20): consteval*/ static FUNCP GenWarpFunc(std::tuple<_Args...>)
    {  return [](const char* p, _Args... args){ return OP()(reinterpret_cast<_T*>(*p), args...); };  };

    template<typename T>
    Proxy(T* p){ new(m_objp)T*(p); m_fp = GenWarpFunc<T>(ARGTPL());}
    //Proxy(T* p):m_objp((void*)p){ m_fp = GenWarpFunc<T>(ARGTPL());}

    template<typename... Args>
    RETTYPE run(Args... arg) const {return m_fp(m_objp, arg...);}

    private:
    char m_objp[16]; // use a emory to storage the address, so, can avoid const cast，avoid cstype cast
    FUNCP m_fp;
};