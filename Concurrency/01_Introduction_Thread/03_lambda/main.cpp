#include <iostream>

using std::cout;
/*
lamdba当需要在调用时输入参数到时候，在（）中写参数
当不需要在调用时输入参数的时候，在[]中写参数
*/
int main(){
    int id=0;//定义整数类型

    //通过引用捕获(不可变):传送给lambda的内容不会被lamdba改变
    auto f0=[&id](){
        cout<<"a) ID in Lambda= "<<id<<"\n";
    };
    f0();//a) ID in Lambda= 0

    //通过值捕获（可变）
    auto f1=[id]() mutable {
        cout<<"b) ID in Lambda= "<<++id<<"\n";
    };
    //写在[id]里并且mutable表示id可以被lambda改变，但是不会影响lamdba之外到id数值（类似函数的形参）
    //调用并在lambda中执行代码
    f1();//b) ID in Lambda= 1
    cout<<"c) ID in main= "<<id<<"\n";//c) ID in main= 0

    //通过引用捕获（可变）
    auto f2=[&id]() mutable{
        cout<<"d) ID in Lambda= "<<++id<<"\n";
    };
    f2();//d) ID in Lambda= 1
    //写在[&id]里并且mutable表示id可以被lambda改变，由于传递的是引用会影响lamdba之外到id数值
    cout<<"e) ID in main= "<<id<<"\n";//e) ID in main= 1
    

    //传递参数
    auto f3=[](const int id){
        cout<<"f) ID in Lambda= "<<id<<"\n";
    };
    //lambda函数可以在这种格式下使用参数
    f3(++id);//f) ID in Lambda= 2

    f0();//a) ID in Lambda= 2

    return 0;
}