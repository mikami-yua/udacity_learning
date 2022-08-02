#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;

int main()
{
    int* p=(int *)malloc(sizeof(int));
    cout<<"address= "<<p<<"; value= "<<*p<<"\n";

    int* p2=(int *)malloc(3*sizeof(int));
    cout<<"address= "<<p2<<"; value= "<<*p2<<"\n";
}