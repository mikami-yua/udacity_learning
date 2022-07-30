#include <cassert>
#include <stdexcept>
#include <string>

using std::string;

/*
向类中添加 3 个私有成员变量：
名字
年级（例如9年级）
平均绩点
编写公共构造函数以设置私有属性。
创建公共成员函数以设置每个成员变量。在设置值之前，请验证：
年级从0（幼儿园）到12
GPA从0.0到4.0
如果违反任何不变量，则该函数必须引发异常
在（类外部）中，声明一个对象类型并测试每个成员函数调用。
*/

class Student{
    public:
        Student(string name,int grade,float gpa);

        // accessors
        string Name() const{
            return name_;
        }
        int Grade() const
        {
            return grade_;
        }
        float GPA() const
        {
            return gpa_;
        }

        // mutators
        void Name(string name)
        {
            name_ = name;
            Validate();
        }
        void Grade(int grade)
        {
            grade_ = grade;
            Validate();
        }
        void GPA(float gpa)
        {
            gpa_ = gpa;
            Validate();
        }

    private:
        string name_;
        int grade_;
        float gpa_;
        void Validate()
        {
            if (Grade() < 0 || Grade() > 12 || GPA() < 0.0 || GPA() > 4.0)
                throw std::invalid_argument("argument out of bounds");
        }
};

Student::Student(string name,int grade,float gpa):
    name_(name),grade_(grade),gpa_(gpa)
{
    Validate();    
}

int main(){
    Student david("David Silver", 10, 4.0);
    assert(david.Name() == "David Silver");
    assert(david.Grade() == 10);
    assert(david.GPA() == 4.0);

    bool caught{false};
    try
    {
        david.Grade(20);
    }
    catch (...)
    {
        caught = true;
    }
    assert(caught);
}