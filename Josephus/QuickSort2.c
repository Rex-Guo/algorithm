#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

int Partition(int a[], int low, int high)
{
	int point, temp;
	//mΪ�м�λ��
	int m = low + (high - low) / 2;

	//��λ���ڸ�λ�����ϴ������������λ
	if (a[low] > a[high])
	{
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
	}
	//�м�λ�ô��ڸ�λ�ϴ����������λ
	if (a[m] > a[high])
	{
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
	}
	//���������������λ���Ѿ�����������,����м�����ȵ�λ�󽻻�,ȷ���������е��м���Ǹ�����low��λ����
	if (a[m] > a[low])
	{
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
	}

	point = a[low];

	while (low < high)
	{
		while (low < high && a[high] >= point)
		{
			high--;
		}

		temp = a[low];
		a[low] = a[high];
		a[high] = temp;

		while (low<high && a[low] <= point)
		{
			low++;
		}

		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
	}

	return low;
}


void QuickSort(int a[], int low, int high)
{
	int point;
	if (low < high)
	{
		point = Partition(a, low, high);
		QuickSort(a, low, point - 1);
		QuickSort(a, point + 1, high);
	}
}


//����ʵ��
int main()
{
	int i;//;a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	int a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	//int a[10] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 };
	QuickSort(a, 0, 9);

	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);

	}

	system("pause");
	return 0;
}
#endif