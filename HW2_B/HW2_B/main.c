#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int a, b, c, e, f;

	a = 0;
	b = 5;
	c = 10;

	// ������� a = 0, b = 5, c = 10

	e = c > b ? b * ++c - 10 * 2 : c-- * b + 10 * 2;

	// c > b���� ���� ��ȯ�ǹǷ� 3�׿������� �պκ� ����.
	// b * ++c���� c�� �������̹Ƿ� 10 + 1�� ���Ե� �� ���.
	//����, e = 5 * 11 - 10 * 2�� ����ǰ�, c���� 11�� �����, e = 35.

	f = 10 == c ? b * ++c - 10 * 2 : c-- * b + 10 * 2;

	// 10 == c���� ������ �����ǵ� c�� ���� ������ ��ȯ�ǹǷ� 3�׿������� �޺κ� ����.
	// c-- * b ���� c�� �������̹Ƿ� c�� 11 - 1�� ����Ǵ� ���� ���� ��� �����̴�.
	// ����, f = 11 * 5 + 10 * 2 = 75.
	// ������ c���� 10�̴�. a�� b���� �������� �������� 0�� 5�� �����ϴ�.

	printf("e= %d\n", e);
	printf("f= %d\n", f);

	// printf�� ����� ��ġ�Ѵ�.

	int nOP1[4] = { 0, }; int nOP2[4] = { 0, }; float fOP1[4] = { 0.0f, }; float fOP2[4] = { 0.0f, };

	printf("--------\nnOP1 �迭�� ��Ҹ� �Է��� �ּ��� (Int) : \n");
	scanf("%d", &nOP1[0]);
	scanf("%d", &nOP1[1]);
	scanf("%d", &nOP1[2]);
	scanf("%d", &nOP1[3]);
	printf("--------\nnOP2 �迭�� ��Ҹ� �Է��� �ּ��� (Int) // 4��° ��ҿ� 0�� ���� �����ּ��� : \n");
	scanf("%d", &nOP2[0]);
	scanf("%d", &nOP2[1]);
	scanf("%d", &nOP2[2]);
	scanf("%d", &nOP2[3]);
	printf("--------\nfOP1 �迭�� ��Ҹ� �Է��� �ּ��� (Float => Int ĳ��Ʈ) : \n");
	scanf("%f", &fOP1[0]);
	scanf("%f", &fOP1[1]);
	scanf("%f", &fOP1[2]);
	scanf("%f", &fOP1[3]);
	printf("--------\nfOP2 �迭�� ��Ҹ� �Է��� �ּ��� (Float => Int ĳ��Ʈ) // 4��° ��ҿ� 0�� ���� �����ּ��� : \n");
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