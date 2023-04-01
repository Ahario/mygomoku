#include "mygo.h"

void bebeep_beginner(int map[20][20], int whoru, int aside)
{
	int i;
	int j;
	int nineway[3] = {-1, 0, 1};
	int rand_x;
	int rand_y;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 2);
	std::pair<int, int> coord;
	rand_x = dis(gen);
	rand_y = dis(gen);
	i = 0;
	j = 0;
	if (check_player(map, aside) == 0)
	{
		if (map[9 + nineway[rand_x]][9 + nineway[rand_y]] == 0)
		{
			map[9 + nineway[rand_x]][9 + nineway[rand_y]] = aside;
		}
		else
			bebeep_beginner(map, whoru, aside);
	}
	else
	{		for(i = 0; i < 20; i++)
		{
			for(j = 0; j < 20; j++)
			{
				if (check_players_four(map, whoru, aside) == 1)
				{
					coord = get_defense_coord(map, whoru, aside, 4);
				}
				else if (check_players_three)
			}
		}
	}
}
 
void bebeep_intermediate(int map[20][20], int whoru, int aside)
{
	printf("this is intermediate\n");
}

void bebeep_blitz(int map[20][20], int whoru, int adie)
{
	printf("this is blitz\n");
}

void bebeep(int map[20][20], int whoru, int difficulty, int aside)
{
	if (difficulty == 1)
		bebeep_beginner(map, whoru, aside);
	if (difficulty == 2)
		bebeep_intermediate(map, whoru, aside);
	if (difficulty == 3)
		bebeep_blitz(map, whoru, aside);
}