#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand() �Լ�
#include <conio.h>  // getch() �Լ�
#include <time.h>   // time() �Լ�

#define RETURN_KEY 13

void main()
{
	int  nRandom;

	printf(">> ����Ű�� ������ ������ �߻��մϴ� ( 0 ~ 7 ) << \n");
	printf(">> ���� �̿��� Ű�� ������ ���α׷��� ����˴ϴ�. << \n");

	int cGetC = 0;
	cGetC = _getch();
	if (cGetC != RETURN_KEY) return;

	printf("\n");

	//// ����� ���� �ٸ� ���� �߻���Ű�� ���� �ð��� ����
	//// ���α׷� ����� ���� �ѹ��� ���ش�
	srand((unsigned)time(NULL));

	//// ������ �������� 0~7������ ������ �߻�
	nRandom = rand() % 8;

	if (nRandom == 0)
		puts("������ 0�Դϴ�");
	else if (nRandom == 1)
		puts("������ 1�Դϴ�");
	else if (nRandom == 2)
		puts("������ 2�Դϴ�");
	else if (nRandom == 3)
		puts("������ 3�Դϴ�");
	else if (nRandom >= 4 && nRandom <= 5)
		puts("������ 4 ~ 5�Դϴ�");
	else
		puts("������ 6 ~ 7�Դϴ�");
}