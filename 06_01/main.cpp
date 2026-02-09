#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;

int turn = 1;

void ThreadFunc(int myTurn) {
    std::unique_lock<std::mutex> lock(mtx);

    cv.wait(lock, [&]() { return turn == myTurn; });
    std::cout << "thread " << myTurn << std::endl;
    turn++;

    cv.notify_all();
}

int main() {
    std::thread t1(ThreadFunc, 1);
    std::thread t2(ThreadFunc, 2);
    std::thread t3(ThreadFunc, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
