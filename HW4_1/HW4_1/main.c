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
	printf("구구단 프로그램입니다. \n");

	while (1)
	{
		printf("원하시는 메뉴를 선택하세요 : \n");
		printf("1. 구구단 모두 출력\n"); printf("2. 원하는 단 선택\n"); printf("3. 시스템 종료\n");

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
				printf("원하는 단의 숫자를 입력해 주세요 : (2 ~ 9)\n");
				scanf("%d", &selnum);
				if (selnum >= 2 && selnum <= 9)
					selnumflag = 0;
				else
					printf("범위를 벗어났습니다. 다시 입력해 주세요 : \n");
			} while (selnumflag);
			printSelected(selnum);
			break;
		case 3:
			printf("시스템을 종료합니다. \n");
			_getch();
			return;
		default:
			printf("잘못된 숫자입니다. 다시 입력해 주세요 : \n");
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
	printf("%5d단\n", selnum);
	for(int i = 1; i < 10; i++)
		printf("%d x %d = %2d  \n", selnum, i, selnum);
	printf("\n");
}