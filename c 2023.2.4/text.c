#define _CRT_SECURE_NO_WARNINGS 1;
#include "text.h"

void bti()
{
	printf("********************************************\n");
	printf("*******1.�����ϵ��   2,������ϵ��  ********\n");
	printf("*******3.�޸���ϵ��   4.ɾ����ϵ��  ********\n");
	printf("*******5.��ϵ���б�   6.����ͨѶ¼  ********\n");
	printf("**************   0.�˳�   ******************\n");
	printf("********************************************\n");
}
enum ze
{
	kuong,
	tianjia,
	chazao,
	xgai,
	shanc,
	sclbiao,
	paixu,

};
int main()
{
	int a = 0;
	hj hjjs;
	chushihua(&hjjs);
	do
	{
		bti();
		scanf("%d", &a);
		switch (a)
		{
		case tianjia:
	     	tianjiahs(&hjjs);
			break;
		case chazao:
			chazaos(&hjjs);
			break;
		case xgai:
			xgailxr(&hjjs);
			break;
		case shanc:
			shanchus(&hjjs);
			break;
		case sclbiao:
			ckanlbiaos(&hjjs);
			break;
		case paixu:
			paixulianxir(&hjjs);
			break;
		case kuong:
			break;
		 default:
			printf("�����������������\n");
			break;
		}
	} while (a);
	
}