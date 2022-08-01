// Example solution for Circle class
#include <iostream>
#include <cmath>
using std::cout;

#define PI 3.1415926;

// Define 线段 struct
struct LineSegment
{
public:
    double length;
};

class Circle{
public:
    Circle(LineSegment &radius);
    double Area();
private:
    LineSegment &radius_;
};

Circle::Circle(LineSegment &radius) : radius_(radius){}

double Circle::Area(){
    return pow(Circle::radius_.length, 2) * PI;
}

int main(){
    LineSegment radius{3};
    Circle circle(radius);
    cout<<circle.Area()<<"\n";
}