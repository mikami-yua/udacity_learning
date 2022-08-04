#include <iostream>
#include <thread>

class Vehicle {
  public:
    Vehicle() {
      _id = 0;
    }
    void addID(int id) { 
      _id = id; 
    }
    void printID() { 
      std::cout << "Vehicle ID=" << _id << std::endl; 
    }

  private:
    int _id;
};
/*
当使用share_ptr的时候，展现了智能指针的智能
在share_ptr的作用域都能改变值
*/

int main(){
    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t=std::thread(&Vehicle::addID, v, 1);
    // wait for thread to finish
    t.join();
    // print Vehicle id
    v->printID();//1
}