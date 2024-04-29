#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include <stdio.h>

int srcLen, dstLen;

int __strlen(char* pStr) // ���� ��ȯ �Լ�
{
	int sLen = 0;
	while (*pStr++ != '\0') // \0 ���ö����� sLen++
		sLen++;
	return sLen;
}

void __strcpy(char* pDst, const char* pSrc) // ���ڿ� ���� �Լ� (�ּҸ� ���� �ű�� ���)
{
	srcLen = __strlen(pSrc); dstLen = __strlen(pDst);
	for (int i = 0; i <= srcLen; i++)
		*pDst++ = *pSrc++; // pDst�� pSrc�� ����. (����)
	for (int i = 0; i < dstLen - srcLen; i++) // dstLen - srcLen�� ��� src�� �� ���� �ݺ����� �ʰ� �ǹǷ� if ����.
		*pDst++ = '\0'; // �׿����� \0���� �ʱ�ȭ.
}

char* __strcpyEx(char* pDst, const char* pSrc) // ���ڿ� ���� �Լ� (�ּҸ� ���� �ű��� ����), ���� ����.
{
	srcLen = __strlen(pSrc); dstLen = __strlen(pDst);
	for (int i = 0; i <= srcLen; i++)
		*(pDst + i) = *(pSrc + i);
	for (int i = srcLen; i < dstLen; i++)
		*(pDst + i) = '\0';
	return pDst;
}

char* __strcat(char* pDst, const char* pSrc) // ���ڿ� �ڿ� ���̱� �Լ�.
{
	srcLen = __strlen(pSrc); dstLen = __strlen(pDst);
	for (int i = 0; i <= srcLen; i++)
		*(pDst + dstLen + i) = *pSrc++; // \0 �ڸ����� �����ؼ� ����.
	return pDst;
}

char* __strrot(char* pStr, int n) // ȸ���Լ�, n�� ȸ���� ��, ������ �����.
{
	int strLen = 0;
	strLen = __strlen(pStr);
	if (n < 0) // ����
		while (n++)
		{
			char c = *(pStr + strLen - 1); // ���ڿ� �� �� ���� �����س���
			for (int i = strLen - 2; i >= 0; i--)
				*(pStr + i + 1) = *(pStr + i); // ������ ���� �ڿ������� ������ ���� ����.
			*pStr = c; // ù ���� ������ �� ����.
		}
	else // ���
		while (n--)
		{
			char c = *pStr; // ���ڿ� �� ó�� ���� �����س���
			for (int i = 0; i < strLen - 1; i++)
				*(pStr + i) = *(pStr + i + 1); // ������ ���� �տ������� �ڷ� ���� ����.
			*(pStr + strLen - 1) = c; // ������ ���� ù �� ����.
		}
	return pStr;
}