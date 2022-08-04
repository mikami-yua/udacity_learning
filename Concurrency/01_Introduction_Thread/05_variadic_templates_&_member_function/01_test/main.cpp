#include <iostream>
#include <string>
#include <thread>

void printID(int id){
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout<<"ID= "<<id<<"\n";
}

void printIDAndName(int id,std::string name){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"ID= "<<id<<", name "<<name<<"\n";
}

int main(){
    int id=0;

    //使用变量模板启动线程
    /*
    std::thread t1(函数名,参数1,参数2);
    */
    std::thread t1(printID,id);
    std::thread t2(printIDAndName,++id,"my string");
    // std::thread t3(printIDAndName, ++id);  // this procudes a compiler error

    // wait for threads before returning
    t1.join();
    t2.join();
    /*
    ID= 0
    ID= 1, name my string
    */
    return 0;
}