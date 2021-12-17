#include <iostream>
#include <math.h>
template<class T>
class PRECISE{
    static T MIN(){return 0;}
};
template<>
class PRECISE<double>{
public:
    static double MIN(){return 1e-9;}
};

template<>
class PRECISE<float>{
public:
    static float MIN(){return 1e-6;}
};

template <class T>
bool isEqual(T a, T b)
{
    return fabs(a-b)>PRECISE<T>::MIN()? false:true;
}

int main()
{
  double a = 0;
  double b = 0.0000000001;
  float c = 0;
  float d = 0.00000001;
  std::cout << isEqual(a, b) << std::endl;
  std::cout << isEqual(c, d) << std::endl;
  return 0;
}
