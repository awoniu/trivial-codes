#include <iostream>
class Point{
public:
    constexpr Point(double x_val=0, double y_val=0) noexcept
    :x(x_val), y(y_val){}
    constexpr double getX() const noexcept{return x;}
    constexpr double getY() const noexcept{return y;}
private:
    double x,y;
};

int main()
{
    Point a(1,2);
    double i = 1.f*rand();
    double j = 1.f*rand();
    Point(i,j);
    return 0;
}