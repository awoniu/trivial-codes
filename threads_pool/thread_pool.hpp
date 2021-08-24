#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>



template<typename T>
T func(T v)
{
    T  a = v;
    return v*v;
};

#endif //__THREAD_POOL_H__