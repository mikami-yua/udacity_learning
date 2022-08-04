#include <iostream>
#include <thread>

void ThreadFunctionEven(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1));  // simulate work
    std::cout << "Even thread\n";
}

void ThreadFunctionOdd(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1));  // simulate work
    std::cout << "Odd thread\n";
}


int main(){
    /* Student Task START */
    for(int i=0;i<6;i++){
        if (i%2==0)
        {
            std::thread t(ThreadFunctionEven);
            t.detach();
        }else{
            std::thread t(ThreadFunctionOdd);
            t.detach();
        }
    }
    /* Student Task END */

    // ensure that main does not return before the threads are finished
    std::this_thread::sleep_for(std::chrono::milliseconds(2));  // simulate work
    std::cout << "End of main is reached" << std::endl;
    /*
    Odd thread
    Even thread
    Odd thread
    Even thread
    Odd thread
    Even thread
    End of main is reached
    */
    return 0;
}
