#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define FETCH 1000
#define RATE 0.0171
//����ʵ��
//int main()
//{
//	
//	double a[49];
//	int i;
//	a[48] = 1000.0;
//
//	for (i = 47; i > 0; i--)
//	{
//		a[i] = (double)(a[i + 1] + 1000.0 / (1 + 0.172 / 12));
//	}
//	for (i = 48; i >0; i--)
//	{
//		printf("��%d��:%2f\n", i, a[i]);
//	}
//	system("pause");
//	return 0;
//}

//ð������ĺ���������Ԫ�������ȽϽ��н�����
//ͨ���۲���Կ����������i�������������˳���Ѿ�������,�Ͳ����ٽ��жԱ��������ԣ����ǿ���ͨ������һ����Ǳ�������������е����Ƿ���ѭ������ǰ���Ѿ��ź���
void BubbleSort(int k[], int n)
{
	int i, j, temp, flag = 1,m;
	for (i = 0; i < n; i++)
	{
		if (flag)
		{
			flag = 0;
			//ÿһ���ɵ����ϵ�����  
			for (j = n - 1; j > i; j--)
			{
				if (k[j - 1] > k[j])
				{
					temp = k[j - 1];
					k[j - 1] = k[j];
					k[j] = temp;
					flag = 1;
				}
			}
		}
		
		for ( m = 0; m < n; m++)
		{
			
			printf("%3d", k[m]);
		}
		printf("\n");
	}
}

void BubbleSort1(int k[], int n)
{
	int i, j, temp, flag = 1, m;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n -i ; j++)
		{
			if (k[j - 1] > k[j])
			{
				temp = k[j - 1];
				k[j - 1] = k[j];
				k[j] = temp;
				flag = 1;
			}

		}

		for (m = 0; m < n; m++)
		{
			printf("%3d", k[m]);
		}
		printf("\n");
	}
}

//��򵥵�������ʽ(����ð������)
//ͨ�����±�Ϊ0������str[0]����ʣ������9�������жԱȽ������������߷������±�Ϊ0��λ���ϣ����Ϳ��Եõ���10������С���Ǹ�
//10������С����λȷ���󣬽�������Ҫ��ʣ��9������С���Ǹ���
//��Ϊ�Ѿ�ȷ����һ����С���������ԾͲ�Ҫ��str[0]��ֱ�Ӵ�str[1]��ʼ����ʣ�µ�8�����ԱȽ������ҳ�9��������С����λ�ŵ��±�Ϊ1��str[1]����λ����
//�����������˼·�Ϳ��Խ���ʮ�����������ģ���С���󣩵�����
//�����Ѿ���ѡ��������
void Sort(int k[], int n)
{
	int i, j, temp, m,l;
	for (i = 0; i < n; i++)
	{
		l = i;
		for (j = i+1; j < n; j++)
		{			
			if (k[j] < k[l])
			{
				l = j;							
			}
		}
		if(l!=i)
		{
			temp = k[l];
			k[l] = k[i];
			k[i] = temp;
		}
		

		for (m = 0; m < n; m++)
		{
			printf("%3d", k[m]);
		}
		printf("\n");
	}
}

int main()
{
	int i;//;a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	int a[10] = { 5, 2, 96, 0, 3, 9, 1, 7, 4, 8 };

	for (i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);

	}
	printf("\n");
	Sort(a, 10);
	//BubbleSort1(a, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);

	}
	printf("\n");
	system("pause");
	return 0;
}
#endif