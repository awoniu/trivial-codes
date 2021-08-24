template<typename T>
void func(T* p)
{
    T a;
    a++;
    *p += 1;
}

template<typename T>
void func1(const T* p)
{
    T a = *p;
}

//can not pass compiler
int main()
{
    int a = 1;
    func(&a);
    const int* b = &a;
    func(b);
    func1(b);

    return 0;
}