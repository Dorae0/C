#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "Display.h"

int UserNum = 0;

void main()
{
	int answer = 0;
	printf("���ϴ� �������� �� ���ڸ� �Է��� �ּ��� : \n");

	while (1)
	{	
		scanf("%d", &UserNum);
		if (UserNum < 2 || UserNum > 9)
			printf("������ ������ϴ�. �ٽ� �Է��� �ּ��� : \n");
		else
		{
			answer = Display();
			printf("%d���� ������ �� ���� %d\n", UserNum, answer);
			break;
		}
	}
	_getch();
}