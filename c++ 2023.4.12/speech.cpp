#define _CRT_SECURE_NO_WARNINGS 1
#include "speech.h"


speech::speech()
{
	this->m.clear();
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->indxs = 1;

	this->isfile = true;//Ĭ���ļ�Ϊ��
	this->readfile();//���ؼ�¼
}
speech::~speech()
{

}
void speech::title()
{
	cout << "*****************************" << endl;
	cout << "*****  1.��ʼ�ݽ�����  ******" << endl;
	cout << "*****  2.�鿴�����¼  ******" << endl;
	cout << "*****  3.��ձ�����¼  ******" << endl;
	cout << "*****  0.�˳�          ******" << endl;
	cout << "*****************************" << endl;

}
void speech::inicsh()
{
	string namels = "QWERTYUIOPAS";
	
	for (int i = 0; i < namels.size(); i++)
	{
		//��ʼ��ѡ����
		int dfls = 10001 + i;
		string namels1 = "ѡ��";
		namels1 += namels[i];
		selecthand ls;
		ls.m_name = namels1;
		ls.m_score = 0;

		//д��ѡ����
		this->v1.push_back(dfls);
		this->m.insert(make_pair(dfls, ls));
	}
}
void speech::drawlots()
{
	cout << "��" << this->indxs << "��ѡ�ֿ�ʼ��ǩ" << endl;
	cout << "��ǩ�������" << endl;
	cout << "--------------------------------" << endl;
	if (indxs == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------" << endl;
	system("pause");
}
void speech::match()
{
	cout << "-----------��" << this->indxs << "�ֱ�����ʽ��ʼ------------" << endl;
	cout << "��ί���ڴ��" << endl;

	map<double, int,greater<double>> ls;//��ʱѡ������,(����,���)
	vector<int> v;//��ʱ��������
	if (this->indxs == 1)
	{
		v = this->v1;
	}
	else
	{
		v = this->v2;
	}

	int mls = 0;//��¼��ǰѡ��λ��
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		mls++;

		//��ȡƽ����
		deque<double> vs;
		for (int i = 0; i < 10; i++)
		{
			vs.push_back((rand() % 410 + 600) / 10.f);
		}
		sort(vs.begin(), vs.end());
		vs.pop_back();
		vs.pop_front();
		double n = accumulate(vs.begin(), vs.end(), 0);

		//д��ƽ����
		ls.insert(make_pair(n / vs.size(), *it));//��ʱ����
		this->m[*it].m_score = n / vs.size();//����m

		if (mls % 6 == 0)//6��һ��
		{
			//��ӡѡ��
			cout << "��" << mls / 6 << "С��" << endl;
			for (map<double, int>::iterator lsm = ls.begin(); lsm != ls.end(); lsm++)
			{
				cout << lsm->second
					<< " ����:" << this->m[lsm->second].m_name
					<< " �÷�:" << lsm->first << endl;
			}
			cout << endl;

			//д��ǰ��
			map<double, int>::iterator lsm = ls.begin();
			for (int i = 0 ; i < 3 ; i++)
			{
				if (this->indxs == 1)
				{
					this->v2.push_back(lsm->second);
				}
				else
				{
					this->v3.push_back(lsm->second);
				}
				
				lsm++;
			}
			ls.clear();
		}
	}
	cout << "-----------------------------------------" << endl;
	system("pause");
}

void speech::riseinrank()
{
	cout << "-----------------��" << this->indxs << "�ֽ���ѡ��Ϊ-----------------" << endl;
	if (this->indxs == 1)
	{
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)
		{
			cout << *it
				<< " ����:" << this->m[*it].m_name
				<< " �÷�:" << this->m[*it].m_score 
				<< endl;
		}
	}
	else
	{
		for (vector<int>::iterator it = this->v3.begin(); it != this->v3.end(); it++)
		{
			cout << *it
				<< " ����:" << this->m[*it].m_name
				<< " �÷�:" << this->m[*it].m_score
				<< endl;
		}
	}
	system("pause");
	system("cls");
}

void speech::savefile()
{
	ofstream ofs("speech.csv", ios::app);

	ofs << this->v3[0] << "," << this->m[this->v3[0]].m_score << ","
		<< this->v3[1] << "," << this->m[this->v3[1]].m_score << ","
		<< this->v3[2] << "," << this->m[this->v3[2]].m_score << "," << endl;
	ofs.close();
}
void speech::readfile()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())//�ж��ļ��Ƿ񲻴���
	{
		this->isfile = true;
		return;
	}

	char ls;
	ifs >> ls;
	if (ifs.eof())//�ж��ļ��Ƿ�Ϊ��
	{
		this->isfile = true;
		return;
	}

	//д���ļ���this->mfile����
	this->isfile = false;
	ifs.putback(ls);
	string filels;
	int inx = 0;
	while (ifs >> filels)
	{
		vector<string> v;
		int n1 = 0;
		int n2 = -1;
		while (true)
		{

			n2 = filels.find(",", n1);
			if (n2 == -1)
			{
				break;
			}
			string ls = filels.substr(n1, n2 - n1);
			v.push_back(ls);
			n1 = n2 + 1;
		}
		this->mfile.insert(make_pair(inx, v));
		inx++;
	}
	ifs.close();
}
void speech::filerecord()
{
	if (this->isfile)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		for (map<int, vector<string>>::iterator it = this->mfile.begin(); it != this->mfile.end(); it++)
		{
			cout << "��" << it->first+1 << "��"
				<< " �ھ����:" << it->second[0] << " ����:" << it->second[1]
				<< " �Ǿ����:" << it->second[2] << " ����:" << it->second[3]
				<< " �������:" << it->second[4] << " ����:" << it->second[5] << endl;
		}

	}
}
void speech::empty()
{
	this->isfile = true;
	this->mfile.clear();
	ofstream ofs("speech.csv", ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;

}