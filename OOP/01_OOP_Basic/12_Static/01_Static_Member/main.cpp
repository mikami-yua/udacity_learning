#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>
using std::cout;

class Sphere
{
public:
  Sphere(int radius) : radius_(radius), volume_(pi_ * 4 / 3 * pow(radius_, 3))
  {
    if (radius <= 0)
      throw std::invalid_argument("radius must be positive");
  }

  int Radius() const { return radius_; }
  int Volume() const { return volume_; }

  // TODO: mutator
  void Radius(int radius)
  {
    if (radius <= 0)
      throw std::invalid_argument("radius must be positive");
    radius_ = radius;
    volume_ = pi_ * 4 / 3 * pow(radius_, 3);
  }

private:
  static float constexpr pi_{3.14159};
  int radius_;
  float volume_;
};

// Test
int main(void)
{
  Sphere sphere(5);
  cout<<sphere.Radius()<<"\n";
  cout<<sphere.Volume()<<"\n";
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);


  sphere.Radius(3);
  cout<<sphere.Radius()<<"\n";
  assert(sphere.Radius() == 3);
  cout<<sphere.Volume()<<"\n";
  assert(abs(sphere.Volume() - 113.1) < 1);
  
  bool caught{false};
  try
  {
    sphere.Radius(-1);
  }
  catch (...)
  {
    caught = true;
  }
  assert(caught);
}