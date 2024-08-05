// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

class Person
{
public:
	Person();
	~Person();

private:
	int age;
	int high;

};

Person::Person()
{
	cout << "构造函数调用" << endl;
}

Person::~Person()
{
	cout << "析构函数调用" << endl;
}




int main()
{
	std::cout << "Hello World!\n";

	Person p;
}
