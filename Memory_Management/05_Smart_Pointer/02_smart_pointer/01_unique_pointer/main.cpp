#include <iostream>
#include <memory>
#include <string>

using std::string;
using std::cout;

//原始指针
void RawPointer(){
    int *raw_pointer=new int;// create a raw pointer on the heap
    *raw_pointer=1;//assign a value
    cout<<"memory locate: "<<raw_pointer<<"\n";
    cout<<"value: "<<*raw_pointer<<"\n";
    delete raw_pointer;
}

//智能指针
void UniquePointer(){
    std::unique_ptr<int> unique(new int);
    // create a raw pointer on the heap
    *unique=2;//assign a value
    cout<<"memory locate: "<<unique.get()<<"\n";
    cout<<"value: "<<*unique<<"\n";
    // delete is not neccessary
}

class MyClass{
private:
    string _text;

public:
    MyClass(){};
    MyClass(string s):_text(s){};
    ~MyClass(){
        cout << _text << " destroyed"<<"\n";
    }
    void SetText(string s){
        _text=s;
    }
    void GetText(){
        cout<<_text<<"\n";
    }
};




int main(){
    RawPointer();
    UniquePointer();
    /*
    memory locate: 0xf11508
    value: 1
    value: 2
    */

    // create unique pointer to proprietary class
    std::unique_ptr<MyClass> myClass1(new MyClass());
    std::unique_ptr<MyClass> myClass2(new MyClass("string 2"));

    myClass1->GetText();//""
    myClass2->GetText();//string 2

    // call member function using ->
    myClass1->SetText("string 1");

    myClass1->GetText();//string 1
    myClass2->GetText();//string 2

    //使用解引用操作符
    *myClass1=*myClass2;

    myClass1->GetText();//string 2
    myClass2->GetText();//string 2

    //使用get函数检索指向对象的原始指针
    cout<<"Object have stack addr "<<myClass1.get()<<"\n";//Object have stack addr 0xf91508
    cout<<"Object have stack addr "<<myClass2.get()<<"\n";//Object have stack addr 0xf91528

}