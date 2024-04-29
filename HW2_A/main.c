#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	char charArray[5] = { 'G', 'A', 'M', 'E', '\0' };
	float floatArray[4] = { 0.1f, 0.2f, 0.3f, 0.4f };

	printf("--------\n");
	printf("%c\n", charArray[0]);
	printf("%c\n", charArray[1]);
	printf("%c\n", charArray[2]);
	printf("%c\n", charArray[3]);
	printf("%c\n", charArray[4]);
	printf("--------\n");
	printf("%0.1f\n", floatArray[0]);
	printf("%0.1f\n", floatArray[1]);
	printf("%0.1f\n", floatArray[2]);
	printf("%0.1f\n", floatArray[3]);
	printf("--------\n");

	int intArray[1] = { 'a' }; floatArray[0] = 'a';
	printf("%d\n", intArray[0]); printf("%f\n", floatArray[0]);
	printf("--------\n");

	char string[] = "STRING";
	printf("%c\n", string[0]);
	printf("%c\n", string[1]);
	printf("%c\n", string[2]);
	printf("%c\n", string[3]);
	printf("%c\n", string[4]);
	printf("%c\n", string[5]);
	printf("%c\n", string[6]);
	printf("--------\n");
}