#include <iostream>
using std::cout;

int main(){
    int i=1;

    // Declare a reference to i.
    int& j=i;

    //check address
    cout << "i address: " << &i <<",j address: "<< &j<<"\n";
    //i address: 0x61ff08,j address: 0x61ff08

    cout << "The value of j is: " << j << "\n";

    // Change the value of i.
    i = 5;
    cout << "The value of i is changed to: " << i << "\n";
    cout << "The value of j is now: " << j << "\n";

    // Change the value of the reference.
    j = 7;
    cout << "The value of j is now: " << j << "\n";
    cout << "The value of i is changed to: " << i << "\n";
}