#include <iostream>
using std::cout;

//范围内枚举
void scoped_enum(){
    // Create the enum Color with fixed values.
    // scoped enum
    enum class Color { white,
                        black,
                        blue,
                        red};

    // Create a Color variable and set it to Color::blue.
    Color my_color;
    //assign
    my_color=Color::blue;

    // Test to see if my car is red.
    if (my_color==Color::red)
    {
        cout << "The color of my car is red!" << "\n";
    } else {
        cout << "The color of my car is not red." << "\n";
    }
}

void unscoped_enum(){
    enum Color {  white =0,
                  black,
                  blue,
                  red};

    Color my_color=blue;
    cout<<my_color<<"\n";//2
    // Test to see if my car is red.
    if (my_color == red) {
        cout << "The color of my car is red!" << "\n";
    } else {
        cout << "The color of my car is not red." << "\n";
    }    
}

void enum_switch(){
    enum class keypad {up, down, left, right};
    keypad input;
    input=keypad::down;
    switch (input)
    {
        case keypad::up:
            cout<<"up"<<"\n";
            break;
        case keypad::down:
            cout<<"down"<<"\n";
            break;
        case keypad::left:
            cout<<"left"<<"\n";
            break;
        case keypad::right:
            cout<<"right"<<"\n";
            break;
        default:
            break;
    }
}

int main()
{
    scoped_enum();
    unscoped_enum();
    enum_switch();
}