#include <cassert>
#include <stdexcept>
#include <iostream>

class Pyramid{
    public:
        Pyramid(int length,int width,int height);
        int Length() const {return length_;}
        int Width() const { return width_; }
        int Height() const { return height_; }

        // mutators
        void Length(int l);
        void Width(int w);
        void Height(int h);

    private:
        int length_;
        int width_;
        int height_;

        void Validate(){
            if (length_ < 0 || width_ < 0 || height_ < 0)
            {
                throw std::invalid_argument("negative values");
            }
        }
};

//构造函数，在对值进行初始化之后判断是否是合法的值
Pyramid::Pyramid(int length,int width,int height):
    length_(length),width_(width),height_(height){
        Validate();
}

void Pyramid::Length(int l)
{
    if (l > 0)
    {
        length_ = l;
    }
}

void Pyramid::Width(int w)
{
    if (w > 0)
    {
        width_ = w;
    }
}

void Pyramid::Height(int h)
{
    if (h > 0)
    {
        height_ = h;
    }
}

int main(){
    Pyramid pyramid(1,2,3);
    assert(pyramid.Length()==1);
    assert(pyramid.Length()==2);
    assert(pyramid.Length()==3);

    bool caught{false};
    try
    {
        Pyramid invalid(-1, 2, 3);
    }
    catch (...)
    {
        std::cout << "Entered negative values"
                  << "\n";
        caught = true;
    }
    assert(caught);
}