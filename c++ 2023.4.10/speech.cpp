#define _CRT_SECURE_NO_WARNINGS 1
#include "speech.h"
using namespace std;

speech::speech()
{
	this->initia();//��ʼ������
	this->InitialSelect();//��ʼ��ѡ��
}
speech::~speech()
{

}
void speech::initia()
{
	this->m.clear();
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->fallDue = 1;
}
void speech::InitialSelect()//��ʼ��ѡ��
{
	string name = "ABCDEFGHLNRS";
	for (int i = 0; i < 12; i++)
	{
		string namels = "ѡ��";
		selecthand ls(namels + name[i], 0.0);

		this->v1.push_back(10001 + i);
		this->m.insert(make_pair(v1[i],ls));
	}
}
void speech::title()
{
	cout << "************************************" << endl;
	cout << "*********  �ݽ�������ͬ  **********" << endl;
	cout << "********* 1.��ʼ�ݽ����� ************" << endl;
	cout << "********* 2.�鿴������� ***********" << endl;
	cout << "********* 3.��ձ�����¼ ***********" << endl;
	cout << "********* 0.�˳��������� ***********" << endl;
	cout << "************************************" << endl;
}

void speech::randomls()//ϴ��
{
	cout << "��" << this->fallDue << "�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "------------------" << endl;
	if (this->fallDue == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it1 = this->v1.begin(); it1 != this->v1.end(); it1++)
		{
			cout << *it1 << " ";
		}
		cout << endl;
	}
    else
    {
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it2 = this->v2.begin(); it2 != this->v2.end(); it2++)
		{
			cout << *it2 << " ";
		}
		cout << endl;
	}
	cout << "------------------" << endl;
	system("pause");
	cout << endl;
}
class lsmappx
{
public:
	bool operator()(double n1, double n2) const
	{
		return n1 > n2;
	}
};
void speech::divGroup()//����.��ӡ
{
	//int a = 0;
	//int da = 1;
	//vector<int> v;
	//if (this->fallDue == 1)
	//{
	//	v = this->v1;
	//}
	//else
	//{
	//	v = this->v2;
	//}
	//for (map<int, selecthand>::iterator it = this->m.begin(); it != this->m.end(); it++)
	//{
	//	if (a % 6 == 0)
	//	{
	//		cout << endl;
	//		cout << "��"<< da <<"��ѡ��" << endl;
	//		da++;
	//	}
	//	a++;
	//	cout << "ѡ�ֱ��:" << it->first <<" "<< it->second.m_name << " �÷�" << it->second.m_divide << endl;
	//}
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	if (a % 6 == 0)
	//    {
	//	    cout << endl;
	//	    cout << "��"<< da <<"��ѡ��" << endl;
	//	    da++;
	//    }
	//	a++;
	//	map<int, selecthand>::iterator mls = this->m.find(*it);//ͨ����ֵ����
	//	cout <<"ѡ�ֱ��:" << mls->first << " " << mls->second.m_name << endl;
	//}

	cout << "--------------------��" << this->fallDue << "�ֱ�����ʽ��ʼ-------------------" << endl;

	multimap<double, int, lsmappx> mmp;//��ʱmap����
	int lsmapf = 0;
	vector<int> v;//��ʱ�������뵱ǰ����
	if (this->fallDue == 1)
	{
		v = this->v1;
	}
	else
	{
		v = this->v2;
	}
	
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)//�Ե�ǰ����ѭ��
	{
		lsmapf++;//���6��С��
		//��ί���
		deque<double> dls;
		for (int i = 0; i < 10; i++)
		{
			double douls = (rand() % 401 + 600) / 10.f;
			dls.push_back(douls);
		}

		//ȥͷȥβ
		sort(dls.begin(), dls.end(), greater<double>());
		dls.pop_back();
		dls.pop_front();

		//��ȡƽ����
		double lsf = accumulate(dls.begin(), dls.end(), 0.0);
		double f = lsf / dls.size();

		//m����ѡ����ӷ���
		//this->m[*it].m_divide = f;
		map<int, selecthand>::iterator mls = this->m.find(*it);
		mls->second.m_divide = f;

		mmp.insert(make_pair(f, *it));//��ʱmap������������ֵ

		//for (multimap<double, int, lsmappx>::iterator ls = mmp.begin(); ls != mmp.end(); ls++)
		//{
		//	cout << ls->first << " " << ls->second << endl;
		//}

		if (lsmapf % 6 == 0)//һ�μ�¼һ��
		{
			cout << "��" << lsmapf / 6 << "С������ɼ�:" << endl;

			//��ӡÿ������
			for (multimap<double, int, lsmappx>::iterator itmap = mmp.begin(); itmap != mmp.end(); itmap++)
			{
				cout << "ѡ�ֱ�ţ�" << itmap->second
					<< " ����:" << (this->m.find(itmap->second))->second .m_name
					<< " ����" << itmap->first << endl;
			}
			cout << endl;

			//��С��ǰ����¼��һ��������
			multimap<double, int, lsmappx>::iterator itmap = mmp.begin();
			for (int i = 0 ; i < 3 ;i++)
			{
				if (this->fallDue == 1)
				{
					v2.push_back(itmap->second);
				}
				else
				{
					v3.push_back(itmap->second);
				}
				itmap++;
			}
			mmp.clear();//���һ������

		}
	}
	cout << "--------------------��" << this->fallDue << "�ֱ������-------------------" << endl;
	system("pause");
}
void speech::showScore()
{
	cout << "--------------------��" << this->fallDue << "�ֽ���ѡ��-------------------" << endl;
	vector<int> v;
	if (this->fallDue == 1)
	{
		v = this->v2;
	}
	else
	{
		v = this->v3;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ��:" << *it
			<< " ����:" << (this->m.find(*it))->second.m_name
			<< " ����:" << (this->m.find(*it))->second.m_divide << endl;
	}
	system("pause");
	system("cls");
	this->title();
}
void speech::saveRecrd()
{
	ofstream ofs;
	ofs.open("speechs.csv", ios::app);
	for (vector<int>::iterator it = this->v3.begin(); it != this->v3.end(); it++)
	{
		ofs << (this->m.find(*it))->first
			<< "," << (this->m.find(*it))->second.m_divide << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "������¼�Ѿ�����,��ǰ����Ŀ¼speechs�ļ��鿴" << endl;
}
void speech::loadRecord()
{
	fstream ifs("speechs.csv", ios::in);

	//�ж��ļ��Ƿ񲻴���
	if (!ifs.is_open())
	{
		ifs.close();
		cout << "�ļ�������" << endl;
		return;
	}
	//�ж��ļ��Ƿ�Ϊ��
	char ls;//����һ���ַ������ж��Ƿ�Ϊĩβ
	ifs >> ls;
	if (ifs.eof())
	{
		ifs.close();
		cout << "�ļ�Ϊ��" << endl;
		return;
	}
	ifs.putback(ls);//����ԭ�����ַ�


}
void speech::grade()//����
{
	vector<int> v;
	if (this->fallDue == 1)
	{
		v = this->v1;
	}
	else
	{
		v = this->v2;
	}

	deque<double> f;
	for (vector<int>::iterator its = v.begin(); its != v.end(); its++)//ѭ������
	{
		for (int i = 0; i < 10; i++)
		{
			f.push_back((rand() % 401 + 600) / 10.f);
		}

		sort(f.begin(), f.end());//�����ȥͷȥβ
		f.pop_back();
		f.pop_front();

		map<int, selecthand>::iterator mls = this->m.find(*its);//ͨ����ֵ���Ҳ��������
		mls->second.m_divide = (accumulate(f.begin(), f.end(), 0.f) / f.size());
	}
}
void speech::printgrade()
{
	int a = 0;
	int da = 1;
	vector<int> v;
	if (this->fallDue == 1)
	{
		v = this->v1;
	}
	else
	{
		v = this->v2;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (a % 6 == 0)
		{
			cout << endl;
			cout << "��" << da << "��ѡ��" << endl;
			da++;
		}
		a++;
		map<int, selecthand>::iterator mls = this->m.find(*it);//ͨ����ֵ����
		cout << "ѡ�ֱ��:" << mls->first << " " << mls->second.m_name <<" ѡ�ֵ÷�:"<< mls->second.m_divide << endl;
	}
}