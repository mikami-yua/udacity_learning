#include <iostream>
#include <thread>

using std::cout;

void threadFunction(){
    //模拟工作100s
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //chrono是一个time library

    cout<<"Finished work in thread\n";
}

int main(){
    //create thread
    std::thread t(threadFunction);
    //创建线程并执行函数

    //模拟工作50s
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work in main\n";

    // wait for thread to finish
    t.join();
    /*如果不执行t.join();
    Finished work in main
    terminate called without an active exception
    已放弃 (核心已转储)
    */
    return 0;
    
    /*
    Finished work in main
    Finished work in thread
    */
}