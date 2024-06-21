#include "liba.h"
#include <iostream>
int Tmp::func(double v) { std::cout << "Tmp func" << std::endl; return v*10;}
int Tmp::func1(double v, float v1) { std::cout << "Tmp func1" << std::endl; return v*v1*10;}