#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

typedef struct
{
	int	nDamage;  // ���� ���� ����
	int	nLife;    // ����
} CHARACTER;

void characterInit(CHARACTER* ch[]);
void gameLoop(CHARACTER* ch[], int TurnNum, int NewDeadChar, int DeadChar, int AvoidChar);
void Revive(CHARACTER* ch[], int idx);
void printChar(CHARACTER* ch[]);
void printResult(int TDeadChar, int reviveChar, int NewDeadChar, int AvoidChar, int TurnNum);