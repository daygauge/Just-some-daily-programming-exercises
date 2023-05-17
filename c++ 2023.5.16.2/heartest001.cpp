#define _CRT_SECURE_NO_WARNINGS 1
#include "binlstest001.h"

void swap(lsdata& a, lsdata& b)
{
	lsdata t = a;
	a = b;
	b = t;
}

void hp_init(HP* ls)//��ʼ��
{
	assert(ls);
	ls->capacity = ls->size = 0;
	ls->a = NULL;
}

void hp_destory(HP* ls)//����
{
	assert(ls);
	assert(ls->a);
	free(ls->a);
	hp_init(ls);
}

void hp_up(lsdata* ls, int child)//���ϵ���
{
	assert(ls);
	int chlidls = (child - 1) / 2;//��ȡ���ڵ�
	while (child > 0)
	{
		if (ls[child] < ls[chlidls])//С�� �������ӽڵ�
		{
			swap(ls[child], ls[chlidls]);
			child = chlidls;
			chlidls = (chlidls - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void hp_push(HP* ls, lsdata a)//����
{
	assert(ls);

	if (ls->capacity == ls->size)//�����������������
	{
		int capacityls = ls->capacity == 0 ? ls->capacity = 4 : ls->capacity *= 2;
		lsdata* csl = (lsdata*)realloc(ls->a, sizeof(lsdata) * capacityls);
		if (csl == NULL)
			exit(-1);

		ls->a = csl;
		ls->capacity = capacityls;
	}
	ls->a[ls->size++] = a;
	hp_up(ls->a, ls->size - 1);
}
void hp_down(lsdata* ls, int size, int child)//���µ���
{
	assert(ls);
	int childls = 2 * child + 1;
	while (childls < size)
	{
		if (childls + 1 < size && ls[childls+1] < ls[childls])//С�� ����ҽڵ����ڵ�С�������ҽڵ��滻
		{
			childls++;
		}

		if (ls[child] > ls[childls])
		{
			swap(ls[childls], ls[child]);
			child = childls;
			childls = 2 * child + 1;
		}
		else
		{
			break;
		}
	}
}
void hp_pop(HP* ls)//ɾ���Ѷ�
{
	assert(ls && ls->a);
	swap(ls->a[0], ls->a[ls->size - 1]);
	ls->size--;
	hp_down(ls->a, ls->size, 0);
}

lsdata hp_top(HP* ls)//ȡ�Ѷ�����
{
	return ls->a[0];
}

int hp_size(HP* ls)//�����ݸ���
{
	return ls->size;
}