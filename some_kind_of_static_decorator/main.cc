#include <iostream>
#include <ostream>

//use c++17 c++20 to compile

//it is strange use of mixin and crtp,
//but it can get the benifit from mixin and crtp
//from crtp： it is static polynomiod, and lazy mode; 
//from mixin： it can write serial combined class like D<C<B<A>>>
//it is a decorator, the computes use the same refer to the data, and contribute computation to the same data


struct ComputeData
{
    ComputeData(){std::cout << "ComputeData construct" << std::endl;}
    ~ComputeData(){std::cout << "ComputeData deconstruct" << std::endl;}
    friend std::ostream& operator<<(std::ostream& oss, const ComputeData& v)
    {
        oss << "ComputeData:" << &v; return oss;
    }
};

template<typename T, template<typename> typename TT>
struct TemplateTrait
{
    using Type = T;
    TemplateTrait(TT<T>* v){}
};

struct InitCompute;
template<typename T>
struct ComputeBase
{
    ComputeBase(ComputeData& data):m_data(data){}
    void compute()
    {
        using PRECOMPUTE = typename decltype(TemplateTrait(std::declval<T*>()))::Type;
        using CURCOMPUTE = T;
        if constexpr(!std::is_same_v<T, InitCompute>)
        {
            PRECOMPUTE(m_data).compute(); //lazymode, construct here, and destruct here
            static_cast<CURCOMPUTE*>(this)->compute_impl();
        }
    }
    ComputeData& getData(){return m_data;};
    ComputeData& m_data;
};

struct InitCompute:ComputeBase<InitCompute>
{
    InitCompute(ComputeData& v):ComputeBase<InitCompute>(v){};
};

template<typename PreCompute>
struct AddCompute:ComputeBase<AddCompute<PreCompute>>
{
    AddCompute(ComputeData& data):ComputeBase<AddCompute<PreCompute>>(data)
    {std::cout << "AddCompute construct(data)" << std::endl;}
    AddCompute(AddCompute&&)=delete;
    AddCompute(const AddCompute&)=delete;
    AddCompute& operator=(AddCompute&&)=delete;
    AddCompute& operator=(const AddCompute&)=delete;    
    ~AddCompute(){std::cout << "AddCompute deconstruct" << std::endl;}
    void compute_impl()
    {
        std::cout << "AddCompute" << this->m_data << std::endl;
    };
};

template<typename PreCompute>
struct SubCompute:ComputeBase<SubCompute<PreCompute>>
{
    SubCompute(ComputeData& data):ComputeBase<SubCompute<PreCompute>>(data)
    {std::cout << "SubCompute construct(data)" << std::endl;}
    SubCompute(SubCompute&&)=delete;
    SubCompute(const SubCompute&)=delete;
    SubCompute& operator=(SubCompute&&)=delete;
    SubCompute& operator=(const SubCompute&)=delete; 
    ~SubCompute(){std::cout << "SubCompute deconstruct" << std::endl;}
    void compute_impl()
    {
        std::cout << "SubCompute data:" << this->m_data << std::endl;
    };
};

template<typename PreCompute>
struct MulCompute:public ComputeBase<MulCompute<PreCompute>>
{
    using Base = ComputeBase<MulCompute<PreCompute>>;
    MulCompute(ComputeData& data):ComputeBase<MulCompute<PreCompute>>(data)
    {std::cout << "MulCompute construct(data):data = " <<&data<< std::endl;}
    MulCompute(MulCompute&&)=delete;
    MulCompute(const MulCompute&)=delete;
    MulCompute& operator=(MulCompute&&)=delete;
    MulCompute& operator=(const MulCompute&)=delete;
    ~MulCompute(){std::cout << "MulCompute deconstruct" << std::endl;}
    void compute_impl()
    {
        std::cout << "MulCompute data:" << this->m_data << std::endl;
    };
};

int main()
{
    ComputeData data;
    MulCompute<AddCompute<SubCompute<InitCompute>>> cpt(data);
    cpt.compute();
}