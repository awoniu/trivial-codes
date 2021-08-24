// show a way to get the const property in template. 
// inspire by the eigen, see the meta.h in eigen, it is wonderful
template <typename T> struct is_const { enum { value = 0 }; };
template <typename T> struct is_const<T const> { enum { value = 1 }; };

template<bool Condition, typename Then, typename Else>
struct conditional { typedef Then type; };
template<typename Then, typename Else>
struct conditional <false, Then, Else> { typedef Else type; };

template <typename T, typename U>
struct CONST_GET
{typedef typename conditional< is_const<T>::value, const U, U >::type type;};

struct Data{
    Data():m_val(1){};
    int m_val;
};

template<typename T> class A{
public:
typename CONST_GET<T, Data>::type m_data;
};

int main()
{
    int i=0;
    A<const int> a;
    A<int> b;
    //a.m_data.m_val = 0;   //  const member value, cannot change
    b.m_data.m_val = 0;

    return 0;
}