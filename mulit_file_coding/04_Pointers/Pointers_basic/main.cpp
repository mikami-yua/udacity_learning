#include <iostream>
using std::cout;

void Accessing_Memory_Address(){
    cout<<__func__<<"\n";
    int i=5;
    int j=6;

    // Print the memory addresses of i and j
    cout << "The address of i is: " << &i << "\n";
    cout << "The address of j is: " << &j << "\n";
}

void Storing_Memory_Address_int(){
    cout<<__func__<<"\n";

    int i=5;
    //定义一个指向i的指针，并初始化指针的地址为i
    int* pointer_to_i= &i;

    // Print the memory addresses of i and j
    cout << "The address of i is:          " << &i << "\n";
    cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
    cout << "The address of variable pointer_to_i is: " << &pointer_to_i << "\n";

    //从指针地址获得对象的方法：解引用（de-reference）
    cout << "The value of variable pointer_to_i is: " << *pointer_to_i << "\n";
}

void change_value_by_pointer(){
    int i = 5;
    // A pointer pointer_to_i is declared and initialized to the address of i.
    int* pointer_to_i = &i;

    // Print the memory addresses of i and j
    cout << "The address of i is:          " << &i << "\n";
    cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";

    // The value of i is changed.
    *pointer_to_i = 7;
    cout << "The new value of the variable i is                     : " << i << "\n";
    cout << "The value of the variable pointed to by pointer_to_i is: " << *pointer_to_i << "\n";
}


int main(){
    Accessing_Memory_Address();
    Storing_Memory_Address_int();
    change_value_by_pointer();
}