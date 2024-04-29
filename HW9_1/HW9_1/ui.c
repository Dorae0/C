#include "ui.h"
int state = 1;

void gotoxy(int x, int y) {
    //x, y 좌표 설정
    COORD pos = { x,y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void mainUI()
{
    struct _finddata_t fd;
    char keyInput = 'a';
    long handle;
    handle = _findfirst("C:\\DH\\HW\\HW9_1\\Data\\Data*.*", &fd);
    if (handle == -1)
        state = 11;

    while (1)
    {
        switch (state)
        {
        case 1:
            State1();
            break;
        case 2:
            State2();
            break;
        case 3:
            State3();
            break;
        case 11:
            State1_1();
            break;
        case 31:
            State3_1();
            break;
        }
        keyInput = _getch();
        if(keyInput == 224)
            keyInput = _getch();
        if (keyInput == UP)
        {
            switch (state)
            {
            case 2:
                State1();
                break;
            case 3:
                State2();
                break;
            case 31:
                State1_1();
                break;
            }
        }
        else if (keyInput == DOWN)
        {
            switch (state)
            {
            case 1:
                State2();
                break;
            case 2:
                State3();
                break;
            case 11:
                State3_1();
                break;
            }
        }
        else if (keyInput == ENTER)
        {
            switch (state)
            {
            case 1:
            case 11:
                Gametype = 1;
                break;
            case 2:
                Gametype = 2;
                break;
            case 3:
            case 31:
                break;
            }
            return;
        }
    }
}

void State1()
{
    state = 1;
    system("cls");
    gotoxy(56, 10);
    printf("Sample Game");
    gotoxy(55, 13);
    printf("▷새로 시작");
    gotoxy(57, 14);
    printf("이어 하기");
    gotoxy(57, 15);
    printf("종료");
}

void State2()
{
    state = 2;
    system("cls");
    gotoxy(56, 10);
    printf("Sample Game");
    gotoxy(57, 13);
    printf("새로 시작");
    gotoxy(55, 14);
    printf("▷이어 하기");
    gotoxy(57, 15);
    printf("종료");
}

void State3()
{
    state = 3;
    system("cls");
    gotoxy(56, 10);
    printf("Sample Game");
    gotoxy(57, 13);
    printf("새로 시작");
    gotoxy(57, 14);
    printf("이어 하기");
    gotoxy(55, 15);
    printf("▷종료");
}

void State1_1()
{
    state = 11;
    system("cls");
    gotoxy(56, 10);
    printf("Sample Game");
    gotoxy(55, 13);
    printf("▷새로 시작");
    gotoxy(57, 14);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DARK_GRAY);
    printf("이어 하기");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(57, 15);
    printf("종료");
}

void State3_1()
{
    state = 31;
    system("cls");
    gotoxy(56, 10);
    printf("Sample Game");
    gotoxy(57, 13);
    printf("새로 시작");
    gotoxy(57, 14);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DARK_GRAY);
    printf("이어 하기");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(55, 15);
    printf("▷종료");
}