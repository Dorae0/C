#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#define ROULETTE_TIME 50000

void printScoremenu();
void slotmachineGame();
int calculateScore(int slotInt1, int slotInt2, int slotInt3);
int miniGame();

void main()
{
	srand((unsigned)time(NULL));
	int menuflag = 0;

	printf("--------\n");
	printf("���� �ӽ� �����Դϴ�. \n");
	start:
	printf("�޴��� ������ �ּ��� : \n");

	printf("1. ���� ���� ���� \n2. ���� ����\n");

	scanf("%d", &menuflag);

	switch (menuflag)
	{
	case 1:
		printScoremenu();
		goto start;
		break;
	case 2:
		slotmachineGame();
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�. �ٽ� �Է��� �ּ��� : \n");
		goto start;
	}
}

void printScoremenu()
{
	printf("--------\n\n");
	printf("7 7 7 : + 1000�� \n\n");
	printf("�� �ڸ��� ��� ���� ���� (7 ����) : + 100�� \n\n");
	printf("�� �ڸ� �� �� �ڸ��� ���� ���� : + 10�� \n\n");
	printf("�� �ڸ� ��� �ٸ� ���� : - 1�� \n\n");
	printf("������ 0�� �Ǹ� ���� �����Դϴ�. \n\n");
	printf("--------\n\n");
}

void slotmachineGame()
{
	int score = 0;
	int Timecount = 0;
	int slotInt1 = 0;
	int slotInt2 = 0;
	int slotInt3 = 0;

	score = miniGame();

	printf("\n\n--------\n\n");
	printf("������ �����մϴ�. : \n\n");
	printf("--------\n\n");

	while (1)
	{
		int time1 = ROULETTE_TIME;
		int time2 = ROULETTE_TIME;
		int time3 = ROULETTE_TIME;
		printf("���� �ӽ��� ���� �ð��� ������ �ּ��� : ");
		scanf("%d", &Timecount);
		printf("\n--------\n\n");

		int roundscore = 0;

		if (score <= 0)
		{
			printf("������ 0�� �Ǿ����ϴ�. ���� �����Դϴ�. \n");
			_getch();
			return;
		}
		else
		{
			while (Timecount--)
			{
				slotInt1 = rand() % 10;
				slotInt2 = rand() % 10;
				slotInt3 = rand() % 10;
			}
			while (time1--)
			{
				slotInt1 = rand() % 10;
				slotInt2 = rand() % 10;
				slotInt3 = rand() % 10;

				printf("\r < %d %d %d > ", slotInt1, slotInt2, slotInt3);
			}
			while (time2--)
			{
				slotInt2 = rand() % 10;
				slotInt3 = rand() % 10;

				printf("\r < %d %d %d > ", slotInt1, slotInt2, slotInt3);
			}
			while (time3--)
			{
				slotInt3 = rand() % 10;

				printf("\r < %d %d %d > ", slotInt1, slotInt2, slotInt3);
			}

			roundscore = calculateScore(slotInt1, slotInt2, slotInt3);
			score += roundscore;
			if (roundscore == -1)
				printf("�ƽ����ϴ�! -1���Դϴ�. ���� ������ %d���Դϴ�.\n", score);
			else
				printf("�����մϴ�! %d���Դϴ�. ���� ������ %d���Դϴ�.\n", roundscore, score);
		}
	}
}

int calculateScore(int slotInt1, int slotInt2, int slotInt3)
{
	if (slotInt1 == 7 && slotInt2 == 7 && slotInt3 == 7)
		return 1000;
	else if (slotInt1 == slotInt2 && slotInt2 == slotInt3)
		return 100;
	else if (slotInt1 == slotInt2 || slotInt1 == slotInt3 || slotInt2 == slotInt3)
		return 10;
	else
		return -1;
}

int miniGame()
{
	char minigametype = 'a';
	int answer = 0;
	int rand2 = 0;
	int select1 = 0;
	int select2 = 0;
	answer = rand() % 3 + 1;
	rand2 = rand() % 2;

	printf("--------\n\n");
	printf("�⺻ ����Ʈ ȹ�� ������ �����մϴ�. : \n\n");
	printf("--------\n\n");

	printf("�� ���� �� �� �ϳ����� 100�� ����ֽ��ϴ�. \n");
	printf("������ �ΰ��� ������ 10�� ����ֽ��ϴ�. \n");
	printf("�ϳ��� ���� ������ ���Ŀ���, 10�� ����ִ� �� �ϳ��� �����մϴ�. \n");
	printf("�� ���Ŀ� ���� �ٲ� ������ �ٲ��� ���� ������ �����մϴ�. \n");
	printf("�� ������ ���� �������� �Ͽ� �⺻���� �����˴ϴ�. \n");
	printf("ȹ�� ������ �����ϰ� 50������ ������ ���� �ֽ��ϴ�. \n\n");

	printf("--------\n\n");
	printf("����Ʈ ȹ�� �̴ϰ����� �Ͻðڽ��ϱ�? (Y / N) : \n\n");
	printf("--------\n\n");

	scanf(" %c", &minigametype);

	switch (minigametype)
	{
	case 'n':
	case 'N':
		printf("����Ʈ ȹ�� �̴ϰ����� �����ϰ� 50������ �����մϴ�. \n");
		return 50;
		break;
	case 'y':
	case 'Y':
		printf("--------\n\n");
		printf("����Ʈ ȹ�� �̴ϰ����� �����մϴ�. \n\n");
		break;
	}

	printf("�� �� �� �� ���� �� �� �ϳ��� ������ �ּ��� : (1 / 2 / 3) ");
	

	scanf(" %d", &select1);

	switch (select1)
	{
	case 1:
		if (select1 == answer)
		{
			switch (rand2)
			{
			case 0:
				printf("�� �� �� 2�� ���� ���Ƚ��ϴ�. ������ ������ �ּ��� : (1 / 2 / 3) ");
				break;
			case 1:
				printf("�� �� �� 3�� ���� ���Ƚ��ϴ�. ������ ������ �ּ��� : (1 / 2 / 3) ");
				break;
			}
		}
		else
		{
			switch (answer)
			{
			case 2:
				printf("�� �� �� 3�� ���� ���Ƚ��ϴ�. ������ ������ �ּ��� : (1 / 2 / 3) ");
				break;
			case 3:
				printf("�� �� �� 2�� ���� ���Ƚ��ϴ�. ������ ������ �ּ��� : (1 / 2 / 3) ");
				break;
			}
		}
		break;
	case 2:
		if (select1 == answer)
		{
			switch (rand2)
			{
			case 0:
				printf("�� �� �� 1�� ���� ���Ƚ��ϴ�. ������ ������ �ּ��� : (1 / 2 / 3) ");
				break;
			case 1:
				printf("�� �� �� 3�� ���� ���Ƚ��ϴ�. ������ ������ �ּ��� : (1 / 2 / 3) ");
				break;
			}
		}
		else
		{
			switch (answer)
			{
			case 1:
				printf("�� �� �� 3�� ���� ���Ƚ��ϴ�. ������ ������ �ּ��� : (1 / 2 / 3) ");
				break;
			case 3:
				printf("�� �� �� 1�� ���� ���Ƚ��ϴ�. ������ ������ �ּ��� : (1 / 2 / 3) ");
				break;
			}
		}
		break;
	case 3:
		if (select1 == answer)
		{
			switch (rand2)
			{
			case 0:
				printf("�� �� �� 1�� ���� ���Ƚ��ϴ�. ������ ������ �ּ��� : (1 / 2 / 3) ");
				break;
			case 1:
				printf("�� �� �� 2�� ���� ���Ƚ��ϴ�. ������ ������ �ּ��� : (1 / 2 / 3) ");
				break;
			}
		}
		else
		{
			switch (answer)
			{
			case 1:
				printf("�� �� �� 2�� ���� ���Ƚ��ϴ�. ������ ������ �ּ��� : (1 / 2 / 3) ");
				break;
			case 2:
				printf("�� �� �� 1�� ���� ���Ƚ��ϴ�. ������ ������ �ּ��� : (1 / 2 / 3) ");
				break;
			}
		}
		break;
	}

	scanf(" %d", &select2);

	if (select2 == answer)
	{
		switch (answer)
		{
		case 1:
			printf("\r�� �� �� 1�� ���� �����̾����ϴ�. 100���� ȹ���߽��ϴ�. ");
			break;
		case 2:
			printf("\r�� �� �� 2�� ���� �����̾����ϴ�. 100���� ȹ���߽��ϴ�. ");
			break;
		case 3:
			printf("\r�� �� �� 3�� ���� �����̾����ϴ�. 100���� ȹ���߽��ϴ�. ");
			break;
		}
		return 100;
	}
	else
	{
		switch (answer)
		{
		case 1:
			printf("\r�� �� �� 1�� ���� �����̾����ϴ�. 10���� ȹ���߽��ϴ�. ");
			break;
		case 2:
			printf("\r�� �� �� 2�� ���� �����̾����ϴ�. 10���� ȹ���߽��ϴ�. ");
			break;
		case 3:
			printf("\r�� �� �� 3�� ���� �����̾����ϴ�. 10���� ȹ���߽��ϴ�. ");
			break;
		}
		return 10;
	}
}