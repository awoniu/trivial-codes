#include <chrono>
#include <thread>
#include <iostream>
namespace time_count
{
class TimeCount final{
public:
  int64_t timeDuration()
  {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-m_start).count();
  }
private:
  std::chrono::system_clock::time_point m_start=std::chrono::system_clock::now();
};
}//time_count

int main()
{
  time_count::TimeCount a;
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  std::cout << (a.timeDuration()) << std::endl;
  return 0;
}

