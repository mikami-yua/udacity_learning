#include <iostream>
#include <thread>
#include <vector>

void printHello(){
    std::cout<<"Hello from Worker thread #"
            <<std::this_thread::get_id()
            <<"\n";
}

int main(){
    // create threads
    std::vector<std::thread> threads;
    for(size_t i=0;i<5;i++){
        // copying thread objects causes a compile error
        /*
        std::thread t(printHello);
        threads.push_back(t);
        */
       // moving thread objects will work
       threads.emplace_back(std::thread(printHello));//emplace_back原地增加元素，不触发构造函数

    }

    // do something in main()
    std::cout << "Hello from Main thread #" 
            << std::this_thread::get_id()
            <<"\n";
    
    // call join on all thread objects using a range-based loop 
    for(auto &t:threads){
        t.join();
    }
    /*
    Hello from Main thread #139711520491328
    Hello from Worker thread #139711469541120
    Hello from Worker thread #139711477933824
    Hello from Worker thread #139711486326528
    Hello from Worker thread #139711494719232
    Hello from Worker thread #139711503111936
    */


    return 0;

}