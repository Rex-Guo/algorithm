#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

//Լɪ������
//����������n���ˣ����1~n)����1��ʼ����������m���˳���ʣ�µ��˼�����1��ʼ��������˳��������߱�š�
typedef struct node
{
	int data;
	struct node *next;
}node;

node *create(int n)
{
	node *p = NULL;
	node *head;
	node *s = NULL;
	//head��һ���յ�ͷ��㲢������,Ҳ���ڻ���
	head = (node*)malloc(sizeof(node));

	//pָ��ǰ�ڵ�
	p = head;
	int i = 1;

	if (0 != n)
	{
		while (i<=n)
		{
			s = (node*)malloc(sizeof(node));
			s->data = i++;
			p->next = s;
			p = s;
		}
		s->next = head->next;
	}
	free(head);
	//����ָ������ĵ�һ������ָ��
	return s->next;
}

int main()
{
	int n = 41;
	int m = 3;
	int i;
	node *p = create(n);
	node *temp;

	m %= n;

	//��p == p->nextʱ��ʾ��ʣ��һ����������,ѭ��ִ��ֱ�����һ�����
	while (p != p->next)
	{
		//��1��ʼ����������m���˳�,ָ���ƶ���Ҫɾ������ǰһ�����
		for ( i = 1; i < m-1; i++)
		{
			p = p->next;
		}
		//p���ΪҪ�Ƴ�����ǰһ�����
		//��ӡҪ�Ƴ��Ľ��
		printf("%d->", p->next->data);
		//��ʱ����ָ��Ҫ�˳��Ľ��
		temp = p->next;
		//p����һ�����ָ��Ҫ�˳�������һ�����,��ʱҪ�˳��Ľ���������ɾ��
		p->next = temp->next;

		//�ͷ�Ҫ�˳��Ľ��
		free(temp);

		//pָ�������ƶ��Ա������ѭ����ѭ��m-1�ε�����һ��Ҫɾ���Ľ���ǰһ�����
		p = p->next;
	}

	printf("%d\n", p->data);

	
	system("pause");

	return 0;
}
#endif