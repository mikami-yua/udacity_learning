#include <iostream>
#include <thread>//并发工具库
#include <vector>

using std::cout;

int main(){
    std::vector<std::thread> threads;

    //开启n个线程
    int nThreads=4;
    for(int i=0;i<nThreads;i++){
        threads.emplace_back(std::thread([](){
            while (true);
        }));
    }

    //在离开main函数之前，等待相乘执行结束
    std::for_each(threads.begin(),threads.end(),[](std::thread &t){
        t.join();
    });
}