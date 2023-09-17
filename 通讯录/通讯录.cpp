#include<iostream>
#include<string>
#define max 1000
using namespace std;
struct person
{
	string name;
	int sex;//1�� 2Ů
	int age;
	string phone;
};
struct book
{
	struct person personarray[max];
	int size;
};
//��ʾ�˵�
void showmenu()
{
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˳�ͨѶ¼" << endl;
}
//�����ϵ��
void addperson(book*booka) {
	if (booka->size==max)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "��������" << endl;
		cin >> name;
		booka->personarray[booka->size].name = name;
		int sex = 0;
		cout << "�����Ա� 1���� 2��Ů" << endl;
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
				cout << "�������,����������" << endl;
			}
		}
		int age = 0;
		cout << "��������" << endl;
		cin >> age;
		booka->personarray[booka->size].age = age;
		cout << "����绰����" << endl;
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
				cout << "�����������������" << endl;
			}
		}
		booka->size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
//��ʾ��ϵ��
void showperson(book*booka) {
	if (booka->size == 0)
		{
			cout << "ͨѶ¼Ϊ��" << endl;
		}
	else
		{
		for (int i = 0; i < booka->size; i++)
			{
				cout << "������" << booka->personarray[i].name<<"\t";
				cout << "�Ա�" << (booka->personarray[i].sex==1?"��":"Ů" )<< "\t";
				cout << "���䣺" << booka->personarray[i].age << "\t";
				cout << "�绰��" << booka->personarray[i].phone << endl;
			}
		}
	system("pause");
	system("cls");
}
//�����ϵ��
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
//ɾ����ϵ��
void deleteperson(book* booka)
{
	cout << "��������ɾ������ϵ��" << endl;
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
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "�޸���ϵ��" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void findperson(book* booka)
{
	cout << "��������" << endl;
	string name;
	cin >> name;
	int i=exist(booka, name);
	if (int (exist(booka,name))==-1)
	{
		cout << "δ�ҵ�����ϵ��" << endl;
	}
	else
	{
		cout << "������" << booka->personarray[i].name << "\t";
		cout << "�Ա�" << (booka->personarray[i].sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << booka->personarray[i].age << "\t";
		cout << "�绰��" << booka->personarray[i].phone << endl;

	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void modifyperson(book* booka)
{
	cout << "��������" << endl;
	string name;
	cin >> name;
	if (int (exist(booka,name) )== -1)
	{
		cout << "δ�ҵ�����ϵ��" << endl;
	}
	else
	{
		cout << "�������µ���Ϣ" << endl;
		int i = exist(booka, name);
		string name;
		cout << "��������" << endl;
		cin >> name;
		booka->personarray[i].name = name;
		int sex = 0;
		cout << "�����Ա� 1���� 2��Ů" << endl;
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
				cout << "�������,����������" << endl;
			}
		}
		int age = 0;
		cout << "��������" << endl;
		cin >> age;
		booka->personarray[i].age = age;
		cout << "����绰����" << endl;
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
				cout << "�����������������" << endl;
			}
		}
		cout << "��ӳɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//�����ϵ��
void clearperson(book* booka)
{
	cout << "�Ƿ���� 1����� 2�������" << endl;
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
			cout << "ͨѶ¼�����" << endl;
			system("pause");
			system("cls");
			break;
		}
		else
		{
			cout << "�������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
//ѡ����
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
		cout << "��ӭ�´�ʹ��" << endl;
		return 0;
		break;
	default:
		cout << "��������" << endl;
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