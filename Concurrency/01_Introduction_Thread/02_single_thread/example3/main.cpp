#include <iostream>
#include <thread>

using namespace std;

void threadFunction(){
    this_thread::sleep_for(chrono::milliseconds(50));
    std::cout << "Finished work 1 in thread\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 2 in thread\n";
}

int main(){
    //创建进程
    thread t(threadFunction);

    //do something in main
    this_thread::sleep_for(chrono::milliseconds(50));
    std::cout << "Finished work 1 in main\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 2 in main\n";

    // wait for thread to finish
    t.join();

    /*
    Finished work 1 in main
    Finished work 1 in thread
    Finished work 2 in main
    Finished work 2 in thread
    */
    return 0;
}