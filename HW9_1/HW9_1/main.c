#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "rw.h"

int Gametype;


void main()
{
	int turn = 0; int nDead = 0; int Dead = 0; int avoid = 0;
	CHARACTER* ch[MAX];
	CHARACTER* tmp[MAX];
	mainUI();
	switch (Gametype)
	{
	case 1:
		characterInit(ch);
		gameLoop(ch, 0, 0, 0, 0);
		break;
	case 2:
		for (int i = 0; i < MAX; i++)
		{
			ch[i] = (CHARACTER*)malloc(sizeof(CHARACTER));
			tmp[i] = (CHARACTER*)malloc(sizeof(CHARACTER));
		}
		readData(tmp, &turn, &nDead, &Dead, &avoid);
		for (int i = 0; i < MAX; i++)
		{
			if (tmp[i] != NULL)
			{
				if (tmp[i]->nLife == -1)
				{
					free(ch[i]);
					ch[i] = NULL;
				}
				else
				{
					ch[i]->nDamage = tmp[i]->nDamage;
					ch[i]->nLife = tmp[i]->nLife;
				}
			}
		}
		for (int i = 0; i < MAX; i++)
		{
			free(tmp[i]);
			tmp[i] = NULL;
		}	
		gameLoop(ch, turn, nDead, Dead, avoid);
		break;
	}
}