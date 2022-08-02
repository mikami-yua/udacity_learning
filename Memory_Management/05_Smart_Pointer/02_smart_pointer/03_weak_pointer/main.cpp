#include <iostream>
#include <memory>

using std::cout;

void test1(){
    std::shared_ptr<int> mySharedPointer(new int);
    cout<<"shared pointer count ="<<mySharedPointer.use_count()<<"\n";

    std::weak_ptr<int> myWeakPointer1(mySharedPointer);
    std::weak_ptr<int> myWeakPointer2(mySharedPointer);
    cout<<"shared pointer count ="<<mySharedPointer.use_count()<<"\n";
    //std::weak_ptr<int> myWeakPtr3(new int);
}

int main(){

    std::shared_ptr<int> mySharedPointer(new int);
    cout<<"shared pointer count ="<<mySharedPointer.use_count()<<"\n";
    std::weak_ptr<int> myWeakPtr(mySharedPointer);
    if (myWeakPtr.expired() == true)
    {
        std::cout << "Weak pointer expired!" << std::endl;
    }
    mySharedPointer.reset(new int);
    //弱指针失效
    if (myWeakPtr.expired() == true)
    {
        std::cout << "Weak pointer expired!" << std::endl;
    }

}