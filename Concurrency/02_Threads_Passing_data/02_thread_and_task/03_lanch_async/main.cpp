#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <vector>
#include <chrono>

void workerFunction(int n)
{
    // print system id of worker thread
    std::cout << "Worker thread id = " << std::this_thread::get_id() << std::endl;

    // perform work
    for (int i = 0; i < n; ++i)
    {
        sqrt(12345.6789);
    }
}

int main(){
    // print system id of worker thread
    std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;

    // start time measurement
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    
    // launch various tasks
    std::vector<std::future<void>> futures;
    int nLoop=10,nThread=5;
    for(int i=0;i<nThread;i++){
        futures.emplace_back(std::async(std::launch::async,workerFunction,nLoop));
    }

    // wait for tasks to complete
    for(const std::future<void> &ftr : futures)
        ftr.wait();

    // stop time measurement and print execution time
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Execution finished after " << duration <<" microseconds" << std::endl;
    
    return 0;
    /*
    Main thread id = 140405185673024
    Worker thread id = 140405134726912
    Worker thread id = 140405143119616
    Worker thread id = 140405151512320
    Worker thread id = 140405159905024
    Worker thread id = 140405168297728
    Execution finished after 262 microseconds

    std::launch::async，那么就是声明的时候就回去创建新的线程
    */
}