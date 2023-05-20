#define _CRT_SECURE_NO_WARNINGS 1
#include "btntestls.h"


//����һ���ڵ�
BTNode* BuyNode(binlst a)
{
	BTNode* ls = (BTNode*)malloc(sizeof(BTNode));//�������ٽڵ�
	assert(ls);

	//��ʼ��
	ls->data = a;
	ls->left = ls->right = NULL;
	return ls;
}

BTNode* CreatBinaryTree(binlst* ls, int* lp)//�������鹹��������
{
	//�����������˼��
	if (ls[*lp] == 0)//����Ϊ0�����������ǿսڵ�
	{
		(*lp)++;
		return NULL;
	}
	BTNode* btnls = BuyNode(ls[*lp]);//�������ٽڵ�
	(*lp)++;//����ֵʹ�ú�,λ��++
	btnls->left = CreatBinaryTree(ls, lp);
	btnls->right = CreatBinaryTree(ls, lp);
	return btnls;
}

void printfbtn(BTNode* ls)//������ǰ�����
{
	if (ls == NULL)
	{
		//std::cout << '#' << " ";
		return;
	}
	std::cout << ls->data << " ";
	printfbtn(ls->left);
	printfbtn(ls->right);

}
void levelOrder(BTNode* ls)//�������������
{
	std::queue<BTNode*> q;//��������
	if (ls != NULL)
	{
		q.push(ls);//д��ͷ�ڵ�
	}

	while (!q.empty())
	{
		BTNode* lscs = q.front();
		std::cout << lscs->data << " ";//���ض��е�һ��Ԫ�ص�ֵ
		q.pop();
		if (lscs->left != NULL)
			q.push(lscs->left);
		if (lscs->right != NULL)
			q.push(lscs->right);
	}
}
void btndestry(BTNode* ls)//����������
{
    if(!ls)
		return;
	btndestry(ls->left);
	btndestry(ls->right);
	free(ls);//���ú������������������Ҳ����ӽڵ�
}