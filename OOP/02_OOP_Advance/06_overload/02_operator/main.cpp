#include <iostream>
using std::cout;

class Point{
public:
    Point(int a,int b):x(a),y(b){}
    Point(){}

    // TODO: Define + operator overload
    Point operator+(const Point a){
        Point c;
        c.x=a.x+x;
        c.y=a.y+y;
        return c;
    }

    int x;
    int y;

};

// Test in main()
int main()
{
    Point p1(10, 5), p2(2, 4);
    Point p3 = p1 + p2; // An example call to "operator +";
    cout<<p3.x<<"\n";
    cout<<p3.y<<"\n";

}
