#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include "Semaphore.h"

int availableSeats = 10;

int read() {
    return availableSeats;
}

void write(int count, MonitorReadWrite& mrw)
{
    mrw.wait();
    availableSeats += count;
    mrw.signal();
}


int main(int argc, char** argv)
{
    MonitorReadWrite mrw(10);
    read();
    write(10, mrw);
}
