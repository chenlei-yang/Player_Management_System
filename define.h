#include "stdio.h"
#include "conio.h"
#include "windows.h"
#include "stdlib.h"
#include "string.h"

// a link list to save account
// the first palyer save coach
struct player
{
	// save the player's name
	char name[1000];
	// save the player's position(like GK,CF,SS)
	char pos[1000];
	// save the player's team
	char team[1000];
	// save the player's weight
	int weight;
	// save the player's height
	int height;
	// save the player's number
	int num;
	// save the player's goal
	int goal;
	// save the player's pass
	int pass;
	// save the red card
	int red;
	// save the yellow card
	int yellow;
	// save the player's value
	int value;
	// point to next player
	struct palyer *next;
};

// a struct to save team information
struct team_information
{
	// team name
	char name[1000];
	// the sum of player
	int player_N;
	int score,win,lose,draw;
	int goal,pass;
	int yellow,red;
	int value;
	struct team_information *next;
};

// a link list to save account
// the first account is admin
struct account
{
	// to save user's name
	char User_name[1000];
	// to save user's password
	char Password[1000];
	// to save user's privilege
	// -1 means user don't exist
	// 1 means admin (only admin can delete account)
	// 2 means coach
	// 3 means nomal user
	int privilege;
	// record the wrong time of the wrong input
	int wrong_time;
	// record the left frozen time of the account
	int sleep_time;
	// to save team name
	char team_name[1000];
	// to save coach name
	char coach_name[1000];
	// to save player
	struct player *player_pHead;
	// to save team information
	struct team_information *team_inf;
	// point to next account
	struct account *next;
};

#include "encipher.h"
#include "account.h"
#include "player.h"
#include "board.h"
#include "load.h"
#include "sign.h"
#include "menu.h"
#include "save.h"
