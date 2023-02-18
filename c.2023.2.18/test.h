#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define CSH 3
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

void charsju(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDateType x);//β����������
void SeqListPushFront(SeqList* ps, SLDateType x);//ͷ����������
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);// ˳�����posλ�ò���x

void sancu(SeqList* ps);
void SeqListPopFront(SeqList* ps);//ͷ��ɾ������
void SeqListPopBack(SeqList* ps);//β��ɾ������
void SeqListErase(SeqList* ps, size_t pos);// ˳���ɾ��posλ�õ�ֵ

int SeqListFind(SeqList* ps, SLDateType x);// ˳������
void SeqListDestroy(SeqList* ps);//����
void xgai(SeqList* ps);//�޸�
