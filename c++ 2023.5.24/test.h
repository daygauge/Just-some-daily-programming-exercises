#pragma once
#include <iostream>
using namespace std;
#include <queue>
#include <vector>



class ls
{
public:
	ls(int m_sls = 0) :m_s(m_sls){}
public:
	void m_wait();
	void m_signal();
	int m_s;
};
void ls::m_wait()
{
	while (m_s <= 0)
		cout << "��Դ��ռ��" << endl;
	this->m_s--;
}
void ls::m_signal()
{
	this->m_s++;
}

class ls01
{
public:
	ls01(int m_sls = 0) :m_s1(m_sls) {}
public:
	void m_wait1();
	void m_signal1();
	queue<int> m_q;
	int m_s1;
};
void ls01::m_wait1()//v����,��ȡ�����ٽ�������
{
	if (this->m_s1 <= 0)
		m_q.push(1);
	this->m_s1--;
}
void ls01::m_signal1()//p����,�黹�ٽ�������
{
	this->m_s1++;
}