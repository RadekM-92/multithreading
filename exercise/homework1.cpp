#include <iostream>
#include <mutex>
#include <sstream>
#include <thread>
#include <vector>

// Zaimplementuj program, w którym 4 wątki będą wyświetlać swój std::this_thread::id() określoną liczbę razy
// a potem usypialy sie na okreslona jednostke czasu podana jako parametr


void printThreadId(int repetition, std::mutex & mt, std::chrono::duration<double> sleepTime){
    std::stringstream ss;
    std::lock_guard<std::mutex> guard(mt);
    for(int i=0; i<repetition; i++){
        ss << std::this_thread::get_id() << std::endl;
    }
    std::cout << ss.rdbuf() << std::endl;
    std::this_thread::sleep_for(sleepTime);
}

int main()
{
    using namespace std::chrono_literals;

    std::vector<std::thread> threads;
    std::mutex printThreadIdMutex;

    for(int i=0; i<4; i++){
        threads.emplace_back(printThreadId, 3, std::ref(printThreadIdMutex), 2s);
    }
    for(auto && t : threads){
        t.join();
    }

    return 0;
}