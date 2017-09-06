#if(1)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

void show(int *a,int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%3d", a[i]);

	}
	printf("\n");
}
void MergeSort(int a[], int n)
{
	int i,next, left_min, left_max, right_min, right_max;
	int *temp = (int*)malloc(n*sizeof(int));
	
	//iΪ����,��1��ʼÿ������һ��
	for (i = 1; i < n; i=i*2)
	{
		for (left_min = 0; left_min < n - i; left_min = right_max)
		{
			left_max = right_min = left_min + i;
			right_max = left_max + i;

			if (right_max > n)
			{
				right_max = n;
			}			

			//��ʱ���������ָ��
			next = 0;
			while (left_min < left_max && right_min < right_max)
			{
				if (a[left_min] < a[right_min])
				{
					temp[next++] = a[left_min++];
					show(temp, 5);					
				}
				else
				{
					temp[next++] = a[right_min++];
					show(temp, 5);					
				}
			}
			show(a, 10);
			//left_min<left_max˵���ұ߲����Ѿ������뵽��temp��������߲�����ʣ��,ʣ�����Ϊ:left_max - left_min��
			//��ʣ��Ĳ����ƶ���a�����right_min��ǰһ��λ�ÿ�ʼ������ǰ�ƶ����
			while (left_min < left_max)
			{
				a[--right_min] = a[--left_max];
				show(a, 10);
			}

			//���right_min < right_max ʣ��������������right�Ŀ������λ��,�����Ѿ��ź��������,�����ƶ�
			

			//����С�������ƶ����������ǰ��
			while (next > 0)
			{
				a[--right_min] = temp[--next];
				show(a, 10);
			}		
		}
	}

}

void MergeSortxxx(int k[], int n)
{
	int i, next, left_min, left_max, right_min, right_max;
	int *temp = (int *)malloc(n * sizeof(int));

	for (i = 1; i < n; i *= 2)
	{
		for (left_min = 0; left_min < n - i; left_min = right_max)
		{
			right_min = left_max = left_min + i;
			right_max = left_max + i;

			if (right_max > n)
			{
				right_max = n;
			}

			next = 0;

			while (left_min < left_max && right_min < right_max)
			{
				if (k[left_min] < k[right_min])
				{
					temp[next++] = k[left_min++];
				}
				else
				{
					temp[next++] = k[right_min++];
				}
			}

			while (left_min < left_max)
			{
				k[--right_min] = k[--left_max];
			}

			while (next > 0)
			{
				k[--right_min] = temp[--next];
			}
		}
	}
}

//����ʵ��
int main()
{
	int i;//;a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	int a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	//int a[10] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 };
	show(a, 10);
	MergeSort(a, 10);

	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);

	}

	system("pause");
	return 0;
}
#endif