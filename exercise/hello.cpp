#include <iostream>
#include <thread>

// Build cmd: g++ hello.cpp -std=c++17 -lpthread

int main()
{
    std::thread th([](){std::cout<<"Hello\n";});
    th.join();

    return 0;
}