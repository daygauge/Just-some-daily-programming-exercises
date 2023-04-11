#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <deque>
#include <numeric>
#include <fstream>
using namespace std;



class selecthand
{
public:
	selecthand(string name,double divide):m_name(name),m_divide(divide){}
	string m_name;
	double m_divide;
};

class speech
{
public:
	//����
	speech();
	//����
	~speech();
	void initia();
	//��ʼ��ѡ��
	void InitialSelect();
	//��������
	void assemblecs();

	//����
	void title();
	//ϴ��
	void randomls();
	//����
	void divGroup();
	//��ʾ��������
	void showScore();
	//��������ļ�
	void saveRecrd();
	//�鿴��¼
	void loadRecord();
	map<int, vector<string>> mload;//��ʱ������¼����
	void printindxs();//��¼��ӡ
	void clearls();//�������

	//����
	void grade();
	void printgrade();

	int  fallDue;
	vector<int> v1;//��1�� 12��
	vector<int> v2;//��2�� 6��
	vector<int> v3;//��3�� 3��
	map<int, selecthand> m;//ѡ��
};

