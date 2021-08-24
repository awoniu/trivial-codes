#include <iostream>
#include <functional>
#include <future>
#include <thread>
#include <chrono>
#include <cstdlib>
 
void thread_set_promise(std::promise<int>& promiseObj) {
    std::cout << "In a thread, making data...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    int res = 10;
    promiseObj.set_value(res);
    std::cout << "make:" << res << std::endl;
    std::cout << "make Finished\n";
}

void thread_get_future(std::promise<int>& promiseObj){
    std::cout << "In a thread, getting data...\n";
    std::future<int> futureObj = promiseObj.get_future();
    std::chrono::milliseconds span(100);
    while (futureObj.wait_for(span) != std::future_status::ready)
        std::cout<< "waiting.." << std::endl;
    int res = futureObj.get();
    std::cout << "get:" << res << std::endl;
    std::cout << "get Finished" << std::endl;


    std::promise<int> promiseObj1;
    std::thread t(&thread_set_promise, std::ref(promiseObj1));
    std::future<int> futureObj1 = promiseObj1.get_future();
    while (futureObj1.wait_for(span) != std::future_status::ready)
        std::cout<< "waiting1.." << std::endl;
    int res1 = futureObj1.get();
    std::cout << "get1:" << res << std::endl;
    std::cout << "get1 Finished" << std::endl;
    t.join();
}

int main() {
    std::promise<int> promiseObj;
    std::thread t(&thread_set_promise, std::ref(promiseObj));
    std::thread t1(&thread_get_future, std::ref(promiseObj));    
    t.join();
    t1.join();
    return 0;
}