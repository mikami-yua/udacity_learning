#include <stdlib.h>
#include <iostream>

using std::cout;

class MyClass{
private:
    int *_number;

public:
    MyClass(){
        _number=(int *)malloc(sizeof(int));
        cout<<"Allocated memory"<<"\n";
    }
    ~MyClass(){
        free(_number);
        cout<<"Delete memory\n";
    }
    void SetNumber(int number){
        *_number=number;
        cout << "Number: " << *_number << "\n";
    }
};

int main(){
    //allocate memory using malloc
    MyClass *myClass=(MyClass *)malloc(sizeof(MyClass));
    myClass->SetNumber(42);
    cout << "Size of a class: " << sizeof(myClass) << "\n";//4
    cout << "Size of a class: " << sizeof(int) << "\n";//4
    free(myClass);

    // allocate memory using new
    MyClass *myClass2=new MyClass();
    myClass2->SetNumber(52);
    cout << "Size of a class: " << sizeof(myClass2) << "\n";//4
    cout << "Size of a class: " << sizeof(int) << "\n";//4
    delete myClass2;
}