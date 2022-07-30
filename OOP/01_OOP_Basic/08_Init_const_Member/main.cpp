#include <assert.h>
#include <string>
#include <iostream>
using std::string;
using std::cout;

class Person{
    public:
    Person(string n);
    string GetName(){
        return this->name; 
    }
    private:
    string const name;
};

Person::Person(string n): name(n){}

// Test
int main()
{
    Person alice("Alice");
    cout<<alice.GetName()<<"\n";
}