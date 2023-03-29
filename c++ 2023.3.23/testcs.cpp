#pragma once
#include "testcs.h"
#define DILEL "EmployeeD.txt"
#include <iostream>
menu::menu()
{
	this->ofpeoples = 0;
	this->s_staffandworkers = NULL;
	this->FileM();

	int i = this->NOP();
	cout << "����ɹ���ǰְ������Ϊ:" << i << endl;
	this->ofpeoples = i;
	this->s_staffandworkers = new staffandworkers * [this->ofpeoples];

	this->LnitEmp();

	for (int s = 0; s < this->ofpeoples; s++)
	{
		cout << this->s_staffandworkers[s]->id << " "
			<< this->s_staffandworkers[s]->name << " "
			<< this->s_staffandworkers[s]->deptid << endl;
	}
}
menu::~menu()
{
	for (int i = 0; i < this->ofpeoples; i++)
	{
		delete this->s_staffandworkers[i];
	}
	if (this->s_staffandworkers != NULL)
	{
		delete[] this->s_staffandworkers;
	}
}

void menu::menus()//����
{
	cout << " 0.�˳�������� " << endl;
	cout << " 1.����ְ����Ϣ  " << endl;
	cout << " 2.��ʾְ����Ϣ " << endl;
	cout << " 3.ɾ����ְְ�� " << endl;
	cout << " 4.�޸�ְ����Ϣ " << endl;
	cout << " 5.����ְ����Ϣ " << endl;
	cout << " 6.���ձ������ " << endl;
	cout << " 7.��������ĵ� " << endl;
	cout << endl;
}

void menu::add()//���ְ��
{
	int ls = 0;
	staffandworkers** ls0;
	cout << "������Ҫ��ӵ�ְ������" << endl;
	cin >> ls;
	if (ls > 0)
	{
		//���ٶ�̬�ڴ�
		int cs = this->ofpeoples + ls;
		ls0 = new staffandworkers * [cs];
		if (this->s_staffandworkers != NULL)
		{
			int i = 0;
			while (i < this->ofpeoples)
			{
				ls0[i] = this->s_staffandworkers[i];
				i++;
			}
		}
		int i = 0;//��ӵ�ְ������
		while (i < ls)
		{
			int ids = 0;
			string names;
			int s = 0;
			bool bool_s = false;
			while (true)
			{
				if (bool_s)
				{
					break;
				}
				cout << "�������" << i + 1 << "��ְ���ı��" << endl;
				cin >> ids;
				int m_i = 0;
				if (this->ofpeoples)
				{
					while (m_i < this->ofpeoples + i )
					{
						if (ls0[m_i]->id == ids)
						{
							m_i++;
							break;
						}
						m_i++;
					}
					if (ls0[m_i-1]->id == ids)
					{
						cout << "ְ������Ѵ���,����������" << endl;
					}
					else
					{
						bool_s = true;
					}
				}
				else
				{
					if (i)
					{
						while (m_i < i)
						{
							if (ls0[m_i]->id == ids)
							{
								m_i++;
								break;
							}
							m_i++;
						}
						if (ls0[m_i-1]->id == ids)
						{
							cout << "ְ������Ѵ���,����������" << endl;
						}
						else
						{
							bool_s = true;
						}
					}
					else
					{
						bool_s = true;
					}
				}
			}
			while (true)
			{
				cout << "�������" << i + 1 << "��ְ��������" << endl;
				cin >> names;
				if (names.find(' ') == string::npos)
				{
					break;
				}
				else
				{
					cout << "�벻Ҫ�������д��пո�" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
			while (true)
			{
				cout << "��ѡ���" << i + 1 << "��ְ���ĸ�λ" << endl
					<< "1.Ա��" << endl << "2.����" << endl << "3.�ܲ�" << endl;
				cin >> s;

				staffandworkers* lscs = NULL;
				switch (s)
				{
				case 1:
					lscs = new staff(ids, names, s);
					break;
				case 2:
					lscs = new handle(ids, names, s);
					break;
				case 3:
					lscs = new boss(ids, names, s);
					break;
				default:
					break;
				}
				if (lscs == NULL)
				{
					cout << "ѡ�����" << endl;
				}
				else
				{
					ls0[this->ofpeoples + i] = lscs;
					break;
				}
			}
			i++;
		}
		//�ͷ�ԭ�пռ�
		if (this->s_staffandworkers != NULL)
		{
			delete[] this->s_staffandworkers;
		}

		this->s_staffandworkers = ls0;//�����¿ռ�ָ��
		this->ofpeoples = cs;//�����µĸ���
		cout << "��ӳɹ�" << ls << "����ְ��" << endl;
		this->WriteF();
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

void menu::WriteF()
{
	ofstream ofs;
	ofs.open(DILEL, ios::out);
	for (int i = 0; i < this->ofpeoples; i++)
	{
		ofs << this->s_staffandworkers[i]->id << " "
			<< this->s_staffandworkers[i]->name << " "
			<< this->s_staffandworkers[i]->deptid << endl;
	}
	ofs.close();
}

void menu::FileM()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(DILEL, ios::in);
	if (!ifs.is_open())
	{
		this->ofpeoples = 0;
		this->s_staffandworkers = NULL;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//�ļ����ڵ���Ϊ��
	char cs;
	ifs >> cs;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->ofpeoples = 0;
		this->s_staffandworkers = NULL;
		ifs.close();
		return;
	}
	ifs.close();
}

void menu::LnitEmp()//�ļ����ڲ���Ϊ��
{

	ifstream ifs;
	ifs.open(DILEL, ios::in);

	int id = 0;
	string id1;
	int id2;

	int cs = 0;
	while (ifs >> id && ifs >> id1 && ifs >> id2)
	{
		staffandworkers* ls = NULL;
		if (id2 == 1)
		{
			ls = new staff(id, id1, id2);
		}
		else if (id2 == 2)
		{
			ls = new handle(id, id1, id2);
		}
		else
		{
			ls = new boss(id, id1, id2);
		}
		this->s_staffandworkers[cs] = ls;
		cs++;
	}
	ifs.close();
}

int menu::NOP()
{
	ifstream ifs;
	ifs.open(DILEL, ios::in);
	int i = 0;
	int id = 0;
	string id1;
	int id2;
	while (ifs >> id && ifs >> id1 && ifs >> id2)
	{
		i++;
	}
	ifs.close();
	return i;
}

void menu::DisplayInformation()
{
	for (int i = 0; i < this->ofpeoples; i++)
	{
		cout << "ְ�����:" << this->s_staffandworkers[i]->id
			<< "\tְ������:" << this->s_staffandworkers[i]->name
			<< "\t��λ:" << this->s_staffandworkers[i]->deptid
			<< endl;
	}
	system("pause");
}

int cszgongI;
void menu::DeleteEmployee()
{
	if (this->ofpeoples == 0)
	{
		cout << "��ǰְ���б�Ϊ��" << endl;
		return;
	}
	int i = 0;
	if (cs())
	{
		i = cszgongI;
		for (; i < this->ofpeoples - 1; i++)
		{
			this->s_staffandworkers[i] = this->s_staffandworkers[i + 1];
		}
		this->ofpeoples--;
		this->WriteF();
		cout << "ɾ���ɹ�" << endl;
		system("pause");
		return;
	}
	cout << "�Ҳ���ְ�����" << endl;
	system("pause");
}
void menu::FindEmployees()
{
	bool cs = false;
	int cs1 = 0;
	if (this->ofpeoples == 0)
	{
		cout << "��ǰְ���б�Ϊ��" << endl;
		return;
	}

	int m_id;
	string m_name;
	int i = 0;
	cout << "ѡ����ҵķ���:1.���ձ�Ų���,0������������:";
	cin >> cs1;
	if (cs1)
	{
		cout << "������ְ��������ڲ���:" << endl;
		cin >> m_id;
		while (i < this->ofpeoples)
		{
			if (this->s_staffandworkers[i]->id == m_id)
			{
				cszgongI = i;
				cs = true;
			}
			i++;
		}
	}
	else
	{
		cout << "������ְ���������ڲ���:" << endl;
		cin >> m_name;
		while (i < this->ofpeoples)
		{
			if (this->s_staffandworkers[i]->name == m_name)
			{
				cszgongI = i;
				cs = true;
			}
			i++;
		}
	}
	if (cs)
	{
		cout << "ְ�����:" << this->s_staffandworkers[cszgongI]->id
			<< "\tְ������:" << this->s_staffandworkers[cszgongI]->name
			<< "\t��λ:" << this->s_staffandworkers[cszgongI]->deptid
			<< endl;
		system("pause");
	}
	else
	{
		cout << "���޴���" << endl;
	}
}
bool menu::cs()
{
	if (this->ofpeoples == 0)
	{
		cout << "��ǰְ���б�Ϊ��" << endl;
		return false;
	}
	int m_id;
	int i = 0;
	cout << "������ְ��������ڲ���:" << endl;
	cin >> m_id;
	while (i < this->ofpeoples)
	{
		if (this->s_staffandworkers[i]->id == m_id)
		{
			cszgongI = i;
			return true;
		}
		i++;
	}
	return false;
}
void menu::xg()
{
	if (this->ofpeoples == 0)
	{
		cout << "��ǰְ���б�Ϊ��" << endl;
		return;
	}
	int i = 0;
	if (cs())
	{
		i = cszgongI;
		cout << "��Ҫ�޸ĵ�ְ�����: ";
		cin >> this->s_staffandworkers[i]->id;
		cout << "��Ҫ�޸ĵ�ְ������:" ;
		cin >> this->s_staffandworkers[i]->name;
		while (true)
		{
			cout << "��Ҫ�޸ĵ�ְ����λ" << endl;
			cout << "1.Ա��" << endl << "2.����" << endl << "3.�ܲ�" << endl;
			cin >> this->s_staffandworkers[i]->deptid;
			if (this->s_staffandworkers[i]->deptid > 0 && this->s_staffandworkers[i]->deptid < 4)
			{
				break;
			}
		}
		if (this->s_staffandworkers[i]->deptid == 1)
		{
			staffandworkers* css = new staff(this->s_staffandworkers[i]->id,
				this->s_staffandworkers[i]->name, this->s_staffandworkers[i]->deptid);
			this->s_staffandworkers[i] = css;
		}
		else if (this->s_staffandworkers[i]->deptid == 2)
		{
			staffandworkers* css = new handle(this->s_staffandworkers[i]->id,
				this->s_staffandworkers[i]->name, this->s_staffandworkers[i]->deptid);
			this->s_staffandworkers[i] = css;
		}
		else
		{
			staffandworkers* css = new boss(this->s_staffandworkers[i]->id,
				this->s_staffandworkers[i]->name, this->s_staffandworkers[i]->deptid);
			this->s_staffandworkers[i] = css;
		}
		this->WriteF();
		cout << "�޸ĳɹ�" << endl;
		system("pause");
	}
}
void menu::paixu()
{
	if (this->ofpeoples == 0)
	{
		cout << "��ǰְ���б�Ϊ��" << endl;
		return;
	}
	staffandworkers** lspx = new staffandworkers * [this->ofpeoples];
	for (int s = 0; s < this->ofpeoples; s++)
	{
		if (this->s_staffandworkers[s]->deptid = 1)
		{
			lspx[s] = new staff(this->s_staffandworkers[s]->id,
				this->s_staffandworkers[s]->name, this->s_staffandworkers[s]->deptid);
		}
		else if (this->s_staffandworkers[s]->deptid = 2)
		{
			lspx[s] = new handle(this->s_staffandworkers[s]->id,
				this->s_staffandworkers[s]->name, this->s_staffandworkers[s]->deptid);
		}
		else
		{
			lspx[s] = new boss(this->s_staffandworkers[s]->id,
				this->s_staffandworkers[s]->name, this->s_staffandworkers[s]->deptid);
		}
	}
	staffandworkers* lxc;
	for (int i = 0; i < this->ofpeoples-1; i++)
	{
		for(int j = 0;j<this->ofpeoples-i-1;j++)
		{
			if (lspx[j]->id > lspx[j+1]->id)
			{
				lxc = lspx[j];
		     	lspx[j] = lspx[j + 1];
				lspx[j + 1] = lxc;
			}
		}
	}
	cout << "������ְ���б�Ϊ:" << endl;
	for (int i = 0; i < this->ofpeoples; i++)
	{
		cout << "ְ�����:" << lspx[i]->id
			<< "\tְ������:" << lspx[i]->name
			<< "\t��λ:" << lspx[i]->deptid
			<< endl;
	}
	int num;
	cout << "�Ƿ����ְ���б�Ϊ��������1.true,0.false��:";
	cin >> num;
	cout << endl;
	if (num)
	{
		for (int i = 0; i < this->ofpeoples; i++)
		{
			delete this->s_staffandworkers[i];
		}
		delete[] this->s_staffandworkers;
		this->s_staffandworkers = lspx;
		this->WriteF();
		cout << "���³ɹ�" << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < this->ofpeoples; i++)
	{
		delete lspx[i];
	}
	delete[] lspx;
	system("pause");
}
void menu::delWD()
{
	if (this->ofpeoples == 0)
	{
		cout << "��ǰְ���б�Ϊ��" << endl;
		return;
	}

	cout << "�Ƿ�����ļ�:1,true,0.false" << endl;
	int cs1 = 0;
	cin >> cs1;
	if (!cs1)
	{
		return;
	}

	for (int i = 0; i < this->ofpeoples; i++)
	{
		delete this->s_staffandworkers[i];
	}
	delete[] this->s_staffandworkers;
	this->ofpeoples = 0;
	this->s_staffandworkers = NULL;

	ofstream ofs(DILEL, ios::trunc);
	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}