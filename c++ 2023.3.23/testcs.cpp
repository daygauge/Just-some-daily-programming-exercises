#pragma once
#include "testcs.h"
menu::menu()
{
	this->ofpeoples = 0;
	this->s_staffandworkers = NULL;
}
menu::~menu()
{

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
			cout << "�������" << i + 1 << "��ְ���ı��" << endl;
			cin >> ids;
			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> names;
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
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}