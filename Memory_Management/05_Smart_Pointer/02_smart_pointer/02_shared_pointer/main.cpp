#include <iostream>
#include <memory>

using std::cout;

void use_count(){
    std::shared_ptr<int> shared1(new int);
    cout<<"shared pointer count= "<<shared1.use_count()<<"\n";//1
    {
        std::shared_ptr<int> shared2 = shared1;
        cout << "shared pointer count = " << shared1.use_count() <<"\n";//2
    }
    std::cout << "shared pointer count = " << shared1.use_count() << "\n";//1
}




class MyClass{
public:
    std::shared_ptr<MyClass> _member;
    ~MyClass() { 
        cout << "Destructor of MyClass called" << "\n";
    }
};


void reset_func(){
    std::shared_ptr<MyClass> shared(new MyClass);
    cout<<"shared pointer count = "<<shared.use_count()<<"\n";//1
    std::shared_ptr<MyClass> shared2=shared;
    cout<<"shared pointer count = "<<shared.use_count()<<"\n";//2
    shared.reset(new MyClass);
    cout<<"shared pointer count = "<<shared.use_count()<<"\n";//1
}

int main(){
    std::shared_ptr<MyClass> myClass1(new MyClass);
    std::shared_ptr<MyClass> myClass2(new MyClass);
}