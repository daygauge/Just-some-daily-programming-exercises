#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"


//�鿴ʥ���ﱳ��
//�鿴����װ��ʥ����
//��������ʥ����
//��ȡʥ����
//�����ļ�
//�鿴��ǰװ��ʥ����



void biaot()
{
	printf("*********************************************\n");
	printf("****  1.�鿴ʥ���ﱳ��   2.�鿴����װ��  ****\n");
	printf("****  3.��������ʥ����   4.��ȡʥ����    ****\n");
	printf("****             0.�˳�������            ****\n");
	printf("*********************************************\n");
}

enum MyEnum
{
	BCTC,
	BEIB,
	ZBEI,
	SHENJI,
	CHAKAN,
};
int main()
{
	sywbbxz sywbbb;
	sywzb zb = { 0 };
	int a = 0;
	cshua(&sywbbb,&zb);
	do
	{
		biaot();
		scanf("%d", &a);
		switch (a)
		{
		case BEIB://�鿴ʥ���ﱳ��
			chakanbeibao(&sywbbb);
			break;
		case ZBEI://����װ��
			zuangbeisyw(&sywbbb,&zb);
			break;
		case SHENJI://��������ʥ����
			shenyiwusj(&sywbbb);
			break;
		case CHAKAN://��ȡʥ����
			huoqusyw(&sywbbb);
			break;
		case BCTC://�˳�������
			baocuen(&sywbbb,&zb);
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (a);
}