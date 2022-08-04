#include <iostream>
#include <thread>
#include <future>

void modifyMessage(std::promise<std::string> &&prms,std::string message){
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    std::string modifiedMessage=message+" has been modified";
    prms.set_value(modifiedMessage);
}

/*
std::future<std::string> ftr=prms.get_future();//与promise绑定

在执行这步到时候
std::string messageFromThread=ftr.get();//从线程获取结果
为了获取get（）函数的结果，当前线程会出现等待现象
*/
int main(){
    // define message
    std::string messageToThread = "My Message";

    // create promise and future
    std::promise<std::string> prms;
    std::future<std::string> ftr=prms.get_future();//与promise绑定

    // start thread and pass promise as argument
    std::thread t(modifyMessage,std::move(prms),messageToThread);

    // print original message to console
    std::cout << "Original message from main(): " << messageToThread << std::endl;

    // retrieve modified message via future and print to console
    std::string messageFromThread=ftr.get();//从线程获取结果

    std::cout << "Modified message from thread(): " << messageFromThread << std::endl;

    // thread barrier
    t.join();

    return 0;
    /*
    Original message from main(): My Message
    Modified message from thread(): My Message has been modified
    */
}