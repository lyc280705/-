#include<iostream>
#include<string>
#define max 1000
using namespace std;
struct person
{
	string name;
	int sex;//1男 2女
	int age;
	string phone;
};
struct book
{
	struct person personarray[max];
	int size;
};
//显示菜单
void showmenu()
{
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出通讯录" << endl;
}
//添加联系人
void addperson(book*booka) {
	if (booka->size==max)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		string name;
		cout << "输入姓名" << endl;
		cin >> name;
		booka->personarray[booka->size].name = name;
		int sex = 0;
		cout << "输入性别 1、男 2、女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				booka->personarray[booka->size].sex = sex;
				break;
			}
			else
			{
				cout << "输入错误,请重新输入" << endl;
			}
		}
		int age = 0;
		cout << "输入年龄" << endl;
		cin >> age;
		booka->personarray[booka->size].age = age;
		cout << "输入电话号码" << endl;
		string number;
		while (true)
		{
			cin >> number;
			int len = number.length();
			if (len == 11)
			{
				booka->personarray[booka->size].phone = number;
				break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
			}
		}
		booka->size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
//显示联系人
void showperson(book*booka) {
	if (booka->size == 0)
		{
			cout << "通讯录为空" << endl;
		}
	else
		{
		for (int i = 0; i < booka->size; i++)
			{
				cout << "姓名：" << booka->personarray[i].name<<"\t";
				cout << "性别：" << (booka->personarray[i].sex==1?"男":"女" )<< "\t";
				cout << "年龄：" << booka->personarray[i].age << "\t";
				cout << "电话：" << booka->personarray[i].phone << endl;
			}
		}
	system("pause");
	system("cls");
}
//检测联系人
int exist(book* booka, string name)
{
	for (int i = 0; i < booka->size; i++)
	{
		if (booka->personarray[i].name == name)
		{
			return i;
		}
	}
	return -1;
}
//删除联系人
void deleteperson(book* booka)
{
	cout << "请输入需删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = exist(booka, name);
	if (ret!=-1)
	{
		for (int i = ret; i < booka->size; i++)
		{
			booka->personarray[i] = booka->personarray[i + 1];
			booka->size--;
		}
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "无该联系人" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void findperson(book* booka)
{
	cout << "输入姓名" << endl;
	string name;
	cin >> name;
	int i=exist(booka, name);
	if (int (exist(booka,name))==-1)
	{
		cout << "未找到该联系人" << endl;
	}
	else
	{
		cout << "姓名：" << booka->personarray[i].name << "\t";
		cout << "性别：" << (booka->personarray[i].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << booka->personarray[i].age << "\t";
		cout << "电话：" << booka->personarray[i].phone << endl;

	}
	system("pause");
	system("cls");
}
//修改联系人
void modifyperson(book* booka)
{
	cout << "输入姓名" << endl;
	string name;
	cin >> name;
	if (int (exist(booka,name) )== -1)
	{
		cout << "未找到该联系人" << endl;
	}
	else
	{
		cout << "请输入新的信息" << endl;
		int i = exist(booka, name);
		string name;
		cout << "输入姓名" << endl;
		cin >> name;
		booka->personarray[i].name = name;
		int sex = 0;
		cout << "输入性别 1、男 2、女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				booka->personarray[i].sex = sex;
				break;
			}
			else
			{
				cout << "输入错误,请重新输入" << endl;
			}
		}
		int age = 0;
		cout << "输入年龄" << endl;
		cin >> age;
		booka->personarray[i].age = age;
		cout << "输入电话号码" << endl;
		string number;
		while (true)
		{
			cin >> number;
			int len = number.length();
			if (len == 11)
			{
				booka->personarray[i].phone = number;
				break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
			}
		}
		cout << "添加成功" << endl;
	}
	system("pause");
	system("cls");
}
//清空联系人
void clearperson(book* booka)
{
	cout << "是否清空 1、清空 2、不清空" << endl;
	int choose = 0;
	cin >> choose;
	while (true)
	{
		if (choose == 2)
		{
			system("cls");
			break;
		}
		else if (choose == 1)
		{
			booka->size = 0;
			cout << "通讯录已清空" << endl;
			system("pause");
			system("cls");
			break;
		}
		else
		{
			cout << "输入错误" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
//选择功能
int functionchoose(int select,book* booka)
{
	switch (select)
	{
	case 1:
		addperson(booka);
		break;
	case 2:
		showperson(booka);
		break;
	case 3:
		deleteperson(booka);
		break;
	case 4:
		findperson(booka);
		break;
	case 5:
		modifyperson(booka);
		break;
	case 6:
		clearperson(booka);
		break;
	case 0:
		cout << "欢迎下次使用" << endl;
		return 0;
		break;
	default:
		cout << "输入有误" << endl;
	}
}
int main()
{
	book booka;
	booka.size = 0;
	int select = 0;
	while (true)
	{
		showmenu();
		cin >> select;
		functionchoose(select, &booka);
		if (select == 0) break;
	}
	system("pause");
	return 0;
}