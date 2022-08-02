#include <iostream>

using std::cout;

class ExclusiveCopy{
private:
    int *_myInt;

public:
    ExclusiveCopy(){
        _myInt=(int *)malloc(sizeof(int));
        cout<<"resource allocated"<<"\n";
    }
    ~ExclusiveCopy(){
        if (_myInt != nullptr)
        {
            free(_myInt);
            cout << "resource freed" << std::endl;
        }
    }
    ExclusiveCopy(ExclusiveCopy &source){
        _myInt=source._myInt;
        source._myInt=nullptr;
    }
    ExclusiveCopy &operator=(ExclusiveCopy &source){
        _myInt = source._myInt;
        source._myInt = nullptr;
        return *this;
    }
    void printOwnAddress() { 
        cout << "Own address on the stack is " << this << std::endl; 
    }
    void printMemberAddress() { 
        cout << "Managing memory block on the heap at " << _myInt << std::endl;
    }

};

int main()
{
    ExclusiveCopy source;
    source.printOwnAddress();//Own address on the stack is 0x61ff0c
    source.printMemberAddress();//Managing memory block on the heap at 0x1041a48
    ExclusiveCopy destination(source);
    destination.printOwnAddress();//Own address on the stack is 0x61ff08
    destination.printMemberAddress();//Managing memory block on the heap at 0x1041a48

    return 0;
}