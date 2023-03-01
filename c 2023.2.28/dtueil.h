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

void QueueInit(Queue* pq);//��ʼ��

void QueueDestroy(Queue* pq);//����
void QueuePush(Queue* pq, QDataType x);//��β�����
void QueuePop(Queue* pq);//��ͷ������
QDataType QueueFront(Queue* pq);//���ض�ͷ
QDataType QueueBack(Queue* pq);//���ض�β
int QueueSize(Queue* pq);//����Ԫ�ظ���
bool QueueEmpty(Queue* pq);//�����Ƿ�Ϊ��


void day(Queue* pq);



