#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include "CriticalPath.h"  
#include <stdio.h>
#include <stdlib.h>

//����������������  
typedef int KeyType;
typedef struct Node
{
	KeyType key;          //�ؼ���  
	struct Node * left;   //����ָ��  
	struct Node * right;  //�Һ���ָ��  
	struct Node * parent; //ָ�򸸽ڵ�ָ��  
}Node, *PNode;

//������������в�����  
//����Ļ�������Ҫ�ı�����ĵ�ַ�����Դ����Ƕ���ָ��  
void inseart(PNode * root, KeyType key)
{
	//��ʼ��������  
	PNode p = (PNode)malloc(sizeof(Node));
	p->key = key;
	p->left = p->right = p->parent = NULL;
	//����ʱ��ֱ����Ϊ�����  
	if ((*root) == NULL){
		*root = p;
		return;
	}
	//���뵽��ǰ��㣨*root��������  
	if ((*root)->left == NULL && (*root)->key > key){
		p->parent = (*root);
		(*root)->left = p;
		return;
	}
	//���뵽��ǰ��㣨*root�����Һ���  
	if ((*root)->right == NULL && (*root)->key < key){
		p->parent = (*root);
		(*root)->right = p;
		return;
	}
	//���ܲ��뵽��ǰ�������Һ��Ӿ��õݹ�ķ�ʽ�ҵ����Բ�����Ľ��
	if ((*root)->key > key)
	{
		inseart(&(*root)->left, key);
	}		
	else if ((*root)->key < key)
	{
		inseart(&(*root)->right, key);
	}		
	else
	{
		return;
	}		
}

//����Ԫ��,�ҵ����عؼ��ֵĽ��ָ�룬û�ҵ�����NULL  
PNode search(PNode root, KeyType key)
{
	if (root == NULL)
	{
		return NULL;
	}
		
	if (key > root->key) //����������  
	{
		return search(root->right, key);
	}		
	else if (key < root->key) //����������  
	{
		return search(root->left, key);
	}		
	else
	{
		return root;
	}		
}

//������С�ؼ���,����ʱ����NULL  
PNode searchMin(PNode root)
{
	if (root == NULL)
	{
		return NULL;
	}		
	if (root->left == NULL)
	{
		return root;
	}
		
	else  //һֱ�������ң�ֱ��û�����ӵĽ�� 
	{
		return searchMin(root->left);
	}		
}

//�������ؼ���,����ʱ����NULL  
PNode searchMax(PNode root)
{
	if (root == NULL)
		return NULL;
	if (root->right == NULL)
		return root;
	else  //һֱ���Һ����ң�ֱ��û���Һ��ӵĽ��  
		return searchMax(root->right);
}

//����ĳ������ǰ��  
PNode searchPredecessor(PNode p)
{
	//����  
	if (p == NULL)
		return p;
	//�����������������������Ǹ�  
	if (p->left)
		return searchMax(p->left);
	//��������,����ĳ��������������������  
	else{
		if (p->parent == NULL)
			return NULL;
		//����Ѱ��ǰ��  
		while (p){
			if (p->parent->right == p)
				break;
			p = p->parent;
		}
		return p->parent;
	}
}

//����ĳ�����ĺ��  
PNode searchSuccessor(PNode p)
{
	//����  
	if (p == NULL)
	{
		return p;
	}
		
	//��������������������С���Ǹ�  
	if (p->right)
	{
		return searchMin(p->right);
	}	
	else{
		//��������,����ĳ��������������������  ���else������Զ������ִ��
		if (p->parent == NULL)
		{
			return NULL;
		}			
		//����Ѱ�Һ��  
		while (p)
		{
			if (p->parent->left == p)
			{
				break;
			}				
			p = p->parent;
		}
		return p->parent;
	}
}

//���ݹؼ���ɾ��ĳ�����,ɾ���ɹ�����1,���򷵻�0  
//����Ѹ����ɾ������ôҪ�ı�����ĵ�ַ�����Դ�����ָ��  
int deleteNode(PNode* root, KeyType key)
{
	PNode q;
	//���ҵ�Ҫɾ���Ľ��  
	PNode p = search(*root, key);
	KeyType temp;    //�ݴ��̽���ֵ  
	//û�鵽�˹ؼ���  
	if (!p)
	{
		return 0;
	}		
	//1.��ɾ�����Ҷ�ӽ�㣬ֱ��ɾ��  
	if (p->left == NULL && p->right == NULL){
		//ֻ��һ��Ԫ�أ�ɾ��֮����һ�ſ���  
		if (p->parent == NULL){
			free(p);
			(*root) = NULL;
		}
		else{
			//ɾ���Ľ���Ǹ��ڵ������  
			if (p->parent->left == p)
			{
				p->parent->left = NULL;
			}				
			else  //ɾ���Ľ���Ǹ��ڵ���Һ��� 
			{
				p->parent->right = NULL;
			}				
			free(p);
		}
	}

	//2.��ɾ���ֻ��������  
	else if (p->left && !(p->right))
	{
		p->left->parent = p->parent;
		//���ɾ���Ǹ���㣬Ҫ�ı丸�ڵ�ָ��  
		if (p->parent == NULL)
		{
			*root = p->left;
		}	
		else if (p->parent->left == p)
		{
			//ɾ���Ľ���Ǹ��ڵ������  
			p->parent->left = p->left;
		}			
		else 
		{
			//ɾ���Ľ���Ǹ��ڵ���Һ���  
			p->parent->right = p->left;
		}
			
		free(p);
	}
	//3.��ɾ���ֻ���Һ���  
	else if (p->right && !(p->left))
	{
		p->right->parent = p->parent;
		//���ɾ���Ǹ���㣬Ҫ�ı丸�ڵ�ָ��  
		if (p->parent == NULL)
		{
			*root = p->right;
		}
		else if (p->parent->left == p)
		{
			//ɾ���Ľ���Ǹ��ڵ������  
			p->parent->left = p->right;
		}			
		else 
		{
			//ɾ���Ľ���Ǹ��ڵ���Һ��� 
			p->parent->right = p->right;
		}			
		free(p);
	}
	//4.��ɾ���Ľ��������ӣ������Һ���  
	//�ý��ĺ�̽��϶���������(�ο�������Һ�̽�㺯��)  
	//ɾ����̽��,��̽���ֵ����ý��  
	else{
		//�ҵ�Ҫɾ�����ĺ��  
		//q = searchSuccessor(p);
		//�ҵ�Ҫɾ������ǰ��  
		q = searchPredecessor(p);
		temp = q->key;
		//ɾ����̽��  
		deleteNode(root, q->key);
		p->key = temp;
	}
	return 1; 
}

//����һ�ö��������  
void create(PNode* root, KeyType *keyArray, int length)
{
	int i;
	//����������������  
	for (i = 0; i < length; i++)
	{
		inseart(root, keyArray[i]);
	}		
}
//�������������������
void midTravl(PNode root)
{
	if (root != NULL)
	{
		midTravl(root->left);
		printf("%d\n", root->key);
		midTravl(root->right);
	}
}
//�����������У������ؼ�����Ωһ�ġ�
int main()
{
	int i;
	PNode root = NULL;
	KeyType nodeArray[11] = { 15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9 };
	create(&root, nodeArray, 11);
	//deleteNode(&root, 13);
	//deleteNode(&root, 7);
	deleteNode(&root, 6);
	/*for (i = 0; i < 2; i++)
	{
		deleteNode(&root, nodeArray[i]);
	}	*/	
	printf("%d\n", searchPredecessor(root)->key);
	printf("%d\n", searchSuccessor(root)->key);
	printf("%d\n", searchMin(root)->key);
	printf("%d\n", searchMax(root)->key);
	//printf("%d\n", search(root, 13)->key);
	printf("--�������--\n");
	midTravl(root);
	system("pause");
	return 0;
}
#endif