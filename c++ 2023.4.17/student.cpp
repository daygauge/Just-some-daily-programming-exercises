#define _CRT_SECURE_NO_WARNINGS 1
#include "userpre.h"
#include "fileclass.h"

extern vector<MachineRoom*> m;
void student::title()
{
	cout << "-----------------------" << endl;
	cout << "1.����ԤԼ" << endl;
	cout << "2.�鿴�ҵ�ԤԼ" << endl;
	cout << "3.�鿴����ԤԼ    " << endl;
	cout << "4.ȡ��ԤԼ        " << endl;
	cout << "0.ע������        " << endl;
	cout << "-----------------------" << endl;
}
bool student::login()
{
	//���ڶԱ������Ƿ���ȷ
	string n1;
	string n2;
	string n3;

	string a1;
	string a2;
	string a3;
	fstream fs(XSHENG, ios::in);

	cout << "������ѧ��:";
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
			this->test1 = n1;
			this->test2 = n2;
			return true;
		}
	}
	fs.close();
	cout << "�˺Ż��������" << endl;
	system("pause");
	system("cls");
	return false;
}
void student::applyformac()
{
	int date = 0;//����
	int shi = 0;//������
	int mac = 0;//������

	do
	{
		cout << "��ѡ��ԤԼ����" << endl;
		cout << "1.����һ" << endl;
		cout << "2.���ڶ�" << endl;
		cout << "3.������" << endl;
		cout << "4.������" << endl;
		cout << "5.������" << endl;
		cout << endl;
		cin >> date;
	} while (date>5||date<1);
	
	do
	{
		cout << "��ѡ��ԤԼʱ��" << endl;
		cout << "1.����/2.����" << endl;
		cin >> shi;
	} while (shi > 2 || shi < 1);
	
	do
	{
		cout << "��ѡ�����" << endl;
		cout << "��ǰ���û���Ϊ:" << endl;
		manage().viewmac();//����Ա�������ӡ�ӿ�

		cin >> mac;
	} while (mac<1 || mac>m.size());
	
	//��¼�ļ�
	ofstream ofs;
	switch(date)
	{
	case 1:
		ofs.open(DATE1, ios::app);
		break;
	case 2:
		ofs.open(DATE2, ios::app);
		break;
	case 3:
		ofs.open(DATE3, ios::app);
		break;
	case 4:
		ofs.open(DATE4, ios::app);
		break;
	case 5:
		ofs.open(DATE5, ios::app);
		break;
	}
	ofs << date;
	ofs << shi;
	ofs << mac;
	ofs << endl;
	//��¼�����Ϣ
	ofs << test1 << endl;
	ofs << test2 << endl;
	cout << "ԤԼ��ӳɹ�,�����.." << endl;
	system("pause");
	system("cls");
}
void student::viewmac()
{

}
void student::viewmacs()
{

}
void student::cancellmac()
{

}