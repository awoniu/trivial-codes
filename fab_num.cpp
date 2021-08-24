#include <iostream>

template<int NUM>
struct fab{
   enum{ ret = fab<NUM-2>::ret+fab<NUM-1>::ret };
    //int iret= fab<NUM-2>().iret+fab<NUM-1>().iret;
};

template<>
struct fab<1>{
    enum {ret = 1};
};

template<>
struct fab<0>{
   enum {ret = 0};
};

int main()
{
    fab<32> obj;
    //int ires = obj.iret;
    int res = fab<40>::ret;
    std::cout << res << std::endl;    
  //  std::cout << res << std::endl;
}

