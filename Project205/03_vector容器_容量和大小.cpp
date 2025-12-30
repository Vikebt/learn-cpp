#include <iostream>
#include <vector>
using namespace std;

// vector容器的容量和大小

void printVector(vector<int>& v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    for(int i=0; i<10; i++)
    {
        v1.push_back(i);
    }

    if (v1.empty())
    {
        cout << "v1 is empty" << endl;
    }
    else 
    {
        cout << "v1 size: " << v1.size() << endl;
        cout << "v1 capacity: " << v1.capacity() << endl;
    }
    printVector(v1);
    v1.resize(12);
    printVector(v1);
    v1.resize(15,100);
    printVector(v1);

}

int main()
{
    test01();
    return 0;
}