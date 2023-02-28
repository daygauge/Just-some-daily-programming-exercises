#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"


#ifndef LSS
void StacKInit(ST* sp)//��ʼ��
{
	assert(sp);
	sp->a = NULL;
	sp->capacity = 0;
	sp->top = 0;
}
void StacKDestroy(ST* sp)//����
{
	assert(sp);
	if (sp->a)
		free(sp->a);
	sp->a = NULL;
	sp->capacity = 0;
	sp->top = 0;
}
void StackPrint(ST* sp)//��ӡ
{
	assert(sp);
	int i = 0;
	while (i < sp->top)
	{
		printf("%d ", sp->a[i]);
		i++;
	}
	printf("\n");
}
void StackPush(ST* ps, STData x)//��ջ
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int as = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STData* s = (STData*)realloc(ps->a, as * sizeof(STData));
		if (s == NULL)
			return;
		ps->a = s;
		ps->capacity = as;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)//��ջ
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
STData StackTop(ST* sp)//����ջ����ֵ
{
	assert(sp);
	return sp->a[sp->top - 1];
}
int StackSize(ST* sp)//ջ��Ԫ�ظ���
{
	assert(sp);
	return sp->top;
}
bool StackEmpty(ST* ps)//ջ�Ƿ�Ϊ��
{
	assert(ps);
	return ps->top == 0;
}
#endif

