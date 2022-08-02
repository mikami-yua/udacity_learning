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

    void *operator new(size_t size){
        cout << "new: Allocating " << size << " bytes of memory" <<"\n";
        void *p=malloc(size);
        return p;
    }
    void operator delete(void *p){
        cout << "delete: Memory is freed again " <<"\n";
        free(p);
    }
};

int main(){
    MyClass *c=new MyClass();
    cout << "Size of a class: " << sizeof(c) << "\n";//4
    cout << "Size of a class: " << sizeof(double) << "\n";//8
    delete c;//delete: Memory is freed again
    /*
    new: Allocating 8 bytes of memory
    Constructor is called
    Size of a class: 4
    Size of a class: 8
    Destructor is called
    delete: Memory is freed again
    */
}