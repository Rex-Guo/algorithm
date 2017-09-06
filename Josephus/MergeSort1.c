#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#define MAXSIZE 100

void Merge(int *list1, int list1Size, int *list2, int list2Size)
{
	//i����1���±�,j����2���±�,kΪ��ʱ������±�
	int i, j, k,m;
	int temp[MAXSIZE];

	i = k = j = 0;
	while (i<list1Size && j< list2Size)
	{
		if (list1[i] < list2[j])
		{
			temp[k++] = list1[i++];
		}
		else
		{
			temp[k++] = list2[j++];
		}
	}
	//˵������1��Ԫ����ʣ��,��ʣ�µĿ�������ʱ������
	while (i<list1Size)
	{
		temp[k++] = list1[i++];
	}
	//˵������2��Ԫ����ʣ��,��ʣ�µĿ�������ʱ������
	while (j<list2Size)
	{
		temp[k++] = list2[j++];
	}
	//������1����ʼ��ַ��ʼ������2�Ľ�����ַλ��,����ʱ�������ź����Ԫ�ؿ���������1��
	for (m = 0; m < (list1Size + list2Size); m++)
	{
		list1[m] = temp[m];
	}
}

void MergeSort(int a[], int n)
{
	if (n > 1)
	{
		int *list1 = a;
		int list1Size = n / 2;
		int *list2 = a + n / 2;
		int list2Size = n - list1Size;

		MergeSort(list1, list1Size);
		MergeSort(list2, list2Size);

		Merge(list1, list1Size, list2, list2Size);
	}	
}

//�ݹ�ʵ��
int main()
{
	int i;//;a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	int a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	//int a[10] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 };
	MergeSort(a, 10);

	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);

	}

	system("pause");
	return 0;
}
#endif