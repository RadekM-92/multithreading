#include <vector>
#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>
using namespace std;

// Secure your code so that each thread can safely enter its full text into the stream.
std::mutex do_work_mutex;

void do_work(int id) {
    this_thread::sleep_for(100ms);
    std::lock_guard<std::mutex> guard(do_work_mutex);
    cout << "Thread [" << id << "]: " << "Job done!" << endl;
}

int main() {
    vector<thread> threads;
    for (int i = 0; i < 20; i++) {
        threads.emplace_back(thread(do_work, i));
    }
    for (auto && t : threads) {
        t.join();
    }
    return 0;
}
