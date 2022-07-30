#include <assert.h>
#include <string>

// TODO: Define class Person
// TODO: Define a public constructor with an initialization list
// TODO: Define a public member variable: name

class Person
{
public:
    std::string name;
    int age;
    Person(std::string n,int a) : name(n),age(a) {}
};

// Test
int main()
{
    Person alice("Alice",10);
    Person bob("Bob",11);
    assert(alice.name != bob.name);
}