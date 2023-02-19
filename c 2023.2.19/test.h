#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define ZJ 3

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;//˳���
	size_t size;//˳������
	size_t capacity; // �ڴ����
}SeqList;


// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps);//��ʼ��
void SeqListPrint(SeqList* ps);//˳���б��ӡ
void SeqListPushBack(SeqList* ps, SLDateType x); //β��
void SeqListPopBack(SeqList* ps);                //βɾ
void SeqListPushFront(SeqList* ps, SLDateType x);//ͷ��
void SeqListPopFront(SeqList* ps);               //ͷɾ
void SeqListInsert(SeqList* ps, int pos, SLDateType x);// ˳�����posλ�ò���x
void SeqListErase(SeqList* ps, int pos);// ˳���ɾ��posλ�õ�ֵ
void SeqListDestroy(SeqList* ps);                //����
int SeqListFind(SeqList* ps, SLDateType x);// ˳������
void xgai(SeqList* ps);                         //�޸�



