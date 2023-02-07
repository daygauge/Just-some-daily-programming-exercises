#define _CRT_SECURE_NO_WARNINGS 1;
#include "text.h"


void baochunweijian(hj* txrs)
{
	FILE* a = fopen("test.asb", "w");
	if (a == NULL)
	{
		perror("fopen");
		return;
	}
	fwrite(txrs->ji, sizeof(hej), txrs->su, a);
	printf("�ѱ��浱ǰ��ϵ����Ϣ");
}

void jiazaiwenjian(hj* txrs)
{
	FILE* a = fopen("test.asb", "r");
	if (a == NULL)
	{
		perror("fopen");
		return;
	}
	hej sz = { 0 };
	while (fread(&sz,sizeof(hej),1,a))
	{
		shifssukr(txrs);
		txrs->ji[txrs->su] = sz;
		txrs->su++;
	}
	fclose(a);
	a = NULL;
}
void chushihua(hj* txrs)
{
	txrs->ji = (hej*)calloc(CSNC ,sizeof(hej));
	if (txrs->ji == NULL)
	{
		perror("�ڴ治��,�޷�����ͨѶ¼�ռ�\n");
		return;
	}
	txrs->su = 0;
	txrs->jic = CSNC;

	jiazaiwenjian(txrs);
}

void shifssukr(hj* txrt)
{
	if (txrt->su == txrt->jic)
	{
		hej* lings = (hej*)realloc(txrt->ji, (txrt->jic + JA) * sizeof(hej));
		if (lings == NULL)
		{
			printf("����ʧ��\n");
			return ;
		}
		txrt->ji = lings;
		txrt->jic += JA;
		printf("���ݳɹ�\n");
	}
}
void tianjiahs(hj* txrs)
{
	shifssukr(txrs);

	printf("����������:");
	scanf("%s",txrs->ji[txrs->su].xmin);
	printf("�������Ա�:");
	scanf("%s", txrs->ji[txrs->su].xinb);
	printf("����������:");
	scanf("%d",&(txrs->ji[txrs->su].nianling));
	printf("������绰:");
	scanf("%s", txrs->ji[txrs->su].dianhua);
	printf("�������ַ:");
	scanf("%s", txrs->ji[txrs->su].dizhi);

	txrs->su++;
	printf("��ӳɹ�\n");

}



void ckanlbiaos(hj* txrs)
{
	printf("%-10s %-5s %-5s %-20s %-20s\n", "����","�Ա�", "����", "�绰", "��ַ");
	for (int i = 0;i < txrs->su ;i++)
	{
		printf("%-10s %-5s %-5d %-20s %-20s\n", txrs->ji[i].xmin, 
			                                    txrs->ji[i].xinb,
			                                    txrs->ji[i].nianling,
			                                    txrs->ji[i].dianhua,
			                                    txrs->ji[i].dizhi);
	}
}

void chazaos(hj* txrs)
{
	char s[XM]={0};
		printf("��������ϵ���������в���:\n");
		scanf("%s", s);
		for (int i = 0;i < txrs->su;i++)
		{
			if (strstr(txrs->ji[i].xmin, s))
			{
				printf("%-10s %-5s %-5s %-20s %-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
				printf("%-10s %-5s %-5d %-20s %-20s\n", txrs->ji[i].xmin,
					txrs->ji[i].xinb,
					txrs->ji[i].nianling,
					txrs->ji[i].dianhua,
					txrs->ji[i].dizhi);
				return ;
			}
		}
		printf("�Ҳ�����ϵ��,��ȷ����ϵ���Ƿ���ȷ\n");
	return ;
}

void xgailxr(hj* txrs)
{
	char s[XM] = { 0 };
	printf("��������Ҫ�޸ĵ���ϵ������:\n");
	scanf("%s", s);
	for (int i = 0;i < txrs->su;i++)
	{
		if (strstr(txrs->ji[i].xmin, s))
		{
			printf("%-10s %-5s %-5s %-20s %-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
			printf("%-10s %-5s %-5d %-20s %-20s\n", txrs->ji[i].xmin,
				                                    txrs->ji[i].xinb,
				                                    txrs->ji[i].nianling,
				                                    txrs->ji[i].dianhua,
			                                      	txrs->ji[i].dizhi);

			printf("�������޸ĺ������:\n");
			scanf("%s", txrs->ji[i].xmin);
			printf("�������Ա�:\n");
			scanf("%s", txrs->ji[i].xinb);
			printf("�������޸ĺ������:\n");
			scanf("%d", &(txrs->ji[i].nianling));
			printf("�������޸ĺ�ĵ绰:\n");
			scanf("%s", txrs->ji[i].dianhua);
			printf("�������޸ĺ�ĵ�ַ:\n");
			scanf("%s", txrs->ji[i].dizhi);
			printf("�޸ĳɹ�\n");
			return ;
		}
	}
	printf("�������ϵ�����Ʋ�����\n");
}

void shanchus(hj* txrs)
{
	char s[XM] = { 0 };
	printf("��������Ҫɾ������ϵ������:\n");
	scanf("%s", s);
	for (int i = 0;i <= TXRDX;i++)
	{
		if (strstr(txrs->ji[i].xmin, s))
		{
			for (int j = i;j <= txrs->su;j++)
			{
				txrs->ji[j] = txrs->ji[j + 1];
			}
			txrs->su--;
			printf("ɾ���ɹ�\n");
			return ;
		}
	}
	printf("ɾ��ʧ��,��ȷ���������ϵ�������Ƿ���ȷ\n");
}

int cmp(const void* s1, const void* s2)
{
	return ((hej*)s1)->nianling - ((hej*)s2)->nianling;
}

void paixulianxir(hj* txrs)
{
	qsort(txrs->ji, txrs->su, sizeof(txrs->ji[0]), cmp);
	ckanlbiaos(txrs);
}