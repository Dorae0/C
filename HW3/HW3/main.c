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
	
	if (Operator == '+')
		answer = Operand[0] + Operand[1];
	else if (Operator == '-')
		answer = Operand[0] - Operand[1];
	else if (Operator == '*')
		answer = Operand[0] * Operand[1];
	else if (Operator == '/' || Operator == '%')
	{
		if (Operand[1] == 0)
			flag = 2;
		else
		{
			if (Operator == '/')
				answer = Operand[0] / Operand[1];
			else if (Operator == '%')
				answer = (int)Operand[0] % (int)Operand[1];
		}
	}
	else
		flag = 1;

	if (flag == 0)
		printf("��� ���� %f�Դϴ�.\n", answer);
	else if (flag == 1)
		printf("���Ŀ� ���� �ʴ� ���Դϴ�.\n");
	else
		printf("����� �� ���� ���Դϴ�.\n");
	printf("--------\n");
}