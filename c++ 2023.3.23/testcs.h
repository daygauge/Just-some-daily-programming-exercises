#pragma once
using namespace std;
#include <iostream>
#include <fstream>

class staffandworkers;
class menu
{
public:
	menu();
	~menu();
	int ofpeoples;
	staffandworkers** s_staffandworkers;
	//����
	void menus();
	//���ְ��
	void add();
	//���浱ǰ�ļ�ְ������
	void WriteF();
	//ͳ������
	int NOP();
	//��ѯ�ļ�����
	void FileM();
	//��ʼ��ְ��
	void LnitEmp();
	//��ʾְ����Ϣ
	void DisplayInformation();
	//ɾ��ְ��
	void DeleteEmployee();

	bool cs();
	//����ְ��
	void FindEmployees();
	//�޸�ְ��
	void xg();
	//���ձ������
	void paixu();
	//��������ĵ�
	void delWD();
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

class handle :public staffandworkers//����
{
public:
	handle(int id, string name, int deptid);
	virtual void showstaff();//��ʾ������Ϣ
	virtual string post();//��ȡ��λ

};

class boss :public staffandworkers//�ܲ�
{
public:
	boss(int id, string name, int deptid);
	virtual void showstaff();//��ʾ������Ϣ
	virtual string post();//��ȡ��λ
};

