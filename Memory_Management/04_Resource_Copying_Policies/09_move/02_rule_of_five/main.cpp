#include <stdlib.h>
#include <iostream>

using std::cout;
/*
为了支持移动语义，又增加了移动构造函数和移动赋值运算符，
*/
class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    //构造函数
    MyMovableClass(size_t size){
        _size=size;
        _data=new int[_size];
        cout<<"CREATING instance of MyMovableClass at " << this;
        cout<<" allocated with size = " << _size * sizeof(int) << " bytes"<<"\n"; 
    }

    //析构函数
    ~MyMovableClass(){
        delete[] _data;
        cout<<"DELETING instance of MyMovableClass at " << this<<"\n";
    }
    //重载赋值运算符
    MyMovableClass &operator=(const MyMovableClass &source){
        cout<<"ASSIGNING content of instance"<<&source<<" ";
        cout<<"to instance "<<this<<"\n";
        if (this==&source)
        {
            return *this;
        }
        delete[] _data;
        _data=new int[source._size];
        *_data=*source._data;
        _size = source._size;
        return *this;
    }

    //拷贝构造函数
    MyMovableClass(const MyMovableClass &source){
        _size=source._size;
        _data=new int[_size];
        *_data=*source._data;
        cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }
    //移动构造函数
    MyMovableClass(MyMovableClass &&source){
        cout<<"MOVING (c’tor) instance "<<&source;
        cout<<" to instance "<<this<<"\n";
        _data=source._data;
        _size=source._size;
        source._data=nullptr;
        source._size=0;
    }
    //移动赋值运算符
    MyMovableClass &operator=(MyMovableClass &&source){
        cout << "MOVING (assign) instance " << &source << " to instance " << this <<"\n";
        if (this==&source)
        {
            return *this;
        }
        delete[] _data;
        _data=source._data;
        _size=source._size;
        source._data = nullptr;
        source._size = 0;
        return *this;
    }
};

int main(){
    MyMovableClass obj1(100); // constructor
    //CREATING instance of MyMovableClass at 0x61ff08 allocated with size = 400 bytes

    obj1 = MyMovableClass(200); // move assignment operator
    /*
    CREATING instance of MyMovableClass at 0x61ff08 allocated with size = 800 bytes
    MOVING (assign) instance 0x61ff08 to instance 0x61ff00
    */

   MyMovableClass obj2 = MyMovableClass(300); // move constructor
}