#include "mygo.h"

std::pair<int,int> get_defense_coord(int map[20][20], int whoru, int aside, int howmany)
{
	int i;
	int j;
	std::pair<int, int> coord;
	int dx[4] = {1,0,1,-1};
	int dy[4] = {0,1,1,1};
	int flag = 0;
	int k;
	int ori;
	coord.first = 0;
	coord.second = 0;
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
						if (check_howmany(map,i,j,k,1, ori, howmany) == 1)
						{
							coord.first = i;
							coord.second = j;
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
	return (coord);
}