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

void hp_up(lsdata* ls, int child)//���ϵ���,lsΪ�����飬childΪ��������±�
{
	assert(ls);
	int chlidls = (child - 1) / 2;//��ȡ���ڵ�
	while (child > 0)
	{
		if (ls[child] < ls[chlidls])//С�� �½ڵ��Ƿ�С�ڸ��ڵ�
		{
			swap(ls[child], ls[chlidls]);//���������ڵ��е�1ֵ
			child = chlidls;//�����½ڵ�
			chlidls = (chlidls - 1) / 2;//���¸��ڵ�
		}
		else
		{
			break;
		}
	}
}

void hp_down(lsdata* ls, int size, int child)//���µ���,lsΪ������,sizeΪ���������childΪ��ʼ����
{
	assert(ls);
	int childls = 2 * child + 1;//��ȡ�ӽڵ�
	while (childls < size)//�ӽڵ��±� < ���ڵ��±���ѭ��
	{
		if (childls + 1 < size && ls[childls + 1] < ls[childls])//С�� ����ҽڵ����ڵ�С�������ҽڵ��滻
		{
			childls++;//ͨ���±�++��ȡ���ҽڵ�
		}

		if (ls[child] > ls[childls])//С�ѣ����ڵ�����ӽڵ����
		{
			swap(ls[childls], ls[child]);//�������ڵ���ӽڵ�
			child = childls;//���ڵ���µ��ӽڵ�λ��
			childls = 2 * child + 1;//�ӽڵ����
		}
		else//�ҵ�����λ�þ��˳�
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

void hp_pop(HP* ls)//ɾ���Ѷ�
{
	assert(ls && ls->a);
	swap(ls->a[0], ls->a[ls->size - 1]);//������һ��Ԫ�غ����һ��Ԫ��
	ls->size--;//Ԫ�ظ���--
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
void hp_down1(lsdata* ls, int size, int child)
{
	int z = child * 2 + 1;//��ȡ�ӽڵ�
	while (z < size)
	{
		if (z + 1 < size && ls[z+1] < ls[z])//��� �滻���ҽڵ�ϴ��ֵ
		{
			z++;
		}

		if (ls[z] < ls[child])//��� �ӽڵ���ڸ��ڵ����滻
		{
			swap(ls[z], ls[child]);
			//���¸��ӽڵ�
			child = z;
			z = child * 2 + 1;
		}
		else
		{
			break;
		}

	}
}
void hp_sort(HP* ls)//������
{
	int n = ls->size;
	while (n > 0)
	{
		swap(ls->a[0], ls->a[n-1]);//������һ�������һ��ֵ
		n--;//���һ��ֵ�����Ӷ����Ƴ�
		hp_down1(ls->a, n, 0);
	}
}