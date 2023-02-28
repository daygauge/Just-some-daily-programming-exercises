#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>
#define LSS
#ifndef LSS
typedef int STData;
typedef struct ss
{
    STData* a;
    int top;
    int capacity;
}ST;
void StacKInit(ST* sp);//��ʼ��
void StacKDestroy(ST* sp);//����
void StackPrint(ST* sp);//��ӡ
void StackPush(ST* ps, STData x);//��ջ
void StackPop(ST* ps);//��ջ
STData StackTop(ST* sp);//����ջ����ֵ
int StackSize(ST* sp);//ջ��Ԫ�ظ���
bool StackEmpty(ST* ps);//ջ�Ƿ�Ϊ��
#else
//typedef int QDataType;
//typedef struct ss
//{
//    struct ss* next;
//    QDataType a;
//}QNode;
//typedef struct Queue
//{
//    QNode* _front;
//    QNode* _rear;
//}Queue;
//void QueueInit(Queue* q);// ��ʼ������ 
//void QueuePush(Queue* q, QDataType data);// ��β����� 
//void QueuePop(Queue* q);// ��ͷ������ 
//QDataType QueueFront(Queue* q);// ��ȡ����ͷ��Ԫ�� 
//QDataType QueueBack(Queue* q);// ��ȡ���ж�βԪ�� 
//int QueueSize(Queue* q);// ��ȡ��������ЧԪ�ظ��� 
//int QueueEmpty(Queue* q);// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
//void QueueDestroy(Queue* q);// ���ٶ��� 
#endif // !LSS




//typedef struct {
//    int* AS;
//    int tset;
//
//    int n1;
//    int n2;
//} MyCircularQueue;
//
//MyCircularQueue* myCircularQueueCreate(int k) //��ʼ��
//{
//    MyCircularQueue* Mycs = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    int* pa = (int*)malloc((k + 1) * sizeof(int));
//    Mycs->AS = pa;
//    Mycs->tset = k;
//    Mycs->n1 = 0;
//    Mycs->n2 = 0;
//
//    return Mycs;
//}
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) //����Ԫ��
//{
//    if ((obj->n2 + 1) % (obj->tset + 1) == obj->n1)
//    {
//        return false;
//    }
//    obj->AS[obj->n2++] = value;
//    if (obj->n2 == obj->tset+1)
//        obj->n2 = 0;
//    return true;
//
//}
//bool myCircularQueueDeQueue(MyCircularQueue* obj)//ɾ��Ԫ��
//{
//    if (obj->n1 == obj->n2)
//    {
//        return false;
//    }
//    obj->n1++;
//    if (obj->n1 == obj->tset+1)
//        obj->n1 = 0;
//    return true;
//}
//int myCircularQueueFront(MyCircularQueue* obj) //��ȡ����Ԫ��
//{
//    if (obj->n1 != obj->n2)
//    {
//        return obj->AS[obj->n1];
//    }
//    return -1;
//}
//int myCircularQueueRear(MyCircularQueue* obj) //��ȡ��βԪ��
//{
//    if (obj->n1 == obj->n2)
//        return -1;
//    if (obj->n2 == 0)
//        return obj->AS[obj->tset];
//    else
//        return obj->AS[obj->n2 - 1];
//}
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) //����Ƿ�Ϊ��
//{
//    return obj->n1 == obj->n2;
//}
//bool myCircularQueueIsFull(MyCircularQueue* obj) //����Ƿ�����
//{
//
//    return (obj->n2 + 1) % (obj->tset + 1) == obj->n1;
//}
//void myCircularQueueFree(MyCircularQueue* obj) 
//{
//
//}
