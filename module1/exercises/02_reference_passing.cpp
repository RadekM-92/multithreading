#include <thread>
#include <iostream>
using namespace std;

void add10(int & a)
{
    a += 10;
    std::cout<<"Inside thread: " << a <<std::endl;
}

int main()
{
    // run add10 function in a thread
    // pass 5 as an argument and read it's value
    int sum = 5;
    std::thread th(add10, std::ref(sum));
    std::cout<<"Before thread join(): " << sum <<std::endl;
    th.join();
    std::cout<<"After thread join(): " << sum <<std::endl;

    return 0;
}

