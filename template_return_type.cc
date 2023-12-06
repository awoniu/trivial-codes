#include <iostream>
template<typename T>
struct A
{
  //double get(){ return m_v*1.5; } /*gcc not allow*/
  //int get(){ return m_v*2; } /*gcc not allow*/

/*pytorch way: in tensor template*/
  template<typename TP>
  struct identity{ /*a empty class waste no space*/ };
  template<typename TT>
  TT get(){ return _get(identity<TT>()); }
  double _get(identity<double>){ return m_v*1.5; }
  int _get(identity<int>){ return m_v*2; }

/* c++17 way: */
  template<typename TT>
  TT get1(){
  if constexpr(std::is_same_v<TT, double>)
    return m_v*1.5;
  else if constexpr(std::is_same_v<TT, int>)
    return m_v*2;
  }


  int m_v = 10;
};

int main()
{
  A<int> a;
  int v = a.get<int>();
  double v1 = a.get<double>();
  std::cout << v << std::endl;
  std::cout << v1 << std::endl;
  int v2 = a.get1<int>();
  double v3 = a.get1<double>();
  std::cout << v2 << std::endl;
  std::cout << v3 << std::endl;
  return 0;
}
