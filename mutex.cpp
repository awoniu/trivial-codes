#include <iostream>
#include <mutex>
class ABCD{
public:
    ABCD(){}
    //A(const A& obj){
    //    m_data = obj.m_data;
    //}
private:
    int m_data;
};

int main()
{
    ABCD a;
    ABCD b;
    b = a;
    auto c = a;
}