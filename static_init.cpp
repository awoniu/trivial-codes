#include <iostream>
#include <vector>
std::vector<int> func(){
    std::cout << "g_vec init" << std::endl; 
    return std::vector<int>();
}
static std::vector<int> g_vec = func();


int main()
{
    
return 0;
}