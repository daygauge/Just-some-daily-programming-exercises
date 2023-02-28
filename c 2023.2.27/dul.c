#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"

void QueueInit(Queue* q)// ��ʼ������ 
{
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
}
void QueuePush(Queue* q, QDataType data)// ��β����� 
{
	assert(q);
	QNode* ss = (QNode*)malloc(sizeof(QNode));
	if (ss != NULL)
	{
		ss->a = data;
		ss->next = NULL;
		if (q->_front == NULL)
		{
			q->_front = q->_rear = ss;
		}
		else
		{
			q->_rear->next = ss;
			q->_rear = ss;
		}
	}
}
void QueuePop(Queue* q)// ��ͷ������ 
{
	assert(q);
	assert(!QueueEmpty(q));
	QNode* next = q->_front->next;
	free(q->_front);
	q->_front = next;
	if (q->_front = NULL)
	{
		q->_rear = NULL;
	}
}
QDataType QueueFront(Queue* q)// ��ȡ����ͷ��Ԫ�� 
{
	assert(q->_front);
	return  q->_front->a;
}
QDataType QueueBack(Queue* q)// ��ȡ���ж�βԪ�� 
{
	assert(q->_rear);
	return q->_rear->a;
}
int QueueSize(Queue* q)// ��ȡ��������ЧԪ�ظ��� 
{
	int i = 0;
	QNode* ss = q->_front;
	while (ss)
	{
		ss = ss->next;
		i++;
	}
	return i;
}
int QueueEmpty(Queue* q)// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
{
	return q->_front == NULL;
}
void QueueDestroy(Queue* q)// ���ٶ��� 
{

	QNode* ss2 = q->_front->next;
	while (ss2)
	{
		QNode* ss1 = ss2->next;
		free(ss2);
		ss2 = ss1;
	}
	q->_front = q->_rear = NULL;
}