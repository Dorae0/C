#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int answerInit();

void main()
{
	srand((unsigned)time(NULL));
	int userNum = 0;
	int count = 0;
	int loopcount = 0;
	int Answer = 0;

	printf("--------\n");
	printf("���� ���߱� ���α׷��Դϴ�.\n");
	
	while(loopcount < 3)
	{
		if(loopcount == 0)
			Answer = answerInit();

		printf("%d��° �õ��Դϴ�. ���ڸ� �Է��ϼ��� : \n", loopcount + 1);
		scanf("%d", &userNum);
		
		if (userNum == Answer)
		{
			printf("�����Դϴ�. ����Ʈ�� 10�� �߰��Ǿ����ϴ�! ���� ������ ���߾� �ּ���. \n");
			count++;
			loopcount = 0;
		}
		else
		{
			loopcount++;
			if (userNum == 2 && Answer == 1 || userNum == 9 && Answer == 10)
				printf("...\n");
			else if (userNum < Answer)
				printf("%d���� Ů�ϴ�. \n", userNum);
			else if (userNum > Answer)
				printf("%d���� �۽��ϴ�. \n", userNum);
		}
	}

	printf("\n<���� ������ %d���Դϴ�.>\n", count * 10);
	_getch();
}

int answerInit()
{
	int randomInit;
	randomInit = rand() % 10 + 1;
	return randomInit;
}