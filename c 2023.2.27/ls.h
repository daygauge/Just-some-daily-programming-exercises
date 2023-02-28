#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	// size_t _size;
}Queue;


void QueueInit(Queue* pq)// ��ʼ������ 
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)// ���ٶ��� 
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)// ��β����� 
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;

	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)// ��ͷ������ 
{
	assert(pq);
	//if (pq->head == NULL)
	//	return;
	assert(!QueueEmpty(pq));

	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
}

QDataType QueueFront(Queue* pq)// ��ȡ����ͷ��Ԫ�� 
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

QDataType QueueBack(Queue* pq)// ��ȡ���ж�βԪ�� 
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

int QueueSize(Queue* pq)// ��ȡ��������ЧԪ�ظ��� 
{
	assert(pq);

	int n = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		++n;
		cur = cur->next;
	}

	return n;
}
bool QueueEmpty(Queue* pq)// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
{
	assert(pq);
	return pq->head == NULL;
}