#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	char Operator = 'a';
	float Operand[2] = { 0.0f, };
	short int flag = 0;
	float answer = 0;

	printf("--------\n간이 계산기입니다. +, -, *, /, %% 연산을 수행합니다. (%% 연산은 int로 캐스트하여 진행됩니다.)\n\n계산식을 형식에 맞게 입력해 주세요 : \n");
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
		printf("결과 값은 %f입니다.\n", answer);
		break;
	case 1:
		printf("형식에 맞지 않는 식입니다.\n");
		break;
	default:
		printf("계산할 수 없는 식입니다.\n");
		break;
	}
	printf("--------\n");
}