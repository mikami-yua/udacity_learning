#include <iostream>

using std::cout;

void myFunction(int &val)
{
    ++val;
}

int main(){
    int i = 1;
    int &j = i;//int &j 中的int &相当于起别名
    cout<<&j<<"\n";//0x61ff08
    cout<<j<<"\n";//1
    i++;
    cout<<j<<"\n";//2
    j++;
    cout<<i<<"\n";//3
    delete &j;
    cout<<"i= "<<i<<"; j= "<<j<<"\n";//3 3

    int a=1;
    myFunction(a);
    cout << "a = " << a <<"\n";//2
}
