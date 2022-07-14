#include <iostream>
#include <string>
#include <vector>

int main(){
    std::vector<std::string> brothers{"David","Ethan","Adam"};
    for (std::string const& brother : brothers)
    {
        std::cout<<"Hello "<<brother<<"!\n";
    }

    int a,b,sum;

    a=2;
    b=3;
    sum=a+b;
    
    std::cout<<sum<<std::endl;

    return 0; 
}
