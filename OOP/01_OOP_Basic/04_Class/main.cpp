#include <iostream>
using std::cout;

class Date{
public:
    int Day(){return this->day;}
    void SetDay(int d){
        if (d>0 && d<32)
        {
            this->day=d;
        }
    }

    int Month(){return this->month;}
    void SetMonth(int m){
        if (m>0 && m<13)
        {
            this->month=m;
        }
        
    }

    int Year() { return this->year; }
    void SetYear(int y)
    {
        if (y > 0)
            this->year = y;
    }

private:
    int day{1};
    int month{1};
    int year{0};
};

int main(){
    Date data;
    data.SetDay(-1);
    data.SetMonth(11);
    data.SetYear(1997);
    cout<<data.Day()<<"/"<<data.Month()<<"/"<<data.Year()<<"\n";
}