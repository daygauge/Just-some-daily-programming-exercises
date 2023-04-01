#pragma once
#include <stddef.h> 

template<class T>
class MyArrar
{
public:
	MyArrar(int M_cs)
	{
		//cout << "����1" << endl;
		this->M_testcssz = new T[M_cs];
		this->M_testszdax = M_cs;
		this->M_testszgs = 0;
	}
	MyArrar(MyArrar& cs)
	{
		//cout << "����2" << endl;
		this->M_testcssz = new T[cs.M_testszdax];
		this->M_testszdax = cs.M_testszdax;
		this->M_testszgs = cs.M_testszgs;
		for (int i = 0; i < cs.M_testszgs; i++)
		{
			this->M_testcssz[i] = cs.M_testcssz[i];
		}
	}
	~MyArrar()
	{
		//cout << "����" << endl;
		if (this->M_testcssz != NULL)
		{
			delete[] this->M_testcssz;
			this->M_testcssz = NULL;
			this->M_testszdax = 0;
			this->M_testszgs = 0;
		}
	}

	MyArrar& operator=(MyArrar& cs)
	{
		//cout << "operator=" << endl;
		if (this->M_testcssz != NULL)
		{
			delete[] this->M_testcssz;
			this->M_testcssz = NULL;
			this->M_testszdax = 0;
			this->M_testszgs = 0;
		}
		this->M_testcssz = new T[cs.M_testszdax];
		this->M_testszdax = cs.M_testszdax;
		this->M_testszgs = cs.M_testszgs;
		for (int i = 0; i < cs.M_testszgs; i++)
		{
			this->M_testcssz[i] = cs.M_testcssz[i];
		}
		return *this;
	}
	//β��βɾ
	void Tailinsertion(T s)
	{
		if (this->M_testszgs < this->M_testszdax)
		{
			this->M_testcssz[this->M_testszgs] = s;
			this->M_testszgs++;
		}
	}
	void Taildeletion(T s)
	{
		if (this->M_testszgs > 0)
		{
			this->M_testcssz[this->M_testszgs] = 0;
			this->M_testszgs--;
		}
		else
		{
			cout << "����Ϊ��" << endl;
		}
	}
	//�±����
	T& operator[](int a)
	{
		return this->M_testcssz[a];
	}
	//void SubscriptAccess(int a)
	//{
	//	if (a >= 0 && a < this->M_testszgs)
	//	{
	//		cout << this->M_testcssz[a] << endl;
	//	}
	//	else
	//	{
	//		cout << "�±�Խ��" << endl;
	//		return;
	//	}
	//}
	//��ȡԪ�ظ���������
	void gainnumbervolume()
	{
		cout << "Ԫ�ظ���Ϊ:" << this->M_testszgs<<endl
			<< "��ǰ�������Ϊ:" << this->M_testszdax << endl;
	}

public:
	T* M_testcssz;
	int M_testszgs;
	int M_testszdax;

};