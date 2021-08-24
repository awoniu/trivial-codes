//参考 effective c++ 24和46
//non-member函数才能做到满足混合式乘法 rational_a=2*rational_b;
//friend函数，才能绕过编译器实参推导,friendyiban1
//模板类的friend函数直接定义在类体内，最简洁简单，注意体积大的函数最好在封装到外面，避免实例化后膨胀
//模板类的friend函数定义在类体外时，参考operator<<
#include <iostream>
template<typename T> class Rational;

template<typename T> 
std::ostream& operator<<(std::ostream& os,const Rational<T>& obj);


template<typename T>
class Rational{
public:
    Rational(const T& numerator=0, const T& denominator=1);
    const T numerator() const;
    const T denominator() const;
    void setNumerator(T val);
    void setDenominator(T val);

friend
    const Rational<T> operator*(const Rational<T>& l_obj, const Rational<T>& r_obj)
    {
        return doMultiply(l_obj, r_obj);   //函数体较大时，单独封装防止模板实例后代码膨胀
    }

friend 
    std::ostream& operator<< <T>(std::ostream& os,const Rational<T>& obj);   //类体外的friend定义

private:
    T m_n;
    T m_d;
};

template<typename T>
Rational<T>::Rational(const T& numerator, const T& denominator):m_n(numerator),m_d(denominator){}

template<typename T>
const T Rational<T>::numerator() const{return m_n;}

template<typename T>
const T Rational<T>::denominator() const{return m_d;}

template<typename T>
void Rational<T>::setNumerator(T val){m_n = val;}

template<typename T>
void Rational<T>::setDenominator(T val){m_d = val;}

template<typename T>
const Rational<T> doMultiply(const Rational<T> l_obj, const Rational<T> r_obj)
{
    return Rational<T>(l_obj.numerator()*r_obj.numerator(),l_obj.denominator()*r_obj.denominator());
}

template<typename T>
std::ostream& operator<<(std::ostream& os,const Rational<T>& obj)
{
    os << obj.numerator()<<":"<<obj.denominator()<<";";
    return os;
}

int main()
{
    Rational<int> a(1,2);
    Rational<int> b(3,4);
    auto c = a*b;
    std::cout << a << b << c <<std::endl;
    c.setDenominator(a.denominator());
    std::cout << a << b << c <<std::endl;    
    return 0;
}