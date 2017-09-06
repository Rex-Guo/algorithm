#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include<math.h>
#define MAX 100
int  Search_Seq(int array[], int n, int k)/*�������в����±�Ԫ�ص�ֵ��k*/
{
	int  i = 0;
	array[n] = k;
	while (array[i] != k) i++;
	if (i<n) return i;
	else return -1;
}             //˳�����
double length(int n)
{
	int i, sum = 0;
	double ave;
	for (i = 0; i <= n; i++)
	{
		sum = sum + i;
	}
	ave = sum / n;
	return i;
}

void bubble(int *p, int n)  //�Ľ��ĵط�
{
	int i, j, temp;          /*������*/
	for (i = 0; i<n - 1; i++)
	{
		for (j = 0; j<n - i - 1; j++)
		{
			if (p[j]>p[j + 1])
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}
double loga(double n, double base)
{
	return log(n) / log(base);
}
int Search_Bin(int array[], int n, int key)/*�������в��ҹؼ��ֳ�����n��Ԫ��,����ҵ��������ĵ�ַ,else����-1*/
{
	int l, r, mid;
	l = 0;
	r = n - 1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (key == array[mid])
			return mid;   /*�ҵ��˷��ص�ַ*/
		else if (key<array[mid])
			r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}       //�۰����

int Search_Blk(int array[], int n, int k)
{
	int i, j;
	for (i = 3; i<MAX; i += 4)
	{
		if (k == array[i])
		{
			printf("��%d����Ϊ%d", i, k);
			return 1;
		}
		else if (k<array[i])
		{
			for (j = i - 3; j<i; j++)
			{
				if (k == array[j])
				{
					// printf("��%d����Ϊ%d",j,k);
					return 1;
				}
			}
			break;
		}
	}//�ֿ����
}

void main()
{
	int i, k, m, n, result;
	double ave;
	int array[MAX];
	printf("�������ָ���:\n");
	scanf("%d", &n);
	printf("�������ֵ�ֵ:\n");
	for (i = 0; i<n; i++)
		scanf("%d", &array[i]);
	printf("��������ҵ�����:");
	scanf("%d", &k);
	printf("������ҷ�ʽ1 ˳����ң�2 �۰���ң�3 �ֿ����:");
	scanf("%d", &m);
	switch (m)
	{
	case 1:
		printf("      ˳�����!\n");
		result = Search_Seq(array, n, k);
		if (result >= 0)
		{
			printf("��Ҫ���ҵ���λ�ڵ�%dλ!\n", result + 1);
			ave = length(n);
			printf("ƽ�����ҳ���Ϊ%f", ave);
		}
		else
			printf("      ����ʧ��!\n");
		break;
	case 2:
		bubble(array, n);
		for (i = 0; i<n; i++)   //���������<=��i=n���һ�����������ʾ��������  
		{
			printf(" %d", array[i]);
			if ((i + 1) % 5 == 0)
				printf("\n");
		}
		printf("      �۰����!\n");
		result = Search_Bin(array, n, k);
		if (result >= 0)
		{
			printf("��Ҫ���ҵ���λ�ڵ�%dλ!\n", result + 1);
			ave = loga(n + 1, 2) - 1;
			printf("ƽ�����ҳ���Ϊ%f", ave);
		}
		else
			printf("      ����ʧ��!\n");
		break;
	case 3:
		bubble(array, n);
		for (i = 0; i<n; i++)
		{
			printf(" %d", array[i]);
			if ((i + 1) % 5 == 0)
				printf("\n");
		}
		printf("      �ֿ����!\n");
		result = Search_Blk(array, n, k);
		if (result >= 0)
			printf("��Ҫ���ҵ���λ�ڵ�%dλ!\n", result + 1);
		else
			printf("      ����ʧ��!\n");
		//  printf("      �ֿ����!\n");
		result = Search_Blk(array, n, k);
		break;
	default:
		printf("1 ˳����ң�2 �۰���ң�3 �ֿ����!\n");
		return;
	}

	system("pause");
}

#endif