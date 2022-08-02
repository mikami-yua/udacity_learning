#include <iostream>
#include <memory>

class MyClass
{
private:
    int _member;

public:
    MyClass(int val) : _member(val) {}
    void printVal() { 
        std::cout << ", managed object " << this 
        << " with val = " << _member << std::endl; 
    }
};

void f(std::unique_ptr<MyClass> ptr){
    std::cout<<"unique_ptr"<<"\n";
    ptr->printVal();
}

int main(){
    std::unique_ptr<MyClass> uniquePtr=std::make_unique<MyClass>(23);
    std::cout << "unique_ptr " << &uniquePtr<<"\n";//unique_ptr 0x61ff04
    uniquePtr->printVal();//, managed object 0xe217d0 with val = 23
    f(std::move(uniquePtr));
    //unique_ptr
    //, managed object 0xe217d0 with val = 23

    if (uniquePtr)
        uniquePtr->printVal();//以这种方式传递对象后，调用方将具有无效的unique_ptr
}