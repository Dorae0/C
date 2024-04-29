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
	printf("난수 맞추기 프로그램입니다.\n");
	
	while(loopcount < 3)
	{
		if(loopcount == 0)
			Answer = answerInit();

		printf("%d번째 시도입니다. 숫자를 입력하세요 : \n", loopcount + 1);
		scanf("%d", &userNum);
		
		if (userNum == Answer)
		{
			printf("정답입니다. 포인트가 10점 추가되었습니다! 다음 난수를 맞추어 주세요. \n");
			count++;
			loopcount = 0;
		}
		else
		{
			loopcount++;
			if (userNum == 2 && Answer == 1 || userNum == 9 && Answer == 10)
				printf("...\n");
			else if (userNum < Answer)
				printf("%d보다 큽니다. \n", userNum);
			else if (userNum > Answer)
				printf("%d보다 작습니다. \n", userNum);
		}
	}

	printf("\n<최종 점수는 %d점입니다.>\n", count * 10);
	_getch();
}

int answerInit()
{
	int randomInit;
	randomInit = rand() % 10 + 1;
	return randomInit;
}