#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MICSS 20
#define SYWSX 4
#define CSGS 3
#define FL 2
typedef struct sywbeibao
{

	char sywmz[MICSS];//����
	int sywdj;//�ȼ�
	float sywsx[SYWSX];//����
}syw;
typedef struct sywb
{
	syw* sywji;
	int sfkp;
	int gs;
}sywbbxz;

typedef struct dqrwzt
{
	float hua[SYWSX];
	float ymao[SYWSX];
	float shalo[SYWSX];
	float beiz[SYWSX];
	float to[SYWSX];
}sywzb;


void cshua(sywbbxz* sywbb, sywzb* zb);//��ʼ��

void chakanbeibao(sywbbxz* sywbb);//ʥ���ﱳ��

void huoqusyw(sywbbxz* sywbb);//��ȡʥ����

void cshuamb(sywbbxz* sywbb);//��ʼ��ʥ��������;

void diaoy(sywbbxz* sywbb, char* ap);//��ʼ��ʥ����ֵ

int kuor(sywbbxz* sywbb);//�ڴ�����

void shenyiwusj(sywbbxz* sywbb);//ʥ��������

void zuangbeisyw(sywbbxz* sywbb, sywzb* zb);//װ��ʥ����
void zbaa(sywbbxz* sywbb);

void baocuen(sywbbxz* sywbb, sywzb* zb);//����
void jiazwj(sywbbxz* sywbb, sywzb* zb);//�����ļ�