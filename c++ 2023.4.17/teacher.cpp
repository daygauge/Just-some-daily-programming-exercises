#define _CRT_SECURE_NO_WARNINGS 1
#include "userpre.h"
#include "fileclass.h"

extern multimap<string, macyys> macyy;
void teacher::title()
{
	cout << "-----------------------" << endl;
	cout << "1.�鿴����ԤԼ        " << endl;
	cout << "2.���ԤԼ        " << endl;
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
	if (macyy.begin() == macyy.end())
	{
		cout << "Ŀǰ����ԤԼ" << endl;
		return;
	}
	for (multimap<string, macyys>::iterator it = macyy.begin(); it != macyy.end(); it++)
	{
		cout << "ѧ��:" << it->second.m_stuid
			<< " ����:" << it->second.m_name
			<< " ԤԼʱ��:" << it->second.mac_date << " " << it->second.mac_shi
			<< " ԤԼ����:" << it->second.mac_mac
			<< " ԤԼ״̬:" << it->second.m_state << endl;
	}
	system("pause");
	system("cls");
}
void teacher::toExamineacs()
{
	int i = 0;//��¼��ǰԤԼ����
	int age = 0;

	if (macyy.begin() == macyy.end())
	{
		cout << "Ŀǰ����ԤԼ" << endl;
		return;
	}

	for (multimap<string, macyys>::iterator it = macyy.begin(); it != macyy.end(); it++)
	{
		cout <<i<<" "
			<< "ѧ��:" << it->second.m_stuid
			<< " ����:" << it->second.m_name
			<< " ԤԼʱ��:" << it->second.mac_date << " " << it->second.mac_shi
			<< " ԤԼ����:" << it->second.mac_mac
			<< " ԤԼ״̬:" << it->second.m_state << endl;
		i++;
	}

	cout << "��ѡ����Ҫ������ԤԼ���:";
	cin >> age;
	if (age >= i || age < 0)//�ж�����Ƿ����
	{
		cout << "��Ų�����" << endl;
		return;
	}

	for (multimap<string, macyys>::iterator its = macyy.begin(); its != macyy.end(); its++)
	{
		if (age == 0)
		{
			if (its->second.m_state == CANC || its->second.m_state == TDLS1 || its->second.m_state == TDLS2)
			{
				cout << "��ԤԼ�ѱ�ȡ�����ѱ�����" << endl;
				return;
			}
			while (true)
			{
				cout << "------------------" << endl;
				cout << "1.ͨ��ԤԼ����" << endl;
				cout << "2.����ԤԼ����" << endl;
				cout << "------------------" << endl;
				cout << "��ѡ��:";
				cin >> age;
				if (age == 1)
				{
					its->second.m_state = TDLS1;
					renew();
					system("pause");
					system("cls");
					return;
				}
				else if (age == 2)
				{
					its->second.m_state = TDLS2;
					renew();
					system("pause");
					system("cls");
					return;
				}
				cout << "ѡ�����,������ѡ��" << endl;
			}
		}
		age--;
	}

}

void teacher::renew()
{
	//�����ļ�����������Ϊmacyy������Ϣ
	ofstream ofs(DATE, ios::out);
	for (multimap<string, macyys>::iterator it = macyy.begin(); it != macyy.end(); it++)
	{
		ofs << it->second.mac_date << endl;
		ofs << it->second.mac_shi << endl;
		ofs << it->second.mac_mac << endl;
		ofs << it->second.m_stuid << endl;
		ofs << it->second.m_name << endl;
		ofs << it->second.m_state << endl;
	}
}