#define _CRT_SECURE_NO_WARNINGS 1;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define XM 20
#define DZ 20
#define DH 20
#define TXRDX 200
#define XB 5

#define CSNC 3
#define JA 2
typedef struct zrxx
{
	char xmin[XM];
	char xinb[XB];
	int nianling;
	char dianhua[DH];
	char dizhi[DZ];

}hej;
//typedef struct txr
//{
//	hej ji[TXRDX];
//	int su;
//}hj;

typedef struct txr
{
	hej *ji;
	int jic;
	int su;
}hj;


void chushihua(hj *txrs);//��ʼ��

void tianjiahs(hj* txrs);//���

void ckanlbiaos(hj* txrs);//��ӡ�б�

int chazaos(hj* txrs);//����

void xgailxr(hj* txrs);//�޸�

void shanchus(hj* txrs);//ɾ��

void paixulianxir(hj* txrs);//����