#include <iostream>
using std::cout;
using std::string;

//define base class
class Animal{
public:
    string color;
    string name;
    int age;
};

//define class snake
class Snake: public Animal{
public:
    int length;
    void MakeSound(){
        cout << "Hiss...\n";
    }
};

class Cat: public Animal{
public:
    int height;
    void MakeSound(){
        cout << "Meow....\n";
    }
};

int main(){
    Snake snake;
    snake.name="brown";
    snake.length=10;
    snake.MakeSound();

    Cat cat;
    cat.name="ajk";
    cat.age=201;
    cat.height=5;
    cout << "My name is " << cat.name << " and Age is: " << cat.age << "\n";
    cat.MakeSound();
}