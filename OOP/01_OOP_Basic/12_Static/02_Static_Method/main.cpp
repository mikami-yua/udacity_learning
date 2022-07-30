#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>
using std::cout;

class Sphere
{
public:
    static float Volume(int radius){
        return pi_ * 4 / 3 * pow(radius, 3);
    }

private:
    static float constexpr pi_{3.14159};
};

// Test
int main(void)
{
    cout<<Sphere::Volume(5)<<"\n";
    assert(abs(Sphere::Volume(5) - 523.6) < 1);
}