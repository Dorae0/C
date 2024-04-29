#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "mem.h"

#define TRUE 1
#define FALSE 0
#define BOOL int

void main()
{
	BOOL flag = TRUE;
	int memsize = 10000;
	char c1[100] = "ABCDE";
	char c2[100] = "BCDEF";
	char* c3; char* c4;
	c3 = __crossmemcpy(c2, c1, 10);
	printf("%s\n", c3);
	c4 = __randmem(memsize);
	printf("\n");
	flag = __scanmem(c4, (memsize * 4 + memsize / 10) + 1);
	free(c3); free(c4);
	c3 = NULL; c4 = NULL;
}