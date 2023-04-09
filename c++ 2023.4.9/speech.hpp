#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>
#define FSTXS "speechcontest.csv"
class selecthand
{
public:
	selecthand():m_number(0), m_name("0"), m_scmre(0) {}
	selecthand(int number,string name,int scmer):m_number(number),m_name(name),m_scmre(scmer){}
	//ѡ�ֺ�
	int m_number;
	//ѡ����
	string m_name;
	//ѡ�ַ�
	double m_scmre;
};
bool prinpaixu(selecthand a1,selecthand a2)
{
	return a1.m_scmre > a2.m_scmre;
}
void printsele(selecthand a)
{
	cout << a.m_name << " ѡ�ֱ��: " << a.m_number << endl;
}
void printselef(selecthand a)
{
	cout << a.m_name << " ѡ�ֱ��: " << a.m_number << " ѡ�ַ���: " << a.m_scmre << endl;
}
class lsdx
{
public:
	selecthand operator()(selecthand a)
	{
		return a;
	}
};

class speech
{
public:

	speech();
	~speech();
	void kickoff();

	void pradd();//prder++
	//��ӡ����
	void title();

	//�鿴֮ǰ��¼
	void takenotes();

	//��ʼ������ѡ����Ϣ
	void initial(vector<selecthand> &v);

	//��ί���
	void grade(deque<double>& ls, vector<selecthand>::iterator &a);

	//��ǰ��ѡ��
	void equalorder();

	//�����ļ�
	void Includeinfile();

	//����ļ�
	void emptys();


	int prder;
	selecthand champion;//�ھ�
	selecthand secondplace;//�Ǿ�
	selecthand thirdwinnerincontest;//����

};
void speech::emptys()
{
	ofstream ofs;
	ofs.open(FSTXS, ios::out);
	ofs.close();
	ofs.open("test.txt", ios::out);
	int a = 0;
	ofs << a;
}

void speech::takenotes()
{
	ifstream ifs;
	ifs.open(FSTXS, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�Ϊ��" << endl;
		return;
	}

	int testls = 1;
	//����
	string js;
	//ѡ�ֺ�
	int m_numbers;
	//ѡ����
	string m_names;
	//ѡ�ַ�
	double m_scmres;
	string lss;
	while ( ifs>>js && ifs >> m_names && ifs >> m_numbers && ifs >> m_scmres && ifs >> lss)
	{
		cout << js << endl;
		cout << m_names << " ���:" << m_numbers << " �ɼ�:" << m_scmres << " "<< lss << endl;
		if (ifs >> m_names && ifs >> m_numbers && ifs >> m_scmres && ifs >> lss)
		{
			cout << m_names << " ���:" << m_numbers << " �ɼ�:" << m_scmres << " " << lss << endl;
			if (ifs >> m_names && ifs >> m_numbers && ifs >> m_scmres && ifs >> lss)
			{
				cout << m_names << " ���:" << m_numbers << " �ɼ�:" << m_scmres << " " << lss << endl;
				testls = 0;
			}
		}
	}
	if (testls)
	{
		cout << "�ļ�Ϊ��" << endl;
		return;
	}
}
void speech::title()
{
	cout << "****************************" << endl;
	cout << "****  ��ӭ�μ��ݽ�����  *****" << endl;
	cout << "*****  1.��ʼ�ݽ�����  *****" << endl;
	cout << "*****  2.�鿴������¼  *****" << endl;
	cout << "*****  3.��ձ�����¼  *****" << endl;
	cout << "*****  4.�˳�������¼  *****" << endl;
	cout << "****************************" << endl;
}
speech::speech()
{
	srand((unsigned int)time(NULL));
	this->prder = 0;
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		this->prder = 0;
	}
	else
	{
		int ls = ifs.get() - 48;
		this->prder = ls;
	}
	ifs.close();
}
speech::~speech()
{
	pradd();
}
void speech::pradd()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << this->prder;
	ofs.close();
}
void speech::Includeinfile()
{
	ofstream ofs;
	ofs.open(FSTXS, ios::app);
	ofs<< "��" << prder << "��" << endl;
	ofs << this->champion.m_name << " " << this->champion.m_number << " " << this->champion.m_scmre <<" �ھ� "<< endl;
	ofs << this->secondplace.m_name << " " << this->secondplace.m_number << " " << this->secondplace.m_scmre <<" �Ǿ� "<< endl;
	ofs << this->thirdwinnerincontest.m_name << " " << this->thirdwinnerincontest.m_number << " " << this->thirdwinnerincontest.m_scmre <<" ���� "<< endl;
	ofs.close();
}
void speech::equalorder()
{
	cout << endl;
	cout << "-----�ھ�-----" << endl;
	cout << this->champion.m_name << " ���:" << this->champion.m_number << " �ɼ�:" << this->champion.m_scmre << endl;
	cout << "-----�Ǿ�-----" << endl;
	cout << this->secondplace.m_name << " ���:" << this->secondplace.m_number << " �ɼ�:" << this->secondplace.m_scmre << endl;
	cout << "-----����-----" << endl;
	cout << this->thirdwinnerincontest.m_name << " ���:" << this->thirdwinnerincontest.m_number << " �ɼ�:" << this->thirdwinnerincontest.m_scmre << endl;
}
void speech::initial(vector<selecthand>& v)
{
	string namecs = "vQWERTYUIOPAS";
	for (int i = 1; i <= 12; i++)
	{
		string name = "ѡ��";
		selecthand ls(i + 10000, name + namecs[i], 0.0);
		v.push_back(ls);
	}
	random_shuffle(v.begin(), v.end());//������Ϣ;
}
void speech::grade(deque<double> &ls ,vector<selecthand>::iterator &a)
{
	for (int i = 0; i < 6; i++)//С��1���
	{
		for (int i = 0; i < 10; i++)
		{
			ls.push_back(rand() % 40 + 60.0);
		}
		//ȡƽ����
		sort(ls.begin(), ls.end());
		ls.pop_back();
		ls.pop_front();
		int fsoeef = accumulate(ls.begin(), ls.end(), 0);
		a->m_scmre = fsoeef / 8.0;
		a++;
		ls.clear();
	}
}

void speech::kickoff()
{
	//��ʼ������ѡ����Ϣ
	vector<selecthand> v;
	initial(v);//ѡ�ֳ�ʼ��

	//����
	vector<selecthand> v1;
	vector<selecthand> v2;
	vector<selecthand>::iterator it = v.begin();
	for (int i = 0; i < 12 && it!=v.end() ; i++)
	{
		if (i < 6)
			v1.push_back(*it);
		else
			v2.push_back(*it);
		it++;
	}
	cout << "Ŀǰѡ���б�" << endl;
	cout << "С��1��" << endl;
	for_each(v1.begin(), v1.end(), printsele);
	cout << "С��2��" << endl;
	for_each(v2.begin(), v2.end(), printsele);
	system("pause");

	//��ί���
	deque<double> ls;
	vector<selecthand>::iterator v1ls = v1.begin();
	grade(ls, v1ls);
	vector<selecthand>::iterator v2ls = v2.begin();
	grade(ls, v2ls);

	cout << "-----------------------------------------" << endl;
	cout << "��ί��֣�" << endl;
	sort(v1.begin(), v1.end(), prinpaixu);
	sort(v2.begin(), v2.end(), prinpaixu);
	cout << endl;
	cout << "С��1��" << endl;
	for_each(v1.begin(), v1.end(), printselef);
	cout << "С��2��" << endl;
	for_each(v2.begin(), v2.end(), printselef);

	//��̭һ��ѡ��
	for (int i = 0; i < 3; i++)
	{
		v1.pop_back();
		v2.pop_back();
	}
	system("pause");
	cout << "�ѽ���һ���ѡ�֣����ڿ�ʼ�ڶ��ֱ���" << endl;
	system("pause");

	//��ʾ����ѡ��
	cout << "��ǰ�ѽ���ѡ��Ϊ:" << endl;
	v.clear();
	v.resize(v1.size() + v2.size());
	vector<selecthand>::iterator itzh = transform(v1.begin(), v1.end(), v.begin(), lsdx());
	transform(v2.begin(), v2.end(), itzh, lsdx());//�ڶ��ִ��ǰ
	for_each(v.begin(), v.end(), printsele);
	system("pause");
	cout << "-----------------------------------------" << endl;
	cout << "��ί���" << endl;
	system("pause");
	for_each(v.begin(), v.end(), printselef);//�ڶ��ִ�ֺ�
	system("pause");

	//�ھ��Ǿ���������
	sort(v.begin(), v.end(), prinpaixu);//�����ȥ��ǰ��
	v.pop_back();
	v.pop_back();
	v.pop_back();

	cout << "ǰ��������:" << endl;
	this->champion = v[0];
	this->secondplace = v[1];
	this->thirdwinnerincontest = v[2];
	equalorder();//��ӡǰ����
	this->prder++;
	pradd();//��¼��ǰ����
	Includeinfile();//�����ļ�
	system("pause");
}