#include <iostream>
#include <thread>

class Vehicle{
private:
    int _id;

public:
    Vehicle(){
        _id=0;
    }
    void addID(int id){
        _id=id;
        std::cout<<"add Vehicle ID=" << _id <<"\n";
        std::cout<<"address= " <<this<<"\n";
    }
    void printID(){
        std::cout<<"Vehicle ID=" << _id <<"\n";
    }
};

/*
使用类到成员函数调用线程时
    std::thread(&Vehicle::addID,v1,1)
    std::thread（&类：：方法，对象，参数1,。。。）

    当调用到对象不是引用时,并没有传入地址，而是copy，所以值不会带出
*/
int main(){
    Vehicle v1,v2;

    std::cout<<"address= " <<&v1<<"\n";
    std::cout<<"address= " <<&v2<<"\n";
    //call member function on object v1
    std::thread t1=
        std::thread(&Vehicle::addID,v1,1);
    std::thread t2 =
      std::thread(&Vehicle::addID, &v2, 2);  // call member function on object v2

    // wait for thread to finish
    t1.join();
    t2.join();

    // print Vehicle id
    v1.printID();
    v2.printID();
    /*
    add Vehicle ID=2
    add Vehicle ID=1
    Vehicle ID=0
    Vehicle ID=2
    */
    return 0;
}