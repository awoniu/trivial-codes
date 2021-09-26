#include <iostream>
#include "opencv_includes.hpp"
int main()
{
    cv::Point p;
    cv::Mat a;
    a.create(100,100,CV_8UC1);
    cv::Mat b(a,cv::Rect(5,5,5,5));
    return 0;
}
