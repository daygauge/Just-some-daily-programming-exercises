#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

void ches1()
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);
	SeqListPushFront(&sl, 40);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void btdy()
{
	printf("***********************************\n");
	printf("***** 1.λ�ò��� 2.ͷ�� 3.β�� ****\n");
	printf("***** 4.λ��ɾ�� 5.ͷɾ 6.βɾ ****\n");
	printf("***** 7.����     8.�޸� 9.��ӡ ****\n");
	printf("*****-1.����     0.�˳�        ****\n");
	printf("***********************************\n");
}
void xxingbasdbos()
{
	//ches1();
	SeqList ss;
	int a = 0;
	int i = 0, j = 0;
	SeqListInit(&ss);
	do
	{
		btdy();
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("���������λ�����������: ");
			scanf("%d %d", &i, &j);
			SeqListInsert(&ss, i, j);
			break;
		case 2:
			printf("��������������: ");
			scanf("%d", &i);
			SeqListPushFront(&ss, i);
			break;
		case 3:
			printf("��������������: ");
			scanf("%d", &i);
			SeqListPushBack(&ss, i);
			break;
		case 4:
			printf("��������Ҫɾ�����ݵ�λ��: ");
			scanf("%d", &i);
			SeqListErase(&ss, i);
			break;
		case 5:
			SeqListPopFront(&ss);
			break;
		case 6:
			SeqListPopBack(&ss);
			break;
		case 7:
			printf("������Ҫ���ҵ�ֵ: ");
			scanf("%d", &i);
			SeqListFind(&ss, i);
			break;
		case 8:
			xgai(&ss);
			break;
		case 9:
			SeqListPrint(&ss);
			break;
		case 0:
			break;
		case -1:
			SeqListDestroy(&ss);
			break;
		default:
			printf("�������");
			break;
		}



	} while (a);
}
//int main()
//{
//	xxingbasdbos();
//
//
//	return 0;
//}

#define N 100
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType array[N];
	size_t size;
}SeqList;

typedef struct SeqList
{
	SLDataType* array; 
	size_t size; 
	size_t capicity; 
}SeqList;
int main()
{


	return 0;
}