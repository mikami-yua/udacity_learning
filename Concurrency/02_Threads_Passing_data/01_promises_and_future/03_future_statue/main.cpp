#include <iostream>
#include <thread>
#include <future>
#include <cmath>

void computeSqrt(std::promise<double> &&prms,double input){
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // simulate work
    double output=sqrt(input);
    prms.set_value(output);    
}
/*
auto status=ftr.wait_for(std::chrono::milliseconds(1000));
当wait_for的时间过短时，子线程到结果还没有得到
    status==std::future_status::timeout || 
            status==std::future_status::deferred
    这种情况下无法获得计算结果

当wait_for的时间足够时，可以得到子线程到运算结果ftr.get()函数结果可用
    status==std::future_status::ready

    没有运行到ftr.get()函数就不会在当前线程强制等待结果
*/

int main(){
    // define input data
    double inputData = 42.0;

    // create promise and future
    std::promise<double> prms;
    std::future<double> ftr=prms.get_future();

    // start thread and pass promise as argument
    std::thread t(computeSqrt,std::move(prms),inputData);

// Student task STARTS here
    // wait for result to become available
    auto status=ftr.wait_for(std::chrono::milliseconds(4000));
    if (status==std::future_status::ready)// result is ready
    {
        std::cout << "Result = " << ftr.get()<< std::endl;
    }//  timeout has expired or function has not yet been started
    else if(status==std::future_status::timeout || 
            status==std::future_status::deferred){
                std::cout << "Result unavailable" << std::endl;
    }
// Student task ENDS here 

    // thread barrier
    t.join();

}