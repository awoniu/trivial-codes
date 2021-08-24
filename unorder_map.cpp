#include <iostream>
#include <unordered_map>

class A{
public:
    A(){std::cout << "A() construct" << std::endl;};
    A(int data):m_data(data){std::cout << "A(int) construct" << std::endl;};
    A(const A& obj){std::cout << "A(const A& obj) construct" << std::endl; m_data = obj.m_data;};
private:
    int m_data;
};

int main()
{
    std::unordered_map<std::string, A> map;
    map["1"] = A(1);
    map["2"] = A(2);
    map["3"] = A(3);

    std::cout << "***" << std::endl;
        for(const std::pair<std::string, A>& obj: map)   //will refer to a temporary construct obj A, it will call copy construct
            std::cout << obj.first << std::endl;

    return 0;
}