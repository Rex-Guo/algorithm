#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include "CriticalPath.h"  
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_LENGTH 26 //��������󳤶�
#define WORD_LENGTH 20 //������󳤶�

//����
typedef struct Word
{
	char English[WORD_LENGTH];
	char Chinese[WORD_LENGTH];
	struct Word *next;
}Word, *PWordList;

//������
typedef struct
{
	char ch;        //����ֵ
	PWordList pWord;//ָ�򵥴�����
}Index;


Index indexTable[MAX_LENGTH];  //������
int length;                    //��������

//���ֲ��ҷ�����������,���ҵ������±꣬����ʧ�ܣ�����Ҫ�����λ��
int binarySearch(char ch, int low, int high)
{
	int mid = (low + high) / 2;
	if (low>high)
		return low;
	if (indexTable[mid].ch == ch)
		return mid;
	else if (indexTable[mid].ch>ch)
		binarySearch(ch, low, mid - 1);
	else
		binarySearch(ch, mid + 1, high);
}

//���ļ��ж��뵥�ʣ������ֵ�
void createDictionary()
{
	FILE *fp;
	char str[WORD_LENGTH * 3];
	PWordList Pword = 0;
	int i, j, m = 0, index;

	if ((fp = fopen("document/dictionary.txt", "r")) == NULL){
		printf("can not open file!\n");
		exit(0);
	}

	while (!feof(fp)){
		Pword = (PWordList)malloc(sizeof(Word));
		i = j = m = 0;
		fgets(str, WORD_LENGTH * 3, fp);
		while (str[i] != '\n'){
			if (m == 0){
				if (str[i] == ' '){
					m = 1;
					Pword->English[j] = '\0';
					j = 0;
				}
				else{
					if (str[i] >= 'A'&&str[i] <= 'Z')
						str[i] += 32;
					Pword->English[j++] = str[i];
				}
			}
			if (m == 1){
				if (str[i] != ' ')
					Pword->Chinese[j++] = str[i];
			}
			i++;
		}
		Pword->Chinese[j] = '\0';

		//ȡ���ʵ�����ĸ�����������������ڣ���������ʲ����������ָ��ķ����У������ڣ�����������͵���
		index = binarySearch(Pword->English[0], 0, length - 1);
		if (indexTable[index].ch == Pword->English[0]){//�鵽������
			Pword->next = indexTable[index].pWord;
			indexTable[index].pWord = Pword;
		}
		else{//����ʧ��
			for (i = length; i >= index; i--)
				indexTable[i + 1] = indexTable[i];
			length++;
			indexTable[index].ch = Pword->English[0];
			Pword->next = NULL;
			indexTable[index].pWord = Pword;
		}

		//	printf("%-10s%-10s\n",word.English,word.Chinese);
	}

	if (fclose(fp)){
		printf("can not close file!\n");
		exit(0);
	}
}

//���ҵ���,���ɹ�����NULL���ɹ������������
PWordList search(char *word)
{
	int i = 0, index;
	PWordList p = 0;
	PWordList pWord = NULL;
	while (word[i]){
		if (word[i] >= 'A'&&word[i] <= 'Z')
			word[i] += 32;
		i++;
	}
	index = binarySearch(word[0], 0, length - 1);
	if (indexTable[index].ch == word[0]){//�鵽������
		p = indexTable[index].pWord;
		while (p){
			if (strcmp(p->English, word) == 0){
				pWord = (PWordList)malloc(sizeof(Word));
				strcpy(pWord->Chinese, p->Chinese);
				strcpy(pWord->English, p->English);
				pWord->next = NULL;
				break;
			}
			p = p->next;
		}
	}
	return pWord;
}

int main()
{
	PWordList p = 0;
	char word[WORD_LENGTH];
	createDictionary();
	printf("������Ҫ���ҵĵ��ʣ�\n");
	gets(word);
	p = search(word);
	if (p){
		printf("�ҵ��õ��ʣ�\n%-20s%-20s\n", p->English, p->Chinese);
		free(p);
	}
	else
		printf("����ҵĵ��ʲ�����!\n");

	system("pause");
	return 0;

}
#endif