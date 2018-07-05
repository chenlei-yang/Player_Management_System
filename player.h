// find player by name
// if exist return the point of the struct else return NULL
struct player *player_find_name(struct account *now_account,char name[])
{
	struct player *pTemp;
	pTemp=now_account->player_pHead->next;
	while(pTemp!=NULL)
	{
		if (strcmp(pTemp->name,name)==0) return pTemp;
		pTemp=pTemp->next;
	}
	return NULL;
}

// find player by num
// if exist return the point of the struct else return NULL
struct player *player_find_num(struct account *now_account,int num)
{
	struct player *pTemp;
	pTemp=now_account->player_pHead->next;
	while(pTemp!=NULL)
	{
		if (pTemp->num==num) return pTemp;
		pTemp=pTemp->next;
	}
	return NULL;
}

// show team informantion
void player_inf(struct account *now_account)
{
	while(1)
	{
		struct account *pTemp,*now_team;
		char team_name[1000];
		pTemp=account_pHead->next;
		system("CLS");
		printf("Tip:press 0 to exit\n\n");
		printf("Here is team list:\n");
		while(pTemp!=NULL)
		{
			if (pTemp->privilege!=2)
			{
				pTemp=pTemp->next;
				continue;
			}
			printf("%s\n",pTemp->team_name);
			pTemp=pTemp->next;
		}
		printf("\nplease input the team's name you want to view:\n");
		scanf("%s",team_name);
		
		if (strcmp(team_name,"0")==0) return;
		
		if ((!account_find_teamname(team_name))||(strcmp(team_name,"admin")==0))
		{
			printf("This team isn't exist!\n");
			printf("Press any key to input again!\n");
			fflush(stdin); getchar();
			continue;
		}
		
		now_team=account_find_teamname(team_name);
		system("CLS");
		struct team_information *team_inf;
		team_inf=now_team->team_inf;
		printf("**************************************************\n");
		printf("*                Team Infomation                 *\n");
		printf("*        Team:--------------------%-15s*\n",now_team->team_name);
		printf("*        Coach:-------------------%-15s*\n",now_team->coach_name);
		printf("*        Player sum:--------------%-15d*\n",team_inf->player_N);
		printf("*        Value--------------------%-15d*\n",team_inf->value);
		printf("*        Win:---------------------%-15d*\n",team_inf->win);
		printf("*        Draw:--------------------%-15d*\n",team_inf->draw);
		printf("*        Lose:--------------------%-15d*\n",team_inf->lose);
		printf("*        Goal:--------------------%-15d*\n",team_inf->goal);
		printf("*        Pass:--------------------%-15d*\n",team_inf->pass);
		printf("*        Red Card:----------------%-15d*\n",team_inf->red);
		printf("*        Yellow Card:-------------%-15d*\n",team_inf->yellow);
		printf("**************************************************\n\n");
		printf("Press any key to back!\n");
		fflush(stdin); getchar();	
	}
}

// add player to team
void player_add(struct account *now_account)
{
	int i;
	struct player *new_player;
	new_player=(struct player*)malloc(sizeof(struct player));
	while(1)
	{
		system("CLS"); fflush(stdin);
		printf("Tip:press 0 to exit\n");
		printf("Player's name:\n");
		scanf("%s",new_player->name);
		
		if (strcmp(new_player->name,"0")==0) return;
		
		if (player_find_name(now_account,new_player->name)!=NULL)
		{
			printf("This player has already exist!\n");
			printf("Press any key to change a name!\n");
			fflush(stdin); getchar();
			continue;
		}
		
		printf("set %s as player's name(y/n):",new_player->name);
		fflush(stdin); 
		char ch=getchar();
		if (ch=='y'||ch=='Y') break;
	}

	while(1)
	{
		system("CLS"); fflush(stdin);
		printf("Tip:press 0 to exit\n");
		printf("Tip:GK,RB,CB,LB,RM,CM,LM,ACM,DCM,RF,LF,CF,SS\n");
		printf("Player's position:\n");
		scanf("%s",new_player->pos);
		
		if (strcmp(new_player->pos,"0")==0) return;
		
		if (strcmp(new_player->pos,"GK") && 
			strcmp(new_player->pos,"RB") && 
			strcmp(new_player->pos,"CB") && 
			strcmp(new_player->pos,"LB") && 
			strcmp(new_player->pos,"RM") && 
			strcmp(new_player->pos,"CM") && 
			strcmp(new_player->pos,"LM") &&
			strcmp(new_player->pos,"ACM") && 
			strcmp(new_player->pos,"DCM") && 
			strcmp(new_player->pos,"RF") &&
			strcmp(new_player->pos,"LF") &&
			strcmp(new_player->pos,"CF") &&
			strcmp(new_player->pos,"SS")   
		)
			continue;
		
		printf("set %s as player's position(y/n):",new_player->pos);
		fflush(stdin); 
		char ch=getchar();
		if (ch=='y'||ch=='Y') break;
	}
	
	while(1)
	{
		system("CLS"); fflush(stdin);
		printf("Tip:press 0 to exit\n");
		printf("Player's weight:\n");
		scanf("%d",&new_player->weight);
		
		if (new_player->weight==0) return;
		
		printf("set %d as player's weight(y/n):",new_player->weight);
		fflush(stdin); 
		char ch=getchar();
		if (ch=='y'||ch=='Y') break;
	}

	while(1)
	{
		system("CLS"); fflush(stdin);
		printf("Tip:press 0 to exit\n");
		printf("Player's height:\n");
		scanf("%d",&new_player->height);
		
		if (new_player->height==0) return;
		
		printf("set %d as player's height(y/n):",new_player->height);
		fflush(stdin); 
		char ch=getchar();
		if (ch=='y'||ch=='Y') break;
	}
	
	while(1)
	{
		system("CLS"); fflush(stdin);
		printf("Tip:press 0 to exit\n");
		printf("Player's number:\n");
		scanf("%d",&new_player->num);
		
		if (new_player->num==0) return;
		
		if (player_find_num(now_account,new_player->num)!=NULL)
		{
			printf("This number has already used!\n");
			printf("Press any key to change a number!\n");
			fflush(stdin); getchar();
			continue;
		}
		
		printf("set %d as player's number(y/n):",new_player->num);
		fflush(stdin); 
		char ch=getchar();
		if (ch=='y'||ch=='Y') break;
	}

	while(1)
	{
		system("CLS"); fflush(stdin);
		//printf("Tip:press 0 to exit\n");
		printf("Player's goal:\n");
		scanf("%d",&new_player->goal);
		
		//if (new_player->goal==0) return;
		
		printf("set %d as player's goal(y/n):",new_player->goal);
		fflush(stdin); 
		char ch=getchar();
		if (ch=='y'||ch=='Y') break;
	}
	
	while(1)
	{
		system("CLS"); fflush(stdin);
		//printf("Tip:press 0 to exit\n");
		printf("Player's pass:\n");
		scanf("%d",&new_player->pass);
		
		
		//if (new_player->pass==0) return;
		
		printf("set %d as player's pass(y/n):",new_player->pass);
		fflush(stdin); 
		char ch=getchar();
		if (ch=='y'||ch=='Y') break;
	}
	
	while(1)
	{
		system("CLS"); fflush(stdin);
		//printf("Tip:press 0 to exit\n");
		printf("Player's yellow card:\n");
		scanf("%d",&new_player->yellow);
		
		//if (new_player->yellow==0) return;
		
		printf("set %d as player's yellow card(y/n):",new_player->yellow);
		fflush(stdin); 
		char ch=getchar();
		if (ch=='y'||ch=='Y') break;
	}

	while(1)
	{
		system("CLS"); fflush(stdin);
		//printf("Tip:press 0 to exit\n");
		printf("Player's red card:\n");
		scanf("%d",&new_player->red);
		
		
		//if (new_player->red==0) return;
		
		printf("set %d as player's red card(y/n):",new_player->red);
		fflush(stdin); 
		char ch=getchar();
		if (ch=='y'||ch=='Y') break;
	}	

	while(1)
	{
		system("CLS"); fflush(stdin);
		//printf("Tip:press 0 to exit\n");
		printf("Player's value:\n");
		scanf("%d",&new_player->value);
		
		//if (new_player->value==0) return;
		
		printf("set %d as player's value(y/n):",new_player->value);
		fflush(stdin); 
		char ch=getchar();
		if (ch=='y'||ch=='Y') break;
	}	
	now_account->team_inf->goal+=new_player->goal;
	now_account->team_inf->pass+=new_player->pass;
	now_account->team_inf->red+=new_player->red;
	now_account->team_inf->yellow+=new_player->yellow;
	now_account->team_inf->value+=new_player->value;
	//new_player->goal=0; new_player->pass=0;
	//new_player->red=0; new_player->yellow=0;
	//new_player->value=0;
	struct player *pEnd,*pNew;
	pEnd=now_account->player_pHead;
	while(pEnd->next!=NULL)
	{
		pEnd=pEnd->next;
	}
	//pNew=(struct player *)malloc(sizeof(struct player));
	pNew=new_player;
	pEnd->next=pNew;
	pNew->next=NULL;
	
	now_account->team_inf->player_N++;
	save_account();
	
	printf("\nFinish!\n");
	fflush(stdin); getch();
}

// edit player
void player_edit(struct account *now_account)
{
	while(1)
	{
		struct player *pTemp,*now_player,new_player;
		char player_name[1000];
		pTemp=now_account->player_pHead->next;
		system("CLS");
		printf("Tip:press 0 to exit\n\n");
		printf("Here is player list:\n");
		while(pTemp!=NULL)
		{
			printf("%s\n",pTemp->name);
			pTemp=pTemp->next;
		}
		printf("\nplease input the player's name you want to edit:\n");
		scanf("%s",player_name);
		
		if (strcmp(player_name,"0")==0) return;
		
		if (!player_find_name(now_account,player_name))
		{
			printf("This player isn't exist!\n");
			printf("Press any key to input again!\n");
			fflush(stdin); getchar();
			continue;
		}
		
		now_player=player_find_name(now_account,player_name);
		
		while(1)
		{
			system("CLS");
			
			printf("1. name-------------%s\n",now_player->name); 
			printf("2. position---------%s\n",now_player->pos);
			printf("3. weight-----------%d\n",now_player->weight);
			printf("4. height-----------%d\n",now_player->height);
			printf("5. number-----------%d\n",now_player->num);
			printf("6. goal-------------%d\n",now_player->goal);
			printf("7. pass-------------%d\n",now_player->pass);
			printf("8. red--------------%d\n",now_player->red);
			printf("9. yellow-----------%d\n",now_player->yellow);
			printf("10.value------------%d\n",now_player->value);
			printf("0. exit\n\n");
			printf("please input the number:\n");
			
			fflush(stdin);
			char ch=getchar(),ch1=getchar();
			
			if (ch=='1'&&ch1=='0')
			{
				while(1)
				{
					system("CLS"); fflush(stdin);
					//printf("Tip:press 0 to exit\n");
					printf("Player's value:\n");
					scanf("%d",&new_player.value);
					
					//if (new_player.goal==0) break;
					
					printf("change %d as player's value(y/n):",new_player.value);
					fflush(stdin); 
					char ch=getchar();
					if (ch=='y'||ch=='Y') 
					{
						now_account->team_inf->value=now_account->team_inf->value-now_player->value+new_player.value;
						now_player->value=new_player.value;
						save_account();
						printf("Finish!\n");
						printf("Press any key to exit!\n");
						fflush(stdin); getchar();					
						break;
					}
				}			
			}
			else if (ch=='1'&&ch1!='0')
			{
				while(1)
				{
					system("CLS"); fflush(stdin);
					printf("Tip:press 0 to back\n");
					printf("Player's name:\n");
					scanf("%s",new_player.name);
		
					if (strcmp(new_player.name,"0")==0) break;

					if (player_find_name(now_account,new_player.name)!=NULL)
					{
						printf("This name has already exist!\n");
						printf("Press any key to change a name!\n");
						fflush(stdin); getchar();
						continue;
					}
					
					printf("change %s as player's name(y/n):",new_player.name);
					fflush(stdin); 
					char ch=getchar();
					if (ch=='y'||ch=='Y') 
					{
						strcpy(now_player->name,new_player.name);
						save_account();
						printf("Finish!\n");
						printf("Press any key to exit!\n");
						fflush(stdin); getchar();					
						break;
					}
				}
			}
			else if (ch=='2')
			{
				while(1)
				{
					system("CLS"); fflush(stdin);
					printf("Tip:press 0 to exit\n");
					printf("Tip:GK,RB,CB,LB,RM,CM,LM,ACM,DCM,RF,LF,CF,SS\n");
					printf("Player's position:\n");
					scanf("%s",new_player.pos);
					if (strcmp(new_player.pos,"GK") && 
						strcmp(new_player.pos,"RB") && 
						strcmp(new_player.pos,"CB") && 
						strcmp(new_player.pos,"LB") && 
						strcmp(new_player.pos,"RM") && 
						strcmp(new_player.pos,"CM") && 
						strcmp(new_player.pos,"LM") &&
						strcmp(new_player.pos,"ACM") && 
						strcmp(new_player.pos,"DCM") && 
						strcmp(new_player.pos,"RF") &&
						strcmp(new_player.pos,"LF") &&
						strcmp(new_player.pos,"CF") &&
						strcmp(new_player.pos,"SS")   
						)
						continue;
					
					if (strcmp(new_player.pos,"0")==0) break;
					
					printf("change %s as player's position(y/n):",new_player.pos);
					fflush(stdin); 
					char ch=getchar();
					if (ch=='y'||ch=='Y') 
					{
						strcpy(now_player->pos,new_player.pos);
						save_account();
						printf("Finish!\n");
						printf("Press any key to exit!\n");
						fflush(stdin); getchar();					
						break;
					}
				}				
			}
			else if (ch=='3')
			{
				while(1)
				{
					system("CLS"); fflush(stdin);
					printf("Tip:press 0 to exit\n");
					printf("Player's weight:\n");
					scanf("%d",&new_player.weight);
					
					if (new_player.weight==0) break;
					
					printf("change %d as player's weight(y/n):",new_player.weight);
					fflush(stdin); 
					char ch=getchar();
					if (ch=='y'||ch=='Y') 
					{
						now_player->weight=new_player.weight;
						save_account();
						printf("Finish!\n");
						printf("Press any key to exit!\n");
						fflush(stdin); getchar();					
						break;
					}
				}				
			}
			else if (ch=='4')
			{
				while(1)
				{
					system("CLS"); fflush(stdin);
					printf("Tip:press 0 to exit\n");
					printf("Player's height:\n");
					scanf("%d",&new_player.height);
					
					if (new_player.height==0) break;
					
					printf("change %d as player's height(y/n):",new_player.height);
					fflush(stdin); 
					char ch=getchar();
					if (ch=='y'||ch=='Y') 
					{
						now_player->height=new_player.height;
						save_account();
						printf("Finish!\n");
						printf("Press any key to exit!\n");
						fflush(stdin); getchar();					
						break;
					}
				}				
			}
			else if (ch=='5')
			{
				while(1)
				{
					system("CLS"); fflush(stdin);
					printf("Tip:press 0 to exit\n");
					printf("Player's number:\n");
					scanf("%d",&new_player.num);
					
					if (new_player.num==0) break;
					
					if (player_find_num(now_account,new_player.num)!=NULL)
					{
						printf("This number has already used!\n");
						printf("Press any key to change a number!\n");
						fflush(stdin); getchar();
						continue;
					}
					
					printf("change %d as player's number(y/n):",new_player.num);
					fflush(stdin); 
					char ch=getchar();
					if (ch=='y'||ch=='Y') 
					{
						now_player->num=new_player.num;
						save_account();
						printf("Finish!\n");
						printf("Press any key to exit!\n");
						fflush(stdin); getchar();					
						break;
					}
				}
			}
			else if (ch=='6')
			{
				while(1)
				{
					system("CLS"); fflush(stdin);
					//printf("Tip:press 0 to exit\n");
					printf("Player's goal:\n");
					scanf("%d",&new_player.goal);
					
					//if (new_player.goal==0) break;
					
					printf("change %d as player's goal(y/n):",new_player.goal);
					fflush(stdin); 
					char ch=getchar();
					if (ch=='y'||ch=='Y') 
					{
						now_account->team_inf->goal=now_account->team_inf->goal-now_player->goal+new_player.goal;
						now_player->goal=new_player.goal;
						save_account();
						printf("Finish!\n");
						printf("Press any key to exit!\n");
						fflush(stdin); getchar();					
						break;
					}
				}				
			}
			else if (ch=='7')
			{
				while(1)
				{
					system("CLS"); fflush(stdin);
					//printf("Tip:press 0 to exit\n");
					printf("Player's pass:\n");
					scanf("%d",&new_player.pass);
					
					//if (new_player.pass==0) break;
					
					printf("change %d as player's pass(y/n):",new_player.pass);
					fflush(stdin); 
					char ch=getchar();
					if (ch=='y'||ch=='Y') 
					{
						now_account->team_inf->pass=now_account->team_inf->pass-now_player->pass+new_player.pass;
						now_player->pass=new_player.pass;
						save_account();
						printf("Finish!\n");
						printf("Press any key to exit!\n");
						fflush(stdin); getchar();					
						break;
					}
				}				
			}
			else if (ch=='8')
			{
				while(1)
				{
					system("CLS"); fflush(stdin);
					//printf("Tip:press 0 to exit\n");
					printf("Player's red card:\n");
					scanf("%d",&new_player.red);
					
					//if (new_player.red==0) break;
					
					printf("change %d as player's red card(y/n):",new_player.red);
					fflush(stdin); 
					char ch=getchar();
					if (ch=='y'||ch=='Y') 
					{
						now_account->team_inf->red=now_account->team_inf->red-now_player->red+new_player.red;
						now_player->red=new_player.red;
						save_account();
						printf("Finish!\n");
						printf("Press any key to exit!\n");
						fflush(stdin); getchar();					
						break;
					}
				}				
			}
			else if (ch=='9')
			{
				while(1)
				{
					system("CLS"); fflush(stdin);
					//printf("Tip:press 0 to exit\n");
					printf("Player's yellow card:\n");
					scanf("%d",&new_player.yellow);
					
					//if (new_player.yellow==0) break;
					
					printf("change %d as player's yellow card(y/n):",new_player.yellow);
					fflush(stdin); 
					char ch=getchar();
					if (ch=='y'||ch=='Y') 
					{
						now_account->team_inf->yellow=now_account->team_inf->yellow-now_player->yellow+new_player.yellow;
						now_player->yellow=new_player.yellow;
						save_account();
						printf("Finish!\n");
						printf("Press any key to exit!\n");
						fflush(stdin); getchar();					
						break;
					}
				}				
			}
			else if (ch=='0')
				break;
			else 
			{
				MessageBox(0,"Please input the right number","Tip",0);
				//printf("Please input the right number\n");
				//printf("Press any key to continue!");
				//getch();
			}
		}
	}
}

// view player
void player_view(struct account *now_account)
{
	while(1)
	{
		system("CLS");
		
		printf("1. View by team\n");
		printf("2. Search by name\n");
		printf("3. Search by number\n");
		//printf("4. Advanced search\n");
		printf("0. exit\n\n");
		printf("please input the number:\n");
		
		fflush(stdin);
		char ch=getchar();
		if (ch=='1')
		{
			struct account *pTemp=account_pHead->next;
			while(pTemp!=NULL)
			{
				if (pTemp->privilege!=2)
				{
					pTemp=pTemp->next;
					continue;
				}
				system("CLS");
				printf("                              %s\n\n",pTemp->team_name);
				printf("Number\tName\t\tPosition\tGoal\tPass\tRed\tYellow\t\n");
				struct player *pTemp_player;
				pTemp_player=pTemp->player_pHead->next;
				while(pTemp_player!=NULL)
				{
					printf("%-8d",pTemp_player->num);
					printf("%-16s",pTemp_player->name);
					printf("%-16s",pTemp_player->pos);
					printf("%-8d",pTemp_player->goal);
					printf("%-8d",pTemp_player->pass);
					printf("%-8d",pTemp_player->red);
					printf("%-8d\n",pTemp_player->yellow);
					pTemp_player=pTemp_player->next;
				}
				printf("\nPress any key to view next team\n");
				fflush(stdin); getch();
				pTemp=pTemp->next;
			}
		}
		else if (ch=='2')
		{
			int flag=0;
			char search_name[1000];
			system("CLS");
			printf("Please input the name you want to search:\n");
			scanf("%s",search_name);
			system("CLS");
			printf("Name      team      Position\tGoal\tPass\tRed\tYellow\t\n");
			struct account *pTemp=account_pHead->next;
			while(pTemp!=NULL)
			{
				if (pTemp->privilege!=2)
				{
					pTemp=pTemp->next;
					continue;
				}
				struct player *now_player;
				if (player_find_name(pTemp,search_name)!=NULL)
				{
					now_player=player_find_name(pTemp,search_name);
					printf("%-10s",now_player->name);
					printf("%-10s",pTemp->team_name);
					printf("   %-9s",now_player->pos);
					printf("%-8d",now_player->goal);
					printf("%-8d",now_player->pass);
					printf("%-8d",now_player->red);
					printf("%-8d\n",now_player->yellow);
					flag=1;
				}
				pTemp=pTemp->next;
			}
			if (flag)
			{
				printf("\nPress any key to back!\n");
				fflush(stdin); getch();
				continue;		
			}
			else 
			{
				system("CLS");
				printf("This player doesn't exist!\n");
				printf("Press any key to back!\n");
				fflush(stdin); getch();
				continue;
			}
		}
		else if (ch=='3')
		{
			int flag=0,search_num;
			system("CLS");
			printf("Please input the number you want to search:\n");
			scanf("%d",&search_num);
			system("CLS");
			printf("Name            team         Number\tGoal\tPass\tRed\tYellow\t\n");
			struct account *pTemp=account_pHead->next;
			while(pTemp!=NULL)
			{
				if (pTemp->privilege!=2)
				{
					pTemp=pTemp->next;
					continue;
				}
				struct player *now_player;
				if (player_find_num(pTemp,search_num)!=NULL)
				{
					now_player=player_find_num(pTemp,search_num);
					printf("%-16s",now_player->name);
					printf("%-16s",pTemp->team_name);
					printf("%-8d",now_player->num);
					printf("%-8d",now_player->goal);
					printf("%-8d",now_player->pass);
					printf("%-8d",now_player->red);
					printf("%-8d\n",now_player->yellow);
					flag=1;
				}
				pTemp=pTemp->next;
			}
			if (flag)
			{
				printf("\nPress any key to back!\n");
				fflush(stdin); getch();
				continue;		
			}
			else 
			{
				system("CLS");
				printf("This player doesn't exist!\n");
				printf("Press any key to back!\n");
				fflush(stdin); getch();
				continue;
			}
		}
		else if (ch=='0')
			return;
		else 
		{
			MessageBox(0,"Please input the right number","Tip",0);
			//printf("Please input the right number\n");
			//printf("Press any key to continue!");
			//getch();
		}
	}	
}

// delete player
void player_delete(struct account *now_account)
{
	while(1)
	{
		struct player *pTemp,*now_player,new_player,*pre,*Next;
		char player_name[1000];
		pTemp=now_account->player_pHead->next;
		system("CLS");
		printf("Tip:press 0 to exit\n");
		printf("Here is player list:\n");
		while(pTemp!=NULL)
		{
			printf("%s\n",pTemp->name);
			pTemp=pTemp->next;
		}
		printf("\nplease input the player's name you want to delete:\n");
		scanf("%s",player_name);
		
		if (strcmp(player_name,"0")==0) return;
		
		if (!player_find_name(now_account,player_name))
		{
			printf("This player doesn't exist!\n");
			printf("Press any key to input again!\n");
			fflush(stdin); getchar();
			continue;
		}
		
		now_player=player_find_name(now_account,player_name);
		
		printf("Are you sure to delete player %s:(y/n)",player_name);
		fflush(stdin); 
		char ch=getchar();
		if (ch!='y'&&ch!='Y') continue;
		
		pre=now_account->player_pHead;
		while(pre->next!=now_player)
		{
			pre=pre->next;
		}
		Next=now_player->next;
		pre->next=Next;
		struct team_information *team_inf;
		team_inf=now_account->team_inf;
		team_inf->goal-=now_player->goal;
		team_inf->pass-=now_player->pass;
		team_inf->red-=now_player->red;
		team_inf->yellow-=now_player->yellow;
		team_inf->player_N--;
		free(now_player);
		
		save_account();
		printf("Finish!\n");
		printf("Press any key to exit!\n");
		fflush(stdin); getch();
		return;
	}
}

// edit match
void match_edit(struct account *now_account)
{
	char ch;
	while(1)
	{
		//clear the screen
		system("CLS");
		struct team_information *team_inf;
		team_inf=now_account->team_inf;
	
		printf("***************************************\n");
		printf("            Team information          *\n");
		printf("*     Team:---------------%-12s*\n",now_account->team_name);
		printf("*     Coach:--------------%-12s*\n",now_account->coach_name);
		printf("*     Score:--------------%-12d*\n",team_inf->score);
		printf("*     Win:----------------%-12d*\n",team_inf->win);
		printf("*     Draw:---------------%-12d*\n",team_inf->draw);		
		printf("*     Lose:---------------%-12d*\n",team_inf->lose);
		printf("***************************************\n\n");
			
		printf("***************************\n");
		printf("*    1. edit win match    *\n"); 
		printf("*    2. edit draw match   *\n");
		printf("*    3. edit lose match   *\n");
		printf("*    0. exit              *\n");
		printf("***************************\n\n");
		printf("please input the number:\n");
		
		fflush(stdin);
		ch=getchar();
		
		if (ch=='1')
		{
			int new_win;
			while(1)
			{
				system("CLS"); fflush(stdin);
				printf("Tip:press 0 to exit\n");
				printf("The number of win matchs:\n");
				scanf("%d",&new_win);
				
				if (new_win==0) break;
				
				printf("change %d as win matchs(y/n):",new_win);
				fflush(stdin); 
				char ch=getchar();
				if (ch=='y'||ch=='Y') 
				{
					team_inf->score=team_inf->score-3*team_inf->win+3*new_win; 
					team_inf->win=new_win;
					save_account();
					printf("Finish!\n");
					printf("Press any key to exit!\n");
					fflush(stdin); getchar();					
					break;
				}
			}	
		}
		else if (ch=='3')
		{
			int new_lose;
			while(1)
			{
				system("CLS"); fflush(stdin);
				printf("Tip:press 0 to exit\n");
				printf("The number of lose matchs:\n");
				scanf("%d",&new_lose);
				
				if (new_lose==0) break;
				
				printf("change %d as lose matchs(y/n):",new_lose);
				fflush(stdin); 
				char ch=getchar();
				if (ch=='y'||ch=='Y') 
				{
					team_inf->lose=new_lose;
					save_account();
					printf("Finish!\n");
					printf("Press any key to exit!\n");
					fflush(stdin); getchar();					
					break;
				}
			}	
		}
		else if (ch=='2')
		{
			int new_draw;
			while(1)
			{
				system("CLS"); fflush(stdin);
				printf("Tip:press 0 to exit\n");
				printf("The number of draw matchs:\n");
				scanf("%d",&new_draw);
				
				if (new_draw==0) break;
				
				printf("change %d as draw matchs(y/n):",new_draw);
				fflush(stdin); 
				char ch=getchar();
				if (ch=='y'||ch=='Y') 
				{
					team_inf->score=team_inf->score-team_inf->draw+new_draw;
					team_inf->draw=new_draw;
					save_account();
					printf("Finish!\n");
					printf("Press any key to exit!\n");
					fflush(stdin); getchar();					
					break;
				}
			}	
		}
		else if (ch=='0')
			return;
		else 
		{
			MessageBox(0,"Please input the right number","Tip",0);
			//printf("Please input the right number\n");
			//printf("Press any key to continue!");
			//getch();
		}
	}
	//printf("Press any key to back!\n");
	//fflush(stdin); getchar();	
}

void player_statistics(struct account *now_account)
{
	struct account *pTemp;
	pTemp=account_pHead->next;
}

