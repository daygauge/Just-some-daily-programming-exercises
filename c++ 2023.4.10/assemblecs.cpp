#define _CRT_SECURE_NO_WARNINGS 1
#include "speech.h"
//void printmap(map<int, selecthand>::iterator ls)
//{
//	cout << "ѡ�ֱ��:" << ls->first << " " << ls->second.m_name << " ����:" << ls->second.m_divide << endl;
//}
//void speech::operator()(map<int, selecthand>::iterator ls)
//{
//	cout << "ѡ�ֱ��:" << ls->first << " " << ls->second.m_name << " ����:" << ls->second.m_divide << endl;
//}
// 
// 
// 
void speech::assemblecs()
{
	randomls();//��ǩ
	divGroup();//��ʼ����
	showScore();//��ʾ����ѡ��
	this->fallDue++;//������������
	randomls();
	divGroup();
	showScore();

	saveRecrd();//�����ļ�
}
//void speech::assemblecs()
//{
//	cout << "-----------��" << this->fallDue << "���ݽ�������ʽ��ʼ------------" << endl;
//	////��ʼ��ѡ��
//	//InitialSelect();
//	//cout << "����Ϊ����ѡ��:" << endl;
//	//for (map<int, selecthand>::iterator it1 = this->m.begin(); it1 != this->m.end(); it1++)
//	//{
//	//	cout << "ѡ�ֱ��;" << it1->first <<" " << it1->second.m_name<< endl;
//	//}
//	
//	//ϴ��
//	//random_shuffle(v1.begin(), v1.end());
//	//cout << "�����������..." << endl;
//	//cin.ignore();
//	randomls();
//
//	//����
//	//cout << "��������Ϊ����С����У�ÿ��С��Ϊ6��ѡ��:" << endl;
//	//cout << "���������Ա���£�..." << endl;
//	//divGroup();
//	//cout << "�����������..." << endl;
//	//cin.ignore();
//
//	////��ί����
//	//grade();
//	//cout << "��ǰѡ�ַ�������:" << endl;
//	//printgrade();
//	//��ȡǰ�������ڶ���
//
//	//ϴ��
//
//	//��ί����
//
//	//��ȡǰ��
//}