#pragma once
using namespace std;
#include <iostream>

class menu
{
public:
	int ofpeoples;
	staffandworkers** s_staffandworkers;

	void menus();//����

	void add();//���ְ��



};



class staffandworkers//ְ��
{
public:
	virtual void showstaff() = 0;//��ʾ������Ϣ
	virtual string post() = 0;//��ȡ��λ

	int id = 0;
	string name;
	int deptid = 0;
};

class staff :public staffandworkers//Ա��
{
public:
	staff(int id, string name, int deptid);
	virtual void showstaff();//��ʾ������Ϣ
	virtual string post();//��ȡ��λ
};
staff::staff(int id, string name, int deptid)
{
	this->id = id;
	this->name = name;
	this->deptid = deptid;
}

void staff::showstaff()
{
	cout << "ְ�����:" << this->id
		<< "\tְ������:" << this->name
		<< "\t��λ:" << this->deptid
		<< "\t��λְ��:��ɾ����ӵ�����" << endl;
}
string staff::post()
{
	return "Ա��";
}

class handle :public staffandworkers//����
{
public:
	handle(int id, string name, int deptid);
	virtual void showstaff();//��ʾ������Ϣ
	virtual string post();//��ȡ��λ

};
handle::handle(int id, string name, int deptid)
{
	this->id = id;
	this->name = name;
	this->deptid = deptid;
}
void handle::showstaff()
{
	cout << "ְ�����:" << this->id
		<< "\tְ������:" << this->name
		<< "\t��λ:" << this->deptid
		<< "\t��λְ��:�����ܲý��ӵ�����" << endl;
}
string handle::post()
{
	return "����";
}

class boss :public staffandworkers//�ܲ�
{
public:
	boss(int id, string name, int deptid);
	virtual void showstaff();//��ʾ������Ϣ
	virtual string post();//��ȡ��λ

};
boss::boss(int id, string name, int deptid)
{
	this->id = id;
	this->name = name;
	this->deptid = deptid;
}
void boss::showstaff()
{
	cout << "ְ�����:" << this->id
		<< "\tְ������:" << this->name
		<< "\t��λ:" << this->deptid
		<< "\t��λְ��:��������" << endl;
}
string boss::post()
{
	return "�ܲ�";
}
