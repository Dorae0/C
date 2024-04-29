#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include <stdio.h>
#include <math.h>

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
	if(n < 0) // ����
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

//�� ������ �Լ��� ���� ������ �����Դϴ�.

char* __strchr(const char* s, int c) // ���ڿ� ������ Ư�� ���ڸ� ã�� �Լ�. ã�� ��� ã�� ������ return / ã�� ���ϸ� NULL return.
{
	int idx = 0;
	while (*(s + idx) != '\0') // \0 ������ �ݺ�.
	{
		if (*(s + idx) == c) // ���ڸ� ã���� �ٷ� return. �������� ���� ���� ���� ���⿡�� ���� ���ؼ�.
			return s + idx;
		idx++; // ã�� ���� ���. �� ��쿡�� idx++�� �Ѵ�.
	}
	return NULL; // ������ ã�� ���� ���. NULL ��ȯ.
}

char* __strrchr(const char* s, int c) // ���� �Լ��� ¦�� �̷�� �Լ�. �� �Լ��� �ڿ������� ã�� ������.
{
	srcLen = __strlen(s); // ���ʹ� �ٸ��� ���ڿ��� ���̸� �޾Ƽ� �����Ѵ�. 0��° ������ ���� ���� ������� �� Ȯ���� �� ���� ����.
	int idx = srcLen; // idx�� ���ڿ��� ���̷� �����ϰ�

	while (idx > 0) // idx�� 0���� Ŭ �� ������ �ݺ�.
	{
		if (*(s + idx) == c) // ���ڸ� ã���� �ٷ� return. �������� ���� ���� ���� ���⿡�� ���� ���ؼ�.
			return s + idx;
		idx--; // ã�� ���� ���. �� ��쿡�� idx--�� �Ѵ�.
	}
	return NULL; // ������ ã�� ���� ���. NULL ��ȯ.
}

int __strcmp(const char* s1, const char* s2) // ���ڿ� �� �Լ�. ��ȯ�� ���̰� ���� ������ ASCII �ڵ� ���� �� (s1 - s2)
{
	int idx = 0;
	while (1)
	{
		if (*(s1 + idx) != *(s2 + idx))
			return *(s1 + idx) - *(s2 + idx); // �ٸ� ��� ���� ��ȯ�ϱ⿡ ���� ���� ����.
		if (*(s1 + idx) == '\0' && *(s2 + idx) == '\0')
			return 0; // \0 ���� ���� ���� ���� �� ���ڿ��� ���� �� ��. �̿ܿ� �̷� ���� ����.
		idx++; // ã�� ���� ��� idx++
	}
}

int __stricmp(const char* s1, const char* s2) // �� �Լ��� ¦�� �̷�� �Լ� (1), ��ҹ��ڸ� �������� �ʴ´�.
{
	int idx = 0;
	while (1)
	{
		if (*(s1 + idx) != *(s2 + idx) && abs(*(s1 + idx) - *(s2 + idx)) != 32 && (*(s1 + idx) >= 'A' && *(s1 + idx) <= 'Z') || (*(s1 + idx) >= 'a' && *(s1 + idx) <= 'z')) // abs �Լ��� Ȱ���Ͽ� ������ 32�� ���� ������.
			return *(s1 + idx) - *(s2 + idx);
		if (*(s1 + idx) == '\0' && *(s2 + idx) == '\0')
			return 0;
		idx++;
	}
}

int __strncmp(const char* s1, const char* s2, int n) // �� �Լ��� ¦�� �̷�� �Լ� (2), �� ���� ������ ������ �� �ִ�.
{
	int idx = 0;
	while (n--)
	{
		if (*(s1 + idx) != *(s2 + idx))
			return *(s1 + idx) - *(s2 + idx);
		if (*(s1 + idx) == '\0' && *(s2 + idx) == '\0')
			return 0;
		idx++;
	}
	return 0; // ã�� ���ϸ� return 0
}

int __strnicmp(const char* s1, const char* s2, int n) // �� �Լ��� ¦�� �̷�� �Լ� (3), �� ���� ������ ������ �� �ְ�, ��ҹ��ڸ� �������� �ʴ´�.
{
	int idx = 0;
	while (n--)
	{
		if (*(s1 + idx) != *(s2 + idx) && abs(*(s1 + idx) - *(s2 + idx)) != 32 && (*(s1 + idx) >= 'A' && *(s1 + idx) <= 'Z') || (*(s1 + idx) >= 'a' && *(s1 + idx) <= 'z')) // abs �Լ��� Ȱ���Ͽ� ������ 32�� ���� ������.
			return *(s1 + idx) - *(s2 + idx);
		if (*(s1 + idx) == '\0' && *(s2 + idx) == '\0')
			return 0;
		idx++;
	}
	return 0; // ã�� ���ϸ� return 0
}

size_t __strcspn(const char* c1, const char* c2) // c1�� �ִ� ���ڰ� c2�� ���ԵǾ� ���� ���� ����� ũ�� ���� ��ȯ.
{
	int idx1 = 0; int idx2 = 0;
	while (*(c1 + idx1) != '\0') // c1 + idx�� ���� \0�� ������ ������.
	{
		idx2 = 0; // idx2 �ʱ�ȭ.
		while (*(c2 + idx2) != '\0')
		{
			if (*(c1 + idx1) == *(c2 + idx2))
				return (size_t)idx1; // idx1 ��ȯ.
			idx2++;
		}
		idx1++;
	}
	return 0;
}

char* __strlwr(char* s) // �빮�ڸ� �ҹ��ڷ� ��ȯ�ϴ� �Լ�
{
	int idx = 0;
	while (*(s + idx) != '\0')
	{
		if (*(s + idx) >= 'A' && *(s + idx) <= 'Z') //�빮�� ������ ������
			*(s + idx) += 32; // �ƽ�Ű �ڵ� �� +32
		idx++;
	}
	return s;
}

char* __strncat(char* pDst, const char* pSrc, size_t maxlen) // strcat�� Ȯ�� �Լ�. �󸶳� ������ �� ������ �� �� �ִ�.
{
	srcLen = __strlen(pSrc); dstLen = __strlen(pDst);
	if (srcLen < maxlen) maxlen = srcLen; // maxlen�� srcLen���� �� ��� srcLen�� �ִ� ���̸�ŭ�� �۵�.

	for (int i = 0; i < maxlen; i++)
		*(pDst + dstLen + i) = *(pSrc + i);
	*(pDst + dstLen + maxlen) = '\0'; // �ڿ� \0�� ���� ����.
	return pDst;
}

char* __strncpy(char* pDst, const char* pSrc, size_t maxlen) // strcpy�� Ȯ�� �Լ�. �󸶳� ������ �� ������ �� �� �ִ�.
{
	srcLen = __strlen(pSrc); dstLen = __strlen(pDst);
	if (srcLen < maxlen) maxlen = srcLen; // maxlen�� srcLen���� �� ��� srcLen�� �ִ� ���̸�ŭ�� �۵�.

	for (int i = 0; i <= srcLen; i++)
		*pDst++ = *pSrc++; // pDst�� pSrc�� ����. (����)
	for (int i = 0; i < dstLen - srcLen; i++) // dstLen - srcLen�� ��� src�� �� ���� �ݺ����� �ʰ� �ǹǷ� if ����.
		*pDst++ = '\0'; // �׿����� \0���� �ʱ�ȭ.
}		