#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

class Pro;
int zmls_ina = 0;
vector<Pro> lsa;
class Pro
{
public:
	Pro(int a = 0, int b = 0, bool c = true) :m_ina(a), m_stor(b){}
	int m_ina;//ԤԼ����
	int m_stor;//�����������
};
bool forlspr(Pro& ls1, Pro& ls2)
{
	return &ls1 == &ls2;
}
void lsreyirsn(Pro& ls)
{
	if (ls.m_ina == ls.m_stor)//�黹��Դ
	{
		zmls_ina += ls.m_ina;
		cout << "�黹��Դ" << endl;
	}
	return;
}
void applsf(Pro& ls, int storls)//����
{
	int a = 0;
		if (storls > zmls_ina)
		{
			cout << "����ʧ��,��Դ����" << endl;//�޷���������while(zmls_ina < ls.m_ina - ls.m_stor)
			return;
		}
		if (storls + ls.m_stor < ls.m_ina)//�������� < ԤԼ����
		{
			for (int i = 0; i < lsa.size(); i++)
				if (zmls_ina - storls < lsa[i].m_ina - lsa[i].m_stor)//�Ƿ����벻��ȫ״̬
				{
					a++;
				}
			if (a >= (lsa.size() - 1))
			{
				cout << "����ʧ�ܣ�����벻��ȫ״̬" << endl;
				return;
			}
			else
			{
				ls.m_stor += storls;
				zmls_ina -= storls;
				cout << "����ɹ�" << endl;
				lsreyirsn(ls);
			}
		}
		else if (storls + ls.m_stor == ls.m_ina)
		{
			ls.m_stor += storls;
			zmls_ina -= storls;
			cout << "����ɹ�" << endl;
			lsreyirsn(ls);
		}
		else
			cout << "����ʧ��" << endl;
	    return;
}
void test01()
{
	Pro a1(5);
	Pro a2(4);
	Pro a3(6);
	Pro a4(8);
	lsa.push_back(a1);
	lsa.push_back(a2);
	lsa.push_back(a3);
	lsa.push_back(a4);
	
	zmls_ina = 10;
	applsf(lsa[0], 2);
	applsf(lsa[1], 1);
	applsf(lsa[2], 3);
	applsf(lsa[0], 3);
	applsf(lsa[3], 2);

}
int main()
{
	//test01();
	vector<int> v = { 0, 1, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	Solution ls;
	vector<double> vdls = ls.sampleStats(v);
	for (int i = 0; i < vdls.size(); i++)
	{
		cout << vdls[i] << "  ";
	}
	return 0;

}