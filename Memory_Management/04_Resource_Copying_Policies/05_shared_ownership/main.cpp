#include <iostream>

using std::cout;

class SharedCopy{
private:
    int *_myInt;
    static int _count;

public:
    SharedCopy(int val);
    ~SharedCopy();
    SharedCopy(SharedCopy &source);
};

int SharedCopy::_count = 0;

SharedCopy::SharedCopy(int val){
    _myInt=(int *)malloc(sizeof(int));
    *_myInt=val;
    _count++;
    cout << "resource allocated at address " << _myInt <<"\n";
}

SharedCopy::~SharedCopy(){
    _count--;
    if (_count==0)
    {
        free(_myInt);
        cout << "resource freed at address " << _myInt <<"\n";
    }else{
        cout << "instance at address " << this << " goes out of scope with _count = " << _count << std::endl;
    }
    
}

SharedCopy::SharedCopy(SharedCopy &source)
{
    _myInt = source._myInt;
    ++_count;
    std::cout << _count << " instances with handles to address " << _myInt << " with _myInt = " << *_myInt << std::endl;
}

int main()
{
    SharedCopy source(42);
    SharedCopy destination1(source);
    SharedCopy destination2(source);
    SharedCopy destination3(source);

    /*
    resource allocated at address 0xf91a48
    2 instances with handles to address 0xf91a48 with _myInt = 42
    3 instances with handles to address 0xf91a48 with _myInt = 42
    4 instances with handles to address 0xf91a48 with _myInt = 42
    instance at address 0x61ff00 goes out of scope with _count = 3
    instance at address 0x61ff04 goes out of scope with _count = 2
    instance at address 0x61ff08 goes out of scope with _count = 1
    resource freed at address 0xf91a48
    */
    return 0;
}