#define _CRT_SECURE_NO_WARNINGS 1
#include "speech.h"

void speech::speechhost()
{
	//��һ�ֱ���
	this->inicsh();//��ʼ��
	//��ǩ
	this->drawlots();
	//����
	this->match();
	//��ʾ����
	this->riseinrank();
	//�ڶ��ֱ���
	this->indxs++;
	//��ǩ
	this->drawlots();
	//����
	this->match();
	//��ʾ����
	this->riseinrank();

	//�������
	this->savefile();
	
	//��������
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m.clear();
	this->mfile.clear();
	this->indxs = 1;
	//�����������
	this->readfile();
}