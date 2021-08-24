#include <iostream>
#include <vector>
//curiously recurring template pattern

//static polymorphism

template<typename DERIVED=AnimalBase>
class Animal
{
public:
    void sayHi(int a) const
    {
        static_cast<const DERIVED*>(this)->sayHi(a);
    }
    DERIVED* cast(){return std::static_cast<DERIVED*>(this); };
};

class AnimalBase
{

};

class Cat:public Animal<Cat>
{
public:
    void sayHi(int a) const
    {
        for(int i=0;i<abs(a); i++)
            std::cout << "miao~";
        std::cout  << std::endl;
    }
};

class Dog:public Animal<Dog>
{
public:
    void sayHi(int a) const
    {
        for(int i=0;i<abs(a); i++)
            std::cout << "wof~";
        std::cout  << std::endl;
    }
};

class Mouse:public Animal<Mouse>
{
public:
    void sayHi(int a) const
    {
        for(int i=0;i<abs(a); i++)
            std::cout << "zip~";
        std::cout << std::endl;
    }
};

template<typename T>
void sayHiFunc(const Animal<T> &animal)
{
    animal.sayHi(2);
}

int main()
{
    Cat c; Dog d; Mouse m;
    c.sayHi(1); d.sayHi(2); m.sayHi(3);
    sayHiFunc(c); sayHiFunc(d);  sayHiFunc(m);

    return 0;
}