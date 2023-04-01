#include "mygo.h"

void init_startscreen(int map[20][20], int *pside, int *difficulty)
{
	int i;
	int j;
	int k;
	char side[2];
	for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 20; j++)
			map[i][j] = 0;
	}
	for(i = 0; i < 21; i++)
	{
		for(j = 0; j < 33; j++)
		{
			if (i == 0)
			{
				if (j < 14)
				{
					printf(" ");
				}
				else if (j >= 14)
					printf("%c ", 'A' + j - 14);
				
			}
			if (i == 1)
			{
				if (j < 14)
				{
					printf(" ");
				}
				else
					printf("--");
			}
			if (j < 14 && i > 1)
			{
				if (i == 4 && j >= 5 && j <= 7)
				{
					if(j == 5)
						printf("Y");
					if (j == 6)
						printf("O");
					if (j == 7)
						printf("U");
				}
				else if (i == 10 && j >= 5 && j <= 7)
				{
					if (j == 5)
						printf("A");
					if (j == 6)
						printf(" ");
					if (j == 7)
						printf("I");
				}
				else if (i > 1 && j == 12 && i <= 10)
					printf("%d", i - 1);
				else if (i >= 11 && j == 11)
				{
					printf("%d", i - 1);
					j++;
				}
				else if (i > 1 && j == 13)
					printf("|");
				else
					printf(" ");
				fflush(stdout);
			}
			if (j >= 14 && i > 1)
			{
				printf(".");
				fflush(stdout);
				if (j != 33)
					printf(" ");
			}
			usleep(5000);
		}
		printf("\n");
	}
	printf("---------------------------------------------------\n");
	while(1)
	{
		printf("           Choose Your Side(O/X) : ");
		scanf("%c", side);
		if (side[0] == 'O' || side[0] == 'X')
		{
			if (side[0] == 'O')
				*pside = -1;
			else
				*pside = -2;
			break;
		}		
	}
	while(1)
	{
		printf("           Choose Your Difficulty(1/2/3) : ");
		scanf("%d", &k);
		if (k >= 1 && k <= 3)
		{
			*difficulty = k;
			break;
		}

		
	}
}

void update_and_ready(int map[20][20], int turn, int whoru, int difficulty)
{
	int i;
	int j;
	int col;
	char side[2];
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	for(i = 0; i < 21; i++)
	{
		for(j = 0; j < 33; j++)
		{
			if (i == 0)
			{
				if (j < 14)
				{
					printf(" ");
				}
				else if (j >= 14)
					printf("%c ", 'A' + j - 14);
				
			}
			if (i == 1)
			{
				if (j < 14)
				{
					printf(" ");
				}
				else
					printf("--");
			}
			if (j < 14 && i > 1)
			{
				if (i == 4 && j >= 5 && j <= 7 && whoru == 1)
				{
					if(j == 5)
						printf("Y");
					else if (j == 6)
						printf("O");
					else if (j == 7)
						printf("U");
					else
						printf(" ");
				}
				else if (i == 4 && j >= 2 && j <= 7 && whoru == 0)
				{
					if (j == 2)
						printf("-");
					else if (j == 3)
						printf(">");
					else if(j == 5)
						printf("Y");
					else if (j == 6)
						printf("O");
					else if (j == 7)
						printf("U");
					else
						printf(" ");
				}
				else if (i == 10 && j >= 2 && j <= 7 && whoru == 1)
				{
					if (j == 2)
						printf("-");
					else if (j == 3)
						printf(">");
					else if (j == 5)
						printf("A");
					else if (j == 6)
						printf(" ");
					else if (j == 7)
						printf("I");
					else
						printf(" ");
				}
				else if (i == 10 && j >= 5 && j <= 7 && whoru == 0)
				{
					if (j == 5)
						printf("A");
					else if (j == 6)
						printf(" ");
					else if (j == 7)
						printf("I");
				}
				else if (i > 1 && j == 12 && i <= 10)
					printf("%d", i - 1);
				else if (i >= 11 && j == 11)
				{
					printf("%d", i - 1);
					j++;
				}
				else if (i > 1 && j == 13)
					printf("|");
				else
					printf(" ");
			}
			if (j >= 14 && i > 1)
			{
				if (map[i-2][j-14] == 0)
					printf(".");
				else if (map[i-2][j-14] == -1)
					printf("O");
				else if (map[i-2][j-14] == -2)
					printf("X");
				if (j != 33)
					printf(" ");
			}
			// usleep(5000);
		}
		printf("\n");
	}
	printf("---------------------------------------------------\n");
	if (whoru == 0)
	{
	printf("           Choose Your Move(Num + Letter) : ");
	scanf("%d%c", &col, side);

	map[col - 1][side[0] - 'A'] = turn;
	}
	// else
	// {
	// printf("           This Is AI's Turn(Num + Letter) : ");
	// scanf("%d%c", &col, side);
	// if (turn == 0)
	// 	map[col - 1][side[0] - 'A'] = -1;
	// else if (turn == 1)
	// 	map[col - 1][side[0] - 'A'] = -2;
	// }
	else
	{
		bebeep(map, whoru, difficulty, turn);
	}
}
