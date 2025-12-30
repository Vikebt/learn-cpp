#include <iostream>
#include <set>
using namespace std;

// set和multiset的区别

void printSet(set<int> s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
    
    pair<set<int>::iterator, bool> ret = s1.insert(10);

    if (ret.second)
    {
        cout << "The first insert 10 success" << endl;
    }
    else
    {
        cout << "The first insert 10 failed" << endl;
    }

    ret = s1.insert(10);
    if (ret.second)
    {
        cout << "The second insert 10 success" << endl;
    }
    else
    {
        cout << "The second insert 10 failed" << endl;
    }

    // multiset
    multiset<int> s2;
    s2.insert(10);
    s2.insert(10);

    for (multiset<int>::iterator it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
}

int main()
{
    test01();
    return 0;
}