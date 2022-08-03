#include <iostream>
#include <thread>

using std::cout;

int main() {
  cout<<"Hello concurrent world from main! Thread id = "
    <<std::this_thread::get_id()<<"\n";
}