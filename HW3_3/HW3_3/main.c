#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand() 함수
#include <conio.h>  // getch() 함수
#include <time.h>   // time() 함수

#define RETURN_KEY 13

void main()
{
	int  nRandom;

	printf(">> 리턴키를 누르면 난수가 발생합니다 ( 0 ~ 7 ) << \n");
	printf(">> 엔터 이외의 키를 누르면 프로그램이 종료됩니다. << \n");

	int cGetC = 0;
	cGetC = _getch();
	if (cGetC != RETURN_KEY) return;

	printf("\n");

	//// 실행시 마다 다른 수를 발생시키기 위해 시간을 적용
	//// 프로그램 실행시 최초 한번만 해준다
	srand((unsigned)time(NULL));

	//// 나머지 연산으로 0~7까지의 난수를 발생
	nRandom = rand() % 8;

	if (nRandom == 0)
		puts("난수는 0입니다");
	else if (nRandom == 1)
		puts("난수는 1입니다");
	else if (nRandom == 2)
		puts("난수는 2입니다");
	else if (nRandom == 3)
		puts("난수는 3입니다");
	else if (nRandom >= 4 && nRandom <= 5)
		puts("난수는 4 ~ 5입니다");
	else
		puts("난수는 6 ~ 7입니다");
}