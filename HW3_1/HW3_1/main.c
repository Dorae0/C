#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	char Operator = 'a';
	float Operand[2] = { 0.0f, };
	short int flag = 0;
	float answer = 0;

	printf("--------\n���� �����Դϴ�. +, -, *, /, %% ������ �����մϴ�. (%% ������ int�� ĳ��Ʈ�Ͽ� ����˴ϴ�.)\n\n������ ���Ŀ� �°� �Է��� �ּ��� : \n");
	scanf("%f %c %f", &Operand[0], &Operator, &Operand[1]);

	switch (Operator)
	{
	case '+':
		answer = Operand[0] + Operand[1];
		break;
	case '-':
		answer = Operand[0] - Operand[1];
		break;
	case '*':
		answer = Operand[0] * Operand[1];
		break;
	case '/':
	case '%':
		if (Operand[1] == 0)
			flag = 2;
		else
		{
			switch (Operator)
			{
			case '/':
				answer = Operand[0] / Operand[1];
				break;
			case '%':
				answer = (int)Operand[0] % (int)Operand[1];
				break;
			}
		}
		break;
	default:
		flag = 1;
		break;
	}

	switch (flag)
	{
	case 0:
		printf("��� ���� %f�Դϴ�.\n", answer);
		break;
	case 1:
		printf("���Ŀ� ���� �ʴ� ���Դϴ�.\n");
		break;
	default:
		printf("����� �� ���� ���Դϴ�.\n");
		break;
	}
	printf("--------\n");
}