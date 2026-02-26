#include<iostream>
#include<string>
using namespace std;
#define maxnum 100
struct people {
	string name;
	string gender;
	int age;
	string phone;
};
struct ressbook {
	people arr[maxnum];
	int size;
};
void add(ressbook*abs)//1.添加联系人
{
	if ( abs->size== maxnum)
	{
		cout << "通讯录已满!" << endl;
	}
	cout << "联系人姓名:";
	cin >> abs->arr[abs->size].name;
	cout << "联系人性别:";
	cin >> abs->arr[abs->size].gender;
	cout << "联系人年龄:";
	cin >> abs->arr[abs->size].age;
	cout << "联系人电话:";
	cin >> abs->arr[abs->size].phone;
	cout << "添加成功！" << endl;
	abs->size++;
	system("pause");
	system("cls");
}
void show(ressbook abs)//2.显示联系人
{
	for (int i = 0; i < abs.size; i++)
	{
		cout << "姓名:" << abs.arr[i].name <<"\t"
		<< "性别:" << abs.arr[i].gender <<"\t"
		 << "年龄:" << abs.arr[i].age <<"\t"
			<< "电话:" << abs.arr[i].phone <<endl;
	}
	system("pause");
	system("cls");
}
int exist(ressbook abs,string name)
{
	for (int i = 0; i < abs.size; i++)
	{
		if (abs.arr[i].name == name)
			return i;
	}
	return -1;
}
void delet(ressbook*abs,int x)//3.删除联系人
{
	for (int i = x; i < abs->size; i++)
	{
		abs->arr[i].name = abs->arr[i+1].name;
		abs->arr[i].gender = abs->arr[i+1].gender;
		abs->arr[i].age = abs->arr[i+1].age;
		abs->arr[i].phone = abs->arr[i+1].phone;
	}
	abs->size--;
	system("cls");
}
void find(ressbook abs, int i) {
	cout << "姓名:" << abs.arr[i].name <<"\t";
	cout << "性别:" << abs.arr[i].gender <<"\t";
	cout << "年龄:" << abs.arr[i].age <<"\t";
	cout<< "电话:" << abs.arr[i].phone << endl;
}
void xiugai(ressbook* abs, int n)//5.修改联系人
{
	cout << "姓名改为:";
	cin >> abs->arr[n].name;
	cout << "性别 年龄 电话:";
	cin >> abs->arr[n].gender >> abs->arr[n].age >> abs->arr[n].phone;
}
void clean(ressbook* abs)//6.清楚通讯录
{
	cout << "确认清除通讯录?(y/n)";
	char m;
	cin >> m;
	if (m == 'y' || m == 'Y')
	{
		abs->size = 0;
		cout << "通讯录已空!" << endl;
	}
	else {
		cout << "取消操作!" << endl;
	}
	system("pause");
	system("cls");
}
//菜单界面
void showmenu()
{
	cout << "**********************\n";
	cout << "**** 1.添加联系人 ****\n";
	cout << "**** 2.显示联系人 ****\n";
	cout << "**** 3.删除联系人 ****\n";
	cout << "**** 4.查找联系人 ****\n";
	cout << "**** 5.修改联系人 ****\n";
	cout << "**** 6.清空联系人 ****\n";
	cout << "**** 0.退出通讯录 ****\n";
}
int main()
{

	int select=0;
	ressbook abs;
	abs.size = 0;
	while (true)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			add(&abs);
			break;
		case 2://显示联系人
			show(abs);
			break;
		case 3://删除联系人
		{
			cout << "输入删除的联系人姓名:" << endl;
			string name1;
			cin >> name1;
			if (exist(abs, name1) == -1)
			{
				cout << "查无此人!" << endl;
				system("pause");
				system("cls");
			}
			else {
				cout << "找到此人!" << endl;
				int i = exist(abs, name1);
				delet(&abs, i);
			}
		}
			break;
		case 4: // 查找联系人
		{
			cout << "输入要查找的联系人姓名:" << endl;
			string name2;
			cin >> name2;
			int x = exist(abs, name2);
			if (x == -1)
			{
				cout << "查无此人!" << endl;
			}
			else
			{
				cout << "找到此人!" << endl;
				find(abs, x); // 调用查找函数
			}
			system("pause");
			system("cls");
		}
		break;
		case 5://修改联系人
		{
			cout << "输入要修改的联系人姓名:" << endl;
			string name3;
			cin >> name3;
			int x = exist(abs, name3);
			if (x == -1)
			{
				cout << "查无此人!" << endl;
				system("pause");
				system("cls");
			}
			else {
				cout << "找到此人!" << endl;
				int n = exist(abs, name3);
				xiugai(&abs, n);
			}
		}
			break;
		case 6://清空联系人
			clean(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用!" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	return 0;
}