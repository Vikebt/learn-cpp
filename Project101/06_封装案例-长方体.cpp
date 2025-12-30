#include <iostream>
#include <string>
using namespace std;

// 长方体类设计
// 1.创建长方体类
// 2.设计属性
// 3.设计行为 获取长方体面积和体积
// 4.分别利用全局函数和成员函数 判断两个长方体是否相等

class Cube
{
	public:
		// 设置长宽高
		void setLength(int length) { this->length = length; }
		void setWidth(int width) { this->width = width; }
		void setHeight(int height) { this->height = height; }
		// 获取长宽高
		int getLength() { return this->length; }
		int getWidth() { return this->width; }
		int getHeight() { return this->height; }
		// 获取长方体体积
		int getVolume() { return this->length * this->width * this->height; }
        // 获取长方体面积
		int getArea() { return 2 * (this->length * this->width + this->length * this->height + this->width * this->height); }
		bool isSameCube(Cube& c)
		{
			if (length == c.getLength() && width == c.getWidth() && height == c.getHeight())
			{
				return true;
			}
			return false;
		}

	private:
		int length; // 长
		int width; // 宽
		int height; // 高
};

// 全局函数判断两个长方体是否相等
// 引用传递，此处当然也可使用值传递（前提是传入参数不需要修改）或指针传递（传入指针变量，.换成->即可）
bool isEqual(Cube& c1, Cube& c2)
{
	if (c1.getLength() == c2.getLength() && c1.getWidth() == c2.getWidth() && c1.getHeight() == c2.getHeight())
	{
		return true;
	}
	return false;
}

int main()
{
	Cube c1, c2;
	c1.setLength(5);
	c1.setWidth(4);
	c1.setHeight(3);
	cout << "c1的体积为：" << c1.getVolume() << endl;
	cout << "c1的面积为：" << c1.getArea() << endl;
	c2.setLength(5);
	c2.setWidth(4);
	c2.setHeight(4);
	cout << "c2的体积为：" << c2.getVolume() << endl;
	cout << "c2的面积为：" << c2.getArea() << endl;

	// 利用全局函数判断两个长方体是否相等
	bool result = isEqual(c1, c2);
	if (result)
	{
		cout << "c1和c2相等" << endl;
	}
	else
	{
		cout << "c1和c2不相等" << endl;
	}
	// 利用成员函数判断两个长方体是否相等
	bool result2 = c1.isSameCube(c2);
	if (result2)
	{
		cout << "c1和c2相等" << endl;
	}
	else
	{
		cout << "c1和c2不相等" << endl;
	}

	return 0;
}