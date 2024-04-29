#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printAll();
void printSelected(int selnum);

void main()
{
	int flag = 0;
	int selnumflag = 1;
	int selnum = 0;

	printf("--------\n");
	printf("������ ���α׷��Դϴ�. \n");

	while (1)
	{
		printf("���Ͻô� �޴��� �����ϼ��� : \n");
		printf("1. ������ ��� ���\n"); printf("2. ���ϴ� �� ����\n"); printf("3. �ý��� ����\n");

		scanf("%d", &flag);

		switch (flag)
		{
		case 1:
			printAll();
			break;
		case 2:
			selnumflag = 1;
			do
			{
				printf("���ϴ� ���� ���ڸ� �Է��� �ּ��� : (2 ~ 9)\n");
				scanf("%d", &selnum);
				if (selnum >= 2 && selnum <= 9)
					selnumflag = 0;
				else
					printf("������ ������ϴ�. �ٽ� �Է��� �ּ��� : \n");
			} while (selnumflag);
			printSelected(selnum);
			break;
		case 3:
			printf("�ý����� �����մϴ�. \n");
			_getch();
			return;
		default:
			printf("�߸��� �����Դϴ�. �ٽ� �Է��� �ּ��� : \n");
		}
	}
}

void printAll()
{
	int printnum = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			for (int k = i * 3 + 2; k < i * 3 + 5; k++)
			{
				if(k < 10)
					printf("%d x %d = %2d  ", k, j, k * j);
			}
			printf("\n");
		}
		printf("\n");
	}
}

void printSelected(int selnum)
{
	if (selnum > 9 || selnum < 2)
	{
		_getch();
		return;
	}
	printf("%5d��\n", selnum);
	for(int i = 1; i < 10; i++)
		printf("%d x %d = %2d  \n", selnum, i, selnum);
	printf("\n");
}