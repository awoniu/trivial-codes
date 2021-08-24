#include <iostream>
#include <math.h>
#define NUM (1000)
long func(long a)
{
    if(a <= 0){return 0;}
    volatile long b[NUM] = {0};
    int c = rand()%NUM, d = rand()%NUM;
    b[c] = (long)a+rand();

    return b[d] + func(a-1);
}
int main()
{
    for(long i=0; i<1000000000000000; i+=10){
        std::cout << "*" << i << std::endl;
        try{
            func(i);
        }
        catch(...)
        {
            std::cout << "*******" << std::endl;
        }

    }
    return 0;

}
