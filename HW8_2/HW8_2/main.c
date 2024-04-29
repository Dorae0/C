#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "char.h"

void main()
{	
	CHARACTER* ch[MAX];
	characterInit(ch);
	gameLoop(ch);

	for (int i = 0; i < MAX; i++)
		if (ch[i] != NULL)
		{
			free(ch[i]);
			ch[i] = NULL;
		}
}