#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#define MAX_TREE_SIZE 100
typedef char ElemType;

//���ӽ��
typedef struct CTNode
{
	//���ӽ����±�
	int child;
	//ָ����һ�����ӽ���ָ��
	struct CTNode *next;
}*Childptr;

//��ͷ�ṹ
typedef struct
{
	//��������еĽ������
	ElemType data;
	//���˫�׵��±�
	int parent;
	//ָ���һ�����ӵ�ָ��
	Childptr firstchild;

}CTBox;

//���ṹ

typedef struct
{
	//�������
	CTBox nodes[MAX_TREE_SIZE];
	//r����λ��n������
	int r, n;
};

#endif