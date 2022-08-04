#include <iostream>
#include <thread>

void threadFunction() {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate work
  std::cout << "Finished work in thread\n";
}

int main(){
    std::thread t(threadFunction);

    //脱离子线程，继续主线程
    t.detach();

    // do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate work
    std::cout << "Finished work in main\n";

    /*
    Finished work in main
    */
    return 0;
}