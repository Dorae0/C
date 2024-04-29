#define _CRT_SECURE_NO_WARNINGS
#define UP 72
#define DOWN 80
#define ENTER 13
#define DARK_GRAY 8
#define WHITE 15

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <io.h>

extern int Gametype;

void gotoxy(int x, int y);
void mainUI();
void State1();
void State2();
void State3();
void State1_1();
void State3_1();