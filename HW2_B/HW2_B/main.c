#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int a, b, c, e, f;

	a = 0;
	b = 5;
	c = 10;

	// 여기까지 a = 0, b = 5, c = 10

	e = c > b ? b * ++c - 10 * 2 : c-- * b + 10 * 2;

	// c > b에서 참이 반환되므로 3항연산자의 앞부분 실행.
	// b * ++c에서 c가 전위식이므로 10 + 1이 대입된 후 계산.
	//따라서, e = 5 * 11 - 10 * 2가 저장되고, c에는 11이 저장됨, e = 35.

	f = 10 == c ? b * ++c - 10 * 2 : c-- * b + 10 * 2;

	// 10 == c에서 위에서 재정의된 c에 의해 거짓이 반환되므로 3항연산자의 뒷부분 실행.
	// c-- * b 에서 c가 후위식이므로 c에 11 - 1이 저장되는 것은 식의 계산 이후이다.
	// 따라서, f = 11 * 5 + 10 * 2 = 75.
	// 이후의 c값은 10이다. a와 b에는 증감식이 없었으니 0과 5로 동일하다.

	printf("e= %d\n", e);
	printf("f= %d\n", f);

	// printf의 결과와 일치한다.

	int nOP1[4] = { 0, }; int nOP2[4] = { 0, }; float fOP1[4] = { 0.0f, }; float fOP2[4] = { 0.0f, };

	printf("--------\nnOP1 배열의 요소를 입력해 주세요 (Int) : \n");
	scanf("%d", &nOP1[0]);
	scanf("%d", &nOP1[1]);
	scanf("%d", &nOP1[2]);
	scanf("%d", &nOP1[3]);
	printf("--------\nnOP2 배열의 요소를 입력해 주세요 (Int) // 4번째 요소에 0을 넣지 말아주세요 : \n");
	scanf("%d", &nOP2[0]);
	scanf("%d", &nOP2[1]);
	scanf("%d", &nOP2[2]);
	scanf("%d", &nOP2[3]);
	printf("--------\nfOP1 배열의 요소를 입력해 주세요 (Float => Int 캐스트) : \n");
	scanf("%f", &fOP1[0]);
	scanf("%f", &fOP1[1]);
	scanf("%f", &fOP1[2]);
	scanf("%f", &fOP1[3]);
	printf("--------\nfOP2 배열의 요소를 입력해 주세요 (Float => Int 캐스트) // 4번째 요소에 0을 넣지 말아주세요 : \n");
	scanf("%f", &fOP2[0]);
	scanf("%f", &fOP2[1]);
	scanf("%f", &fOP2[2]);
	scanf("%f", &fOP2[3]);

	int nOP3[4] = { 0, }; float fOP3[4] = { 0.0f, };

	if (nOP2[3] == 0) nOP2[3] = 1; if (fOP2[3] == 0.0f) fOP2[3] = 1.0f;

	nOP3[0] = nOP1[0] + nOP2[0];
	nOP3[1] = nOP1[1] - nOP2[1];
	nOP3[2] = nOP1[2] * nOP2[2];
	nOP3[3] = nOP1[3] / nOP2[3];

	nOP2[0] = nOP1[0] + nOP2[0];
	nOP2[1] = nOP1[1] - nOP2[1];
	nOP2[2] = nOP1[2] * nOP2[2];
	nOP2[3] = nOP1[3] / nOP2[3];

	fOP3[0] = (int)fOP1[0] + (int)fOP2[0];
	fOP3[1] = (int)fOP1[1] - (int)fOP2[1];
	fOP3[2] = (int)fOP1[2] * (int)fOP2[2];
	fOP3[3] = (int)fOP1[3] / (int)fOP2[3];

	fOP2[0] = (int)fOP1[0] + (int)fOP2[0];
	fOP2[1] = (int)fOP1[1] - (int)fOP2[1];
	fOP2[2] = (int)fOP1[2] * (int)fOP2[2];
	fOP2[3] = (int)fOP1[3] / (int)fOP2[3];

	printf("--------\n<nOP2>\n");
	printf("%d\n", nOP2[0]);
	printf("%d\n", nOP2[1]);
	printf("%d\n", nOP2[2]);
	printf("%d\n", nOP2[3]);
	printf("--------\n<nOP3>\n");
	printf("%d\n", nOP3[0]);
	printf("%d\n", nOP3[1]);
	printf("%d\n", nOP3[2]);
	printf("%d\n", nOP3[3]);
	printf("--------\n<fOP2>\n");
	printf("%0.1f\n", fOP2[0]);
	printf("%0.1f\n", fOP2[1]);
	printf("%0.1f\n", fOP2[2]);
	printf("%0.1f\n", fOP2[3]);
	printf("--------\n<fOP3>\n");
	printf("%0.1f\n", fOP3[0]);
	printf("%0.1f\n", fOP3[1]);
	printf("%0.1f\n", fOP3[2]);
	printf("%0.1f\n", fOP3[3]);
}