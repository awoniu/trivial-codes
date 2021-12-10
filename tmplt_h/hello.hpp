#ifndef _HELLO_
#define _HELLO_
#include <iostream>
template<class T>
class Hello{
public:
Hello();
void func(T val);
};

template<class T>
void helloFunc(T val);

#endif