#include <stdio.h>

void MyFunc()
{
    int k = 3;
    printf("3: %p \n", &k);//3: 0061FEEC
}

int main()
{
    int i = 1;
    printf("1: %p \n", &i);//1: 0061FF1C

    int j = 2;
    printf("2: %p \n", &j);//2: 0061FF18

    MyFunc();

    int l = 4;
    printf("4: %p \n", &l);//4: 0061FF14

    return 0;
}