#define _CRT_SECURE_NO_WARNINGS
#define BOOL int
#define FALSE 0
#define TRUE 1
#define MAX 100

typedef struct
{
	BOOL bIsLive;  // 생존 여부
	int	nDamage;  // 공격 받은 정도
	int	nLife;    // 생명
} CHARACTER;

void characterInit(CHARACTER* ch);
void gameLoop(CHARACTER* ch);
void Revive(CHARACTER* ch, int idx);
void printChar(CHARACTER* ch);
void printResult(int TDeadChar, int reviveChar, int NewDeadChar, int AvoidChar, int TurnNum);