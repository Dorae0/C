#define _CRT_SECURE_NO_WARNINGS
#include "Display.h"

extern int UserNum;

int Display()
{
	for (int i = 1; i < 10; i++)
		printf("%d x %d = %2d \n", UserNum, i, UserNum * i);
	return UserNum * 8;
}