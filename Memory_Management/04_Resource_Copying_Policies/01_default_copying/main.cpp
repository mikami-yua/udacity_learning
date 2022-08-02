#include <iostream>

using std::cout;

class MyClass
{
private:
    int *_myInt;

public:
    MyClass()
    {
        _myInt = (int *)malloc(sizeof(int));
    };
    ~MyClass()
    {
        free(_myInt);
    };
    void printOwnAddress() { 
        cout << "Own address on the stack is " << this << std::endl; 
    }
    void printMemberAddress() { 
        cout << "Managing memory block on the heap at " << _myInt << std::endl;
    }
};

int main(){
    // instantiate object 1
    MyClass myclass1;
    myclass1.printOwnAddress();//pointer myclass1：on the stack is 0x61ff1c
    myclass1.printMemberAddress();//memory block on the heap at 0xfc1a40

    // copy object 1 into object 2
    MyClass myclass2(myclass1);
    myclass2.printOwnAddress();//pointer myclass2：on the stack is 0x61ff18
    myclass2.printMemberAddress();//memory block on the heap at 0xfc1a40
    return 0;
}