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
	printf("string ���� �Լ� �׽�Ʈ�Դϴ�. string 1�� ���� �Է��Ͻÿ� : \n");
	scanf("%[^\n]s", &string1); // ��ĭ�� �����ؼ� %s�� �Է¹������� %[^\n]s
	printf("string1�� ���̴� %d�Դϴ�. \n", __strlen(string1));

	printf("--------\nstring 2�� ���� �Է��Ͻÿ� : \n");
	scanf(" %[^\n]s", &string2);
	printf("string 3�� ���� �Է��Ͻÿ� : \n");
	scanf(" %[^\n]s", &string3);
	printf("string 4�� ���� �Է��Ͻÿ� : \n");
	scanf(" %[^\n]s", &string4);

	__strcpy(string4, string2);
	printf("string4�� ����մϴ� : %s \n", string4);
	printf("string4�� ����մϴ� : %s \n", __strcpyEx(string4, string3));
	printf("strcat �׽�Ʈ�Դϴ�. string 2 �ڿ� string 3�� ���Դϴ� : %s \n", __strcat(string2, string3));

	printf("string 5�� ���� �Է��Ͻÿ� : \n");
	scanf(" %[^\n]s", &string5);

	printf("strrot �׽�Ʈ�Դϴ�. ȸ���� ���� �Է��Ͻÿ� (����) : \n");

	scanf("%d", &rotnum);

	printf("%d�� ȸ�� ����Դϴ� : %s\n", rotnum, __strrot(string5, rotnum));

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

	printf("strcat �׽�Ʈ�Դϴ�. string 2 �ڿ� string 3�� ���Դϴ� : %s \n", __strncat(string2, string3, 2));	
}