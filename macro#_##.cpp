#include <iostream>

// concatenate two tokens
#define EIGEN_CAT2(a,b) a ## b
#define EIGEN_CAT(a,b) EIGEN_CAT2(a,b)

#define EIGEN_COMMA ,

// convert a token to a string
#define EIGEN_MAKESTRING2(a) #a
#define EIGEN_MAKESTRING(a) EIGEN_MAKESTRING2(a)

//run: "g++ -E ./this_file.cpp -o tmp.log" 
int main()
{
  EIGEN_CAT(1,2);
  EIGEN_MAKESTRING(aa);
  return 0;
}