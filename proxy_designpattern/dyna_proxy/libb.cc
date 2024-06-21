#include "libb.h"
#include <iostream>

int Tmp1::func(double v) const { std::cout << "Tmp1 func" << std::endl; return v*100;}
int Tmp1::func1(double v, float v1) const { std::cout << "Tmp1 func1" << std::endl; return v*v1*100;}