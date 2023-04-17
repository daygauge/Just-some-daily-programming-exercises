#define _CRT_SECURE_NO_WARNINGS 1
#include "userpre.h"
#include "fileclass.h"

extern vector<string> stuv1;
extern vector<string> teav2;
extern vector<MachineRoom*> m;

manage::manage()
{
	//this->ml = new MachineRoom(1, 50);
	//this->m2 = new MachineRoom(2, 100);
	//this->m.push_back(new MachineRoom(1, 50));
	//this->m.push_back(new MachineRoom(2, 100));
}
void manage::title()
{
	cout << "-----------------------" << endl;
	cout << "1.����˺�    " << endl;
	cout << "2.�鿴�˺�    " << endl;
	cout << "3.�鿴����    " << endl;
	cout << "4.���ԤԼ    " << endl;
	cout << "0.ע������    " << endl;
	cout << "-----------------------" << endl;
}

bool manage::login()//����
{
	//���ڶԱ������Ƿ���ȷ
	string n1;
	string n2;

	string a1;
	string a2;

	fstream fs(GUANLI, ios::in);
	fs >> n2;
	fs >> a2;
	fs.close();

	cout << "�������˺�:";
	cin >> n1;
	cout << "����������:";
	cin >> a1;

	if (n2 == n1 && a1 == a2)
	{
		system("cls");
		cout << "����ɹ�..." << endl;
		return true;
	}
	cout << "�˺Ż��������" << endl;
	system("pause");
	system("cls");
	return false;

}
void manage::addna()//����˺�
{
	cout <<"--------------------------------" << endl;
	cout << "��ѡ����Ҫ��ӵ��˺�����" << endl;
	cout << "1.ѧ�������˺�" << endl;
	cout << "2.��ʦ�˺�" << endl;
	cout << "0.����" << endl;
	cout << "--------------------------------" << endl;
	int a = 0;
	cin >> a;
	if (a == 0)
	{
		system("cls");
		return;
	}
		
	if (a == 1)
	{
		string n1;
		string n2;
		string n3;

		cout << "������ѧ��: ";
		cin >> n1;
		cout << "����������: ";
		cin >> n2;
		cout << "����������:" << endl;
		cin >> n3;

		ofstream ofs(XSHENG, ios::app);
		ofs << n1 << endl;
		ofs << n2 << endl;
		ofs << n3 << endl;
		ofs.close();

		cout << "�˺���ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		string n1;
		string n2;
		string n3;

		cout << "������ְ����: " ;
		cin >> n1;
		cout << "����������: ";
		cin >> n2;
		cout << "����������:" << endl;
		cin >> n3;

		ofstream ofs(LSHI, ios::app);
		ofs << n1 << endl;
		ofs << n2 << endl;
		ofs << n3 << endl;
		ofs.close();

		cout << "�˺���ӳɹ�" << endl;
		system("pause");
		system("cls");
	}

	//���¼��������˺�������Ϣ
	stuv1.clear();
	teav2.clear();
	string ls;
	fstream fs(XSHENG, ios::in);
	while (fs >> ls)
	{
		stuv1.push_back(ls);
		ls.clear();
	}
	fs.close();

	ls.clear();
	fstream fs1(LSHI, ios::in);
	while (fs1 >> ls)
	{
		teav2.push_back(ls);
		ls.clear();
	}
	fs1.close();
}
void manage::viewna()//�鿴�˺�
{
	int i = 0;
	cout << "ѧ�������˺�" << endl;
	if (stuv1.begin() == stuv1.end())
		cout << "����ѧ���˺�" << endl;
	for (vector<string>::iterator it = stuv1.begin(); it != stuv1.end();)
	{
		cout << i << " ѧ��:" << *it << " ����:" << *(it + 1) << " ����:" << *(it + 2) << endl;
		it += 3;
		i++;
	}

	i = 0;
	cout << "��ʦ�˺�" << endl;
	if (teav2.begin() == teav2.end())
		cout << "����ѧ���˺�" << endl;
	for (vector<string>::iterator it = teav2.begin(); it != teav2.end();)
	{
		cout << i << " ְ����:" << *it << " ����:" << *(it + 1) << " ����:" << *(it + 2) << endl;
		it += 3;
		i++;
	}
	system("pause");
}
void manage::viewmac()//�鿴����
{
	for (vector<MachineRoom*>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "���:" << (*it)->m1ls << " ����:" << (*it)->m2ls << endl;
	}
}
void manage::emptymac()//���ԤԼ
{
	ofstream n1(DATE1, ios::out);
	n1.close();
	ofstream n2(DATE2, ios::out);
	n2.close();
	ofstream n3(DATE3, ios::out);
	n3.close();
	ofstream n4(DATE4, ios::out);
	n4.close();
	ofstream n5(DATE5, ios::out);
	n5.close();
	cout << "���������ԤԼ" << endl;
	system("pause");
	system("cls");
}