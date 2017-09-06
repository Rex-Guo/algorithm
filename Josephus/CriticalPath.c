#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include "CriticalPath.h"  
#include <stdio.h>
#include <stdlib.h>
int *etv, *ltv; //�¼����緢��ʱ�����ٷ���ʱ������  
int top2; //����Stack2��ָ��  
int *Stack2; //���ڴ洢�������е�ջ  
void CreateGraph(Graph *G) //����ͼ  
{
	EdgeNode *e = NULL;
	G->NumVertex = 10;
	G->NumEdge = 13;
	//��ʼ��ͼ
	for (int i = 0; i < G->NumVertex; ++i)
	{
		G->Vertex[i].data = i;
		G->Vertex[i].in = 0;
		G->Vertex[i].FirstEdge = NULL;
	}
	//������������Ϣ  
	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v0 -> v1 ȨֵΪ3  
	e->next = G->Vertex[0].FirstEdge;
	e->AdjVex = 1;
	e->weight = 3;
	G->Vertex[0].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v0 -> v2 ȨֵΪ4  
	e->next = G->Vertex[0].FirstEdge;
	e->AdjVex = 2;
	e->weight = 4;
	G->Vertex[0].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v1 -> v3 ȨֵΪ5  
	e->next = G->Vertex[1].FirstEdge;
	e->AdjVex = 3;
	e->weight = 5;
	G->Vertex[1].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v1 -> v4 ȨֵΪ6  
	e->next = G->Vertex[1].FirstEdge;
	e->AdjVex = 4;
	e->weight = 6;
	G->Vertex[1].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v2 -> v3 ȨֵΪ8  
	e->next = G->Vertex[2].FirstEdge;
	e->AdjVex = 3;
	e->weight = 8;
	G->Vertex[2].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v2 -> v5 ȨֵΪ7  
	e->next = G->Vertex[2].FirstEdge;
	e->AdjVex = 5;
	e->weight = 7;
	G->Vertex[2].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v3 -> v4 ȨֵΪ3  
	e->next = G->Vertex[3].FirstEdge;
	e->AdjVex = 4;
	e->weight = 3;
	G->Vertex[3].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v4 -> v6 ȨֵΪ 9  
	e->next = G->Vertex[4].FirstEdge;
	e->AdjVex = 6;
	e->weight = 9;
	G->Vertex[4].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v4 -> v7 Ȩֵ 4  
	e->next = G->Vertex[4].FirstEdge;
	e->AdjVex = 7;
	e->weight = 4;
	G->Vertex[4].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v5 -> v7 ȨֵΪ6  
	e->next = G->Vertex[5].FirstEdge;
	e->AdjVex = 7;
	e->weight = 6;
	G->Vertex[5].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v6 -> v9 ȨֵΪ2  
	e->next = G->Vertex[6].FirstEdge;
	e->AdjVex = 9;
	e->weight = 2;
	G->Vertex[6].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v7 -> v8 ȨֵΪ5  
	e->next = G->Vertex[7].FirstEdge;
	e->AdjVex = 8;
	e->weight = 5;
	G->Vertex[7].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;

	e = (EdgeNode*)malloc(sizeof(EdgeNode)); //v8 -> v9 ȨֵΪ3  
	e->next = G->Vertex[8].FirstEdge;
	e->AdjVex = 9;
	e->weight = 3;
	G->Vertex[8].FirstEdge = e;
	++G->Vertex[e->AdjVex].in;
}
void TopoLogicalSort(Graph *G)
{
	int *Stack;   //���ڴ洢���Ϊ0�Ķ����±� 
	int top = 0;  // Stackջ��ָ��  
	int count = 0; //ͳ������Ķ�����  
	int gettop; //ȥ���Ķ����±�  
	Stack = (int *)malloc(sizeof(int) * G->NumVertex);
	top2 = 0;
	Stack2 = (int *)malloc(sizeof(int) * G->NumVertex); //�洢�������������  
	for (int i = 0; i < G->NumVertex; ++i)
	{
		if (!(G->Vertex[i].in)) //�����Ϊ0�Ķ���洢��Stackջ��  
		{
			Stack[++top] = i;
		}			
	}
	etv = (int*)malloc(sizeof(int) * G->NumVertex);
	for (int i = 0; i < G->NumVertex; ++i) //�¼����緢��ʱ���ʼ��Ϊ0  
	{
		etv[i] = 0;
	}
	while (top != 0) //Stackջ��Ϊ��,������δ������Ķ���  
	{
		gettop = Stack[top--]; //��ջ  
		count++;
		Stack2[++top2] = gettop; //���Ѵ���Ķ���ѹ��Stack2ջ��  
		//      printf("V%d ",G->Vertex[gettop].data);  
		for (EdgeNode *e = G->Vertex[gettop].FirstEdge; e; e = e->next) //�����±�Ϊgettop�Ķ��������ӵĶ���  
		{
			int k = e->AdjVex;
			if (!(--G->Vertex[k].in)) //�����ָ��Ķ�����ȼ�1Ϊ0�Ļ�ѹ��Stackջ��  
			{
				Stack[++top] = k;
			}				
			if (etv[gettop] + e->weight > etv[k]) //�¼����緢����ʱ��  
			{
				etv[k] = etv[gettop] + e->weight;
			}				
		}
	}
	////��ӡ������,����
	//while (top2)
	//{
	//	printf("%d:%d:\n", Stack2[top2], etv[top2]);
	//	top2--;
	//}
	//  printf("\n");  
	if (count < G->NumVertex) //�������û����ȫ���  
	{
		printf("�����������,���򼴽��˳�:\n");
		system("pause");
		exit(1);
	}
}
void CriticalPath(Graph *G)
{
	int ete, lte; //�����¼����緢��ʱ�����ٷ���ʱ��ı���  
	TopoLogicalSort(G); //�����������¼������緢��ʱ�����������Stack2  
	ltv = (int *)malloc(sizeof(EdgeNode) * G->NumVertex);

	//��ʼ���¼�������ʱ��  ����ʼ��Ϊ���ֵ(���ʱ��)
	for (int i = 0; i < G->NumVertex; ++i) 
	{
		ltv[i] = etv[G->NumVertex - 1];
	}
	//����ltv��ֵ ��ջ�������ltv�Ļ��ʱ��ֵ������ǰ�ݼ�ֱ��ջ��
	//�ӻ�㵹�����������ltv
	while (top2 != 0) //���Stack2ջ��Ϊ��  
	{
		int gettop = Stack2[top2--]; //��ջ  
		for (EdgeNode *e = G->Vertex[gettop].FirstEdge; e; e = e->next) //�����±�Ϊgettop�Ķ��������ӵĶ���  
		{
			int k = e->AdjVex;
			if (ltv[k] - e->weight < ltv[gettop])
			{
				ltv[gettop] = ltv[k] - e->weight;
			}				
		}
	}
	//ͨ��etv��ltv����ete��lte
	for (int i = 0; i < G->NumVertex; ++i)
	{
		for (EdgeNode *e = G->Vertex[i].FirstEdge; e; e = e->next)
		{
			//kΪ��ǰѡ���Ķ���i����һ������ ete����i������緢��ʱ��, lteΪ��һ����k��ltv(������ʱ��)-e��Ȩֵ(i-k��Ȩֵ),���������Ⱦ��ڹؼ�·����
			int k = e->AdjVex;
			ete = etv[i];  //�¼����緢��ʱ��  
			lte = ltv[k] - e->weight; //�¼�������ʱ��  
			if (ete == lte) //��ȼ��ڹؼ�·����  
			{
				printf(" <V%d -> V%d) weight: %d\n", G->Vertex[i].data, G->Vertex[k].data, e->weight);
			}
		}
	}
}
int main()
{
	Graph G;
	CreateGraph(&G);
	//TopoLogicalSort(&G);
	CriticalPath(&G);
	system("pause");
	return 0;
}
#endif