#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include <stdio.h>

int srcLen, dstLen;

int __strlen(char* pStr) // 길이 반환 함수
{
	int sLen = 0;
	while (*pStr++ != '\0') // \0 나올때까지 sLen++
		sLen++;
	return sLen;
}

void __strcpy(char* pDst, const char* pSrc) // 문자열 복사 함수 (주소를 직접 옮기는 방식)
{
	srcLen = __strlen(pSrc); dstLen = __strlen(pDst);
	for (int i = 0; i <= srcLen; i++)
		*pDst++ = *pSrc++; // pDst에 pSrc를 대입. (복사)
	for (int i = 0; i < dstLen - srcLen; i++) // dstLen - srcLen의 경우 src가 길 때는 반복되지 않게 되므로 if 배제.
		*pDst++ = '\0'; // 잉여값은 \0으로 초기화.
}

char* __strcpyEx(char* pDst, const char* pSrc) // 문자열 복사 함수 (주소를 직접 옮기지 않음), 위와 동일.
{
	srcLen = __strlen(pSrc); dstLen = __strlen(pDst);
	for (int i = 0; i <= srcLen; i++)
		*(pDst + i) = *(pSrc + i);
	for (int i = srcLen; i < dstLen; i++)
		*(pDst + i) = '\0';
	return pDst;
}

char* __strcat(char* pDst, const char* pSrc) // 문자열 뒤에 붙이기 함수.
{
	srcLen = __strlen(pSrc); dstLen = __strlen(pDst);
	for (int i = 0; i <= srcLen; i++)
		*(pDst + dstLen + i) = *pSrc++; // \0 자리부터 시작해서 복사.
	return pDst;
}

char* __strrot(char* pStr, int n) // 회전함수, n은 회전할 양, 음수도 적용됨.
{
	int strLen = 0;
	strLen = __strlen(pStr);
	if (n < 0) // 음수
		while (n++)
		{
			char c = *(pStr + strLen - 1); // 문자열 맨 끝 값을 저장해놓고
			for (int i = strLen - 2; i >= 0; i--)
				*(pStr + i + 1) = *(pStr + i); // 나머지 값은 뒤에서부터 앞으로 복사 시작.
			*pStr = c; // 첫 값에 마지막 값 복사.
		}
	else // 양수
		while (n--)
		{
			char c = *pStr; // 문자열 맨 처음 값을 저장해놓고
			for (int i = 0; i < strLen - 1; i++)
				*(pStr + i) = *(pStr + i + 1); // 나머지 값은 앞에서부터 뒤로 복사 시작.
			*(pStr + strLen - 1) = c; // 마지막 값에 첫 값 복사.
		}
	return pStr;
}