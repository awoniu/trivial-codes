//(CRTP)curiously recurring template pattern
#include <iostream>
 
using namespace std;
 
template<typename T>
struct ordered
{
	bool operator>(const T& rhs) const
	{
		const T& self = static_cast<const T&>(*this);
		return rhs < self;
	}
};
 
struct Int : ordered<Int>
{
	explicit Int(int x) : value(x) {}
 
	bool operator<(const Int& rhs) const
	{
		return this->value < rhs.value;
	}
 
private:
	int value;
};
 
 
int main(int argc, char* argv[])
{
	cout << (Int(4) < Int(6)) << endl;
	cout << (Int(9) > Int(6)) << endl;
	return 0;
}