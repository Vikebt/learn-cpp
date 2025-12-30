#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <ctime>
using namespace std;

//有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分

class Person
{
	public:
		Person(string name, int score) : name(name), score(score) {}
		string name;
		int score;
};

void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;
		// 将创建的Person对象添加到vector中
		Person p(name, score);
		v.push_back(p);

	}
}

void scorePerson(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; //60~100之间随机数
			d.push_back(score);
		}

		//测试打分是否正确
		cout << it->name << "的初始打分情况为：";
		for (deque<int>::iterator it2 = d.begin(); it2 != d.end(); it2++)
		{
			cout << *it2 << " ";
		}
		cout << endl;

		// 排序
		sort(d.begin(), d.end());
		// 去除最高分
		d.pop_back();
		// 去除评委中最低分
		d.pop_front();
		// 取平均分
		int sum = 0;
		for (deque<int>::iterator it2 = d.begin(); it2 != d.end(); it2++)
		{
			sum += *it2;
		}
		int avg = sum / d.size();

		// 将平均分赋给Person对象
		it->score = avg;
		
	}
}

void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << it->name << "的最终分数为：" << it->score << endl;
	}
}

int main()
{
	// 设置随机数种子
	srand(time(NULL)); 

	// 1、创建5名选手
	vector<Person> v;
	createPerson(v);

	// 测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << it->name << "的初始分数为：" << it->score << endl;
	//}
	
	// 2、给5名选手打分
	scorePerson(v);

	// 3、显示最终得分
	showScore(v);

	return 0;
}