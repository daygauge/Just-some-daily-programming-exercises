#define _CRT_SECURE_NO_WARNINGS 1
#include "testcs.h"

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