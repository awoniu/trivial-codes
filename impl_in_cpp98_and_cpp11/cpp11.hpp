#include <memory>
class B{
public:
    B(); 
    ~B();                   //声明必须存在，否则编译器会默认生成inline版本，而此时存在为完整定义的IMPL，无法析构  
                            // 仅声明，不可定义，因为此时的Impl还是未完整定义的对象，无法析构它；因此 = default应该放到cpp里;
    B(B&& rhs);             //仅声明，原因同上
    B& operator=(B&& rhs);  //仅声明，原因同上

    B(const B& lhs);
    B& operator=(const B& lhs);
    void func();
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};