#include <iostream>
#include <math.h>
namespace test{
// 定义容器的空间配置器，和C++标准库的allocator实现一样
template<typename T>
struct Allocator
{
	T* allocate(size_t size) // 负责内存开辟
	{
		return (T*)malloc(sizeof(T) * size);
	}
	void deallocate(void* p) // 负责内存释放
	{
		free(p);
	}
	void construct(T* p, const T& val) // 在指定内存上负责对象构造
	{
		new (p) T(val); // 定位new
	}
	void destroy(T* p) // 负责对象析构
	{
		p->~T(); // ~T()代表了T类型的析构函数
	}
};

template<typename T>
class iterator;

template<typename T, typename Alloc = Allocator<T>>
class vector
{
public:
	vector(int size = 10)
	{
		// 需要把内存开辟和对象构造分开处理
		_first = _allocator.allocate(size);
		_last = _first;
		_end = _first + size;
	}
	~vector()
	{
		// 析构容器有效的元素，然后释放_first指针指向的堆内存
		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destroy(p); // 把_first指针指向的数组的有效元素进行析构操作
		}
		_allocator.deallocate(_first); // 释放堆上的数组内存
		_first = _last = _end = nullptr;
	}
	vector(const vector<T>& rhs)
	{
		int size = rhs._end - rhs._first;
		_first = _allocator.allocate(size);
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; ++i)
		{
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
	}
    //需要给容器提供begin和end方法
    iterator<T> begin(){return iterator<T> (_first);}
    iterator<T> end(){return iterator<T> (_end);}
	vector<T>& operator=(const vector<T>& rhs)
	{
		if (this == &rhs)
			return *this;

		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destroy(p); // 把_first指针指向的数组的有效元素进行析构操作
		}
		_allocator.deallocate(_first);

		int size = rhs._end - rhs._first;
		_first = _allocator.allocate(size);
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; ++i)
		{
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
		return *this;
	}
	void push_back(const T& val) // 向容器末尾添加元素
	{
		if (full())
			expand();
			
		_allocator.construct(_last, val);
		_last++;
	}
	void pop_back() // 从容器末尾删除元素
	{
		if (empty())
			return;

		// 不仅要把_last指针--，还需要析构删除的元素
		--_last;
		_allocator.destroy(_last);
	}
	T back()const // 返回容器末尾的元素的值
	{
		return *(_last - 1);
	}
	bool full()const { return _last == _end; }
	bool empty()const { return _first == _last; }
	int size()const { return _last - _first; }
	T & operator[](int index)
    {
        if(index < 0 || index >= size())
        {
            throw "OutofRangeException";
        }
        return _first[index];
    }
private:
	T* _first; // 指向数组起始的位置
	T* _last;  // 指向数组中有效元素的后继位置
	T* _end;   // 指向数组空间的后继位置
	Alloc _allocator; // 定义容器的空间配置器对象

	void expand() // 容器的二倍扩容
	{
		int size = _end - _first;
		T* ptmp = _allocator.allocate(2 * size);
		for (int i = 0; i < size; ++i)
		{
			_allocator.construct(ptmp + i, _first[i]);
		}
		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destroy(p);
		}
		_allocator.deallocate(_first);
		_first = ptmp;
		_last = _first + size;
		_end = _first + 2 * size;
	}
};


  //迭代器
template<typename T>
class iterator
{
public:
iterator(T* p = nullptr):_ptr(p){}

bool operator!=(const iterator &it)const
{
    return _ptr != it._ptr;
}
void operator++()//迭代器的前置++运算符重载，不用后置++的原因是不用产生临时量
{
    _ptr++;
}
T & operator*()
{
    return *_ptr;
}
const T & operator*()const
{
    return *_ptr;
}
private:
    T* _ptr;
};
}


class A
{
public:
	A() { std::cout << "A()" << std::endl; }
    A(int v) { std::cout << "A(int)" << std::endl; m_v = v; }
	~A() { std::cout << "~A()" << std::endl; }
	A(const A& other) { std::cout << "A(const A&)" << std::endl;m_v =  other.m_v;}
    int m_v=0;
};

int main()
{
    test::vector<A>vec;

    for(int i = 0;i<20;++i)
    {
        vec.push_back(A(i));
    }
    int size = vec.size();
    for(int i = 0;i<size;++i)
    {
        std::cout<<i<<":"<<vec[i].m_v << "; ";
    }
      std::cout<<std::endl;
    std::cout<<"----------------------------------------------------------"<<std::endl;
    test::iterator<A> it = vec.begin();
    for(;it != vec.end();++it)
    {
        std::cout<<(*it).m_v<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"----------------------------------------------------------"<<std::endl;
    for(A& val:vec)//foreach的底层原理也是通过容器的迭代器来实现容器遍历
    {
        std::cout<<val.m_v<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
