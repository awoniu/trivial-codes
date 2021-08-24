#include <iostream>
#include <mutex>
using namespace std;
class LazySingleton  //实现单例模式的类
{
public:
    class AutoClearSingle  //lazy 模式因为static是一个指向堆的指针，指针释放是无法进入析构函数的，因此需要如此
    {
        public:
        ~AutoClearSingle(){if(LazySingleton::instance){delete LazySingleton::instance; LazySingleton::instance=NULL;}};
    };
private:
	LazySingleton() //私有的构造函数,这样就不能再其他地方创建该实例
	{
        std::cout << "LazySingleton construct" << std::endl;
	}

	~LazySingleton() //私有的构造函数,这样就不能再其他地方创建该实例
	{
        std::cout << "LazySingleton deconstruct" << std::endl;
	}

	static LazySingleton* instance;  //定义一个唯一指向实例的指针，并且是私有的
	static int b;
    static std::mutex mtx;
public:
	static LazySingleton* GetInstance()
	{
		std::lock_guard<std::mutex> lck(mtx); //上锁
		if (instance == NULL)
		{
			instance = new LazySingleton;
            static AutoClearSingle clr;
		}
		return instance;
	}
	static void show()
	{
		cout << b << endl;
	}
};

int LazySingleton::b = 10; //静态成员变量在类外进行初始化，它是整个类的一部分并不属于某个类
LazySingleton* LazySingleton::instance = NULL;
std::mutex LazySingleton::mtx;

class HungrySingleton  //实现单例模式的类
{
private:
	HungrySingleton() //私有的构造函数,这样就不能再其他地方创建该实例
	{
        std::cout << "HungrySingleton construct" << std::endl;
	}

	~HungrySingleton() //私有的构造函数,这样就不能再其他地方创建该实例
	{
        std::cout << "HungrySingleton deconstruct" << std::endl;
	}

	static HungrySingleton instance;  //定义唯一实例，并且是私有的
	static int b;
    static std::mutex mtx;
public:
	static HungrySingleton* GetInstance()
	{
		return &instance;
	}
	static void show()
	{
		cout << b << endl;
	}
};

int HungrySingleton::b = 10; //静态成员变量在类外进行初始化，它是整个类的一部分并不属于某个类
HungrySingleton HungrySingleton::instance;
std::mutex HungrySingleton::mtx;


int main()
{
    HungrySingleton* b1 = HungrySingleton::GetInstance();
    cout << b1 << endl;
    b1->show();

    HungrySingleton* b2 = HungrySingleton::GetInstance();
    cout << b2 << endl;
    b2->show();

	LazySingleton* a1 = LazySingleton::GetInstance();
	cout << a1 << endl;
	a1->show();

	LazySingleton* a2 = LazySingleton::GetInstance();
	cout << a2 << endl;
	a2->show();

	return 0;
}