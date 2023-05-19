#pragma once
#include <iostream>
#include <malloc.h>
#include <cassert>



typedef struct BinaryTreeNode
{
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
}BinaryTreeNode;


BinaryTreeNode* Create(BinaryTreeNode ls);//��ʼ��
BinaryTreeNode* BinaryTreeDestory(int* a, int* aing);//��������ǰ�򹹽�������
void BinaryTreeDestory(BinaryTreeNode** ls);//���ٶ�����
int BinaryTreeSize(BinaryTreeNode* ls);//�������ڵ����
int BinaryTreeLeafSisze(BinaryTreeNode* ls);//������Ҷ�ӽڵ����
int BinaryTreeLevelKSize(BinaryTreeNode* ls, int k);//��������K��ڵ����

void BinaryTreePrevOrder(BinaryTreeNode* ls);// ������ǰ����� 
void BinaryTreeInOrder(BinaryTreeNode* ls);// �������������
void BinaryTreePostOrder(BinaryTreeNode* ls);// �������������

typedef int lsdata;
typedef struct Heap
{
	int size;
	int capacity;
	lsdata* a;
}HP;

void hp_init(HP* ls);//��ʼ��
void hp_destory(HP* ls);//����

void hp_push(HP* ls, lsdata a);//����
void hp_up(lsdata* ls, int child);//���ϵ���
void hp_down(lsdata* ls, int size ,int child);//���µ���

void hp_pop(HP* ls);//ɾ���Ѷ�
lsdata hp_top(HP* ls);//ȡ�Ѷ�����
int hp_size(HP* ls);//�����ݸ���;



