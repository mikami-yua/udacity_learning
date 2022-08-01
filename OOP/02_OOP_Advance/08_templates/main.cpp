#include <iostream>
using std::cout;

template <typename T>
T Max(T a,T b){
    return a>b?a:b;
}

int main(){
    cout<<Max(1,2)<<"\n";
    cout<<Max('a','b')<<"\n";
    cout<<Max(1.11,2.34)<<"\n";
}