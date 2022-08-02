#include <iostream>
#include <stdlib.h>

using std::cout;

class MyClass{
private:
    double _mymember;
public:
    MyClass(){
        cout << "Constructor is called\n";
    }
    ~MyClass(){
        cout << "Destructor is called\n";
    }

    void *operator new[](size_t size){
        cout << "new: Allocating " << size << " bytes of memory" <<"\n";
        void *p=malloc(size);
        return p;
    }
    void operator delete[](void *p){
        cout << "delete: Memory is freed again " <<"\n";
        free(p);
    }
};

int main(){
    MyClass *p = new MyClass[3]();
    std::cout << "Addr1: " << p << "\n";
    std::cout << "Addr2: " << p + 1 << "\n";
    std::cout << "Addr2: " << p + 2 << "\n";
    std::cout << "Addr2: " << p + 5 << "\n";
    delete[] p;
    /*
    new: Allocating 32 bytes of memory
    Constructor is called
    Constructor is called
    Constructor is called
    Addr1: 0xf216d0
    Addr2: 0xf216d8
    Addr2: 0xf216e0
    Addr2: 0xf216f8
    Destructor is called
    Destructor is called
    Destructor is called
    delete: Memory is freed again
    */
}