#include <iostream>
#include <string>

using std::cout;
using std::string;

class Water{};
class Alcohol{};
class Coffee{};

class Human{
public:
    string condition="happy";
    string Drink(Water water){
        return "I drank water";
    }
    string Drink(Alcohol alcohol){
        return "I drank alcohol";
    }
    string Drink(Coffee coffee){
        return "I drank coffee";
    }
};

int main(){
    Human david;
    cout<<david.Drink(Water())<<"\n";
    cout<<david.Drink(Alcohol())<<"\n";
    cout<<david.Drink(Coffee())<<"\n";
}