#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    int c = a + b;

    cout << "Hello, World!" << endl;
    cout << "The sum of " << a << " and " << b << " is " << c << endl;
    cout << "short 类型所占内存空间为："<< sizeof(short) << "字节" << endl;
    cout << "int 类型所占内存空间为：" << sizeof(int) << "字节" << endl;
    cout << "long 类型所占内存空间为：" << sizeof(long) << "字节" << endl;
    cout << "long long 类型所占内存空间为：" << sizeof(long long) << "字节" << endl;
    cout << "float 类型所占内存空间为：" << sizeof(float) << "字节" << endl;
    cout << "double 类型所占内存空间为：" << sizeof(double) << "字节" << endl;
    cout << "char 类型所占内存空间为：" << sizeof(char) << "字节" << endl;
    cout << "string 类型所占内存空间为：" << sizeof(string) << "字节" << endl;
    cout << "bool 类型所占内存空间为：" << sizeof(bool) << "字节" << endl;
    
    // 一维数组逆置
    int arr[5] = {5, 4, 3, 2, 1};
    cout << "数组逆置前：" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }  

    cout << "数组逆置后：" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    // 一维数组冒泡排序

    int arr2[9] = {4,8,2,9,5,1,3,7,6};
    cout << "数组排序前：" << endl;
    for(int i = 0; i < 9; i++)
    {
        cout << arr2[i] << endl;
    }

    for (int i = 0; i < 9 - 1; i++)
    {
        for (int j = 0; j < 9 - i - 1; j++)
        {
            if (arr2[j] > arr2[j + 1])
            {
                int temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }

    cout << "数组排序后：" << endl;
    for(int i = 0; i < 9; i++)
    {
        cout << arr2[i] << endl;
    }


    
    return 0;
}