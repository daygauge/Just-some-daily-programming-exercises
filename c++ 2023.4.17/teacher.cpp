#define _CRT_SECURE_NO_WARNINGS 1
#include "userpre.h"
#include "fileclass.h"

void teacher::title()
{
	cout << "-----------------------" << endl;
	cout << "1.�鿴����ԤԼ        " << endl;
	cout << "4.���ԤԼ        " << endl;
	cout << "0.ע������        " << endl;
	cout << "-----------------------" << endl;
}
bool teacher::login()//����
{
	//���ڶԱ������Ƿ���ȷ
	string n1;
	string n2;
	string n3;

	string a1;
	string a2;
	string a3;
	fstream fs(LSHI, ios::in);

	cout << "������ְ����:";
	cin >> n1;
	cout << "����������:";
	cin >> n2;
	cout << "����������:";
	cin >> n3;

	//�ж��Ƿ���ƥ����˺�����
	while (fs >> a1 && fs >> a2 && fs >> a3)
	{
		if (n1 == a1 && n2 == a2 && n3 == a3)
		{
			system("cls");
			cout << "����ɹ�..." << endl;
			fs.close();
			return true;
		}
	}
	fs.close();
	cout << "�˺Ż��������" << endl;
	system("pause");
	system("cls");
	return false;
}
void teacher::ViewApp()
{

}
void teacher::toExamineacs()
{

}