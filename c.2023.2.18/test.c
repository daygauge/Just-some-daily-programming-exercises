#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
#define CASE break;case

bt()
{
	printf("***********************************************\n");
	printf("*******   1 ����˳���   2 ˳���б��ӡ *******\n");
	printf("*******   3 ��������     4 ɾ������     *******\n");
	printf("*******   5 ˳������   6 �޸�˳���   *******\n");
	printf("*******              0.�˳�             *******\n");
	printf("***********************************************\n");
}
enum MyEnum
{
	TC,
	XH,
	DAY,
	CR,
	SC,
	CZ,
	XG,
};
int main()
{
	int a = 0;
	int b = 0;
	SeqList ss;
	SeqListInit(&ss);
	do
	{
		bt();
		scanf("%d", &a);
		switch (a)
		{
		case TC:
			CASE XH:
			SeqListDestroy(&ss);
			CASE DAY:
			SeqListPrint(&ss);
			CASE CR:
			charsju(&ss);
			CASE SC:
			sancu(&ss);
			CASE CZ:
			printf("������ҵ�ֵ:");
			scanf("%d", &b);
			SeqListFind(&ss,b);
			CASE XG:
			xgai(&ss);
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (a);
	return 0;
}