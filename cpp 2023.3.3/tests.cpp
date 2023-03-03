#define _CRT_SECURE_NO_WARNINGS 1
#include "tests.h"

void AddContacts(Books* lx)
{
	if (lx->dqgs == ZDX)
	{
		cout << "ͨѶ¼����\n";
		return;
	}
	cout << "����������: ";
	cin >> lx->txr[lx->dqgs].mane;
	cout << "\n";

	cout << "�������Ա�: ";
	cin >> lx->txr[lx->dqgs].surname;
	cout << "\n";

	cout << "����������: ";
	cin >> lx->txr[lx->dqgs].age;
	cout << "\n";

	cout << "������绰: ";
	cin >> lx->txr[lx->dqgs].telephone;
	cout << "\n";

	cout << "������סַ: ";
	cin >> lx->txr[lx->dqgs].HomeAddress;
	system("cls");
	cout << "��ӳɹ�\n";
	lx->dqgs++;

}

void ShowContacts(Books* lx)
{
	if (lx->dqgs == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��\n";
		return;
	}
	cout << "����\t\t�Ա�\t\t����\t\t�绰\t\tסַ\t\n";
	for (int i = 0; i < lx->dqgs; i++)
	{
		cout << lx->txr[i].mane << "\t\t"
			<< lx->txr[i].surname << "\t\t"
			<< lx->txr[i].age << "\t\t"
			<< lx->txr[i].telephone << "\t\t"
			<< lx->txr[i].HomeAddress << "\n";
	}
	system("pause");
	system("cls");
}
void DeleteContacts(Books* lx)
{
	if (lx->dqgs == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��\n";
		return;
	}
	string xm;
	cout << "��������Ҫɾ������ϵ������:";
	cin >> xm ;
	for (int i = 0; i < lx->dqgs; i++)
	{
		if (lx->txr[i].mane == xm)
		{
			lx->dqgs--;
			for (int j = i; j < lx->dqgs; j++)
				lx->txr[j].mane = lx->txr[j + 1].mane;
			return;
		}
	}
	system("cls");
	cout << "ɾ���ɹ�\n";
}
void SeekContacts(Books* lx)
{
	if (lx->dqgs == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��\n";
		return;
	}
	string xm;
	cout << "��������Ҫ���ҵ���ϵ������:";
	cin >> xm;
	for (int i = 0; i < lx->dqgs; i++)
	{
		if (lx->txr[i].mane == xm)
		{
			cout << "����\t\t�Ա�\t\t����\t\t�绰\t\tסַ\t\n";
			cout << lx->txr[i].mane << "\t\t"
				<< lx->txr[i].surname << "\t\t"
				<< lx->txr[i].age << "\t\t"
				<< lx->txr[i].telephone << "\t\t"
				<< lx->txr[i].HomeAddress << "\n";
			return;
		}
	}
}
void ReviseContacts(Books* lx)
{
	if (lx->dqgs == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��\n";
		return;
	}
	string xm;
	cout << "��������Ҫ�޸ĵ���ϵ������:";
	cin >> xm;
	for (int i = 0; i < lx->dqgs; i++)
	{
		if (lx->txr[i].mane == xm)
		{
			cout << "�������޸ĺ������: ";
			cin >> lx->txr[i].mane;
			cout << "\n";
			cout << "�������޸ĺ���Ա�: ";
			cin >> lx->txr[i].surname;
			cout << "\n";
			cout << "�������޸ĺ������: ";
			cin >> lx->txr[i].age;
			cout << "\n";
			cout << "�������޸ĺ�ĵ绰: ";
			cin >> lx->txr[i].telephone;
			cout << "\n";
			cout << "�������޸ĺ��סַ: ";
			cin >> lx->txr[i].HomeAddress;
			system("cls");
			cout << "�޸ĳɹ�\n";
			return;
		}
	}
}
void EmptyContacts(Books* lx)
{
	lx->dqgs = 0;
	cout << "���ٳɹ�\n";
}