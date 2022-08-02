#include <iostream>
using std::cout;

void AddFour(int &val)
{
    cout<<"&val: "<<&val<<"\n";//&val: 0x61ff0c
    val += 4;
}

int main()
{
    int val = 0;
    cout<<"&val: "<<&val<<"\n";//&val: 0x61ff0c
    AddFour(val);
    val += 2;

    std::cout << "val = " << val << std::endl;//6

    return 0;
}