#include <iostream>
#include <string>
using namespace std;

struct student {
    string name;
    int age;
    float gpa;
};

struct teacher {
    string name;
    int age;
    struct student stu; // 结构体嵌套结构体
};

void print_student1(struct student stu)
{
    cout << "Name: " << stu.name << endl;
    cout << "Age: " << stu.age << endl;
    cout << "GPA: " << stu.gpa << endl;
}

// 结构体指针作为函数参数,可以减少内存空间，提高效率
// 如果下列结构体定义形参改为void print_student2(const struct student * stu)
// 则不能修改结构体变量的值，因为结构体指针是const修饰的，即常量指针，不能修改指向的结构体变量的值
void print_student2(struct student * stu)
{
    stu->name = "Alice";
    stu->age = 18;
    stu->gpa = 3.6;
    cout << "Name: " << stu->name << endl;
    cout << "Age: " << stu->age << endl;
    cout << "GPA: " << stu->gpa << endl;
}   

int main()
{
    // 结构体变量
    struct student stu;
    stu.name = "Alice";
    stu.age = 18;
    stu.gpa = 3.6;
    cout << "Name: " << stu.name << endl;
    cout << "Age: " << stu.age << endl;
    cout << "GPA: " << stu.gpa << endl;

    // 结构体数组
    struct student stuarray[5] =
    {
        {"John", 18, 3.5},
        {"Mary", 19, 3.8},
        {"Tom", 17, 3.2},
        {"Jane", 18, 3.9},
        {"Mike", 19, 3.1}
    };
    for (int i = 0; i < 5; i++)
    {
        cout << "Name: " << stuarray[i].name << endl;
        cout << "Age: " << stuarray[i].age << endl;
        cout << "GPA: " << stuarray[i].gpa << endl;
    }

    // 结构体指针,指向结构体变量，修改结构体变量的值
    // C++中struct可以省略
    struct student * p = &stu;
    p -> name = "Bob";
    p -> age = 19;
    p -> gpa = 3.7;
    cout << "Name: " << p -> name << endl;
    cout << "Age: " << p -> age << endl;
    cout << "GPA: " << p -> gpa << endl;

    // 结构体嵌套结构体
    struct teacher tea;
    tea.name = "Mike";
    tea.age = 30;
    tea.stu.name = "Tom";
    tea.stu.age = 17;
    tea.stu.gpa = 3.3;
    cout << "Teacher Name: " << tea.name << endl;
    cout << "Teacher Age: " << tea.age << endl;
    cout << "Student Name: " << tea.stu.name << endl;
    cout << "Student Age: " << tea.stu.age << endl;
    cout << "Student GPA: " << tea.stu.gpa << endl;

    // 结构体作为函数参数
    print_student1(stu);
    print_student2(&stu);
    
    // 结构体中const用来防止修改结构体变量的值
    // 具体见print_student2函数定义处的注释

    return 0;
}