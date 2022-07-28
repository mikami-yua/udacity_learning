#include <iostream>
#include <string>
using std::cout;
using std::string;

int MultiplyByTwo_passbyvalue(int i) {
    i = 2*i;
    return i;
}

int MultiplyByTwo_passbyreference(int &i) {
    i = 2*i;
    return i;
}

int MultiplyByTwo_passpointer(int *i) {
    *i = 2*(*i);
    return *i;
}

void DoubleString(string &value) {
    // Concatentate the string with a space and itself.
    value = value + " " + value;
}

int main() {
    //Passing Values
    int a = 5;
    cout << "The int a equals: " << a << "\n";//5
    int b = MultiplyByTwo_passbyvalue(a);
    cout << "The int b equals: " << b << "\n";//10
    cout << "The int a still equals: " << a << "\n";//5

    //Passing ref
    int c = 5;
    cout << "The int c equals: " << c << "\n";//5
    int d = MultiplyByTwo_passbyreference(c);
    cout << "The int d equals: " << d << "\n";//10
    cout << "The int c equals: " << c << "\n";//10
    //pass pointer in C code
    int e = 5;
    cout << "The int e equals: " << e << "\n";//5
    int f = MultiplyByTwo_passpointer(&e);
    cout << "The int f equals: " << f << "\n";//10
    cout << "The int e equals: " << e << "\n";//10


    //Passing ref
    string s = "Hello";
    cout << "The string s is: " << s << "\n";//Hello
    DoubleString(s);
    cout << "The string s is now: " << s << "\n";//Hello Hello
}
