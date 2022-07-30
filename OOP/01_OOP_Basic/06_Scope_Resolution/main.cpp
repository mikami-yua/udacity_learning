#include <cassert>
#include <iostream>

class Date
{
public:
    int Day() const { return day; }
    void Day(int day);
    int Month() const { return month; }
    void Month(int month);
    int Year() const { return year; }
    void Year(int year);

private:
    int day{1};
    int month{1};
    int year{0};
};

//在class外定义函数体
void Date::Day(int d){
    this->day=d;
}

void Date::Month(int m){
    this->month=m;
}

void Date::Year(int y){
    this->year=y;
}

//命名空间
//允许程序员将逻辑上相关的变量和函数组合在一起。
//命名空间还有助于避免与在程序的不同部分中具有相同名称的变量之间的冲突
namespace English {
void Hello() { std::cout << "Hello, World!\n"; }
}  // namespace English

namespace Spanish {
void Hello() { std::cout << "Hola, Mundo!\n"; }
}  // namespace Spanish


// Test in main
int main()
{
    Date date;
    date.Day(29);
    date.Month(8);
    date.Year(1981);
    assert(date.Day() == 29);
    assert(date.Month() == 8);
    assert(date.Year() == 1981);

    English::Hello();
    Spanish::Hello();
}