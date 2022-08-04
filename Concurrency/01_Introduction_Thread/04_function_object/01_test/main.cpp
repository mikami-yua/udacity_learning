#include <iostream>
#include <thread>

class Vehicle{
public:
    //重载（）运算符
    void operator()(){
        std::cout << "Vehicle object has been created \n";
    }
};

int main(){
    std::thread t((Vehicle()));//令人迷惑到定义

    // do something in main()
    std::cout << "Finished work in main \n";

    // wait for thread to finish
    t.join();

    /*
    Finished work in main 
    Vehicle object has been created
    */
}