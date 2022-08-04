#include <iostream>
#include <thread>
#include <vector>

/*
使用vector和for循环能启动多个线程
*/

int main(){
    std::vector<std::thread> threads;

    for(size_t i=0;i<10;i++){
        // create new thread from a Lambda
        threads.emplace_back([i](){
            // wait for certain amount of time
            std::this_thread::sleep_for(std::chrono::milliseconds(10 * i));

            // perform work
            std::cout << "Hello from Worker thread #" << i << std::endl;
        });
    }

    // do something in main()
    std::cout << "Hello from Main thread" << std::endl;

    // call join on all thread objects using a range-based loop
    for (auto &t : threads) {
      t.join();
    }
    /*
    Hello from Main thread
Hello from Worker thread #0
Hello from Worker thread #1
Hello from Worker thread #2
Hello from Worker thread #3
Hello from Worker thread #4
Hello from Worker thread #5
Hello from Worker thread #6
Hello from Worker thread #7
Hello from Worker thread #8
Hello from Worker thread #9
    */


    return 0;
}