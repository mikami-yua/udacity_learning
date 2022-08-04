#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>


double divideByNumber(double num, double denom)
{
    std::cout << "div thread id = " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work
    if (denom == 0)
        throw std::runtime_error("Exception from thread: Division by zero!");

    return num / denom;
}

/*
省去了promises的代码，减少了指头到压力
*/

int main(){
    //use async to start a task
    std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;
    double num=42.0,demon=0.0;
    std::future<double> ftr=std::async(divideByNumber,num,demon);

    // retrieve result within try-catch-block
    try
    {
        double result=ftr.get();
        std::cout<<"Result = " << result << std::endl;
    }
    catch(std::runtime_error e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
    
}