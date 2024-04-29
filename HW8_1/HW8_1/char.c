#include "char.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void characterInit(CHARACTER* ch)
{
	srand((unsigned)time(NULL)); // srand
	for (int i = 0; i < MAX; i++) // ��ü �ʱ�ȭ
	{
		(ch + i)->bIsLive = TRUE; // bIsLive = TRUE
		(ch + i)->nLife = rand() % 51 + 50; // nLife = 50 ~ 100
	}
}

void gameLoop(CHARACTER* ch)
{
	srand((unsigned int)time(NULL)); // srand
	int DeadCharIdx[MAX] = { 0, }; // ���� ĳ������ Index (���� �ѹ��� Count)
	int TempCharNum[MAX / 10] = { 0, }; // ��ü ���� ĳ������ 10%�� �̴� ���� ����
	int TurnNum = 0;

	printf("<<������ �����մϴ�>>\n");
	getchar();

	while (++TurnNum)
	{
		int NewDeadChar = 0; // ���� ĳ���� �� (�̹� ��)
		int DeadChar = 0; // ���� ĳ���� �� (�̹� �� ����)
		int DeadCharIdxNum = 0; // ���� ĳ������ Index ��
		int AvoidChar = 0; // ���� ���� ĳ���� ��

		for (int i = 0; i < MAX; i++)
		{
			if ((ch + i)->bIsLive) // ����ִٸ�
			{
				(ch + i)->nDamage = rand() % 11; // ������ ���� (0 ~ 10)
				(ch + i)->nLife -= (ch + i)->nDamage; // nLife���� nDamage ����
				if ((ch + i)->nDamage == 0) // �������� 0�̶��?
					AvoidChar++; // ���ߴٰ� ����
				if ((ch + i)->nLife < 0) // nLife�� 0�� �ƴٸ�?
				{
					(ch + i)->bIsLive = FALSE; // ���� ǥ��
					NewDeadChar++; // �̹� �� ���� ĳ���� �� ǥ��
					DeadCharIdx[DeadCharIdxNum] = i; // ���� ĳ���� �迭�� �߰�
					DeadCharIdxNum++; // ���� ĳ���� Index ++
				}
			}
			else
			{
				DeadChar++; // �̹� �� ���� ���� ĳ���� �� ǥ��
				DeadCharIdx[DeadCharIdxNum] = i; // ���� ĳ���� �迭�� �߰�
				DeadCharIdxNum++; // ���� ĳ���� Index ++
			}
		}

		int TDeadChar = DeadChar + NewDeadChar; // ��� ����

		for (int i = 0; i < TDeadChar / 10; i++) // �ߺ� ���� ���� ���� (10%��)
		{
			TempCharNum[i] = rand() % TDeadChar;
			for (int j = 0; j < i; j++)
				if (TempCharNum[i] == TempCharNum[j])
					i--;
		}

		for (int i = 0; i < TDeadChar / 10; i++) // ��Ȱ
			Revive(ch, DeadCharIdx[TempCharNum[i]]);
		
		system("cls");
		printChar(ch);
		printResult(TDeadChar, TDeadChar / 10, NewDeadChar, TDeadChar + AvoidChar, TurnNum); // PrintResult

		getchar(); // �� ���� ��ư
	}
}

void Revive(CHARACTER* ch, int idx) // ��Ȱ �Լ�
{
	srand((unsigned)time(NULL)); // ����
	(ch + idx)->bIsLive = TRUE; // bIsLive = TRUE
	(ch + idx)->nLife = rand() % 51 + 50; // nLife �ٽ� ����. (50 ~ 100)
}

void printChar(CHARACTER* ch) // ��ü ��� �Լ�
{
	for (int i = 0; i < MAX; i++)
	{
		if ((ch + i)->bIsLive)
			printf("%3d/��/%2d/%3d  ",i + 1, (ch + i)->nDamage, (ch + i)->nLife); // ��������� ���
		else
			printf("%3d/��/%2d/%3d  ",i + 1, (ch + i)->nDamage, (ch + i)->nLife); // �׾������� ���
		if (i % 10 == 9)
			printf("\n");
	}
}

void printResult(int TDeadChar, int reviveChar, int NewDeadChar, int AvoidChar, int TurnNum) // Print �Լ�
{
	printf("<<%d��° �� ����Դϴ�>>\n", TurnNum);
	printf("<<���� ĳ���� : %d��>>\n", MAX - TDeadChar);
	printf("<<��� ĳ���� : %d��>>\n", TDeadChar);
	printf("<<��Ȱ ĳ���� : %d��>>\n", reviveChar);
	printf("<<�̹� �������� ���� ĳ���� : %d��>>\n", NewDeadChar);
	printf("<<�̹� ���ݿ� ���� ���� ���� ĳ���� : %d��>>\n", AvoidChar);
	printf("\nŰ�� �Է��ϼ���>>\n\n");
}