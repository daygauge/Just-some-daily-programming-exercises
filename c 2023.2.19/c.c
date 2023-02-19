#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"


void SeqListInit(SeqList* ps)//��ʼ��
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListPrint(SeqList* ps)//˳���б��ӡ
{
	int as = 0;
	while (as < ps->size)
	{
		printf("%d ", ps->a[as]);
		as++;
	}
	printf("\n");
		
}
void kr(SeqList* ps)//˳�������
{
	if (ps->capacity == ps->size)
	{
		int lskai = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDateType* zjdz = (SLDateType*)realloc(ps->a, lskai * sizeof(SLDateType));
		if (zjdz != NULL)
		{
			ps->a = zjdz;
			ps->capacity = lskai ;
		}
	}
}
void SeqListPushBack(SeqList* ps, SLDateType x)//β��
{
	SeqListInsert(ps, ps->size, x);
}
void SeqListPushFront(SeqList* ps, SLDateType x)//ͷ��
{
	SeqListInsert(ps, 0, x);
}
void SeqListInsert(SeqList* ps, int pos, SLDateType x)// ˳�����posλ�ò���x
{
	assert(pos >= 0 && pos <= ps->size);
	kr(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListPopBack(SeqList* ps)//βɾ
{
	SeqListErase(ps, ps->size-1);
}
void SeqListPopFront(SeqList* ps)//ͷɾ
{
	SeqListErase(ps, 0);
}
void SeqListErase(SeqList* ps, int pos)// ˳���ɾ��posλ�õ�ֵ
{
	assert(pos >= 0 && pos <= ps->size);
	int as = pos;
	while (as<=ps->size)
	{
		ps->a[as] = ps->a[as + 1];
		as++;
	}
	ps->size--;
}
int SeqListFind(SeqList* ps, SLDateType x)// ˳������
{
	for (int i = 0; i < ps->size; i++)
		if (ps->a[i] == x)
			return ps->a[i];
	return -1;
}

void SeqListDestroy(SeqList* ps)//����
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void xgai(SeqList* ps)
{
	int as = 0;
	int zi = 0;
	scanf("%d %d", &as, &zi);
	if (as <= ps->size)
		ps->a[as] = zi;
}