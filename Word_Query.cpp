#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

class word 
{
public:
	char name[30];
	int num;
	word *next;
};

//查询
void readfile(word*&head)
{
	FILE *fp;
	if ((fp = fopen("test.txt", "r")) == NULL) // 打开的文件名
	{
		cout << "无法打开文件" << endl;
		exit(0);
	}
	char ch, temp[30];
	word *p;
	while (!feof(fp))
	{
		int i = 0;

		ch = fgetc(fp);

		temp[0] = ' ';

		while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || temp[0] == ' ')
		{
			if (ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z')
			{
				temp[i] = ch;
				i++;
			}
			ch = fgetc(fp);
			if (feof(fp)) break;
		}
		temp[i] = '\0';

		p = head->next;
		while (p)
		{
			if (!_stricmp(temp, p->name))
			{
				p->num++; break;
			}
			p = p->next;
		}
		if (!p&&temp[0] != '\0')
		{
			p = new word;
			strcpy(p->name, temp);
			p->num = 1;
			p->next = head->next;
			head->next = p;
		}
	}
}

//排序
void sort(word*&head)
{
	word *q;
	int a[1000], i;
	for (i = 0; i<1000; i++)
		a[i] = 0;
	for (i = 0; i<10; i++)
	{
		q = head;
		while (q != NULL)
		{
			if (q->num>a[i])
				a[i] = q->num;
			else
				q = q->next;
		}
		q = head;
		while (q != NULL)
		{
			if (a[i] == q->num)
			{
				q->num = 0;
				cout << "出现频率:" << a[i] << endl;
				puts(q->name);
				break;
			}
			else
				q = q->next;
		}
	}
}


int main()
{
	word *head;

	head = new word;

	head->next = NULL;

	readfile(head);

	sort(head);

	return 0;
}
