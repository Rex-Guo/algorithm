#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

void print()
{
	char c;
	scanf("%c", &c);

	if (c != '#')
	{
		print();
	}

	if (c != '#')
	{
		printf("%c", c);
	}
}

int count = 0;

//row �� j ��
int notDanger(int row, int j, int(*chess)[8])
{
	int i, k, flag0 = 0, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;

	//�ж��з���
	for (i = row, k = j ; k < 8; k++)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag0 = 1;
			break;
		}
	}

	//�ж��з���
	for (i = 0; i < 8; i++)
	{
		if (*(*(chess + i) + j) != 0)
		{
			flag1 = 1;
			break;
		}
	}

	//�ж����Ϸ�
	for (i = row, k = j; i >= 0 && k >= 0; i--, k--)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag2 = 1;
			break;
		}
	}

	//�ж����·�
	for (i = row, k = j; i < 8 && k < 8; i++, k++)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag3 = 1;
			break;
		}
	}

	//�ж����Ϸ�
	for (i = row, k = j; i >= 0 && k < 8; i--, k++)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag4 = 1;
			break;
		}
	}

	//�ж����·�
	for (i = row, k = j; i < 8 && k >= 0; i++, k--)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag5 = 1;
			break;
		}
	}

	if (flag0 || flag1 || flag2 || flag3 || flag4 || flag5)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//row ��ʾ��ʼ�� n ��ʾ���� int(*chess)[8] ��ʾָ������ÿһ�е�ָ��
void EightQueen(int row, int n, int(*chess)[8])
{
	int chess2[8][8], i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			chess2[i][j] = chess[i][j];
		}
	}

	if (8 == row)
	{
		printf("�� %d ��\n", count + 1);
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				printf("%d ", *(*(chess2 + i) + j));
			}
			printf("\n");
		}
		printf("\n");
		count++;
		if (count == 8)
		{
			system("pause");
		}
	}
	else
	{
		//�ж����λ���Ƿ���Σ��
		//���û��Σ�� ��������  j������
		for (j = 0; j < n; j++)
		{
			//�ж��Ƿ�Σ��
			if (notDanger(row, j, chess))
			{
				for (i = 0; i < 8; i++)
				{
					*(*(chess2 + row) + i) = 0;
				}
				*(*(chess2 + row) + j) = 1;

				EightQueen(row + 1, n, chess2);
			}
		}
	}
}
//8�ʺ�����
void main()
{
	int chess[8][8], i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			chess[i][j] = 0;
		}
	}

	EightQueen(0, 8, chess);

	printf("�ܹ��� %d �ֽ������\n\n", count);

	//print();

	int u = 10;
	int *p = &u;
	//�����ſ��Զ�ָ����в���
	printf("%d", p[0]);
	printf("%d", p[1]);

	system("pause");
	return 0;
}

#endif