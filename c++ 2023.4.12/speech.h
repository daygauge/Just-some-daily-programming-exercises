#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <random>
#include <numeric>
#include <deque>
#include <fstream>

class selecthand
{
public:
	string m_name;
	double m_score;
};

class speech
{
public:
	speech();
	~speech();
	void title();
	//��ʼ��
	void inicsh();
	//������
	void speechhost();
	//��ǩ
	void drawlots();
	//����
	void match();
	//��ʾ����
	void riseinrank();
	//�����ļ�
	void savefile();
	//��ȡ�ļ�
	void readfile();
	//��ʾ�����¼
	void filerecord();
	//����ļ�
	void empty();
	bool isfile;//�ж��ļ�
	map<int,vector<string>> mfile;//�����¼
	int indxs;//��ǰ��������
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	map <int, selecthand> m;
};