/*
计算体积
定义一个名为 的类。Sphere
添加一个私有成员变量：radius
定义一个构造函数来初始化半径。
定义返回半径的访问器方法。
定义一个成员函数以返回球体的体积。
编写一个函数来初始化类型 为 的对象
*/
#include <cmath>
#include <stdexcept>
#include <iostream>
using std::cout;

class Sphere{
    public:
        Sphere(int r);

        //Accessors
        int GetRadius() const {
            return this->radius_;
        }
        float GetVolume() const{
            return this->volume_;
        }

    private:
        int radius_;
        float volume_;
        float const pi_=3.1415926; 
        void Vaild();
};

void Sphere::Vaild(){
    if(radius_<0){
            throw std::invalid_argument("radius must be positive");
        }
}

Sphere::Sphere(int r): radius_(r){
    Vaild();
    volume_=pi_ * 4 / 3 * pow(radius_, 3);
}

int main(){
    Sphere sphere1(5);
    cout<<sphere1.GetVolume()<<"\n";
    Sphere sphere2(-2);
    cout<<sphere1.GetVolume()<<"\n";
}