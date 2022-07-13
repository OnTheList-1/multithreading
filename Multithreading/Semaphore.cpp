#include "Semaphore.h"

MonitorReadWrite::MonitorReadWrite(int a_numberOfSemaphores)
    : readerCount(a_numberOfSemaphores), numberOfSemaphores(a_numberOfSemaphores) {}

void MonitorReadWrite::wait()
{
    std::unique_lock<std::mutex> lock(mtx);
    while (readerCount == 0)
        cv.wait(lock);
    --readerCount;
}

void MonitorReadWrite::signal()
{
    std::unique_lock<std::mutex> lock(mtx);
    ++readerCount;
    cv.notify_one();
}
