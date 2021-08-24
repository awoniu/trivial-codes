class A{
public:
    A();
    A(const A& lhs);
    A& operator=(const A& lhs);
    ~A();  //必须存在
    void func();
private:
    struct Impl;
    Impl *pImpl;
};