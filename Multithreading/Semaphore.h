#pragma once
#include <mutex>
#include <semaphore>
class MonitorReadWrite
{
    std::mutex mtx;
    std::condition_variable cv;
    int readerCount = 0;
    const int numberOfSemaphores;
public:
    explicit MonitorReadWrite(int numberOfSemaphores);
    ~MonitorReadWrite() = default;

    void wait();
    void signal();
};