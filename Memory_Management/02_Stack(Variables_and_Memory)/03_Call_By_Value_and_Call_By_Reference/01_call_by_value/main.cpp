#include <iostream>
using std::cout;

bool MyLocalFunction(int myInt)
{
    cout<<"myInt: "<<&myInt<<"\n";//myInt: 0x61fef0    
    bool isBelowThreshold = myInt < 42 ? true : false;
    cout<<"isBelowThreshold: "<<&isBelowThreshold<<"\n";//isBelowThreshold: 0x61fedf
    return isBelowThreshold;
}

int main()
{
    int var=23;
    cout<<"var: "<<&var<<"\n"; //var: 0x61ff0c
    bool res = MyLocalFunction(var);
    cout<<"res: "<<&res<<"\n";//res: 0x61ff0b
    return 0;
}