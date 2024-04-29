#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include <stdio.h>
#include <math.h>

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
	if(n < 0) // 음수
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

//이 이후의 함수는 과제 이후의 범위입니다.

char* __strchr(const char* s, int c) // 문자열 내에서 특정 문자를 찾는 함수. 찾은 경우 찾은 번지를 return / 찾지 못하면 NULL return.
{
	int idx = 0;
	while (*(s + idx) != '\0') // \0 전까지 반복.
	{
		if (*(s + idx) == c) // 문자를 찾으면 바로 return. 후위식을 쓰지 못한 것은 여기에서 쓰기 위해서.
			return s + idx;
		idx++; // 찾지 못한 경우. 이 경우에는 idx++를 한다.
	}
	return NULL; // 끝까지 찾지 못한 경우. NULL 반환.
}

char* __strrchr(const char* s, int c) // 위의 함수와 짝을 이루는 함수. 이 함수는 뒤에서부터 찾아 나간다.
{
	srcLen = __strlen(s); // 위와는 다르게 문자열의 길이를 받아서 접근한다. 0번째 번지에 무슨 값이 들어있을 지 확정할 수 없기 때문.
	int idx = srcLen; // idx를 문자열의 길이로 설정하고

	while (idx > 0) // idx가 0보다 클 때 까지는 반복.
	{
		if (*(s + idx) == c) // 문자를 찾으면 바로 return. 후위식을 쓰지 못한 것은 여기에서 쓰기 위해서.
			return s + idx;
		idx--; // 찾지 못한 경우. 이 경우에는 idx--를 한다.
	}
	return NULL; // 끝까지 찾지 못한 경우. NULL 반환.
}

int __strcmp(const char* s1, const char* s2) // 문자열 비교 함수. 반환은 차이가 나는 지점의 ASCII 코드 값의 차 (s1 - s2)
{
	int idx = 0;
	while (1)
	{
		if (*(s1 + idx) != *(s2 + idx))
			return *(s1 + idx) - *(s2 + idx); // 다른 경우 차를 반환하기에 조건 없이 지정.
		if (*(s1 + idx) == '\0' && *(s2 + idx) == '\0')
			return 0; // \0 값이 같이 나온 경우는 두 문자열이 같을 때 뿐. 이외에 이런 경우는 없다.
		idx++; // 찾지 못한 경우 idx++
	}
}

int __stricmp(const char* s1, const char* s2) // 위 함수와 짝을 이루는 함수 (1), 대소문자를 구분하지 않는다.
{
	int idx = 0;
	while (1)
	{
		if (*(s1 + idx) != *(s2 + idx) && abs(*(s1 + idx) - *(s2 + idx)) != 32 && (*(s1 + idx) >= 'A' && *(s1 + idx) <= 'Z') || (*(s1 + idx) >= 'a' && *(s1 + idx) <= 'z')) // abs 함수를 활용하여 절댓값이 32일 때를 제외함.
			return *(s1 + idx) - *(s2 + idx);
		if (*(s1 + idx) == '\0' && *(s2 + idx) == '\0')
			return 0;
		idx++;
	}
}

int __strncmp(const char* s1, const char* s2, int n) // 위 함수와 짝을 이루는 함수 (2), 몇 개를 비교할지 지정할 수 있다.
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
	return 0; // 찾지 못하면 return 0
}

int __strnicmp(const char* s1, const char* s2, int n) // 위 함수와 짝을 이루는 함수 (3), 몇 개를 비교할지 지정할 수 있고, 대소문자를 구분하지 않는다.
{
	int idx = 0;
	while (n--)
	{
		if (*(s1 + idx) != *(s2 + idx) && abs(*(s1 + idx) - *(s2 + idx)) != 32 && (*(s1 + idx) >= 'A' && *(s1 + idx) <= 'Z') || (*(s1 + idx) >= 'a' && *(s1 + idx) <= 'z')) // abs 함수를 활용하여 절댓값이 32일 때를 제외함.
			return *(s1 + idx) - *(s2 + idx);
		if (*(s1 + idx) == '\0' && *(s2 + idx) == '\0')
			return 0;
		idx++;
	}
	return 0; // 찾지 못하면 return 0
}

size_t __strcspn(const char* c1, const char* c2) // c1에 있는 문자가 c2에 포함되어 있지 않은 블록의 크기 수를 반환.
{
	int idx1 = 0; int idx2 = 0;
	while (*(c1 + idx1) != '\0') // c1 + idx의 값이 \0이 나오기 전까지.
	{
		idx2 = 0; // idx2 초기화.
		while (*(c2 + idx2) != '\0')
		{
			if (*(c1 + idx1) == *(c2 + idx2))
				return (size_t)idx1; // idx1 반환.
			idx2++;
		}
		idx1++;
	}
	return 0;
}

char* __strlwr(char* s) // 대문자를 소문자로 변환하는 함수
{
	int idx = 0;
	while (*(s + idx) != '\0')
	{
		if (*(s + idx) >= 'A' && *(s + idx) <= 'Z') //대문자 범위에 있으면
			*(s + idx) += 32; // 아스키 코드 값 +32
		idx++;
	}
	return s;
}

char* __strncat(char* pDst, const char* pSrc, size_t maxlen) // strcat의 확장 함수. 얼마나 복사할 지 지정해 줄 수 있다.
{
	srcLen = __strlen(pSrc); dstLen = __strlen(pDst);
	if (srcLen < maxlen) maxlen = srcLen; // maxlen이 srcLen보다 길 경우 srcLen의 최대 길이만큼만 작동.

	for (int i = 0; i < maxlen; i++)
		*(pDst + dstLen + i) = *(pSrc + i);
	*(pDst + dstLen + maxlen) = '\0'; // 뒤에 \0은 따로 붙임.
	return pDst;
}

char* __strncpy(char* pDst, const char* pSrc, size_t maxlen) // strcpy의 확장 함수. 얼마나 복사할 지 지정해 줄 수 있다.
{
	srcLen = __strlen(pSrc); dstLen = __strlen(pDst);
	if (srcLen < maxlen) maxlen = srcLen; // maxlen이 srcLen보다 길 경우 srcLen의 최대 길이만큼만 작동.

	for (int i = 0; i <= srcLen; i++)
		*pDst++ = *pSrc++; // pDst에 pSrc를 대입. (복사)
	for (int i = 0; i < dstLen - srcLen; i++) // dstLen - srcLen의 경우 src가 길 때는 반복되지 않게 되므로 if 배제.
		*pDst++ = '\0'; // 잉여값은 \0으로 초기화.
}		