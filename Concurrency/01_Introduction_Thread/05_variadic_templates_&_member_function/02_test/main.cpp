#include <iostream>
#include <string>
#include <thread>

void printName(std::string name, int waitTime) {
  std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
  std::cout << "Name (from Thread) = " << name << std::endl;
  //name+="a";
}

int main(){
    std::string name1="MyThread1";
    std::string name2="MyThread2";

    //使用值复制和移动语义启动线程
    std::thread t1(printName,name1,50);
    std::thread t2(printName,std::move(name2),100);
    // wait for threads before returning
    t1.join();
    t2.join();

    // print name from main
    std::cout << "Name (from Main) = " << name1 << std::endl;
    std::cout << "Name (from Main) = " << name2 << std::endl;
    /*
    Name (from Thread) = MyThread1
    Name (from Thread) = MyThread2
    Name (from Main) = MyThread1
    Name (from Main) = 
    */
}