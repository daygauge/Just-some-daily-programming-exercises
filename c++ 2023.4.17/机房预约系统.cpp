#define _CRT_SECURE_NO_WARNINGS 1
#include "userpre.h"
#define CASE break;case
#include "fileclass.h"
vector<string> stuv1;//ѧ���˺Ŵ洢����
vector<string> teav2;//��ʦ�˺Ŵ洢����
vector<MachineRoom*> m;//������Ϣ
multimap<string ,macyys> macyy;//����ԤԼ��Ϣ

void jiaz();//���س�ʼ��Ϣ

void students(student * ls)//ѧ��
{
	if (!ls->login())
		return;

	int a = 0;
	do
	{
		ls->title();
		cin >> a;
		switch (a)
		{
		case 1:
			ls->applyformac();
			jiaz();
			CASE 2 :
			ls->viewmac();
			CASE 3 :
			ls->viewmacs();
			CASE 4:
			ls->cancellmac();
			jiaz();
			CASE 0:
			system("cls");
			return;
			break;
		default:
			system("cls");
			break;
		}
	} while (a);
}

void teachers(teacher* ls)//��ʦ
{
	if (!ls->login())
		return;

	int a = 0;
	do
	{
		ls->title();
		cin >> a;
		switch (a)
		{
		case 1:
			ls->ViewApp();
		CASE 2 :
			ls->toExamineacs();
			jiaz();
		CASE 0:
		    system("cls");
			return;
			break;
		default:
			system("cls");
			break;
		}
		
	} while (a);
}

void manges(manage* ls)//����Ա
{
	if (!ls->login())
		return;

	int a = 0;
	do
	{
		ls->title();
		cin >> a;
		switch (a)
		{
		case 1:
			ls->addna();
		CASE 2 :
			ls->viewna();
		CASE 3 :
		 	ls->viewmac();
		CASE 4:
			ls->emptymac();
			jiaz();
		CASE 0:
		    system("cls");
			return;
			break;
		default:
			system("cls");
			break;
		}
	} while (a);
}
void titlestest()
{
	cout << "-----------------------" << endl;
	cout << "��������..." << endl;
	cout << "  1.ѧ��" << endl;
	cout << "  2.��ʦ" << endl;
	cout << "  3.����Ա" << endl;
	cout << "-----------------------" << endl;
}
void jiaz()//���س�ʼ��Ϣ
{
	//�����Ϣ
	stuv1.clear();
	teav2.clear();
	m.clear();
	macyy.clear();

	//����ѧ����ʦ�˺�
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

	//���ػ�����Ϣ
	 m.push_back(new MachineRoom(1, 50));
     m.push_back(new MachineRoom(2, 100));

	 //����ԤԼ��Ϣ
	 fstream fst(DATE, ios::in);
	 //�洢ԤԼ��Ϣ
	 string datels;
	 string shils;
	 string macls;
	 string stuidls;
	 string namels;

	 string zt;
	 //д��ԤԼ��Ϣ
	 while (fst >> datels && fst >> shils && fst >> macls && fst >> stuidls && fst >> namels && fst >> zt)
	 {
		 macyys maclsa(datels, shils, macls, stuidls, namels, zt);
		 macyy.insert(make_pair(namels, maclsa));

		 datels.clear();
		 shils.clear();
		 macls.clear();
		 stuidls.clear();
		 namels.clear();
		 zt.clear();
	 }
	 fst.close();

}
int main()
{
	jiaz();
	int a = 0;
	do
	{
		student ls;
		teacher ls1;
		manage ls2;
		titlestest();
		cin >> a;
		switch (a)
		{
		case 1:
			students(&ls);
			CASE 2 :
			teachers(&ls1);
			CASE 3 :
			manges(&ls2);
			break;
		default:
			break;
		}
	} while (a);
	return 0;
}