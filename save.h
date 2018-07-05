// save team information to (User_name)_inf.dat
void save_teaminf(struct team_information *team_inf,char filename[])
{
	FILE *fp;
	char new_filename[1000];
	strcpy(new_filename,filename);
	strcat(new_filename,"_inf.dat");
	fp=fopen(new_filename,"wt");
	fprintf(fp,"%s\n",team_inf->name);
	fprintf(fp,"%d\n",team_inf->player_N);
	fprintf(fp,"%d\n",team_inf->score);
	fprintf(fp,"%d\n",team_inf->win);
	fprintf(fp,"%d\n",team_inf->lose);
	fprintf(fp,"%d\n",team_inf->draw);
	fprintf(fp,"%d\n",team_inf->goal);
	fprintf(fp,"%d\n",team_inf->pass);
	fprintf(fp,"%d\n",team_inf->red);
	fprintf(fp,"%d\n",team_inf->yellow);	
	fprintf(fp,"%d\n",team_inf->value);
	fclose(fp);
	//encipher(new_filename);	
}

// save player to (User_name).dat
void save_player(struct player *player_pHead,char filename[])
{
	FILE *fp;
	char new_filename[1000];
	strcpy(new_filename,filename);
	strcat(new_filename,".dat");
	fp=fopen(new_filename,"wt");
	struct player *pTemp;
	pTemp=player_pHead->next;
	while(pTemp!=NULL)
	{
		fprintf(fp,"%s\n",pTemp->name);
		fprintf(fp,"%s\n",pTemp->pos);
		fprintf(fp,"%d\n",pTemp->weight);
		fprintf(fp,"%d\n",pTemp->height);
		fprintf(fp,"%d\n",pTemp->num);
		fprintf(fp,"%d\n",pTemp->goal);
		fprintf(fp,"%d\n",pTemp->pass);
		fprintf(fp,"%d\n",pTemp->yellow);
		fprintf(fp,"%d\n",pTemp->red);
		fprintf(fp,"%d\n",pTemp->value);
		pTemp=pTemp->next;
	}
	fclose(fp);
	//encipher(new_filename);
}

// save account to account.dat
void save_account()
{
	int i;
	FILE *fp;
	fp=fopen("account.dat","wt");
	fprintf(fp,"%d\n",account_N);
	struct account *pTemp;
	pTemp=account_pHead;
	for (i=0;i<account_N;i++)
	{
		fprintf(fp,"%s\n",pTemp->User_name);
		fprintf(fp,"%s\n",pTemp->Password);
		fprintf(fp,"%d\n",pTemp->privilege);
		fprintf(fp,"%d\n",pTemp->wrong_time);
		fprintf(fp,"%d\n",pTemp->sleep_time);
		fprintf(fp,"%s\n",pTemp->team_name);
		fprintf(fp,"%s\n",pTemp->coach_name);		
		if (pTemp->privilege==2)
		{
			save_player(pTemp->player_pHead,pTemp->User_name);
			strcpy(pTemp->team_inf->name,pTemp->team_name);
			save_teaminf(pTemp->team_inf,pTemp->User_name);
		}
		pTemp=pTemp->next;
	}
	fclose(fp);
	//encipher("account.dat");
}

