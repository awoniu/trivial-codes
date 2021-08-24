#include <iostream>
#include <functional>
        //lambda 捕获的成员变量，其实是通过按值捕获了this指针取得的（保存了this的副本），隐含着对this指针的依赖。
        //因此此处严格的做法是显式的列出来捕获列表，不然容易扑街
class A{
public:
    A(int data):m_data(data){}
    std::function<void()> genFunc(){
        int a = 5;
        //lambda 捕获的成员变量，其实是通过按值捕获了this指针取得的，隐含着对this指针的依赖。
        //因此此处严格的做法是显式的列出来捕获列表，不然容易扑街
        auto func = [=, a = std::move(a)]()     //可以使用move触发调用移动构造
        {
            std::cout << "a=" << a << std::endl;
            std::cout << "m_data=" << m_data << std::endl;  // 隐藏bug: m_data是成员变量，这样其实是等价于copy_of_ptr_this->m_data
        };
        return func;
    }

    std::function<void()> genFunc1(){
        int a = 5;
        auto func =[=, m_data=this->m_data]()    
        {
            std::cout << "a=" << a << std::endl;   //a 不是成员变量，可以按值捕获
            std::cout << "m_data=" << m_data << std::endl;   //
        };
        return func;
    }
    void revise(int data){m_data = data;}
private:
    int m_data;
};

int main()
{
    A* a = new A(10);
    auto f = (*a).genFunc();
    auto f1 = (*a).genFunc1();
    f();f1();
    delete a;
    f();f1();
    return 0;
}