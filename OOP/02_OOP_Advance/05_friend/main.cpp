#include <iostream>
using std::cout;

// Declare class 长方形
class Rectangle;

// Define class Square as friend of Rectangle
class Square{
public:
    Square(int s):side_(s){}

private:
    // Add friend class Rectangle
    friend class Rectangle;
    // Add private attribute side
    int side_;

};

// Define class Rectangle

class Rectangle{
public:
    // Define a Rectangle constructor that takes a Square
    Rectangle(Square a):width_(a.side_),height_(a.side_){}

    int Area(){
        return width_ * height_;
    }
private:
    int width_;
    int height_;
};

/*
friend class
可以在构造函数中使用被被做计好的class中的私有成员
*/
int main()
{
    Square square(4);
    Rectangle rectangle(square);
    //assert(rectangle.Area() == 16);
    cout<<rectangle.Area()<<"\n";//16
}