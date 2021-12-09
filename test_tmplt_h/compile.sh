g++ ./hello.cpp  -shared -fPIC  -o libhello.so
g++ ./main.cpp -o ./test -L. -lhello -Wl,-rpath="./"