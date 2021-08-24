#include <future>
#include <chrono>
using namespace std;

class AsyncTest
{
private:
	int count = 0;
	int maxLoop = 2000000000;
public:
	int process()
	{
		count = 0;
		for (int i = 0; i < maxLoop; i++)
		{
			count++;
		}
		return count;
	}
	void doTest()
	{
		std::future<int> f1 = std::async([this]() {return this->process(); });
		int count1 = f1.get();
		printf("count1=%d\n", count1);

		std::future<int> f2 = std::async([this]() {return this->process(); });
		std::chrono::milliseconds span(1000);
		while (f2.wait_for(span) != std::future_status::ready)
		{
			printf("**count2=%d\n", count);
		}
		printf("count2=%d\n", count);

		std::future<int> f3 = std::async([this]() {return this->process(); });
		while (f3.wait_until(chrono::system_clock::now() + span) != std::future_status::ready)
		{
			printf("**count3=%d\n", count);
		}
		printf("count3=%d\n", count);


		std::future<int> f4 = std::async([this]() {return this->process(); });
		f4.wait();
		int count = f4.get();
		printf("count4=%d\n", count);


	}
};

int main()
{
    AsyncTest a;
    a.doTest();
    return 0;

}