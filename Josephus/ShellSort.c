#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

void ShellSort(int a[], int n)
{
	int i, j, temp;
	int gap = n / 2;

	while (gap >= 1)
	{
		for (i = gap; i < n; i++)
		{
			if (a[i] < a[i - gap])
			{
				temp = a[i];
				j = i - gap;
				//ֱ�Ӳ�������,�ҵ���Ҫ�����λ��
				while (j >= 0 && a[j] > temp)
				{
					a[j + gap] = a[j];
					////��ǰ������ǰһ���������
					j = j - gap;
				}
				//�ҵ���Ҫ�����λ��
				a[j + gap] = temp;
			}
		}
		gap = gap / 2;
	}
}
int main()
{
	printf("%d\n", 1 / 2);
	int i;//;a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	int a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	//int a[10] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 };
	ShellSort(a, 10);

	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);

	}

	system("pause");
	return 0;
}
#endif