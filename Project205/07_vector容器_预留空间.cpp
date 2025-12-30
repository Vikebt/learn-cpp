#include <iostream>
#include <vector>
using namespace std;

// vector容器的预留空间

void test01()
{
    vector<int> v1;

    v1.reserve(100000); // 利用reserve预留空间可以避免频繁的重新开辟空间

    int num = 0; // 统计重新开辟容器空间的次数
    int* p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v1.push_back(i);
        if (p != &v1[0])
        {
            p = &v1[0];
            num++;
        }
    }
    cout << "重新开辟容器空间的次数：" << num << endl;

}



int main()
{
    test01();
    return 0;
}