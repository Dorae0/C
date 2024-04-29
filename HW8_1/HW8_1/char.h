#define _CRT_SECURE_NO_WARNINGS
#define BOOL int
#define FALSE 0
#define TRUE 1
#define MAX 100

typedef struct
{
	BOOL bIsLive;  // ���� ����
	int	nDamage;  // ���� ���� ����
	int	nLife;    // ����
} CHARACTER;

void characterInit(CHARACTER* ch);
void gameLoop(CHARACTER* ch);
void Revive(CHARACTER* ch, int idx);
void printChar(CHARACTER* ch);
void printResult(int TDeadChar, int reviveChar, int NewDeadChar, int AvoidChar, int TurnNum);