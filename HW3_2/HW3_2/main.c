#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	srand((unsigned)time(NULL));
	int randomInt = rand() % 10 + 1;

	int userNum;

	printf("--------\n");
	printf("난수 맞추기 프로그램입니다. 숫자를 입력하세요 : \n");

	scanf("%d", &userNum);

	if (userNum == 2 && randomInt == 1 || userNum == 9 && randomInt == 10)
		printf("...\n");
	else if (userNum < randomInt)
		printf("%d보다 큽니다. 정답을 입력하세요 : \n", userNum);
	else if (userNum > randomInt)
		printf("%d보다 작습니다. 정답을 입력하세요 : \n", userNum);
	else if (userNum == randomInt)
	{
		printf("정답입니다.\n");
		return;
	}
		
	scanf("%d", &userNum);

	if(userNum == randomInt)
		printf("정답입니다.\n");
	else
		printf("오답입니다.\n");
	printf("--------\n");
}