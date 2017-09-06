#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElemType;

typedef struct DualNode
{
	ElemType data;
	struct DualNode *prior;
	struct DualNode *next;

}DualNode, *DuLinkList;

Status InitList(DuLinkList *L)
{
	DualNode *p, *q;
	int i;

	//��ʼ��ͷ���
	*L = (DuLinkList)malloc(sizeof(DualNode));

	if (!(*L))
	{
		return ERROR;
	}

	(*L)->next = (*L)->prior = NULL;

	p = *L;

	for (i = 0; i < 26; i++)
	{
		q = (DuLinkList)malloc(sizeof(DualNode));
		if (!q)
		{
			return ERROR;
		}

		q->data = 'A' + i;
		q->prior = p;
		q->next = p->next;
		p->next = q;

		p = q;
	}

	p->next = (*L)->next;
	(*L)->next->prior = p;

	return OK;
}

void Caesar(DuLinkList *L, int i)
{
	if (i > 0)
	{
		do
		{
			(*L) = (*L)->next;
		} while (--i);
		
	}

	if (i < 0)
	{
		do
		{
			(*L) = (*L)->prior;

		} while (++i);		
	}
}

//����ѭ������������,��ǰ�ƶ�����ֻ������ѭ��,���ܷ���ѭ��
int main()
{
	DuLinkList L;
	int i, n;

	InitList(&L);

	printf("������һ������:");

	scanf("%d", &n);
	printf("\n");

	Caesar(&L, n);

	for (i = 0; i < 26; i++)
	{
		L = L->next;
		printf("%c", L->data);
	}
	printf("\n");
	system("pause");

	return 0;
}

#endif