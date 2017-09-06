#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

//���ʼ�¼
int visit[MAX];
//ͼ�Ľṹ���
typedef struct
{
	int vex[MAX];//��¼����
	int adjmatrix[MAX][MAX];//�ڽӾ���
	int n;//����ĸ���
}GRAPH;

//��ʼ��ͼ
int init_graph(GRAPH *pG)
{
	memset(pG, 0, sizeof(GRAPH));
	pG->n = -1;

	printf("input vex\n");
	while (scanf("%d", &pG->vex[++pG->n]));
	while (getchar() != '\n');

#ifndef _DEBUG_
	int i = 0;

	for (i = 0; i < pG->n; i++)
	{
		printf("V%d ", pG->vex[i]);
	}

	printf("\n");
#endif

	return 0;
}

//��ȡ�����λ��
int locatevex(GRAPH *pG, int vex)
{
	int i = 0;

	for (i = 0; i < pG->n; i++)
	{
		if (pG->vex[i] == vex)
			return i;
	}

	return 0;
}

//����ͼ�Ķ���֮��ı�
int input_edge(GRAPH *pG)
{
	int vex1, vex2;
	int i, j;

	printf("input edge(i,j):\n");
	//������ĸ������
	while (scanf("(%d,%d)", &vex1, &vex2))
	{
		getchar();
		i = locatevex(pG, vex1);
		j = locatevex(pG, vex2);
		pG->adjmatrix[i][j] = pG->adjmatrix[j][i] = 1;
	}

#ifndef _DEBUG_
	int m, n;

	for (m = 0; m < pG->n; m++)
	{
		for (n = 0; n < pG->n; n++)
		{
			printf("%d ", pG->adjmatrix[m][n]);
		}

		printf("\n");
	}

#endif

	return 0;
}

//ջ�����
typedef struct
{
	int buf[MAX];
	int n;
}Stack;

//������ջ
Stack *create_empty_stack()
{
	Stack *stack;

	stack = (Stack *)malloc(sizeof(Stack));
	stack->n = -1;

	return stack;
}

//��ջ
int pop_stack(Stack *stack)
{
	int temp;

	temp = stack->buf[stack->n];
	stack->n--;

	return temp;
}

//��ջ
int push_stack(Stack *stack, int data)
{
	stack->n++;
	stack->buf[stack->n] = data;

	return 0;
}

//�жϿ�ջ
int is_empty_stack(Stack *stack)
{
	if (stack->n == -1)
		return 1;
	else
		return 0;
}

int visit_all(GRAPH *pG)
{
	int i = 0;

	for (i = 0; i < pG->n; i++)
	{
		if (visit[i] != 1)
			break;
	}

	if (i == pG->n)
		return 1;
	else
		return 0;
}

//ͼ����ȷǵݹ����
int DFS(GRAPH *pG, int v)
{
	Stack *stack;
	int i = 0;

	stack = create_empty_stack();
	push_stack(stack, pG->vex[v]);
	visit[v] = 1;
	printf("V%d ", pG->vex[v]);

	while (!is_empty_stack(stack) || !visit_all(pG))
	{
		for (i = 0; i < pG->n; i++)
		{
			if (visit[i] == 0 && pG->adjmatrix[v][i] == 1)
				break;
		}

		if (i == pG->n)
		{
			v = pop_stack(stack);

		}
		else{

			v = i;
			push_stack(stack, pG->vex[v]);
			visit[v] = 1;
			printf("V%d ", pG->vex[v]);
		}
	}

	printf("\n");

	return 0;
}

//���е����
typedef struct node
{
	int data;
	struct node *next;

}ListNode;

typedef struct
{
	ListNode *front;
	ListNode *rear;
}Queue;

//�����ն���
Queue *create_empty_queue()
{
	Queue *queue;
	ListNode *head;

	queue = (Queue *)malloc(sizeof(Queue));
	head = (ListNode *)malloc(sizeof(ListNode));

	queue->front = queue->rear = head;

	return queue;
}

//�ж϶����Ƿ�Ϊ��
int is_empty_queue(Queue *queue)
{
	if (queue->rear == queue->front)
		return 1;
	else
		return 0;
}

//���
int EnterQueue(Queue *queue, int data)
{
	ListNode *temp;

	temp = (ListNode *)malloc(sizeof(ListNode));
	temp->data = data;
	temp->next = NULL;

	queue->rear->next = temp;
	queue->rear = temp;

	return 0;
}

//����
int DelQueue(Queue *queue)
{
	ListNode *temp;

	temp = queue->front;
	queue->front = queue->front->next;
	free(temp);
	temp = NULL;

	return queue->front->data;
}

//ͼ�Ĺ�ȱ���
int BFS(GRAPH *pG, int v)
{
	Queue *queue = create_empty_queue();
	int i = 0;

	memset(&visit, 0, sizeof(visit));

	EnterQueue(queue, v);
	visit[v] = 1;

	while (!is_empty_queue(queue))
	{
		v = DelQueue(queue);
		printf("V%d ", pG->vex[v]);


		for (i = 0; i < pG->n; i++)
		{
			if (visit[i] == 0 && pG->adjmatrix[v][i] == 1)
			{
				EnterQueue(queue, i);
				visit[i] = 1;
			}
		}
	}

	printf("\n");

	return 0;
}

int main()
{
	GRAPH G;
	//int n;

	//���붥�㣬��ʼ��ͼ
	init_graph(&G);

	//��ʼ���ڽӾ���
	input_edge(&G);

	//ͼ����ȱ���
	DFS(&G, 0);

	//ͼ�Ĺ�ȱ���
	BFS(&G, 0);

	return 0;
}
#endif