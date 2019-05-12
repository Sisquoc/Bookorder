#include "pch.h"
#include <iostream>
#include"menu.h"
#include<string>
using namespace std;
class Bookorder
{
private:
	char name[22];
	char date[12];
	char ISBN[250];
	char title[250];
	int quality;
	int number=0;
public:
	Bookorder();
	void choicemenu();
	void OrderDisplay(Bookorder &r);
	void OrderShow();
	void OrderAdd();
	void OrderChange();
	void OrderDelete();
	~Bookorder();
};
Bookorder bo[10];
Bookorder::Bookorder()
{
}
void Bookorder::choicemenu()
{
	int c;
	char choice = 'Y';
	Bookorder order;
	while (choice == 'Y' || choice == 'y')
	{
		do
		{
			menusheet();
			cout << "Please input your order:" << endl;
			cin >> c;
		} while (c < 0 || c>5);
		switch (c)
		{
		case 1:OrderAdd();
			cout << "Do you want to continue(Y/N)" << endl;
			cin >> choice;
			break;
		case 2:OrderChange();
			cout << "Do you want to continue(Y/N)" << endl;
			cin >> choice;
			break;
		case 3:OrderDelete();
			cout << "Do you want to continue(Y/N)" << endl;
			cin >> choice;
			break;
		case 4:OrderShow();
			cout << "Do you want to continue(Y/N)" << endl;
			cin >> choice;
			break;
		case 0:
			choice = 'N';
			break;
		}
	}
}
void Bookorder::OrderDisplay(Bookorder &r)
{
	cout << "顾客姓名		"<< r.name<<endl;
	cout << "订单日期		"<< r.date << endl;
	cout << "ISBN			"<< r.ISBN << endl;
	cout << "书名	     	"<< r.title << endl;
	cout << "订单数量		"<< r.quality << endl;
}
void Bookorder::OrderShow()
{
	int n=number;
	if (n == 0)
	{
		cout << "没有数据";
	}
	else
	{
		do
		{
			cout << "共有"<<number<<"个数据，你想输出哪一个";
			cin >> n;
			OrderDisplay(bo[n-1]);
		} while (n > number);
	}
}
void Bookorder::OrderAdd()
{
	cout << "顾客姓名\n";
	cin >> bo[number].name;
	cout << "订单日期\n";
	cin >> bo[number].date;
	cout << "ISBN\n";
	cin >> bo[number].ISBN;
	cout << "书名\n";
	cin >> bo[number].title;
	cout << "订单数量\n";
	cin >> bo[number].quality;
	number++;
}
void Bookorder::OrderChange()
{
	int n = number;
	if (n == 0)
	{
		cout << "没有数据";
	}
	else
	{
		do
		{
			cout << "共有"<<number<<"个数据，你想修改哪一个";
			cin >> n;
			cout << "输入想修改成的数据"<<endl;
			cin >> bo[n-1].name;
			cin >> bo[n-1].date;
			cin >> bo[n-1].ISBN;
			cin >> bo[n-1].title;
			cin >> bo[n-1].quality;
		} while (n > number);
	}
}
void Bookorder::OrderDelete()
{
	int n = number;
	if (n == 0)
	{
		cout << "没有数据";
	}
	else
	{
		do
		{
			cout << "共有" << number << "个数据，你想删除哪一个";
			cin >> n;
		} while (n > number);
	}
	int i;
	for (i = n; i <= number; i++)
	{
		bo[i-1] = bo[i];
	}
	number--;
}
Bookorder::~Bookorder()
{

}
int main()
{
	Bookorder n;
	n.choicemenu();
	return 0;
}