#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}sqlist, *linklsit;


//ѭ�����������
linklsit CreateLinkList(int Number)
{
	linklsit head = NULL;
	linklsit s, r;
	int i;

	r = head;

	for (i = 1; i <= Number; i++)
	{
		s = (linklsit)malloc(sizeof(sqlist));
		s->data = i;

		if (head == NULL)
		{
			head = s;
		}			
		else
		{
			r->next = s;
		}			
		r = s;             //����r��β��
	}

	r->next = head;

	return head;
}

int main()
{
	linklsit p, r;
	int number, i, j;

	printf("������Latin����Ŀ�ȣ� ");
	scanf("%d", &number);
	printf("\n %dά��Latin����Ϊ��\n\n", number);

	p = CreateLinkList(number);
	r = p;

	for (i = 0; i<number; i++)
	{
		for (j = 0; j<number; j++)
		{
			printf("%3d", r->data);
			r = r->next;
		}
		printf("\n");
		p = p->next;
		r = p;
	}
	printf("\n");

	system("pause");

	return 0;
}

#endif