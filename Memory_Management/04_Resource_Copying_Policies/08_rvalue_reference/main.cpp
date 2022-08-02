#include <iostream>

void myFunction(int &val)
{
    std::cout << "val = " << val << std::endl;
}

int main(){
    int j = 42;
    myFunction(j);

    // myFunction(42); //generate error

    //int k = 23;
    //myFunction(j + k);

    int i = 1; 
    int k = i + j; 
    int &&l = i + j;
    myFunction(k);
    myFunction(l);
    std::cout << "k = " << k << ", l = " << l << std::endl;
}