g++ ./liba.cc -shared -fPIC -o liba.so
g++ ./libb.cc -shared -fPIC -o libb.so
g++ ./main.cc -o ./main.run -L. -la -lb -Wl,-rpath="./"