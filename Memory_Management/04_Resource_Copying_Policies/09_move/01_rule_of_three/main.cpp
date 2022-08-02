#include <stdlib.h>
#include <iostream>

using std::cout;

/*
class有指针的情况下一定需要析构函数
如果需要析构函数，则一定需要拷贝构造函数和重载赋值操作符
*/
class MyMoveableClass{
private:
    int _size;
    int *_data;

public:
    //构造函数
    MyMoveableClass(size_t size){
        _size=size;
        _data=new int[_size];
        cout<<"CREATING instance of MyMovableClass at"<<this<<"\n";
        cout<<"allocated with size = "<<_size*sizeof(int)<<" bytes"<<"\n";
    }

    //析构函数
    ~MyMoveableClass(){
        delete[] _data;
        cout<<"DELETED instance of MyMovableClass at"<<this<<"\n";
    }
    //重载赋值运算符
    MyMoveableClass &operator=(const MyMoveableClass &source){
        cout<<"ASSIGNING content of instance"<<&source<<" ";
        cout<<"to instance "<<this<<"\n";
        if (this==&source)
        {
            return *this;
        }
        delete[] _data;
        _data=new int[source._size];
        //*_data=*source._data;
        _size = source._size;
        return *this;
    }

    //拷贝构造函数
    MyMoveableClass(const MyMoveableClass &source){
        _size=source._size;
        _data=new int[_size];
        // *_data=*source._data;
        cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }

};

int main()
{
    MyMoveableClass obj1(10);   // regular constructor
    /*
    调用构造函数
        CREATING instance of MyMovableClass at0x61ff08
        allocated with size = 40 bytes
    */
    MyMoveableClass obj2(obj1); // copy constructor
    /*
    调用拷贝构造函数
        COPYING content of instance 0x61ff08 to instance 0x61ff00
    */
    obj2 = obj1;               // copy assignment operator
    /*
    调用赋值运算符
        ASSIGNING content of instance0x61ff08 to instance 0x61ff00
    */

    return 0;
}