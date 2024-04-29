#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "Display.h"

int UserNum = 0;

void main()
{
	int answer = 0;
	printf("원하는 구구단의 단 숫자를 입력해 주세요 : \n");

	while (1)
	{	
		scanf("%d", &UserNum);
		if (UserNum < 2 || UserNum > 9)
			printf("범위를 벗어났습니다. 다시 입력해 주세요 : \n");
		else
		{
			answer = Display();
			printf("%d단의 마지막 전 값은 %d\n", UserNum, answer);
			break;
		}
	}
	_getch();
}