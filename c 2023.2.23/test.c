#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"


ListNode* ListCreate()// �������������ͷ���.
{
	ListNode* xtsr = (ListNode*)malloc(sizeof(ListNode));
	if (xtsr == NULL)
		return;
	xtsr->_next = xtsr;
	xtsr->_prev = xtsr;
	return xtsr;
}

void ListPrint(ListNode* pHead)// ˫�������ӡ
{
	assert(pHead);
	ListNode* tstls = pHead->_next;
	while (tstls!=pHead)
	{
		printf("%d ", tstls->_data);
		tstls = tstls->_next;
	}
	printf("\n");
}

ListNode* ccskfar(int x)
{
	ListNode* krsc = (ListNode*)malloc(sizeof(ListNode));
	if (krsc == NULL)
		return;
	krsc->_data = x;
	return krsc;
}
void ListPushBack(ListNode* pHead, LTDataType x)/// ˫������β��
{
	assert(pHead);
	ListInsert(pHead, x);
	//ListNode* pisds = pHead->_prev;
	//ListNode* crds = ccskfar(x);
	//pisds->_next = crds;
	//crds->_prev = pisds;
	//crds->_next = pHead;
	//pHead->_prev = crds;
}
void ListPopBack(ListNode* pHead)// ˫������βɾ
{
	assert(pHead && pHead->_next != pHead);
	ListErase(pHead->_prev);
	//ListNode* wei = pHead->_prev->_prev;
	//free(wei->_next);
	//wei->_next = pHead;
	//pHead->_prev = wei;
}
void ListPushFront(ListNode* pHead, LTDataType x)// ˫������ͷ��
{
	assert(pHead);
	ListInsert(pHead->_next, x);
	//ListNode* nedxign = ccskfar(x);
	//ListNode* nedes = pHead->_next;

	//pHead->_next = nedxign;
	//nedxign->_prev = pHead;
	//nedxign->_next = nedes;
	//nedes->_prev = nedxign;
}

void ListPopFront(ListNode* pHead)// ˫������ͷɾ
{
	assert(pHead);
	ListErase(pHead->_next);
	//ListNode* nesdx = pHead->_next->_next;
	//free(pHead->_next);
	//pHead->_next = nesdx;
	//nesdx->_prev = pHead;
}

ListNode* ListFind(ListNode* pHead, LTDataType x)// ˫���������
{
	assert(pHead);
	ListNode* ndex = pHead->_next;
	while (ndex!= pHead)
	{
		if (ndex->_data == x)
			return ndex;
		ndex = ndex->_next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)// ˫��������pos��ǰ����в���
{
	assert(pos);
	ListNode* nextcr =  ccskfar(x);
	ListNode* prevp = pos->_prev;
	prevp->_next = nextcr;
	nextcr->_prev = prevp;
	nextcr->_next = pos;
	pos->_prev = nextcr;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posprev = pos->_prev;
	ListNode* posnext = pos->_next;
	free(pos);
	posprev->_next = posnext;
	posnext->_prev = posprev;
}

void ListDestory(ListNode* pHead)// ˫����������
{
	assert(pHead);
	ListNode* Des = pHead->_next;
	while (Des != pHead)
	{
		Des = Des->_next;
		free(Des->_prev);
	}
	pHead->_data = pHead;
	pHead->_prev = pHead;
}