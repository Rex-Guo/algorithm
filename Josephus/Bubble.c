#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

//�������ͨ��������ð������,��Ϊ���������ȶ�,���Ե�i�����ͺ���������αȶ�,Ч�ʲ�����
//void BubbleSort(int k[], int n)
//{
//	int i, j, temp;
//	for ( i = 0; i < n-1; i++)
//	{
//		for (j = i+1; j < n; j++)
//		{
//			if (k[i] > k[j])
//			{
//				temp = k[j];
//				k[j] = k[i];
//				k[i] = temp;
//			}
//		}
//	}
//}
//
//void BubbleSort(int k[], int n)
//{
//	int i, j, temp, flag = 1;
//	for (i = 0; i < n; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{		
//			if (k[i] > k[j])
//			{
//				temp = k[i];
//				k[i] = k[j];
//				k[j] = temp;				
//			}
//		}
//
//	}
//}



//ð������ĺ���������Ԫ�������ȽϽ��н�����
//ͨ���۲���Կ����������i�������������˳���Ѿ�������,�Ͳ����ٽ��жԱ��������ԣ����ǿ���ͨ������һ����Ǳ�������������е����Ƿ���ѭ������ǰ���Ѿ��ź���
//void BubbleSort(int k[], int n)
//{
//	int i, j, temp, flag = 1,m;
//	for (i = 0; i < n; i++)
//	{
//		if (flag)
//		{
//			flag = 0;
//			//ÿһ���ɵ����ϵ�����  
//			for (j = n - 1; j > i; j--)
//			{
//				if (k[j - 1] > k[j])
//				{
//					temp = k[j - 1];
//					k[j - 1] = k[j];
//					k[j] = temp;
//					flag = 1;
//				}
//			}
//		}
//
//		for ( m = 0; m < n; m++)
//		{
//
//			printf("%3d", k[m]);
//		}
//		printf("\n");
//	}
//}
//��򵥵�������ʽ(����ð������)
//ͨ�����±�Ϊ0������str[0]����ʣ������9�������жԱȽ������������߷������±�Ϊ0��λ���ϣ����Ϳ��Եõ���10������С���Ǹ�
//10������С����λȷ���󣬽�������Ҫ��ʣ��9������С���Ǹ���
//��Ϊ�Ѿ�ȷ����һ����С���������ԾͲ�Ҫ��str[0]��ֱ�Ӵ�str[1]��ʼ����ʣ�µ�8�����ԱȽ������ҳ�9��������С����λ�ŵ��±�Ϊ1��str[1]����λ����
//�����������˼·�Ϳ��Խ���ʮ�����������ģ���С���󣩵�����
//void Sort(int k[], int n)
//{
//	int i, j, temp, m;
//	for (i = 0; i < n; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			//�������󽻻�
//			if (k[j] < k[i])
//			{
//				temp = k[i];
//				k[i] = k[j];
//				k[j] = temp;				
//			}
//
//		}
//
//		for (m = 0; m < n; m++)
//		{
//			printf("%3d", k[m]);
//		}
//		printf("\n");
//	}
//}

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

//int main()
//{
//	int i, a[10] = {5,2,6,0,3,9,1,7,4,8};
//	BubbleSort(a, 10);
//
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%d", a[i]);
//
//	}
//
//	system("pause");
//	return 0;
//}


void BubbleSort(int k[], int n)
{
	int i, j, temp, flag = 1;
	for ( i = 0; i < n-1; i++)
	{
		if (flag == 1)
		{
			for (j = n - 1; j > i; j--)
			{
				flag = 0;
				//ǰһ���ͺ�һ�������Ƚ� ���û�з����ƶ�˵������Ķ����Ѿ��ź���� k[j - 1] > k[j] �����ٳ���
				if (k[j - 1] > k[j])
				{
					temp = k[j - 1];
					k[j - 1] = k[j];
					k[j] = temp;
					flag = 1;
				}
			}
		}		
	}
}

int main()
{
	int i;//;a[10] = { 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
	int a[10] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 };
	BubbleSort(a, 10);

	for ( i = 0; i < 10; i++)
	{
		printf("%d", a[i]);

	}

	system("pause");
	return 0;
}


#endif