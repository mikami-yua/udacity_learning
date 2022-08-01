#include <iostream>
#include <string>

using std::cout;
using std::string;

class Animal{
public:
    double age;
};

class Pet{
public:
    string name;
};

// Dog derives from *both* Animal and Pet
class Dog:public Animal,public Pet{
public:
    string breed;
};

class Cat : public Animal, public Pet
{
public:
    string color;
};

int main(){
    Cat cat;
    cat.color="black";
    cat.age=10;
    cat.name="Max";

    cout<<cat.color<<"\n";
    cout<<cat.age<<"\n";
    cout<<cat.name<<"\n";
}