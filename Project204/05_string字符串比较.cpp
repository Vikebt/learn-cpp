#include <iostream>
#include <string>
using namespace std;

//string ×Ö·û´®±È½Ï

void test01()
{
    string s1 = "hello";
    string s2 = "hello";

    if (s1.compare(s2) == 0)
    {
        cout << "s1 and s2 are equal" << endl;
    }
    else if (s1.compare(s2) < 0)
    {
        cout << "s1 is less than s2" << endl;
    }
    else
    {
        cout << "s1 is greater than s2" << endl;
    }
}


int main()
{
    test01();
    return 0;
}