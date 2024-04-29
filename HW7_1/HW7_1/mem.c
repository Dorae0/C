#define _CRT_SECURE_NO_WARNINGS
#include "mem.h"
#include "string.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define BOOL int

unsigned char* __crossmemcpy(const unsigned char* pSrc2, const unsigned char* pSrc1, int nSize)
{
	char* answer;
	answer = (char*)malloc(sizeof(char) * (nSize + 1));
	if (answer != NULL)
	{
		int src1Len = __strlen(pSrc1);
		int src2Len = __strlen(pSrc2);
		int diff = src1Len - src2Len;

		int min = src1Len > src2Len ? src2Len : src1Len;

		for (int i = 0; i < min; i++)
		{
			*(answer + i * 2) = *(pSrc1 + i);
			*(answer + i * 2 + 1) = *(pSrc2 + i);
		}
		if (diff > 0)
			__strcpy((answer + min * 2), (pSrc1 + min));
		else if (diff < 0)
			__strcpy((answer + min * 2), (pSrc2 + min));
		*(answer + nSize) = '\0';
		return answer;
	}
	return NULL;
}

unsigned char* __randmem(int nSize)
{
	srand((unsigned) time(NULL));
	char* answer;
	int tSize = nSize * 4 + nSize / 10;
	answer = (char*)malloc(sizeof(char) * (tSize + 1));

	if (answer != NULL)
	{
		int randN = 0;
		for (int i = 1; i <= tSize; i++)
		{
			if (i % 41 == 0)
				*(answer + i - 1) = '\n';
			else
			{
				if ((i % 41) % 4 == 1)
					randN = rand() % 26;
				*(answer + i - 1) = 'A' + randN;
			}
		}
		*(answer + tSize) = '\0';
		printf("%s", answer);
		return answer;
	}
	return NULL;
}

BOOL __scanmem(unsigned char* pMem, int nSize)
{
	if (pMem != NULL)
	{
		for (int i = 0; i < nSize; i++)
		{
			switch (*(pMem + i))
			{
			case 'G' :
				*(pMem + i) = 'P';
				break;
			case 'A':
				*(pMem + i) = 'I';
				break;
			case 'M':
				*(pMem + i) = 'K';
				break;
			case 'E':
				*(pMem + i) = 'A';
				break;
			}
		}
		printf("%s", pMem);
		return TRUE;
	}
	return FALSE;
}