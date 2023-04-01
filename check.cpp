#include "mygo.h"

int check_howmany(int map[20][20], int startx, int starty, int direction, int total, int ori, int howmany)
{
	int flag = 0;
	int dx[4] = {1,0,1,-1};
	int dy[4] = {0,1,1,-1};
	int changex = startx;
	int changey = starty;
	int nextx;
	int nexty;
	std::stack<std::pair<int, int> > stack;
	stack.push(std::make_pair(changex, changey));
	while(!stack.empty())
	{
		total++;
		if (total == howmany)
		{
			flag = 1;
			break;
		}
		nextx = stack.top().first + dx[direction];
		nexty = stack.top().second + dy[direction];
		printf("this is x %d and this is y %d\n", nextx, nexty);
		stack.pop();
		if (nextx + dx[direction] >= 0 && nexty + dy[direction] >= 0 
			&& nextx + dx[direction] < 20 && nexty + dy[direction] < 20)
			{
				if (map[nextx+ dx[direction]][nexty + dy[direction]] == ori)
				{
					printf("this is total : %d\n", total);
					// check_five(map, changex, changey, direction, total);
					stack.push(std::make_pair(nextx, nexty));
				}
			}
	}
	if (flag == 1)
		return (1);
	return (0);
}

int is_game_over(int map[20][20])
{
	int dx[4] = {1,0,1,-1};
	int dy[4] = {0,1,1,1};
	// int visited[20][20][4];
	int i;
	int j;
	int flag = 0;
	int k;
	int ori;
	for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 20; j++)
		{
			if (map[i][j] != 0)
			{
				ori = map[i][j];
				for(k = 0; k < 4; k++)
				{
					if (map[i+dx[k]][j+dy[k]] == ori)
					{
						if (check_howmany(map,i,j,k,1, ori, 5) == 1)
						{
							flag = 1;
							break;
						}
					}
				}
			}
			if (flag == 1)
				break;
		}
		if (flag == 1)
			break;
	}
	if (flag == 1)
		return (1);
	return (0);
}

int check_player(int map[20][20], int whoru)
{
	int i;
	int j;
	int check;
	if (whoru == -1)
		check = -2;
	else
		check = -1;
	for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 20; j++)
		{
			if (map[i][j] == check)
				return (1);
		}
	}
	return (0);
}

int check_players_(int map[20][20], int whoru, int aside)
{
	int dx[4] = {1,0,1,-1};
	int dy[4] = {0,1,1,1};
	// int visited[20][20][4];
	int i;
	int j;
	int flag = 0;
	int k;
	int ori;
	for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 20; j++)
		{
			if (map[i][ j] != 0)
			{
				ori = map[i][j];
				for(k = 0; k < 4; k++)
				{
					if (map[i+dx[k]][j+dy[k]] == ori)
					{
						if (check_howmany(map,i,j,k,1, ori, 4) == 1)
						{
							flag = 1;
							break;
						}
					}
				}
			}
			if (flag == 1)
				break;
		}
		if (flag == 1)
			break;
	}
	if (flag == 1)
		return (1);
	return (0);
}