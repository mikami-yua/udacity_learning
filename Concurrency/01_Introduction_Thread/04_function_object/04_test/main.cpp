#include <iostream>
#include <thread>

int main(){
    int id=0;

    // starting a first thread (by reference)
    auto f0=[&id](){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout<<"a) ID in Thread (call-by-reference) = "
            <<id<<"\n";
    };

    std::thread t1(f0);

    // starting a second thread (by value)
    std::thread t2([id]()mutable{
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout<<"b) ID in Thread (call-by-value) = "
            <<id<<"\n";
    });

    // increment and print id in main
    ++id;
    std::cout << "c) ID in Main (call-by-value) = " << id << std::endl;
    
     // wait for threads before returning
    t1.join();
    t2.join();

    /*
    c) ID in Main (call-by-value) = 1
    b) ID in Thread (call-by-value) = 0
    a) ID in Thread (call-by-reference) = 1
    当f0执行到时候id到值已经发生改变
    */

    return 0;

}