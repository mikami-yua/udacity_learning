#include <iostream>

class MyInt
{
    int *_p; // pointer to heap data
public:
    MyInt(int *p = NULL) { _p = p; }
    ~MyInt()
    {
        std::cout << "resource " << *_p << " deallocated" << std::endl;
        delete _p;
    }
    int &operator*() { return *_p; } // // overload dereferencing operator
};

void allocate_on_stack(){
    double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    for (size_t i = 0; i < 5; ++i)
    {
        // allocate the resource on the stack
        MyInt en(new int(i));

        // use the resource
        std::cout << *en << "/" << den[i] << " = " << *en / den[i] << std::endl;
    }
}

void allocate_on_heap(){
    double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    for (size_t i = 0; i < 5; ++i)
    {
        // allocate the resource on the heap
        double *en = new double(i);

        // use the resource
        std::cout << *en << "/" << den[i] << " = " << *en / den[i] << std::endl;

        // deallocate the resource
        delete en;
    }
}

int main()
{
    allocate_on_stack();
    std::cout<<"-----------------------------"<<"\n";
    allocate_on_heap();
    return 0;
}