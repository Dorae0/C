#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "string.h"

void main()
{
	char string1[100];
	char string2[100];
	char string3[100];
	char string4[100];
	char string5[100];
	int rotnum = 0;

	printf("--------\n");
	printf("string 제작 함수 테스트입니다. string 1의 값을 입력하시오 : \n");
	scanf("%[^\n]s", &string1); // 빈칸을 포함해서 %s로 입력받을때는 %[^\n]s
	printf("string1의 길이는 %d입니다. \n", __strlen(string1));

	printf("--------\nstring 2의 값을 입력하시오 : \n");
	scanf(" %[^\n]s", &string2);
	printf("string 3의 값을 입력하시오 : \n");
	scanf(" %[^\n]s", &string3);
	printf("string 4의 값을 입력하시오 : \n");
	scanf(" %[^\n]s", &string4);

	__strcpy(string4, string2);
	printf("string4를 출력합니다 : %s \n", string4);
	printf("string4를 출력합니다 : %s \n", __strcpyEx(string4, string3));
	printf("strcat 테스트입니다. string 2 뒤에 string 3을 붙입니다 : %s \n", __strcat(string2, string3));

	printf("string 5의 값을 입력하시오 : \n");
	scanf(" %[^\n]s", &string5);

	printf("strrot 테스트입니다. 회전할 양을 입력하시오 (정수) : \n");

	scanf("%d", &rotnum);

	printf("%d번 회전 결과입니다 : %s\n", rotnum, __strrot(string5, rotnum));

	printf("%s\n", __strchr(string5, 'l'));
	printf("%s\n", __strrchr(string5, 'l'));

	char* buf1 = "KOREa";
	char* buf2 = "KOREA";
	char* buf3 = "7890K";
	printf("%d\n", __strcmp(buf1, buf2));
	printf("%d\n", __stricmp(buf1, buf2));
	printf("%d\n", __strncmp(buf1, buf2, 3));
	printf("%d\n", __strnicmp(buf1, buf2, 3));
	printf("%zd\n", __strcspn(buf3, buf2));

	printf("%s\n", __strlwr(string1));

	printf("strcat 테스트입니다. string 2 뒤에 string 3을 붙입니다 : %s \n", __strncat(string2, string3, 2));	
}