#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#include <fstream>
void ls();

class MachineRoom
{
public:
	MachineRoom(int a, int b) :m1ls(a), m2ls(b){}
	//�����������
	int m1ls;
	int m2ls;
	map<int, int> M;
	//���,ԤԼ��Ϣ
};

class macyys
{
public:
	macyys(){}
	macyys(string date, string shi, string mac, string stuid, string name, string state = "�����") :
		mac_date(date),mac_shi(shi),mac_mac(mac),m_stuid(stuid),m_name(name),m_state(state){}
	
	string mac_date;//����
	string mac_shi;//ʱ��
	string mac_mac;//����
	string m_stuid;//ѧ��
	string m_name;//����
	string m_state;//��ǰԤԼ״̬
};
//ѧ��
class student
{
public:
	void title();
	//����
	bool login();
	//����ԤԼ
	void applyformac();
	//�鿴�ҵ�ԤԼ
	void viewmac();
	//�鿴����ԤԼ
	void viewmacs();
	//ȡ��ԤԼ
	void cancellmac();
	void renew();//����ԤԼ�ļ�����


	string test1;//ѧ��
	string test2;//����
};

//��ʦ
class teacher
{
public:
	void title();
	//����
	bool login();
    //�鿴����ԤԼ
	void ViewApp();
	//���ԤԼ
	void toExamineacs();
	void renew();//����ԤԼ�ļ�����
};

//����Ա
class manage
{
public:
	manage();
	void title();

	//����
	bool login();
	//����˺�
	void addna();
	//�鿴�˺�
	void viewna();
	//�鿴����
	void viewmac();
	//���ԤԼ
	void emptymac();
};

