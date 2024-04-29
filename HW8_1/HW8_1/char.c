#include "char.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void characterInit(CHARACTER* ch)
{
	srand((unsigned)time(NULL)); // srand
	for (int i = 0; i < MAX; i++) // 전체 초기화
	{
		(ch + i)->bIsLive = TRUE; // bIsLive = TRUE
		(ch + i)->nLife = rand() % 51 + 50; // nLife = 50 ~ 100
	}
}

void gameLoop(CHARACTER* ch)
{
	srand((unsigned int)time(NULL)); // srand
	int DeadCharIdx[MAX] = { 0, }; // 죽은 캐릭터의 Index (루프 한번당 Count)
	int TempCharNum[MAX / 10] = { 0, }; // 전체 죽은 캐릭터의 10%를 뽑는 난수 저장
	int TurnNum = 0;

	printf("<<게임을 시작합니다>>\n");
	getchar();

	while (++TurnNum)
	{
		int NewDeadChar = 0; // 죽은 캐릭터 수 (이번 턴)
		int DeadChar = 0; // 죽은 캐릭터 수 (이번 턴 제외)
		int DeadCharIdxNum = 0; // 죽은 캐릭터의 Index 수
		int AvoidChar = 0; // 공격 피한 캐릭터 수

		for (int i = 0; i < MAX; i++)
		{
			if ((ch + i)->bIsLive) // 살아있다면
			{
				(ch + i)->nDamage = rand() % 11; // 데미지 받음 (0 ~ 10)
				(ch + i)->nLife -= (ch + i)->nDamage; // nLife에서 nDamage 차감
				if ((ch + i)->nDamage == 0) // 데미지가 0이라면?
					AvoidChar++; // 피했다고 가정
				if ((ch + i)->nLife < 0) // nLife가 0이 됐다면?
				{
					(ch + i)->bIsLive = FALSE; // 죽음 표시
					NewDeadChar++; // 이번 턴 죽은 캐릭터 수 표시
					DeadCharIdx[DeadCharIdxNum] = i; // 죽은 캐릭터 배열에 추가
					DeadCharIdxNum++; // 죽은 캐릭터 Index ++
				}
			}
			else
			{
				DeadChar++; // 이번 턴 제외 죽은 캐릭터 수 표시
				DeadCharIdx[DeadCharIdxNum] = i; // 죽은 캐릭터 배열에 추가
				DeadCharIdxNum++; // 죽은 캐릭터 Index ++
			}
		}

		int TDeadChar = DeadChar + NewDeadChar; // 계산 편의

		for (int i = 0; i < TDeadChar / 10; i++) // 중복 없이 난수 생성 (10%만)
		{
			TempCharNum[i] = rand() % TDeadChar;
			for (int j = 0; j < i; j++)
				if (TempCharNum[i] == TempCharNum[j])
					i--;
		}

		for (int i = 0; i < TDeadChar / 10; i++) // 부활
			Revive(ch, DeadCharIdx[TempCharNum[i]]);
		
		system("cls");
		printChar(ch);
		printResult(TDeadChar, TDeadChar / 10, NewDeadChar, TDeadChar + AvoidChar, TurnNum); // PrintResult

		getchar(); // 턴 진행 버튼
	}
}

void Revive(CHARACTER* ch, int idx) // 부활 함수
{
	srand((unsigned)time(NULL)); // 난수
	(ch + idx)->bIsLive = TRUE; // bIsLive = TRUE
	(ch + idx)->nLife = rand() % 51 + 50; // nLife 다시 설정. (50 ~ 100)
}

void printChar(CHARACTER* ch) // 전체 출력 함수
{
	for (int i = 0; i < MAX; i++)
	{
		if ((ch + i)->bIsLive)
			printf("%3d/♥/%2d/%3d  ",i + 1, (ch + i)->nDamage, (ch + i)->nLife); // 살아있을때 출력
		else
			printf("%3d/♡/%2d/%3d  ",i + 1, (ch + i)->nDamage, (ch + i)->nLife); // 죽어있을때 출력
		if (i % 10 == 9)
			printf("\n");
	}
}

void printResult(int TDeadChar, int reviveChar, int NewDeadChar, int AvoidChar, int TurnNum) // Print 함수
{
	printf("<<%d번째 턴 결과입니다>>\n", TurnNum);
	printf("<<생존 캐릭터 : %d명>>\n", MAX - TDeadChar);
	printf("<<사망 캐릭터 : %d명>>\n", TDeadChar);
	printf("<<부활 캐릭터 : %d명>>\n", reviveChar);
	printf("<<이번 공격으로 죽은 캐릭터 : %d명>>\n", NewDeadChar);
	printf("<<이번 공격에 공격 받지 않은 캐릭터 : %d명>>\n", AvoidChar);
	printf("\n키를 입력하세요>>\n\n");
}