#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct zan
{
	int* a;
	int top;
	int capacity;
}Z;

//��ʼ��
void StackInit(Z* ps);

//����
void StackDestroy(Z* ps);

//��ӡ
void StackPrint(Z* ps);

//��ջ
void StackPush(Z* ps, int x);

//��ջ
void StackPop(Z* ps);

//����ջ��Ԫ��
int StackTop(Z* ps);

//����ջ�Ĵ�С
int StackSize(Z* ps);

//ջ�Ƿ�Ϊ��
bool StackEmpty(Z* ps);