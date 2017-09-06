#if(0)
#include <stdio.h>
#include <stdlib.h>

#define CardNumber 13

typedef struct node
{
	int data;
	struct node *next;
}sqlist, *linklist;

linklist CreateLinkList()
{
	linklist head = NULL;
	linklist s, r;
	int i;

	r = head;

	for (i = 1; i <= CardNumber; i++)
	{
		s = (linklist)malloc(sizeof(sqlist));
		s->data = 0;		//��ʼ��Ϊ0

		if (head == NULL)
		{
			head = s;
		}
		else
		{
			r->next = s;
		}			
		r = s;
	}
	r->next = head;
	return head;

}

//����˳�����
void Magician(linklist head)
{
	linklist p;
	int j;
	int countnumber = 2;					//��ʾ�Ƶĵ���

	p = head;
	p->data = 1;

	while (1)
	{
		for (j = 0; j<countnumber; j++)
		{
			p = p->next;
			if (p->data != 0)			//�ؼ���
			{
				//p->next;				
				j--;
			}
		}

		if (p->data == 0)					/*0��ʾ��λ�û�δ������*/
		{
			p->data = countnumber;
			countnumber++;

			if (countnumber == 14)
			{
				break;//����һ��ѭ��
			}
						
		}
	}
}

//���ٹ���(�ɲ�д)
void DestoryList(linklist * list)
{
	linklist ptr = *list;
	linklist buff[CardNumber];
	int i = 0;

	while (i<CardNumber)
	{
		buff[i++] = ptr;
		ptr = ptr->next;
	}

	for (i = 0; i<CardNumber; i++)
	{
		free(buff[i]);
	}

	*list = 0;
}

int main()
{
	linklist p;
	int i;

	p = CreateLinkList();
	Magician(p);

	printf("������˳�����У�\n");
	for (i = 0; i<CardNumber; i++)
	{
		printf("����%d ", p->data);
		p = p->next;
	}

	DestoryList(&p);

	system("pause");

	return 0;
}

#endif