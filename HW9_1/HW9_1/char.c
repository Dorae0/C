#include "char.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void characterInit(CHARACTER* ch[])
{
	srand((unsigned)time(NULL)); // srand

	for (int i = 0; i < MAX; i++)
		ch[i] = (CHARACTER*)malloc(sizeof(CHARACTER));

	for (int i = 0; i < MAX; i++) // ��ü �ʱ�ȭ
	{
		if (ch[i] != NULL)
		{
			ch[i]->nLife = rand() % 51 + 50; // nLife = 50 ~ 100
			ch[i]->nDamage = 0;
		}
	}
}

void gameLoop(CHARACTER* ch[], int TurnNum, int NewDeadChar, int DeadChar, int AvoidChar)
{
	srand((unsigned int)time(NULL)); // srand
	int DeadCharIdx[MAX] = { 0, }; // ���� ĳ������ Index (���� �ѹ��� Count)
	int TempCharNum[MAX / 10] = { 0, }; // ��ü ���� ĳ������ 10%�� �̴� ���� ����
	char getc = 'a';

	system("cls");
	gotoxy(52, 13);
	printf("<<������ �����մϴ�>>\n");
	getchar();

	if (TurnNum != 0)
		goto PRINT;

	while (++TurnNum)
	{
		NewDeadChar = 0; // ���� ĳ���� �� (�̹� ��)
		AvoidChar = 0; // ���� ���� ĳ���� ��
		DeadChar = 0; // ���� ĳ���� �� (�̹� �� ����)
		int DeadCharIdxNum = 0; // ���� ĳ������ Index ��

		for (int i = 0; i < MAX; i++)
		{
			if (ch[i] != NULL) // ����ִٸ� : ch[i]�� NULL�� �ƴ� ����.
			{
				ch[i]->nDamage = rand() % 11; // ������ ���� (0 ~ 10)
				ch[i]->nLife -= ch[i]->nDamage; // nLife���� nDamage ����
				if (ch[i]->nDamage == 0) // �������� 0�̶��?
					AvoidChar++; // ���ߴٰ� ����
				if (ch[i]->nLife < 0) // nLife�� 0�� �ƴٸ�?
				{
					NewDeadChar++; // �̹� �� ���� ĳ���� �� ǥ��
					DeadCharIdx[DeadCharIdxNum] = i; // ���� ĳ���� �迭�� �߰�
					DeadCharIdxNum++; // ���� ĳ���� Index ++
					free(ch[i]); // ���� ǥ�� (free)
					ch[i] = NULL;
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
	PRINT:
		system("cls");
		printChar(ch);
		TDeadChar = DeadChar + NewDeadChar;
		printResult(TDeadChar, TDeadChar / 10, NewDeadChar, TDeadChar + AvoidChar, TurnNum); // PrintResult

		getc = _getch(); // �� ���� ��ư
		if (getc == 's' || getc == 'S')
			saveData(ch, TurnNum, NewDeadChar, DeadChar, AvoidChar);
	}
}

void Revive(CHARACTER* ch[], int idx) // ��Ȱ �Լ�
{
	srand((unsigned)time(NULL)); // ����
	ch[idx] = (CHARACTER*)malloc(sizeof(CHARACTER));
	if (ch[idx] != NULL)
	{
		ch[idx]->nLife = rand() % 51 + 50; // nLife �ٽ� ����. (50 ~ 100)
		ch[idx]->nDamage = 0;
	}
}

void printChar(CHARACTER* ch[]) // ��ü ��� �Լ�
{
	for (int i = 0; i < MAX; i++)
	{
		if (ch[i] != NULL)
			printf("%3d/��/%2d/%3d  ", i + 1, ch[i]->nDamage, ch[i]->nLife); // ��������� ���
		else
			printf("%3d/��/ 0/  0  ", i + 1); // �׾������� ���
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