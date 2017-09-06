#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

int Partition(int a[], int low, int high)
{
	int point,temp;
	point = a[low];

	while (low < high)
	{
		//�Ӻ�����ǰ��,�ҵ���һ���Ȼ�׼��������ͻ�׼������λ��
		while (low < high && a[high] >= point)
		{
			high--;
		}

		temp = a[low];
		a[low] = a[high];
		a[high] = temp;

		//��ǰ��������,�ҵ���һ���Ȼ�׼��С����,�ͻ�׼������λ��
		while (low<high && a[low] <= point)
		{
			low++;
		}

		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
	}
	//���ص�ǰ��׼����λ��
	return low;
}
   

void QuickSort(int a[], int low,int high)
{
	int point;
	if (low < high)
	{
		//�ҵ���һ����׼��������һ���ƶ����λ��(�Ȼ�׼��������ƶ�������,�Ȼ�׼��С�����ƶ���ǰ��)
		point = Partition(a, low, high);
		//Ȼ���Ե�ǰ��׼����λ�ð���������ֳ��������ٴν��л�׼���Ĳ��ҽ���λ��(�Ȼ�׼��������ƶ�������,�Ȼ�׼��С�����ƶ���ǰ��)
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