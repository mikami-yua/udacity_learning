#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;

int main(){
    void *p=malloc(100);
    cout<<"address= "<<p<<"\n";
    free(p);
    cout<<"address= "<<p<<"\n";
    return 0;
}