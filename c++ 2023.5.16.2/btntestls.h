#pragma once
#include <malloc.h>
#include <assert.h>
#include <iostream>
#include <queue>

typedef int binlst;
typedef struct BinaryTreeNodes
{
	struct BinaryTreeNodes* left;
	struct BinaryTreeNodes* right;
	binlst data;

}BTNode;

BTNode* BuyNode(binlst a);//����һ���ڵ�
BTNode* CreatBinaryTree(binlst* ls, int* lp);//�������鹹��������
void printfbtn(BTNode* ls);//������ǰ�����
void levelOrder(BTNode* ls);//�������������
void btndestry(BTNode* ls);//����������