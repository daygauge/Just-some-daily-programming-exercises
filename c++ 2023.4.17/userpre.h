#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#include <fstream>


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

	string test1;
	string test2;
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