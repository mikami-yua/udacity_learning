#include <iostream>
using std::cout;

void AddThree(int *val)
{
    cout<<"*val: "<<val<<"\n";//*val: 0x61ff0c
    *val += 3;
}

int main()
{
    int val = 0;
    cout<<"&val: "<<&val<<"\n";//&val: 0x61ff0c
    AddThree(&val);
    val += 2;

    std::cout << "val = " << val << std::endl;//5

    return 0;
}