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
	printf("슬롯 머신 게임입니다. \n");
	start:
	printf("메뉴를 선택해 주세요 : \n");

	printf("1. 점수 증감 기준 \n2. 게임 실행\n");

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
		printf("잘못된 번호입니다. 다시 입력해 주세요 : \n");
		goto start;
	}
}

void printScoremenu()
{
	printf("--------\n\n");
	printf("7 7 7 : + 1000점 \n\n");
	printf("세 자리가 모두 같은 숫자 (7 제외) : + 100점 \n\n");
	printf("세 자리 중 두 자리가 같은 숫자 : + 10점 \n\n");
	printf("세 자리 모두 다른 숫자 : - 1점 \n\n");
	printf("점수가 0이 되면 게임 오버입니다. \n\n");
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
	printf("게임을 시작합니다. : \n\n");
	printf("--------\n\n");

	while (1)
	{
		int time1 = ROULETTE_TIME;
		int time2 = ROULETTE_TIME;
		int time3 = ROULETTE_TIME;
		printf("슬롯 머신을 돌릴 시간을 설정해 주세요 : ");
		scanf("%d", &Timecount);
		printf("\n--------\n\n");

		int roundscore = 0;

		if (score <= 0)
		{
			printf("점수가 0이 되었습니다. 게임 오버입니다. \n");
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
				printf("아쉽습니다! -1점입니다. 현재 점수는 %d점입니다.\n", score);
			else
				printf("축하합니다! %d점입니다. 현재 점수는 %d점입니다.\n", roundscore, score);
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
	printf("기본 포인트 획득 게임을 시작합니다. : \n\n");
	printf("--------\n\n");

	printf("세 개의 문 중 하나에는 100이 들어있습니다. \n");
	printf("나머지 두개의 문에는 10이 들어있습니다. \n");
	printf("하나의 문을 선택한 이후에는, 10이 들어있는 문 하나를 공개합니다. \n");
	printf("그 이후에 문을 바꿀 것인지 바꾸지 않을 것인지 선택합니다. \n");
	printf("그 선택을 최종 선택으로 하여 기본금이 설정됩니다. \n");
	printf("획득 게임을 포기하고 50점으로 시작할 수도 있습니다. \n\n");

	printf("--------\n\n");
	printf("포인트 획득 미니게임을 하시겠습니까? (Y / N) : \n\n");
	printf("--------\n\n");

	scanf(" %c", &minigametype);

	switch (minigametype)
	{
	case 'n':
	case 'N':
		printf("포인트 획득 미니게임을 포기하고 50점으로 시작합니다. \n");
		return 50;
		break;
	case 'y':
	case 'Y':
		printf("--------\n\n");
		printf("포인트 획득 미니게임을 시작합니다. \n\n");
		break;
	}

	printf("□ □ □ 세 개의 문 중 하나를 선택해 주세요 : (1 / 2 / 3) ");
	

	scanf(" %d", &select1);

	switch (select1)
	{
	case 1:
		if (select1 == answer)
		{
			switch (rand2)
			{
			case 0:
				printf("▣ ⒳ □ 2번 문이 열렸습니다. 정답을 선택해 주세요 : (1 / 2 / 3) ");
				break;
			case 1:
				printf("▣ □ ⒳ 3번 문이 열렸습니다. 정답을 선택해 주세요 : (1 / 2 / 3) ");
				break;
			}
		}
		else
		{
			switch (answer)
			{
			case 2:
				printf("▣ □ ⒳ 3번 문이 열렸습니다. 정답을 선택해 주세요 : (1 / 2 / 3) ");
				break;
			case 3:
				printf("▣ ⒳ □ 2번 문이 열렸습니다. 정답을 선택해 주세요 : (1 / 2 / 3) ");
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
				printf("⒳ ▣ □ 1번 문이 열렸습니다. 정답을 선택해 주세요 : (1 / 2 / 3) ");
				break;
			case 1:
				printf("□ ▣ ⒳ 3번 문이 열렸습니다. 정답을 선택해 주세요 : (1 / 2 / 3) ");
				break;
			}
		}
		else
		{
			switch (answer)
			{
			case 1:
				printf("□ ▣ ⒳ 3번 문이 열렸습니다. 정답을 선택해 주세요 : (1 / 2 / 3) ");
				break;
			case 3:
				printf("⒳ ▣ □ 1번 문이 열렸습니다. 정답을 선택해 주세요 : (1 / 2 / 3) ");
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
				printf("⒳ □ ▣ 1번 문이 열렸습니다. 정답을 선택해 주세요 : (1 / 2 / 3) ");
				break;
			case 1:
				printf("□ ⒳ ▣ 2번 문이 열렸습니다. 정답을 선택해 주세요 : (1 / 2 / 3) ");
				break;
			}
		}
		else
		{
			switch (answer)
			{
			case 1:
				printf("□ ⒳ ▣ 2번 문이 열렸습니다. 정답을 선택해 주세요 : (1 / 2 / 3) ");
				break;
			case 2:
				printf("⒳ □ ▣ 1번 문이 열렸습니다. 정답을 선택해 주세요 : (1 / 2 / 3) ");
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
			printf("\r⒪ ⒳ ⒳ 1번 문이 정답이었습니다. 100점을 획득했습니다. ");
			break;
		case 2:
			printf("\r⒳ ⒪ ⒳ 2번 문이 정답이었습니다. 100점을 획득했습니다. ");
			break;
		case 3:
			printf("\r⒳ ⒳ ⒪ 3번 문이 정답이었습니다. 100점을 획득했습니다. ");
			break;
		}
		return 100;
	}
	else
	{
		switch (answer)
		{
		case 1:
			printf("\r⒪ ⒳ ⒳ 1번 문이 정답이었습니다. 10점을 획득했습니다. ");
			break;
		case 2:
			printf("\r⒳ ⒪ ⒳ 2번 문이 정답이었습니다. 10점을 획득했습니다. ");
			break;
		case 3:
			printf("\r⒳ ⒳ ⒪ 3번 문이 정답이었습니다. 10점을 획득했습니다. ");
			break;
		}
		return 10;
	}
}