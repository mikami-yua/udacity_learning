#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void pointers_to_objects(){
    cout<< __func__ <<"\n";
    vector<int> v {1, 2, 3};

    // Declare and initialize a pointer to the address of v here:
    vector<int> *pointer_to_v=&v;

    for (int a: v) {
        cout << a << "\n";
    }

    //使用解引用的指针
    for(int i=0;i<v.size();i++){
        cout<<(*pointer_to_v)[i]<<"\n";
    }
    cout << "The first element of v is: " << (*pointer_to_v)[0] << "\n";
}

void AddOne(int* j)
{
    // Dereference the pointer and increment the int being pointed to.
    (*j)++;
}

void Passing_Pointers_to_Function(){
    cout<< __func__ <<"\n";

    int i = 1;
    cout << "The value of i is: " << i << "\n";

    // Declare a pointer to i:
    int* pi = &i;
    AddOne(pi);
    cout << "The value of i is now: " << i << "\n";

}

//pass reference , name is j
int* AddOne(int& j)
{
    // Increment the referenced int and return the
    // address of j.
    j++;
    cout << "The address of j is: " << &j << "\n";//0x61ff0c

    return &j;
}

void Returning_Pointer_from_Function(){
    cout<< __func__ <<"\n";

    int i = 1;
    cout << "The value of i is: " << i << "\n";//1

    // Declare a pointer and initialize to the value
    // returned by AddOne:

    int* my_pointer = AddOne(i);
    cout << "The value of i is now: " << i << "\n";//2
    cout << "The value of the int pointed to by my_pointer is: " << *my_pointer << "\n";//2
    //check addr
    cout << "The address of i is: " << &i << "\n";//0x61ff0c
    cout << "The value of my_pointer is: " << my_pointer << "\n";//0x61ff0c
    // my_pointer has its own addr
    cout << "The addr of my_pointer is: " << &my_pointer << "\n";//0x61ff08

}

int main(){
    //pointers_to_objects();
    //Passing_Pointers_to_Function();
    Returning_Pointer_from_Function();
}
