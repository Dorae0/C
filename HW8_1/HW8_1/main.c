#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "char.h"

void main()
{
	CHARACTER ch[MAX];
	characterInit(ch);
	gameLoop(ch);
}