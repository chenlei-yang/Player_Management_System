// load team information from (User_name)_inf.dat
struct team_information *load_teaminf(char filename[])
{
	FILE *fp;
	char new_filename[1000];
	strcpy(new_filename,filename);
	strcat(new_filename,"_inf.dat");
	//decipher(new_filename);
	struct team_information *team_inf;
	team_inf=(struct team_information *)malloc(sizeof(struct team_information));
	fp=fopen(new_filename,"rt");
	fscanf(fp,"%s",team_inf->name); fgetc(fp);
	fscanf(fp,"%d",&team_inf->player_N); fgetc(fp);
	fscanf(fp,"%d",&team_inf->score); fgetc(fp);
	fscanf(fp,"%d",&team_inf->win); fgetc(fp);
	fscanf(fp,"%d",&team_inf->lose); fgetc(fp);
	fscanf(fp,"%d",&team_inf->draw); fgetc(fp);
	fscanf(fp,"%d",&team_inf->goal); fgetc(fp);
	fscanf(fp,"%d",&team_inf->pass); fgetc(fp);
	fscanf(fp,"%d",&team_inf->red); fgetc(fp);
	fscanf(fp,"%d",&team_inf->yellow); fgetc(fp);
	fscanf(fp,"%d",&team_inf->value); fgetc(fp);
	fclose(fp);
	//encipher(new_filename);
	return team_inf;
}

// load player from (User_name).dat
struct player *load_player(char filename[],struct team_information *team_inf)
{
	int i;
	FILE *fp;
	char new_filename[1000],name[1000];
	strcpy(new_filename,filename);
	strcat(new_filename,".dat");
	fp=fopen(new_filename,"rt");
	struct player *pHead,*pNew,*pPre;
	pHead=pPre=pNew=(struct player *)malloc(sizeof(struct player));
	pHead->next=NULL;
	//printf("%d\n",player_N); getch();
	for (i=1;i<=team_inf->player_N;i++)
	{
		pPre=pNew;
		//printf("1\n"); getch();
		pNew=(struct player *)malloc(sizeof(struct player));
		fscanf(fp,"%s",pNew->name); fgetc(fp);
		fscanf(fp,"%s",pNew->pos); fgetc(fp);
		fscanf(fp,"%d",&pNew->weight); fgetc(fp);
		fscanf(fp,"%d",&pNew->height); fgetc(fp);
		fscanf(fp,"%d",&pNew->num); fgetc(fp);
		fscanf(fp,"%d",&pNew->goal); fgetc(fp);
		fscanf(fp,"%d",&pNew->pass); fgetc(fp);
		fscanf(fp,"%d",&pNew->yellow); fgetc(fp);
		fscanf(fp,"%d",&pNew->red); fgetc(fp);
		fscanf(fp,"%d",&pNew->value); fgetc(fp);
		pNew->next=NULL; pPre->next=pNew;
	}
	return pHead;
}

// load accout from accout.dat
void load_account()
{
	//decipher("account.dat");
	int i;
	FILE *fp;
	fp=fopen("account.dat","rt");
	fscanf(fp,"%d",&account_N);
	if (account_N==0)
	{
		struct account *pNew;
		pNew=account_pHead=(struct account *)malloc(sizeof(struct account));
		strcpy(pNew->User_name,"admin");
		strcpy(pNew->Password,"111111");
		pNew->privilege=1;
		pNew->wrong_time=0;
		pNew->sleep_time=0;
		strcpy(pNew->team_name,"admin");
		strcpy(pNew->coach_name,"admin");
		account_N++; 
	}
	struct account *pNew,*pPre;
	account_pHead=pPre=pNew=(struct account *)malloc(sizeof(struct account));
	pNew->next=NULL;
	fscanf(fp,"%s",pNew->User_name); fgetc(fp);
	fscanf(fp,"%s",pNew->Password); fgetc(fp);
	fscanf(fp,"%d",&pNew->privilege); fgetc(fp);
	fscanf(fp,"%d",&pNew->wrong_time); fgetc(fp);
	fscanf(fp,"%d",&pNew->sleep_time); fgetc(fp);
	fscanf(fp,"%s",pNew->team_name); fgetc(fp);
	fscanf(fp,"%s",pNew->coach_name); fgetc(fp);
	if (pNew->privilege==2)
	{
		pNew->team_inf=load_teaminf(pNew->User_name);
		pNew->player_pHead=load_player(pNew->User_name,pNew->team_inf);
	}
	for (i=1;i<account_N;i++)
	{
		pPre=pNew;
		pNew=(struct account *)malloc(sizeof(struct account));
		pNew->next=NULL;
		pPre->next=pNew;
		fscanf(fp,"%s",pNew->User_name); fgetc(fp);
		fscanf(fp,"%s",pNew->Password); fgetc(fp);
		fscanf(fp,"%d",&pNew->privilege); fgetc(fp);
		fscanf(fp,"%d",&pNew->wrong_time); fgetc(fp);
		fscanf(fp,"%d",&pNew->sleep_time); fgetc(fp);	
		fscanf(fp,"%s",pNew->team_name); fgetc(fp);
		fscanf(fp,"%s",pNew->coach_name); fgetc(fp);	
		if (pNew->privilege==2)
		{
			pNew->team_inf=load_teaminf(pNew->User_name);
			pNew->player_pHead=load_player(pNew->User_name,pNew->team_inf);
		}
	}
	fclose(fp);
}


