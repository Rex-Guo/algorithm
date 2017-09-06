#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 10 /* ���е�������� */
struct node /* ͼ�Ķ���ṹ���� */
{
	int vertex;
	struct node *nextnode;
};
typedef struct node *graph; /* ͼ�Ľṹָ�� */
struct node head[9]; /* ͼ�Ķ������� */
int visited[9]; /* ����������� */
int queue[MAXQUEUE]; /* ������������ */
int front = -1; /* ����ǰ�� */
int rear = -1; /* ���к�� */

/***********************��ά�������ڽӱ���ת��****************************/
void creategraph(int node[20][2], int num)
{
	graph newnode; /* ����ָ�� */
	graph ptr;
	int from; /* ����� */
	int to; /* ���յ� */
	int i;
	for (i = 0; i < num; i++) /* ��i���ߵ���Ϣ���� */
	{
		from = node[i][0]; /* �ߵ���� */
		to = node[i][1]; /* �ߵ��յ� */
		/* �����¶��� */
		newnode = (graph)malloc(sizeof(struct node));
		newnode->vertex = to; /* �������� */
		newnode->nextnode = NULL; /* �趨ָ���ֵ */
		ptr = &(head[from]); /* ����λ�� */
		while (ptr->nextnode != NULL) /* ����������β */
			ptr = ptr->nextnode; /* ��һ������ */
		ptr->nextnode = newnode; /* �����i���ڵ������β�� */
	}
}

/************************ ��ֵ�����************************************/
int enqueue(int value)
{
	if (rear >= MAXQUEUE) /* ��������Ƿ�ȫ�� */
	{
		return -1; /* �޷����� */
	}		
	rear++; /* ���ָ����ǰ�� */
	queue[rear] = value; /* �������� */

	return 0;
}

/************************* ��ֵ������*********************************/
int dequeue()
{
	if (front == rear) /* �����Ƿ�Ϊ�� */
	{
		return -1; /* Ϊ�գ��޷�ȡ�� */
	}		
	front++; /* ǰ��ָ����ǰ�� */
	return queue[front]; /* �Ӷ�����ȡ����Ϣ */
}

/*********************** ͼ�εĹ�����ȱ���************************/
void bfs(int current)
{
	graph ptr;
	/* ������һ������ */
	enqueue(current); /* ������������ */
	visited[current] = 1; /* �ѱ�������¼��־����1*/
	printf(" Vertex[%d]\n", current); /* ��ӡ�����������ֵ */
	while (front != rear) /* �����Ƿ�Ϊ�� */
	{
		current = dequeue(); /* ������Ӷ�����ȡ�� */
		ptr = head[current].nextnode; /* ����λ�� */
		while (ptr != NULL) /* ����������β */
		{
			if (visited[ptr->vertex] == 0) /*����û�б�����*/
			{
				enqueue(ptr->vertex); /* ������������ */
				visited[ptr->vertex] = 1; /* �ñ������Ϊ1 */
				printf(" Vertex[%d]\n", ptr->vertex);/* ӡ����������ֵ */
			}
			ptr = ptr->nextnode; /* ��һ������ */
		}
	}
}

int main()
{
	graph ptr;
	///* ����Ϣ���� */
	int edge[20][2] = { { 1, 2 }, { 2, 1 },
	{ 6, 3 }, { 3, 6 },
	{ 2, 4 }, { 4, 2 },
	{ 1, 5 }, { 5, 1 },
	{ 3, 7 }, { 7, 3 },
	{ 1, 7 }, { 7, 1 },
	{ 4, 8 }, { 8, 4 },
	{ 5, 8 }, { 8, 5 },
	{ 2, 8 }, { 8, 2 },
	{ 7, 8 }, { 8, 7 } };
	//int edge[20][2] = { { 1, 2 }, { 2, 1 }, /* �������� */
	//{ 1, 3 }, { 3, 1 },
	//{ 1, 4 }, { 4, 1 },
	//{ 2, 5 }, { 5, 2 },
	//{ 2, 6 }, { 6, 2 },
	//{ 3, 7 }, { 7, 3 },
	//{ 4, 7 }, { 7, 4 },
	//{ 5, 8 }, { 8, 5 },
	//{ 6, 7 }, { 7, 6 },
	//{ 7, 8 }, { 8, 7 } };
	int i;
	system("cls");
	puts("This is an example of Width Preferred Traverse of Gragh.\n");
	for (i = 1; i <= 8; i++) /*����ṹ�����ʼ��*/
	{
		head[i].vertex = i;
		head[i].nextnode = NULL;
		visited[i] = 0;
	}
	creategraph(edge, 20); /* ͼ��Ϣת�����ڽӱ��Ľ��� */
	printf("The content of the graph's allist is:\n");
	for (i = 1; i <= 8; i++)
	{
		printf(" vertex%d =>", head[i].vertex); /* ����ֵ */
		ptr = head[i].nextnode; /* ����λ�� */
		while (ptr != NULL) /* ����������β */
		{
			printf(" %d ", ptr->vertex); /* ��ӡ����������� */
			ptr = ptr->nextnode; /* ��һ������ */
		}
		printf("\n"); /* ���� */
	}
	printf("The contents of BFS are:\n");
	bfs(1); /* ��ӡ����������� */
	printf("\n"); /* ���� */
	puts(" Press any key to quit...");
	getchar();
	system("pause");
	return 0;
}
#endif