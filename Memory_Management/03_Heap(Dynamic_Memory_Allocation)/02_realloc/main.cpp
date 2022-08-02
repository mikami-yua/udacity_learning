#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;

int main(){
    //为指针定义两个int类型的内存空间
    int *p=(int *)malloc(2*sizeof(int));
    p[0]=1;
    p[1]=2;
    cout<<"address= "<<p+0<<"; value= "<<*(p+0)<<"\n";//address= 0xf31a40; value= 1
    cout<<"address= "<<p+1<<"; value= "<<*(p+1)<<"\n";//ddress= 0xf31a44; value= 2
    cout<<"address= "<<p+2<<"; value= "<<*(p+2)<<"\n";//address= 0xf31a48; value= 1293552833
    cout<<"address= "<<p+3<<"; value= "<<*(p+3)<<"\n";//address= 0xf31a4c; value= 21489

    //为指针重新预留四个int类型的空间
    p=(int *)realloc(p, 4*sizeof(int));
    p[2]=3;
    p[3]=4;
    cout<<"address= "<<p+0<<"; value= "<<*(p+0)<<"\n";//address= 0xf51a40; value= 1
    cout<<"address= "<<p+1<<"; value= "<<*(p+1)<<"\n";//address= 0xf51a44; value= 2
    cout<<"address= "<<p+2<<"; value= "<<*(p+2)<<"\n";//address= 0xf51a48; value= 3
    cout<<"address= "<<p+3<<"; value= "<<*(p+3)<<"\n";//address= 0xf51a4c; value= 4

    //重新将p指向的内存空间定义为只有两个int大小
    p=(int *)realloc(p,2*sizeof(int));

    cout<<"address= "<<p+0<<"; value= "<<*(p+0)<<"\n";//address= 0xf51a40; value= 1
    cout<<"address= "<<p+1<<"; value= "<<*(p+1)<<"\n";//address= 0xf51a44; value= 2
    cout<<"address= "<<p+2<<"; value= "<<*(p+2)<<"\n";//address= 0xf51a48; value= -1864735509
    cout<<"address= "<<p+3<<"; value= "<<*(p+3)<<"\n";//address= 0xf51a4c; value= 13704

}