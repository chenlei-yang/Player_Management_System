// show score board
void score_board(struct account *now_account)
{
	struct team_information *team_pHead=NULL;
	struct account *pTemp;
	pTemp=account_pHead->next;
	while(pTemp!=NULL)
	{
		if (pTemp->privilege!=2)
		{
			pTemp=pTemp->next;
			continue;
		}
		struct team_information *inf;
		inf=pTemp->team_inf;
		if (team_pHead==NULL)
		{
			struct team_information *pNew,*pPre;
			team_pHead=pNew=(struct team_information *)malloc(sizeof(struct team_information));
			pNew->next=NULL; strcpy(pNew->name,inf->name);
			pNew->player_N=inf->player_N; pNew->score=inf->score;
			pNew->win=inf->win; pNew->lose=inf->lose; pNew->draw=inf->draw;
			pNew->goal=inf->goal; pNew->pass=inf->pass;
			pNew->red=inf->red; pNew->yellow=inf->yellow;
		}
		else
		{
			struct team_information *pNew,*pPre,*pNow,*pT;
			pNew=(struct player *)malloc(sizeof(struct player));
			strcpy(pNew->name,inf->name);
			pNew->player_N=inf->player_N; pNew->score=inf->score;
			pNew->win=inf->win; pNew->lose=inf->lose; pNew->draw=inf->draw; 
			pNew->goal=inf->goal; pNew->pass=inf->pass;
			pNew->red=inf->red; pNew->yellow=inf->yellow;
			if ((team_pHead->score)<(pNew->score))
			{
				pT=team_pHead;
				team_pHead=pNew;
				team_pHead->next=pT;
				pTemp=pTemp->next;
				continue;
			}
			pPre=pNow=team_pHead;
			while(pNow!=NULL&&((inf->score)<=(pNow->score)))
			{
				pPre=pNow;
				pNow=pNow->next;
			}
			pPre->next=pNew;
			pNew->next=pNow;
			//printf("%s %s %s\n",pPre->name,pNow->name,pNew->name);
		}
		pTemp=pTemp->next;
	}
	system("CLS");
	printf("                       Score Board\n\n");
	printf("Rank\tTeam\t\tScore\tWin\tDraw\tLose\n");
	struct team_information *pTemp_team;;
	pTemp_team=team_pHead; int i;
	while(pTemp_team!=NULL&&i<=30)
	{
		printf("%-8d%-16s%-8d%-8d%-8d%-8d\n",i,pTemp_team->name,pTemp_team->score,pTemp_team->win,pTemp_team->draw,pTemp_team->lose);
		pTemp_team=pTemp_team->next; i++;
	}
	printf("\nPress any key to back\n");
	getch();
}

// show goal board
void goal_board(struct account *now_account)
{
	struct player *player_pHead=NULL;
	struct account *pTemp;
	pTemp=account_pHead->next;
	while(pTemp!=NULL)
	{
		if (pTemp->privilege!=2)
		{
			pTemp=pTemp->next;
			continue;
		}
		struct player *pTemp_player;
		pTemp_player=pTemp->player_pHead->next;
		while(pTemp_player!=NULL)
		{
			if (player_pHead==NULL)
			{
				struct player *pNew,*pPre;
				player_pHead=pNew=(struct player *)malloc(sizeof(struct player));
				pNew->next=NULL; pNew->goal=pTemp_player->goal;
				pNew->height=pTemp_player->height; strcpy(pNew->name,pTemp_player->name);
				pNew->num=pTemp_player->num; pNew->pass=pTemp_player->pass;
				strcpy(pNew->pos,pTemp_player->pos); pNew->red=pTemp_player->red;
				pNew->weight=pTemp_player->weight; pNew->yellow=pTemp_player->yellow;
				strcpy(pNew->team,pTemp->team_name);
			}
			else
			{
				struct player *pNew,*pPre,*pNow,*pT;
				pNew=(struct player *)malloc(sizeof(struct player));
				pNew->goal=pTemp_player->goal;
				pNew->height=pTemp_player->height; strcpy(pNew->name,pTemp_player->name);
				pNew->num=pTemp_player->num; pNew->pass=pTemp_player->pass;
				strcpy(pNew->pos,pTemp_player->pos); pNew->red=pTemp_player->red;
				pNew->weight=pTemp_player->weight; pNew->yellow=pTemp_player->yellow;
				strcpy(pNew->team,pTemp->team_name);
				if ((player_pHead->goal)<(pNew->goal)||((player_pHead->goal)==(pNew->goal)&&(player_pHead->pass)<=(pNew->pass)))
				{
					pT=player_pHead;
					player_pHead=pNew;
					player_pHead->next=pT;
					pTemp_player=pTemp_player->next;
					continue;
				}
				pPre=pNow=player_pHead;
				while(pNow!=NULL&&((pTemp_player->goal)<(pNow->goal)||((pTemp_player->goal)==(pNow->goal)&&(pTemp_player->pass)<=(pNow->pass))))
				{
					pPre=pNow;
					pNow=pNow->next;
				}
				pPre->next=pNew;
				pNew->next=pNow;
				//printf("%s %s %s\n",pPre->name,pNow->name,pNew->name);
			}
			pTemp_player=pTemp_player->next;
		}
		pTemp=pTemp->next;
	}
	system("CLS");
	printf("                    Goal Board\n\n");
	printf("Rank\tPlayer\t\tTeam\t\tGoal\t\tPass\n");
	struct player *pTemp_player; int i=1;
	pTemp_player=player_pHead;
	while(pTemp_player!=NULL&&i<=20)
	{
		if (pTemp_player->goal==0) 
		{
			pTemp_player=pTemp_player->next;
			continue;
		}
		printf("%-8d%-16s%-16s%-16d%-16d\n",i,pTemp_player->name,pTemp_player->team,pTemp_player->goal,pTemp_player->pass);
		pTemp_player=pTemp_player->next; i++;
	}
	printf("\nPress any key to back\n");
	getch();
}

// show pass board
void pass_board(struct account *now_account)
{
	struct player *player_pHead=NULL;
	struct account *pTemp;
	pTemp=account_pHead->next;
	while(pTemp!=NULL)
	{
		if (pTemp->privilege!=2)
		{
			pTemp=pTemp->next;
			continue;
		}
		struct player *pTemp_player;
		pTemp_player=pTemp->player_pHead->next;
		while(pTemp_player!=NULL)
		{
			if (player_pHead==NULL)
			{
				struct player *pNew,*pPre;
				player_pHead=pNew=(struct player *)malloc(sizeof(struct player));
				pNew->next=NULL; pNew->goal=pTemp_player->goal;
				pNew->height=pTemp_player->height; strcpy(pNew->name,pTemp_player->name);
				pNew->num=pTemp_player->num; pNew->pass=pTemp_player->pass;
				strcpy(pNew->pos,pTemp_player->pos); pNew->red=pTemp_player->red;
				pNew->weight=pTemp_player->weight; pNew->yellow=pTemp_player->yellow;
				strcpy(pNew->team,pTemp->team_name);
			}
			else
			{
				struct player *pNew,*pPre,*pNow,*pT;
				pNew=(struct player *)malloc(sizeof(struct player));
				pNew->goal=pTemp_player->goal;
				pNew->height=pTemp_player->height; strcpy(pNew->name,pTemp_player->name);
				pNew->num=pTemp_player->num; pNew->pass=pTemp_player->pass;
				strcpy(pNew->pos,pTemp_player->pos); pNew->red=pTemp_player->red;
				pNew->weight=pTemp_player->weight; pNew->yellow=pTemp_player->yellow;
				strcpy(pNew->team,pTemp->team_name);
				if ((player_pHead->pass)<(pNew->pass))
				{
					pT=player_pHead;
					player_pHead=pNew;
					player_pHead->next=pT;
					pTemp_player=pTemp_player->next;
					continue;
				}
				pPre=pNow=player_pHead;
				while(pNow!=NULL&&((pTemp_player->pass)<=(pNow->pass)))
				{
					pPre=pNow;
					pNow=pNow->next;
				}
				pPre->next=pNew;
				pNew->next=pNow;
				//printf("%s %s %s\n",pPre->name,pNow->name,pNew->name);
			}
			pTemp_player=pTemp_player->next;
		}
		pTemp=pTemp->next;
	}
	system("CLS");
	printf("              Pass Board\n\n");
	printf("Rank\tPlayer\t\tTeam\t\tPass\n");
	struct player *pTemp_player; int i=1;
	pTemp_player=player_pHead;
	while(pTemp_player!=NULL&&i<=20)
	{
		if (pTemp_player->pass==0)
		{
			pTemp_player=pTemp_player->next;
			continue;
		}
		printf("%-8d%-16s%-16s%-16d\n",i,pTemp_player->name,pTemp_player->team,pTemp_player->pass);
		pTemp_player=pTemp_player->next; i++;
	}
	printf("\nPress any key to back\n");
	getch();
}

// show card board
void card_board(struct account *now_account)
{
	struct player *player_pHead=NULL;
	struct account *pTemp;
	pTemp=account_pHead->next;
	while(pTemp!=NULL)
	{
		if (pTemp->privilege!=2)
		{
			pTemp=pTemp->next;
			continue;
		}
		struct player *pTemp_player;
		pTemp_player=pTemp->player_pHead->next;
		while(pTemp_player!=NULL)
		{
			if (player_pHead==NULL)
			{
				struct player *pNew,*pPre;
				player_pHead=pNew=(struct player *)malloc(sizeof(struct player));
				pNew->next=NULL; pNew->goal=pTemp_player->goal;
				pNew->height=pTemp_player->height; strcpy(pNew->name,pTemp_player->name);
				pNew->num=pTemp_player->num; pNew->pass=pTemp_player->pass;
				strcpy(pNew->pos,pTemp_player->pos); pNew->red=pTemp_player->red;
				pNew->weight=pTemp_player->weight; pNew->yellow=pTemp_player->yellow;
				strcpy(pNew->team,pTemp->team_name);
			}
			else
			{
				struct player *pNew,*pPre,*pNow,*pT;
				pNew=(struct player *)malloc(sizeof(struct player));
				pNew->goal=pTemp_player->goal;
				pNew->height=pTemp_player->height; strcpy(pNew->name,pTemp_player->name);
				pNew->num=pTemp_player->num; pNew->pass=pTemp_player->pass;
				strcpy(pNew->pos,pTemp_player->pos); pNew->red=pTemp_player->red;
				pNew->weight=pTemp_player->weight; pNew->yellow=pTemp_player->yellow;
				strcpy(pNew->team,pTemp->team_name);
				if (((player_pHead->red)<(pNew->red))||((player_pHead->red)==(pNew->red)&&(player_pHead->yellow)<=(pNew->yellow)))
				{
					pT=player_pHead;
					player_pHead=pNew;
					player_pHead->next=pT;
					pTemp_player=pTemp_player->next;
					continue;
				}
				pPre=pNow=player_pHead;
				while(pNow!=NULL&&((pTemp_player->red)<(pNow->red)||((pTemp_player->red)==(pNow->red)&&(pTemp_player->yellow)<=(pNow->yellow))))
				{
					pPre=pNow;
					pNow=pNow->next;
				}
				pPre->next=pNew;
				pNew->next=pNow;
				//printf("%s %s %s\n",pPre->name,pNow->name,pNew->name);
			}
			pTemp_player=pTemp_player->next;
		}
		pTemp=pTemp->next;
	}
	system("CLS");
	printf("                     Card Board\n\n");
	printf("Rank\tPlayer\t\tTeam\t\tRed\tYellow\n");
	struct player *pTemp_player; int i=1;
	pTemp_player=player_pHead;
	while(pTemp_player!=NULL&&i<=20)
	{
		if (pTemp_player->red==0&&pTemp_player->yellow==0)
		{
			pTemp_player=pTemp_player->next;
			continue;
		}
		printf("%-8d%-16s%-16s%-8d%-8d\n",i,pTemp_player->name,pTemp_player->team,pTemp_player->red,pTemp_player->yellow);
		pTemp_player=pTemp_player->next; i++;
	}
	printf("\nPress any key to back\n");
	getch();
}

void weight_board(struct account *now_account)
{
	struct player *player_pHead=NULL;
	struct account *pTemp;
	pTemp=account_pHead->next;
	while(pTemp!=NULL)
	{
		if (pTemp->privilege!=2)
		{
			pTemp=pTemp->next;
			continue;
		}
		struct player *pTemp_player;
		pTemp_player=pTemp->player_pHead->next;
		while(pTemp_player!=NULL)
		{
			if (player_pHead==NULL)
			{
				struct player *pNew,*pPre;
				player_pHead=pNew=(struct player *)malloc(sizeof(struct player));
				pNew->next=NULL; pNew->goal=pTemp_player->goal;
				pNew->height=pTemp_player->height; strcpy(pNew->name,pTemp_player->name);
				pNew->num=pTemp_player->num; pNew->pass=pTemp_player->pass;
				strcpy(pNew->pos,pTemp_player->pos); pNew->red=pTemp_player->red;
				pNew->weight=pTemp_player->weight; pNew->yellow=pTemp_player->yellow;
				strcpy(pNew->team,pTemp->team_name);
			}
			else
			{
				struct player *pNew,*pPre,*pNow,*pT;
				pNew=(struct player *)malloc(sizeof(struct player));
				pNew->goal=pTemp_player->goal;
				pNew->height=pTemp_player->height; strcpy(pNew->name,pTemp_player->name);
				pNew->num=pTemp_player->num; pNew->pass=pTemp_player->pass;
				strcpy(pNew->pos,pTemp_player->pos); pNew->red=pTemp_player->red;
				pNew->weight=pTemp_player->weight; pNew->yellow=pTemp_player->yellow;
				strcpy(pNew->team,pTemp->team_name);
				if ((player_pHead->weight)>(pNew->weight))
				{
					pT=player_pHead;
					player_pHead=pNew;
					player_pHead->next=pT;
					pTemp_player=pTemp_player->next;
					continue;
				}
				pPre=pNow=player_pHead;
				while(pNow!=NULL&&((pTemp_player->weight)>=(pNow->weight)))
				{
					pPre=pNow;
					pNow=pNow->next;
				}
				pPre->next=pNew;
				pNew->next=pNow;
				//printf("%s %s %s\n",pPre->name,pNow->name,pNew->name);
			}
			pTemp_player=pTemp_player->next;
		}
		pTemp=pTemp->next;
	}
	system("CLS");
	printf("            Weight Board\n\n");
	printf("Rank\tPlayer\t\tTeam\t\tWeight\n");
	struct player *pTemp_player; int i=1;
	pTemp_player=player_pHead;
	while(pTemp_player!=NULL&&i<=20)
	{
		printf("%-8d%-16s%-16s%-16d\n",i,pTemp_player->name,pTemp_player->team,pTemp_player->weight);
		pTemp_player=pTemp_player->next; i++;
	}
	printf("\nPress any key to back\n");
	getch();
}

void height_board(struct account *now_account)
{
	struct player *player_pHead=NULL;
	struct account *pTemp;
	pTemp=account_pHead->next;
	while(pTemp!=NULL)
	{
		if (pTemp->privilege!=2)
		{
			pTemp=pTemp->next;
			continue;
		}
		struct player *pTemp_player;
		pTemp_player=pTemp->player_pHead->next;
		while(pTemp_player!=NULL)
		{
			if (player_pHead==NULL)
			{
				struct player *pNew,*pPre;
				player_pHead=pNew=(struct player *)malloc(sizeof(struct player));
				pNew->next=NULL; pNew->goal=pTemp_player->goal;
				pNew->height=pTemp_player->height; strcpy(pNew->name,pTemp_player->name);
				pNew->num=pTemp_player->num; pNew->pass=pTemp_player->pass;
				strcpy(pNew->pos,pTemp_player->pos); pNew->red=pTemp_player->red;
				pNew->weight=pTemp_player->weight; pNew->yellow=pTemp_player->yellow;
				strcpy(pNew->team,pTemp->team_name);
			}
			else
			{
				struct player *pNew,*pPre,*pNow,*pT;
				pNew=(struct player *)malloc(sizeof(struct player));
				pNew->goal=pTemp_player->goal;
				pNew->height=pTemp_player->height; strcpy(pNew->name,pTemp_player->name);
				pNew->num=pTemp_player->num; pNew->pass=pTemp_player->pass;
				strcpy(pNew->pos,pTemp_player->pos); pNew->red=pTemp_player->red;
				pNew->weight=pTemp_player->weight; pNew->yellow=pTemp_player->yellow;
				strcpy(pNew->team,pTemp->team_name);
				if ((player_pHead->height)>(pNew->height))
				{
					pT=player_pHead;
					player_pHead=pNew;
					player_pHead->next=pT;
					pTemp_player=pTemp_player->next;
					continue;
				}
				pPre=pNow=player_pHead;
				while(pNow!=NULL&&((pTemp_player->height)>=(pNow->height)))
				{
					pPre=pNow;
					pNow=pNow->next;
				}
				pPre->next=pNew;
				pNew->next=pNow;
				//printf("%s %s %s\n",pPre->name,pNow->name,pNew->name);
			}
			pTemp_player=pTemp_player->next;
		}
		pTemp=pTemp->next;
	}
	system("CLS");
	printf("               Height Board\n\n");
	printf("Rank\tPlayer\t\tTeam\t\tHeight\n");
	struct player *pTemp_player; int i=1;
	pTemp_player=player_pHead;
	while(pTemp_player!=NULL&&i<=20)
	{
		printf("%-8d%-16s%-16s%-16d\n",i,pTemp_player->name,pTemp_player->team,pTemp_player->height);
		pTemp_player=pTemp_player->next; i++;
	}
	printf("\nPress any key to back\n");
	getch();
}

void value_board(struct account *now_account)
{
	struct player *player_pHead=NULL;
	struct account *pTemp;
	pTemp=account_pHead->next;
	while(pTemp!=NULL)
	{
		if (pTemp->privilege!=2)
		{
			pTemp=pTemp->next;
			continue;
		}
		struct player *pTemp_player;
		pTemp_player=pTemp->player_pHead->next;
		while(pTemp_player!=NULL)
		{
			if (player_pHead==NULL)
			{
				struct player *pNew,*pPre;
				player_pHead=pNew=(struct player *)malloc(sizeof(struct player));
				pNew->next=NULL; pNew->goal=pTemp_player->goal;
				pNew->height=pTemp_player->height; strcpy(pNew->name,pTemp_player->name);
				pNew->num=pTemp_player->num; pNew->pass=pTemp_player->pass;
				strcpy(pNew->pos,pTemp_player->pos); pNew->red=pTemp_player->red;
				pNew->weight=pTemp_player->weight; pNew->yellow=pTemp_player->yellow;
				strcpy(pNew->team,pTemp->team_name);
			}
			else
			{
				struct player *pNew,*pPre,*pNow,*pT;
				pNew=(struct player *)malloc(sizeof(struct player));
				pNew->goal=pTemp_player->goal;
				pNew->height=pTemp_player->height; strcpy(pNew->name,pTemp_player->name);
				pNew->num=pTemp_player->num; pNew->pass=pTemp_player->pass;
				strcpy(pNew->pos,pTemp_player->pos); pNew->red=pTemp_player->red;
				pNew->weight=pTemp_player->weight; pNew->yellow=pTemp_player->yellow;
				pNew->value=pTemp_player->value;
				strcpy(pNew->team,pTemp->team_name);
				if ((player_pHead->value)<(pNew->value))
				{
					pT=player_pHead;
					player_pHead=pNew;
					player_pHead->next=pT;
					pTemp_player=pTemp_player->next;
					continue;
				}
				pPre=pNow=player_pHead;
				while(pNow!=NULL&&((pTemp_player->value)<=(pNow->value)))
				{
					pPre=pNow;
					pNow=pNow->next;
				}
				pPre->next=pNew;
				pNew->next=pNow;
				//printf("%s %s %s\n",pPre->name,pNow->name,pNew->name);
			}
			pTemp_player=pTemp_player->next;
		}
		pTemp=pTemp->next;
	}
	system("CLS");
	printf("               Value Board\n\n");
	printf("Rank\tPlayer\t\tTeam\t\tValue\n");
	struct player *pTemp_player; int i=1;
	pTemp_player=player_pHead;
	while(pTemp_player!=NULL&&i<=20)
	{
		printf("%-8d%-16s%-16s%-16d\n",i,pTemp_player->name,pTemp_player->team,pTemp_player->value);
		pTemp_player=pTemp_player->next; i++;
	}
	printf("\nPress any key to back\n");
	getch();
}

