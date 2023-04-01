#ifndef MYGO_H
# define MYGO_H

# include <iostream>
# include <unistd.h>
# include <string>
# include <stack>
# include <vector>
# include <utility>
# include <functional>
# include <cstdlib>
# include <random>

//whoru
//0 == player
// 1 == Blizcrank
// -1 == O(White)
// -2 == X(Black)

//map
void init_startscreen(int map[20][20], int *pside, int *difficulty);
void update_and_ready(int map[20][20], int turn, int whoru, int difficulty);

//check
int check_howmany(int map[20][20], int startx, int starty, int direction, int total, int ori, int howmany);
int check_players_four(int map[20][20], int whoru, int aside);
int is_game_over(int map[20][20]);
int check_player(int map[20][20], int aside);

//ai
void bebeep_beginner(int map[20][20], int whoru, int aside);
void bebeep_intermediate(int map[20][20], int whoru, int aside);
void bebeep_blitz(int map[20][20], int whoru, int aside);
void bebeep(int map[20][20], int whoru, int difficulty, int turn);

//get
std::pair<int,int> get_defense_coord(int map[20][20], int whoru, int aside, int howmany);

# endif