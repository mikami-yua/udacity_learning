#include <iostream>
#include <string>
using std::string;
using std::cout;

class Car{
    public:
    void PrintCarData(){
        cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
    }

    void IncrementDistance(){
        distance++;
    }

    Car(string c,int n){
        color = c;
        number = n;
    }

    string color;
    int distance=0;
    int number;
};

int main(){
    Car car_1=Car("green",1);
    Car car_2 = Car("red", 2);
    Car car_3 = Car("blue", 3);

    car_1.IncrementDistance();

    // Print out the position and color of each car.
    car_1.PrintCarData();
    car_2.PrintCarData();
    car_3.PrintCarData();
}