#include <cmath>
#include <iostream>

using std::cout;

#define PI 3.1415926

// TODO: Define the abstract class Shape
class Shape{
public:
    // TODO: Define public virtual functions Area() and Perimeter()
    // TODO: Append the declarations with = 0 to specify pure virtual functions
    virtual double Area() const =0;
    virtual double Perimeter() const =0;
};

// TODO: Define Rectangle to inherit publicly from Shape
class Rectangle: public Shape{
public:
    // TODO: Declare public constructor
    Rectangle(int w,int h):width_(w),height_(h){}
    // TODO: Override virtual base class functions Area() and Perimeter()
    double Area() const{
        return width_ * height_ ;
    }
    double Perimeter() const{
        return width_ * 2 + height_ * 2;
    }
private:
    // TODO: Declare private attributes width and height
    int width_;
    int height_;
};

// TODO: Define Circle to inherit from Shape
class Circle:public Shape{
public:
    Circle(double r):radius_(r){}
    double Area() const{
        return PI * radius_ * radius_;
    }
    double Perimeter() const{
        return 2 * PI * radius_;
    }
private:
    double radius_;
};

int main(){
    Circle circle(12.13);
    cout<<circle.Perimeter()<<"\n";
    cout<<circle.Area()<<"\n";

    Rectangle rectangle(10,6);
    cout<<rectangle.Perimeter()<<"\n";
    cout<<rectangle.Area()<<"\n";
}