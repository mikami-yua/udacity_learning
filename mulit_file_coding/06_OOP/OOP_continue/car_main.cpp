#include <iostream>
#include <string>
#include "car.h"
using std::string;
using std::cout;
#include <vector>
using std::vector;

void Putting_Class_Definitions_into_Separate_Files(){
    // Create class instances for each car.
    Car car_1 = Car("green", 1);
    Car car_2 = Car("red", 2);
    Car car_3 = Car("blue", 3);

    // Increment car_1's position by 1.
    car_1.IncrementDistance();

    // Print out the position and color of each car.
    car_1.PrintCarData();
    car_2.PrintCarData();
    car_3.PrintCarData();
}

void scall_up_to_see_the_good_OOP(){
    //创建一个指向cars vector的指针
    // and a null pointer to a car.
    vector<Car*> car_vector;
    Car* cp=nullptr;

    // The vector of colors for the cars:
    vector<string> colors {"red", "blue", "green"};

    //创建100个car，并赋予不同的颜色
    //并将指向这100个car的指针都放在vector中
    for(int i=0;i<100;i++){
        cp=new Car(colors[i%3],i+1);
        car_vector.push_back(cp);
    }

    // Move each car forward by 1.
    for(Car* cp:car_vector){
        cp->IncrementDistance();
    }

    // Print data about each car.
    for (Car* cp: car_vector) {
        cp->PrintCarData();
    }


}

int main()
{
    Putting_Class_Definitions_into_Separate_Files();
    scall_up_to_see_the_good_OOP();
}