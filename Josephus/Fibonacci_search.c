#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include "CriticalPath.h"  
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

#define MAXSIZE 20

void fibonacci(int *f)    //����쳲���������
{
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < MAXSIZE; ++i)
		f[i] = f[i - 2] + f[i - 1];
}
int fibonacci_search(int *a, int key, int n)
{
	int low = 0, high = n - 1;
	int mid = 0;
	int k = 0;
	int F[MAXSIZE];
	fibonacci(F);
	while (n > F[k] - 1) //�����n��쳲������е�λ��
	{
		++k;
	}
		
	for (int i = n; i < F[k] - 1; ++i) //�����鲹ȫ��ʹ��a[n-1]
	{
		a[i] = a[high];
	}
		
	while (low <= high){
		mid = low + F[k - 1] - 1;  //����쳲��������н��лƽ�ָ�
		if (a[mid] > key)
		{
			high = mid - 1;
			k = k - 1;
		}
		else if (a[mid] < key)
		{
			low = mid + 1;
			k = k - 2;

		}
		else{
			if (mid <= high) //���Ϊ�����ҵ���Ӧ��λ��
			{
				return mid;
			}
				
			else
			{
				return -1;
			}	
		}
	}
	return -1;
}

int main()
{

	int a[MAXSIZE] = { 5, 15, 19, 20, 25, 31, 38, 41, 45, 49, 52, 55, 57 };
	int k;
	printf("������Ҫ���ҵ�����:\n");
	scanf("%d", &k);
	int pos = fibonacci_search(a, k, 13);
	if (pos != -1)
	{
		printf("������ĵ�%d��λ���ҵ�Ԫ��:%d\n", pos + 1, k);
	}		
	else
	{
		printf("δ���������ҵ�Ԫ��:%d\n", k);
	}		
	system("pause");
	return 0;
}

#endif