#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

//�����洢��־λ 
//Link(0) ��ʾָ�����Һ��ӵ�ָ��
//Link(1) ��ʾָ��ǰ����̵�����
typedef enum {Link,Thread} PointerTag;

typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;

}BiThrNode, *BiThrTree;

//ȫ�ֱ���,ʼ��ָ��ոշ��ʹ��Ľ��
BiThrTree pre;

int num = 0;
//����һ�ζ�����,Լ���û��������������ʽ��������
void CreateBiTree(BiThrTree *T)
{

	char c;
	scanf("%c", &c);

	printf("��%d :%c\n", num++, c);

	if (' ' == c)
	{
		*T = NULL;

	}
	else
	{
		*T = (BiThrNode*)malloc(sizeof(BiThrNode));

		(*T)->data = c;
		(*T)->ltag = Link;
		(*T)->rtag = Link;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
//�������������
void InThreading(BiThrTree T)
{
	if (T)
	{
		//�ݹ�����������
		InThreading(T->lchild);

		//����ý��û����������ltagΪThread,����lchildָ��ոշ��ʵĽ��
		if (!T->lchild)
		{
			T->ltag = Thread;
			T->lchild = pre;
		}	

		if (!pre->rchild)
		{
			pre->rtag = Thread;
			pre->rchild = T;
		}

		pre = T;

		//�ݹ��Һ���������
		InThreading(T->rchild);
	}
}

void InOrderThreading(BiThrTree *p, BiThrTree T)
{
	*p = (BiThrTree*)malloc(sizeof(BiThrNode));
	(*p)->ltag = Link;
	(*p)->rtag = Thread;
	(*p)->rchild = *p;
	if (!T)
	{
		(*p)->lchild = *p;
	}
	else
	{
		(*p)->lchild = T;
		pre = *p;

		InThreading(T);
		pre->rchild = *p;
		pre->rtag = Thread;
		(*p)->rchild = pre;
	}
}

void Visit(char c)
{
	printf("%c", c);
}

//�������������,�ǵݹ�
void InOrderTraverse(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;

	while (p!=T)
	{
		while (p->ltag == Link)
		{
			p = p->lchild;
		}

		Visit(p->data);

		while (p->rtag == Thread && p->rchild !=T)
		{
			p = p->rchild;
			Visit(p->data);
		}

		p = p->rchild;
	}
}

int main()
{
	BiThrTree p, T = NULL;

	CreateBiTree(&T);

	InOrderThreading(&p,T);

	printf("�������������Ϊ:");

	InOrderTraverse(p);
	printf("\n");
	system("pause");
	return 0;
}

#endif