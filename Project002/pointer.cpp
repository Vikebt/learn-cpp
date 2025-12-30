#include <iostream>
using namespace std;

int swap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    return 0;
}

int swap02(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

void bubbleSort(int* arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap02(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printarray(int* arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a = 10;
    int* ptr;
    ptr = &a;
    //等同于int* ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in pointer: " << *ptr << endl;
    cout << "Address stored in pointer: " << ptr << endl;

    *ptr = 20;
    cout << "New value of a: " << a << endl;
    cout << "New value stored in pointer: " << *ptr << endl;
    
    // sizeof()函数可以用来获取指针所占的内存大小
    cout << sizeof(ptr) << endl;
    cout << sizeof(char *) << endl; // 指针所占的内存大小与char*相同，因为指针本身就是一个地址值
    cout << sizeof(float *) << endl; // 指针所占的内存大小与float*相同，因为指针本身就是一个地址值
    cout << sizeof(double *) << endl; // 指针所占的内存大小与double*相同，因为指针本身就是一个地址值
    
    int* p = nullptr; // nullptr表示空指针，可以用来初始化指针变量
    cout << "Value of p: " << p << endl;
    // 空指针是不可以进行访问的，会导致程序崩溃
    // cout << "Address of p: " << *p << endl;


    int* q = (int*)0x1100;
    cout << "Value of q: " << q << endl;
    // 野指针是不可以进行访问的，会导致程序崩溃
    // cout << "Address of q: " << *q << endl;

    // 1.const修饰指针 -- 常量指针
    // 常量指针指向可以修改，但是不能修改指向的值，只能读取
    int a1 = 10;
    int b1 = 20;
    const int* p1 = &a1;
    // *p1 = 30; // 错误，常量指针不能修改指向的值
    cout << "Value of a1: " << a1 << endl;
    p1 = &b1; //正确，常量指针指向可以修改
    cout << "Value of b1: " << *p1 << endl; //*p1 = b1;

    // 2.const修饰常量 -- 指针常量
    // 指针常量指向不可以修改，只能修改指向的值
    int a2 = 20;
    int b2 = 30;
    int* const p2 = &a2;
    *p2 = b2; //正确，指针常量指向的值可以修改
    // p2 = &b2; // 错误，指针常量指向不可以修改
    cout << "Value of b2: " << b2 << endl;

    // 3.const修饰指针常量 -- 常量指针常量
    // 指针常量指向和指向的值都不能修改
    int a3 = 30;
    int b3 = 40;
    const int* const p3 = &a3;
    // *p3 = b3; // 错误，常量指针常量指向的值和指向都不能修改
    // p3 = &b3; // 错误，常量指针常量指向不可以修改
    cout << "Value of a3: " << a3 << endl;

    // 指针和数组
    int arr[5] = {1, 2, 3, 4, 5};
    int* parr = arr;
    cout << "Value of arr[0]: " << arr[0] << endl; 
    cout << "Value of *parr: " << *parr << endl;
    // 指针遍历数组
    for (int i = 0; i < 5; i++)
    {
        //cout << "Value of arr[" << i << "]: " << arr[i] << endl;
        cout << "Value of arr[" << i << "]: " << *parr << endl;
        parr++;
    }

    // 指针和函数 1.值传递 2.地址传递
    int a4 = 40;
    int b4 = 50;
    cout << "Before swap: a4 = " << a4 << ", b4 = " << b4 << endl;
    // 值传递 -- 传递的是值，函数内对参数的修改不会影响到调用函数的实参
    swap01(a4, b4);
    cout << "After swap01: a4 = " << a4 << ", b4 = " << b4 << endl;
    // 地址传递 -- 传递的是地址，函数内对参数的修改会影响到调用函数的实参
    swap02(&a4, &b4);
    cout << "After swap02: a4 = " << a4 << ", b4 = " << b4 << endl;

    // 指针配合数组和函数示例
    int arr1[10] = {4,3,6,9,1,8,2,7,5,0};
    int len = sizeof(arr1) / sizeof(arr1[0]);
    printarray(arr1, len);
    bubbleSort(arr1, len);
    printarray(arr1, len);

    return 0;
}