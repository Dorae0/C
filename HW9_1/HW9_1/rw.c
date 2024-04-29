#include "rw.h"

void saveData(CHARACTER* ch[], int TurnNum, int NewDeadChar, int DeadChar, int AvoidChar)
{
	CHARACTER emptyChar = { 0, -1 };
	char getc = 'a';
	system("cls");
	gotoxy(105, 13);
	printf("<<������ �����Ͻðڽ��ϱ�? (Y / N)>>\n");
START:
	getc = getchar();
	if (getc == 'y' || getc == 'Y')
	{
		FILE* f;
		tag_Header H;
		f = fopen("C:\\DH\\HW\\HW9_1\\Data\\Data.dat", "wb");
		if (f == NULL)
		{
			system("cls");
			gotoxy(105, 13);
			printf("���� ���� ���� ������ �߻��߽��ϴ�. \n");
			_getch();
		}
		else
		{
			strcpy(H.desc, "ĳ���� ��Ȳ");
			H.ver = 100;
			H.num = MAX;
			H.turn = TurnNum;
			H.nDead = NewDeadChar;
			H.Dead = DeadChar;
			H.avoid = AvoidChar;
			fwrite(&H, sizeof(tag_Header), 1, f);
			for (int i = 0; i < MAX; i++)
			{
				if(ch[i] != NULL)
					fwrite(ch[i], sizeof(CHARACTER), 1, f);
				else
					fwrite(&emptyChar, sizeof(CHARACTER), 1, f);
			}
			
			fclose(f);
			system("cls");
			gotoxy(110, 13);
			printf("���� ������ �Ϸ��߽��ϴ�. \n");
			_getch();
		}
	}
	else if (getc == 'n' || getc == 'N')
		return;
	else
		goto START;
}

void readData(CHARACTER* tmp[], int* turn, int* nDead, int* Dead, int* avoid)
{
	char getc = 'a';
	system("cls");
	gotoxy(105, 13);
	printf("<<������ �ҷ����ðڽ��ϱ�? (Y / N)>>\n");
START:
	getc = getchar();
	FILE* f = NULL;
	if (getc == 'y' || getc == 'Y')
	{
		tag_Header H;
		f = fopen("C:\\DH\\HW\\HW9_1\\Data\\Data.dat", "rb");
		if (f == NULL)
		{
			system("cls");
			gotoxy(102, 13);
			printf("������ �ҷ����� �� ������ �߻��߽��ϴ�. \n");
			_getch();
		}
		else
		{
			fread(&H, sizeof(tag_Header), 1, f);
			if (strcmp(H.desc, "ĳ���� ��Ȳ") != 0) {
				puts("�ּҷ� ������ �ƴմϴ�.");
				goto END;

			}
			if (H.ver != 100) {
				puts("������ Ʋ���ϴ�.");
				goto END;
			}
			*turn = H.turn;
			*nDead = H.nDead;
			*Dead = H.Dead;
			*avoid = H.avoid;
			for(int i = 0; i < H.num; i++)
				fread(tmp[i], sizeof(CHARACTER), 1, f);
			puts("������ �о����ϴ�.");
		END:
			if (f)
				fclose(f);
			return;
		}
	}
	else if (getc == 'n' || getc == 'N')
		return 0;
	else
		goto START;
}