#include <iostream>
#include <string>
#include <thread>

void printName(std::string &name,int waitTime){
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    name += " (from Thread)";
    std::cout << name << std::endl;
}

int main(){
    std::string name("myThread");

    std::thread t(printName,std::ref(name),50);

    t.join();

    name+=" (from Main)";
    std::cout<<name<<"\n";
}