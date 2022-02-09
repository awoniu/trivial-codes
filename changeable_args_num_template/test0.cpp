#include <iostream>
 
using namespace std;
 
void print() {
	cout << "hello world" << endl;
}
 
template<class T>
void print(T a) {
	cout << a << endl;
}
 
template<class T, class ...arg>
void print(const T& a, const arg&... b) {
	cout << a << ", ";
	print(b...);
}
 
int main()
{
	print();
	print(1);
	print(1, 2);
	print(1, 2, 3);
	print(1, 2, 3, 4);
	print(1, 2, 3, 4, 5);
}
