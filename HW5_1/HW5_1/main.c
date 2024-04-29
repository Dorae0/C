#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "Max.h"
#include "Min.h"
#include "Sum.h"
#include "FloatSum.h"

void main()
{
	printf("Int 2개를 입력하시오 : \n");
	int firstVar = 0;
	int secondVar = 0;
	scanf("%d %d", &firstVar, &secondVar);

	printf("Float 2개를 입력하시오 : \n");
	float firstVarFloat = 0.0f;
	float secondVarFloat = 0.0f;
	scanf("%f %f", &firstVarFloat, &secondVarFloat);

	printf("Max : %d\n", Max(firstVar, secondVar));
	printf("Min : %d\n", Min(firstVar, secondVar));
	printf("Sum : %d\n", Sum(firstVar, secondVar));
	printf("FloatSum (Cast) : %lf\n", FloatSum((float)firstVar, (float)secondVar));
	printf("FloatSum : %lf\n", FloatSum(firstVarFloat, secondVarFloat));
	_getch();
}