#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include "CriticalPath.h"  
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
typedef struct {
	int number;
}elemType; //Ԫ����Ϣ�ṹ�� 

typedef struct {
	elemType *elem;
	int length;
}SSTable; //�ܽṹ��


//��������Ϣ
void CreatStable(SSTable *ST, int length)
{
	int i;
	printf("���������ݵĸ���:");
	scanf("%d", &ST->length);
	length = ST->length;
	ST->elem = (elemType *)malloc(length * sizeof(elemType));
	printf("���С������������:\n");
	for (i = 0; i < ST->length; i++)
	{
		printf("��������һ������ :");
		scanf("%d", &ST->elem[i].number);

	}
}
//�ȽϺ���
int EQ(int num1, int num2)
{
	if (num1 == num2)
	{
		return 1;
	}		
	else
	{
		return 0;
	}		
}

int LT(int num1, int num2)
{
	if (num1 < num2)
	{
		return 1;
	}		
	else
	{
		return 0;
	}		
}

//���Һ���
int Search_Bin(SSTable *ST, int number)
{
	int low = 0, high = ST->length -1 ;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (EQ(ST->elem[mid].number, number))
		{
			return mid;
		}				
		else if (LT(number, ST->elem[mid].number))
		{
			high = mid - 1;
		}			
		else
		{
			low = mid + 1;
		}			
	}
	return -1;
}

//������
int main()
{
	int length = 0, number,result;
	SSTable ST;
	CreatStable(&ST, length);
	printf("��������Ҫ�ҵ���:");
	scanf("%d", &number);
	result = Search_Bin(&ST, number);

	if (result >=0)
	{
		printf("�ҵ�����%d\n", ST.elem[result]);
	}		
	else
	{
		printf("û���ҵ�\n");
	}		

	system("pause");
	return 0;
}
#endif