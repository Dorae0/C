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
	printf("���� ���߱� ���α׷��Դϴ�. ���ڸ� �Է��ϼ��� : \n");

	scanf("%d", &userNum);

	if (userNum == 2 && randomInt == 1 || userNum == 9 && randomInt == 10)
		printf("...\n");
	else if (userNum < randomInt)
		printf("%d���� Ů�ϴ�. ������ �Է��ϼ��� : \n", userNum);
	else if (userNum > randomInt)
		printf("%d���� �۽��ϴ�. ������ �Է��ϼ��� : \n", userNum);
	else if (userNum == randomInt)
	{
		printf("�����Դϴ�.\n");
		return;
	}
		
	scanf("%d", &userNum);

	if(userNum == randomInt)
		printf("�����Դϴ�.\n");
	else
		printf("�����Դϴ�.\n");
	printf("--------\n");
}