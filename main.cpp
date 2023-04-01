#include "mygo.h"

int main()
{
	int map[20][20]; //map is 19 by 19 i think...
	// int i;
	// int j;
	int pside = 0;
	int aside = 0;
	int pturn = 0;
	int aturn = 0;
	int difficulty = 0;
	int turn = 1;
	init_startscreen(map, &pside, &difficulty);
	if (pside == -1)
	{
		aside = -2;
		aturn = 1;
	}
	else
	{
		aside = -1;
		pturn = 1;
	}
	printf("%d %d\n", pside, aside);
	while(1)
	{
		if (turn % 2 == pturn)
			update_and_ready(map, pside, 0, difficulty); 
		else
			update_and_ready(map, aside, 1, difficulty);
		turn++;
		if (is_game_over(map) == 1)
			break;
	}
	// for(i = 0; i < 20; i++)
	// {
	// 	for(j = 0; j < 20; j++)
	// 	{
	// 		if(map[i][j] == 0)
	// 			printf(". ");
	// 		if (map[i][j] == -1)
	// 			printf("O ");
	// 		if (map[i][j] == -2)
	// 			printf("X ");
	// 	}
	// 	printf("\n");
	// }
}