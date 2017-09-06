#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

int num = 0;
//����һ�ö����� Լ���û�������������ķ�ʽ��������
void CreateBiTree(BiTree *T)
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
		*T = (BiTNode*)malloc(sizeof(BiTNode));

		(*T)->data = c;
		//printf("����:%c\n", c);
		CreateBiTree(&(*T)->lchild);
		//printf("�ҽ��:%c\n", c);
		CreateBiTree(&(*T)->rchild);
	}
}

//���ʶ��������ľ������
void Visit(char c, int level)
{
	printf("%c λ�ڵ� %d ��\n", c, level);
}
//�������������
PreOrderTraverse(BiTree T, int level)
{
	if (T)
	{
		Visit(T->data, level);
		PreOrderTraverse(T->lchild, level + 1);
		PreOrderTraverse(T->rchild, level + 1);
	}
}

int main()
{
	int level = 1;
	BiTree T = NULL;

	CreateBiTree(&T);

	PreOrderTraverse(T, level);

	system("pause");
	return 0;
}

#endif