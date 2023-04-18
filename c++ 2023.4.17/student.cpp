#define _CRT_SECURE_NO_WARNINGS 1
#include "userpre.h"
#include "fileclass.h"

extern vector<MachineRoom*> m;
extern multimap<string, macyys> macyy;

void student::title()
{
	cout << "-------------------------------" << endl;
	cout << "��ǰ�˺���Ϣ" << " ѧ��:" << this->test1 << " ����:" << this->test2 << endl;
	cout << "1.����ԤԼ" << endl;
	cout << "2.�鿴�ҵ�ԤԼ" << endl;
	cout << "3.�鿴����ԤԼ    " << endl;
	cout << "4.ȡ��ԤԼ        " << endl;
	cout << "0.ע������        " << endl;
	cout << "------------------------------" << endl;
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
	string datetest;//д������
	string shitest;//д��������
	string mactest;//д�������

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
	switch (date)
	{
	case 1:
		datetest = "����һ";
		break;
	case 2:
		datetest = "���ڶ�";
		break;
	case 3:
		datetest = "������";
		break;
	case 4:
		datetest = "������";
		break;
	case 5:
		datetest = "������";
		break;
	default:
		break;
	}

	do
	{
		cout << "��ѡ��ԤԼʱ��" << endl;
		cout << "1.����/2.����" << endl;
		cin >> shi;
	} while (shi > 2 || shi < 1);
	switch (shi)
	{
	case 1:
		shitest = "����";
		break;
	case 2:
		shitest = "����";
		break;
	default:
		break;
	}

	do
	{
		cout << "��ѡ�����" << endl;
		cout << "��ǰ���û���Ϊ:" << endl;
		manage().viewmac();//����Ա�������ӡ�ӿ�

		cin >> mac;
	} while (mac<1 || mac>m.size());
	switch (shi)
	{
	case 1:
		mactest = "1�Ż���";
		break;
	case 2:
		mactest = "2�Ż���";
		break;
	default:
		break;
	}

	ofstream ofs(DATE, ios::app);
	ofs << datetest << endl;
	ofs << shitest << endl;
	ofs << mactest << endl;
	//��¼�����Ϣ
	ofs << test1 << endl;
	ofs << test2 << endl; 
	ofs << TOEX << endl;//ԤԼ״̬
	cout << "ԤԼ��ӳɹ�,�����.." << endl;
	system("pause");
	system("cls");
}
void student::viewmac()
{
	bool i = true;//�ж�ԤԼ�Ƿ�Ϊ��
	//��ӡԤԼ��Ϣ
	for (multimap<string, macyys>::iterator it = macyy.begin(); it != macyy.end(); it++)
	{
		if (it->first == this->test2)
		{
			cout << " ԤԼʱ��:" << it->second.mac_date << " " << it->second.mac_shi
				<< " ԤԼ����:" << it->second.mac_mac
				<< " ԤԼ״̬:" << it->second.m_state << endl;
			i = false;
		}
	}
	if (i)
	{
		cout << "Ŀǰ����ԤԼ" << endl;
		return;
	}
	system("pause");
	system("cls");
}
void student::viewmacs()
{
	if (macyy.begin() == macyy.end())
	{
		cout << "Ŀǰ����ԤԼ" << endl;
		return;
	}
	for (multimap<string, macyys>::iterator it = macyy.begin(); it != macyy.end(); it++)
	{
		cout <<"ѧ��:"<< it->second.m_stuid
			<<" ����:"<< it->second.m_name
			<< " ԤԼʱ��:" << it->second.mac_date << " " << it->second.mac_shi
			<< " ԤԼ����:" << it->second.mac_mac
			<< " ԤԼ״̬:" << it->second.m_state << endl;
	}
	system("pause");
	system("cls");
}
void student::cancellmac()
{
	int i = 0;//��¼��ǰԤԼ����
	int age = 0;
	//��ӡԤԼ��Ϣ
	for (multimap<string, macyys>::iterator it = macyy.begin(); it != macyy.end(); it++)
	{
		if (it->first == this->test2)
		{
			cout <<i<<" "
				<< " ԤԼʱ��:" << it->second.mac_date << " " << it->second.mac_shi
				<< " ԤԼ����:" << it->second.mac_mac
				<< " ԤԼ״̬:" << it->second.m_state << endl;
			i++;
		}
	}
	if (!i)
	{
		cout << "Ŀǰ����ԤԼ..." << endl;
		return;
	}
	cout << endl;
	cout << "��������Ҫȡ����ԤԼ���:";
	cin >> age;
	if (age >= i || age < 0)
	{
		cout << "��Ŵ���򲻴���" << endl;
		system("pause");
		system("cls");
		return;
	}
	//����ԤԼ�����е���Ϣ
	for (multimap<string, macyys>::iterator it = macyy.begin(); it != macyy.end(); it++)
	{
		if (it->first == this->test2)
		{
			if (age == 0)
			{
				it->second.m_state = CANC;
			}
			age--;
		}
	}
	this->renew();//�����ļ�
	cout << "ȡ���ɹ�" << endl;
	system("pause");
	system("cls");
}
void student::renew()
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