#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <io.h>
#include "char.h"

typedef struct{
    char desc[32];
    int ver;
    int num;
    int turn;
    int nDead;
    int Dead;
    int avoid;
}tag_Header;

void saveData(CHARACTER* ch[], int TurnNum, int NewDeadChar, int DeadChar, int AvoidChar);
void readData(CHARACTER* tmp[], int* turn, int* nDead, int* Dead, int* avoid);