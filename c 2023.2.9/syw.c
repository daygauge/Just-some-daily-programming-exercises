#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

void cshua(sywbbxz* sywbb, sywzb* zb)
{
	sywbb->sywji = (syw*)calloc(CSGS, sizeof(syw));
	if (sywbb->sywji != NULL)
	{
		sywbb->sfkp = CSGS;
		sywbb->gs = 0;
		jiazwj(sywbb,zb);
		return;
	}
	perror("�ڴ治��");
}
void jiazwj(sywbbxz* sywbb, sywzb* zb)
{
	FILE* jiazd = fopen("sywbaoc.gfse", "r");
	if (jiazd == NULL)
	{
		perror("jiazwjs");
		return;
	}
	syw wj = { 0 };
	while (fwrite(&wj, sizeof(syw), 1, jiazd))
	{
		kuor(sywbb);
		sywbb->sywji[sywbb->gs] = wj;
		sywbb->gs++;
	}
	fclose(jiazd);
	jiazd = NULL;
}
void baocuen(sywbbxz* sywbb, sywzb* zb)
{
	FILE* baoc = fopen("sywbaoc.gfse", "w");
	if (baoc == NULL)
	{
		perror("baocuens");
		return;
	}
	for (int i = 0; i < sywbb->gs; i++)
		fwrite(sywbb->sywji+i, sizeof(syw), 1, baoc);
	fclose(baoc);
	baoc = NULL;
}
void chakanbeibao(sywbbxz* sywbb)
{
	printf("%-10s %-10s %-30s \n", "ʥ��������", "��ǰ�ȼ�", "����");
	for (int i = 0; i < sywbb->gs; i++)
	{
		printf("%-10s %-10d %.2f  %.2f  %.2f  %.2f",sywbb->sywji[i].sywmz,sywbb->sywji[i].sywdj,
			sywbb->sywji[i].sywsx[0],
			sywbb->sywji[i].sywsx[1],
			sywbb->sywji[i].sywsx[2],
			sywbb->sywji[i].sywsx[3]);
		printf("\n");
	}
}
void cshuamb(sywbbxz* sywbb)
{
	for (int i = 0; i < SYWSX; i++)
	{
		int a = (rand() % 6) + 1;
		switch (a)
		{
		case 1:
			sywbb->sywji[sywbb->gs].sywsx[i] = 3.9f;
			break;
		case 2:
			sywbb->sywji[sywbb->gs].sywsx[i] = 7.8f;
			break;
		case 3:
			sywbb->sywji[sywbb->gs].sywsx[i] = 5.4f;
			break;
		case 4:
			sywbb->sywji[sywbb->gs].sywsx[i] = 2.3f;
			break;
		case 5:
			sywbb->sywji[sywbb->gs].sywsx[i] = 1.1f;
			break;
		case 6:
			sywbb->sywji[sywbb->gs].sywsx[i] = 10.1f;
			break;
		}
	}
}
int kuor(sywbbxz* sywbb)
{
	if (sywbb->sfkp == sywbb->gs)
	{
		syw* kr = realloc(sywbb->sywji, sywbb->sfkp + FL);
		if (kr != NULL)
		{
			printf("�ڴ����ݳɹ�\n");
			sywbb->sfkp += FL;
			return 1;
		}
		perror("�ڴ�����ʧ��");
		return 0;
	}
	return 1;
}
void xzbt()
{
	printf("***************************************\n");
	printf("****   1.����   2.ƽ��  3.����    ****\n");
	printf("****   4.����   5.ħŮ  6.�ɻ�    ****\n");
	printf("****   7.ȾѪ   8.����  9.ǧ��    ****\n");
	printf("****  10.��Ե  11.��Ⱦ 12.����    ****\n");
	printf("****            0.�˳�            ****\n");
	printf("**************************************\n");
}

void diaoy(sywbbxz* sywbb , char* ap)
{
	if (kuor(sywbb))
	{
		strcpy(sywbb->sywji[sywbb->gs].sywmz,ap);
		sywbb->sywji[sywbb->gs].sywdj = 1;
		cshuamb(sywbb);
		sywbb->gs++;
		printf("�Ѵ��뱳��\n");
	}
	else
		printf("�����ڴ治��\n");
}
void huoqusyw(sywbbxz* sywbb)
{
	int a = 0;
	xzbt();
	do
	{
		printf("ѡ����Ҫ��ȡ��ʥ����\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			diaoy(sywbb, "����");
			break;
		case 2:
			diaoy(sywbb, "ƽ��");
			break;
		case 3:
			diaoy(sywbb, "����");
			break;
		case 4:
			diaoy(sywbb, "����");
			break;
		case 5:
			diaoy(sywbb, "ħŮ");
			break;
		case 6:
			diaoy(sywbb, "�ɻ�");
			break;
		case 7:
			diaoy(sywbb, "ȾѪ");
			break;
		case 8:
			diaoy(sywbb, "����");
			break;
		case 9:
			diaoy(sywbb, "ǧ��");
			break;
		case 10:
			diaoy(sywbb, "��Ե");
			break;
		case 11:
			diaoy(sywbb, "��Ⱦ");
			break;
		case 12:
			diaoy(sywbb, "����");

			break;
		case 0:
			break;
		default:
			printf("ѡ�����,������ѡ��");
			break;
		}

	} while (a);
}

void shenyiwusj(sywbbxz* sywbb)
{
	int a = 1;
	chakanbeibao(sywbb);
	while (a)
	{
		printf("��ѡ����Ҫ������ʥ�������(�˳�������0)\n");
		scanf("%d", &a);
		int b = a - 1;
		if (a <= sywbb->gs + 1 && a > 0)
		{
			if (sywbb->sywji[b].sywdj != 20)
			{
				
				sywbb->sywji[b].sywdj++;
				printf("�����ɹ�,��ǰ�ȼ� %d \n", sywbb->sywji[b].sywdj);
			}
			else
			{
				printf("��ʥ����ȼ��Ѵ�����\n");
			}
			
		}
		
	}
}
void zbaa(sywbbxz* sywbb)
{
	printf("***********************\n");
	printf("****  1.��   2.��  ****\n");
	printf("****  3.ɳ   4.��  ****\n");
	printf("****  5.ͷ   0.�˳�   **\n");
	printf("**********************\n");
}
void zuangbeisyw(sywbbxz* sywbb, sywzb* zb)
{
	int a = 0, b = 0;
	float sxlb[SYWSX] = { 0 };
	do
	{
		printf("��ǰ�������\n");
		for (int i = 0; i < SYWSX; i++)
		{
			if (i == 0)
				printf("1����� 2����� 3ɳ��� 4����� 5ͷ��� \n");
			printf("%.2f   %.2f   %.2f   %.2f   %.2f  \n", zb->hua[i], zb->ymao[i], zb->shalo[i], zb->beiz[i], zb->to[i]);
		}
		zbaa(sywbb);
		chakanbeibao(sywbb);
		printf("��ѡ����Ҫ(װ��/�滻)��ʥ�����Լ�λ��\n");
		printf("��ʽ��װ����ʥ������� װ��λ��\n");
		scanf("%d %d", &a, &b);
		if (a <= sywbb->gs && (b <= 5 || b >= 1))
		{
			sxlb[0] = sywbb->sywji[a].sywsx[0];
			sxlb[1] = sywbb->sywji[a].sywsx[1];
			sxlb[2] = sywbb->sywji[a].sywsx[2];
			sxlb[3] = sywbb->sywji[a].sywsx[3];
			printf("װ���ɹ�");
			switch (b)
			{
			case 1:
				zb->hua[0] = sxlb[0];
				zb->hua[1] = sxlb[1];
				zb->hua[2] = sxlb[2];
				zb->hua[3] = sxlb[3];
				break;
			case 2:
				zb->ymao[0] = sxlb[0];
				zb->ymao[1] = sxlb[1];
				zb->ymao[2] = sxlb[2];
				zb->ymao[3] = sxlb[3];
				break;
			case 3:
				zb->shalo[0] = sxlb[0];
				zb->shalo[1] = sxlb[1];
				zb->shalo[2] = sxlb[2];
				zb->shalo[3] = sxlb[3];
				break;
			case 4:
				zb->beiz[0] = sxlb[0];
				zb->beiz[1] = sxlb[1];
				zb->beiz[2] = sxlb[2];
				zb->beiz[3] = sxlb[3];
				break;
			case 5:
				zb->to[0] = sxlb[0];
				zb->to[1] = sxlb[1];
				zb->to[2] = sxlb[2];
				zb->to[3] = sxlb[3];
				break;
			default:
				break;
			}
		}
	} while (a);
}

