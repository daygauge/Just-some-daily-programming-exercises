#define _CRT_SECURE_NO_WARNINGS 1
#include "tests.h"
//struct  xs
//{
//	string mane;
//	int fs;
//};
//struct  ls
//{
//	string mane;
//	struct  xs ddxs[5];
//};
//void cshua(struct ls ss[], int a)
//{
//	string lsz = "ABCDE";
//	for (int i = 0; i < a; i++)
//	{
//		ss[i].mane = "meisdz_";
//		ss[i].mane += lsz[i];
//		for (int j = 0; j < 5; j++)
//		{
//			ss[i].ddxs[j].mane = "xzname_";
//			ss[i].ddxs[j].mane += lsz[j];
//			int s = rand() % 61 + 40;
//			ss[i].ddxs[j].fs = s;
//		}
//	}
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	struct ls ss[3];
//	int csdx = sizeof(ss) / sizeof(ss[0]);
//	cshua(ss,csdx);
//	for (int i = 0; i < csdx; i++)
//	{
//		cout <<"��ʦ����:"<< ss[i].mane << "\n";
//		for (int j = 0; j < 5; j++)
//		{
//			cout <<"\tѧ������:" << ss[i].ddxs[j].mane << " ";
//			cout << ss[i].ddxs[j].fs << "\n";
//		}
//	}
//	return 0;
//}
#define CASE break; case


//void cs()
//{
//	Books txr;
//	txr.dqgs = 0;
//	AddContacts(&txr);
//	AddContacts(&txr);
//	AddContacts(&txr);
//
//	ShowContacts(&txr);
//
//	DeleteContacts(&txr);
//
//	ShowContacts(&txr);
//
//
//	system("pause");
//	system("cls");
//}


void dabt()
{
	cout << "******************************************************\n";
	cout << "*************1   �����ϵ��      *********************\n";
	cout << "*************2   ��ʾ��ϵ��      *********************\n";
	cout << "*************3   ɾ����ϵ��      *********************\n";
	cout << "*************4   ������ϵ��      *********************\n";
	cout << "*************5   �޸�����ϵ��    *********************\n";
	cout << "*************6   ������ϵ���б�  *********************\n";
	cout << "******************************************************\n";

}
//int main()
//{
//	Books txr;
//	txr.dqgs = 0;
//	int a = 0;
//	do
//	{
//		dabt();
//		cout << "��������Ҫִ�е����";
//		cin >> a;
//		switch (a)
//		{
//		case 1:AddContacts(&txr);
//		CASE 2:ShowContacts(&txr);
//		CASE 3:DeleteContacts(&txr);
//		CASE 4:SeekContacts(&txr);
//		CASE 5:ReviseContacts(&txr);
//		CASE 6:EmptyContacts(&txr);
//		default:
//		cout << "�����������������";
//			break;
//		}
//	} while (a);
//
//	return 0;
//}