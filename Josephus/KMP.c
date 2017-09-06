#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
typedef char *String;

void GetNext(String T, int *next)
{
	int j = 0, i = 1;
	next[1] = 0;
	while (i<T[0])
	{
		if (j == 0 || T[i] == T[j])
		{
			//j = 1 (ǰ׺), i=3 (��׺)
			i++;
			j++;
			//=====================================================
			next[i] = j;
			//=======================================================

			//==============================================
			//�ִ�������ȵ�����Ż�����
			/*if (T[i] != T[j])
			{
				next[i] = j;
			}
			else
			{
				next[i] = next[j];
			}*/
			
		}
		else
		{
			//j����   ǰ׺�ǹ̶���, ��׺����Ե�

			j = next[j];

		}
	}
}

//�����Ӵ�T������s��pos���ַ�֮���λ�� �粻�����򷵻�0
int IndexKMP(String s, String T, int pos)
{
	//��ʼ����λ��
	int i = pos;
	int j = 1;
	int next[255];

	GetNext(T, next);

	while (i<=s[0] && j<= T[0])
	{
		if ((j == 0) || (s[i] = T[j]))
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	if (j > T[0])
	{
		return i - T[0];
	}
	else
	{
		return 0;
	}
}

int main()
{
	char T[9] = { 'a', 'b', 'a', 'b', 'a', 'a', 'a', 'b', 'a' };
	char str[255] = " ababaaaba";
	int next[255];

	int i = 1;
	str[0] = 9;

	GetNext(str, next);

	for ( i = 1; i < 10; i++)
	{
		printf("%d ", next[i]);

	}

	system("pause");
	return 0;
}

#endif