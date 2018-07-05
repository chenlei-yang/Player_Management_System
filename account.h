// the sum of account(include admin)
int account_N;
// the link list head of account
struct account *account_pHead=NULL;

// find account by name
// if exist return the point of the struct else return NULL
struct account *account_find_name(char name[])
{
	struct account *pTemp;
	pTemp=account_pHead;
	while(pTemp!=NULL)
	{
		if (strcmp(pTemp->User_name,name)==0) return pTemp;
		pTemp=pTemp->next;
	}
	return NULL;
}

struct account *account_find_teamname(char name[])
{
	struct account *pTemp;
	pTemp=account_pHead;
	while(pTemp!=NULL)
	{
		if (strcmp(pTemp->team_name,name)==0) return pTemp;
		pTemp=pTemp->next;
	}
	return NULL;
}

//cmpare the password to data if right return 1 else return 0
int account_pascmp(char name[],char Password[])
{
	struct account *pTemp;
	pTemp=account_pHead;
	while(pTemp!=NULL)
	{
		if (strcmp(pTemp->User_name,name)==0)
		{
			if (strcmp(pTemp->Password,Password)==0)
				return 1;
			else
				return 0;
		}
		pTemp=pTemp->next;
	}
	return 0;
}

// add account to link list
void account_add(struct account temp)
{
	struct account *pEnd,*pNew;
	pEnd=account_pHead;
	while(pEnd->next!=NULL)
	{
		pEnd=pEnd->next;
	}
	pNew=(struct account *)malloc(sizeof(struct account));
	pEnd->next=pNew;
	pNew->next=NULL;
	strcpy(pNew->User_name,temp.User_name);
	strcpy(pNew->Password,temp.Password);
	pNew->privilege=temp.privilege;
	pNew->sleep_time=temp.sleep_time;
	pNew->wrong_time=temp.wrong_time;
	strcpy(pNew->team_name,temp.team_name);
	strcpy(pNew->coach_name,temp.coach_name);	
	pNew->player_pHead=temp.player_pHead;
	pNew->team_inf=temp.team_inf;
}

// create a coach account
void account_create()
{
	int i;
	char User_name[1000],Password[1000],Password_for_sure[1000];
	char coach_name[1000],team_name[1000];
	while(1)
	{
		system("CLS"); fflush(stdin);
		printf("Tip:press 0 to exit\n");
		printf("User_name:\n");
		scanf("%s",User_name);
		
		if (account_find_name(User_name))
		{
			printf("This User_name has already exist!\n");
			printf("Press any key to change a name!\n");
			fflush(stdin); getchar();
			continue;
		}
		
		if (strcmp(User_name,"0")==0) return;
		
		printf("set %s as your name(y/n):",User_name);
		fflush(stdin); 
		char ch=getchar();
		if (ch=='y'||ch=='Y') break;
	}
	while(1)
	{
		system("CLS"); fflush(stdin);
		printf("Tip:press 0 to exit\n");
		printf("length of the password should at the range of 6-16\n");
		printf("Password:\n");
		//scanf("%s",Password);
		fflush(stdin);
		int len;
		len=input_password(&Password);
		//printf("%s\n",Password);		
		
		if (strcmp(Password,"0")==0) return;
		
		if (len<6)
		{
			printf("\nYour password is too short!\n");
			printf("Press any key to exit!\n");
			fflush(stdin); getch();
			continue;
		}
		
		while(1)
		{
			system("CLS"); fflush(stdin);
			printf("Tip:press 0 to exit\n");
			printf("Please input your password again:\n");
			fflush(stdin);
			int len;
			len=input_password(&Password_for_sure);
			//scanf("%s",Password_for_sure);
			
			if (strcmp(Password_for_sure,"0")==0) return;
			
			if (strcmp(Password,Password_for_sure)==0)
			{
				struct account temp;
				
				strcpy(temp.User_name,User_name); 
				strcpy(temp.Password,Password);
				temp.privilege=2; temp.sleep_time=temp.wrong_time=0;
				
				while(1)
				{
					system("CLS"); fflush(stdin);
					printf("Tip:press 0 to exit\n");
					printf("Please input the main imfomation:\n");
					printf("Please input coach name:");
					
					scanf("%s",coach_name);
					
					if (strcmp(coach_name,"0")==0) return;
					
					printf("set %s as your coach name(y/n):",coach_name);
					
					fflush(stdin); 
					char ch=getchar();
					if (ch=='y'||ch=='Y') break;
				}
				
				strcpy(temp.coach_name,coach_name);
				
				while(1)
				{
					system("CLS"); fflush(stdin);
					printf("Tip:press 0 to exit\n");
					printf("Please input the main imfomation:\n");
					printf("Please input team name:");
					
					scanf("%s",team_name);
					
					if (strcmp(team_name,"0")==0) return;
					
					printf("set %s as your team name(y/n):",team_name);
					
					fflush(stdin); 
					char ch=getchar();
					if (ch=='y'||ch=='Y') break;
				}
				
				strcpy(temp.team_name,team_name);
				temp.player_pHead=(struct player *)malloc(sizeof(struct player));
				temp.player_pHead->next=NULL;
				temp.team_inf=(struct team_information *)malloc(sizeof(struct team_information));
				strcpy(temp.player_pHead->name,temp.coach_name);
				strcpy(temp.team_inf->name,temp.team_name);
				temp.team_inf->player_N=0; temp.team_inf->win=0;
				temp.team_inf->draw=0; temp.team_inf->lose=0;
				temp.team_inf->goal=0; temp.team_inf->pass=0;
				temp.team_inf->red=0; temp.team_inf->yellow=0;
				temp.team_inf->value=0;
				
				account_add(temp); account_N++;
				
				save_account();
				//printf("account_N=%d\n",account_N); getch();
				printf("\nFinish!\n");
				fflush(stdin); getch();
				return;
			}
			else
			{
				printf("\nTwo passwords are not the same!\n");
				printf("Press any key to back!\n");
				fflush(stdin); getch();
				continue;
			}
		}
	}	
}

// edit account
void account_edit()
{
	while(1)
	{
		char User_name_Edit[1000];
		char new_team_name[1000];
		char new_coach_name[1000];
		struct account *temp,*pre,*Next,*account_Edit;
		temp=account_pHead->next;

		system("CLS");
		if (account_N==1)
		{
			printf("There is no account here,please sign in first!\n");
			printf("Press any key to continue!\n");
			getch();
			continue;
		}
		
		printf("Tip:press 0 to exit\n");
		printf("Here is user list\n\n");
		while(temp!=NULL)
		{
			printf("%s\n",temp->User_name);
			temp=temp->next;
		}
		
		printf("\nplease input the User_name you want to view:\n");
		scanf("%s",User_name_Edit);
		
		if (strcmp(User_name_Edit,"0")==0) return;
		
		if (account_find_name(User_name_Edit)==NULL)
		{
			printf("This account doesn't exist!\n");  
			printf("Press any key to back!\n");
			fflush(stdin); getch();
			continue;
		}
		
		account_Edit=account_find_name(User_name_Edit);
		
		system("CLS");
		
		if (account_Edit->privilege==2)
		{
			printf("User_name:%s\n",account_Edit->User_name);
			printf("team_name:%s\n",account_Edit->team_name);
			printf("coach_name:%s\n\n",account_Edit->coach_name);
			printf("1. Edit team_name\n");
			printf("2. Edit coach_name\n");
			
			fflush(stdin);
			char ch=getchar();
			
			if (ch=='1')
			{
				while(1)
				{
					system("CLS");
					printf("Tip:press 0 to exit\n");
					printf("User_name:%s\n",account_Edit->User_name);
					printf("team_name:%s\n",account_Edit->team_name);
					printf("coach_name:%s\n\n",account_Edit->coach_name);
					printf("Please input the new team name:\n");
					
					scanf("%s",new_team_name);
					
					if (strcmp(new_team_name,"0")==0) break;
					
					printf("change your team name to %s(y/n):",new_team_name);
					fflush(stdin); 
					char ch=getchar();
					if (ch=='y'||ch=='Y')
					{
						strcpy(account_Edit->team_name,new_team_name);
						printf("Finish!");
						printf("\nPress any key to back!\n");
						fflush(stdin); getch();
						save_account();
						return;
					}
				}
			}
			else if (ch=='2')
			{
				while(1)
				{
					system("CLS");
					printf("Tip:press 0 to exit\n");
					printf("User_name:%s\n",account_Edit->User_name);
					printf("team_name:%s\n",account_Edit->team_name);
					printf("coach_name:%s\n\n",account_Edit->coach_name);
					printf("Please input the new coach name:\n");
					
					scanf("%s",new_coach_name);
					
					if (strcmp(new_coach_name,"0")==0) break;
					
					printf("change your coach name to %s(y/n):",new_coach_name);
					fflush(stdin); 
					char ch=getchar();
					if (ch=='y'||ch=='Y')
					{
						strcpy(account_Edit->coach_name,new_coach_name);
						printf("Finish!");
						printf("\nPress any key to back!\n");
						fflush(stdin); getch();
						save_account();
						return;
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
				continue;
			}	
		}
		else
		{
			printf("User_name:%s\n\n",account_Edit->User_name);
			printf("This is a normal account!\n");
			printf("You have nothing to edit!\n\n");
			printf("Press any key to back!\n");
			fflush(stdin); getch();
			continue;
		}
		
		//printf("\nPress any key to exit!\n");
		//fflush(stdin); getch();
		return;
	}
}

// view account
void account_view()
{
	while(1)
	{
		char User_name_View[1000];
		struct account *temp,*pre,*Next,*account_View;
		temp=account_pHead->next;

		system("CLS");
		if (account_N==1)
		{
			printf("There is no account here,please sign in first!\n");
			printf("Press any key to continue!\n");
			getch();
			continue;
		}
		
		printf("Tip:press 0 to exit\n");
		printf("Here is user list\n\n");
		while(temp!=NULL)
		{
			printf("%s\n",temp->User_name);
			temp=temp->next;
		}
		
		printf("\nplease input the User_name you want to view:\n");
		scanf("%s",User_name_View);
		
		if (strcmp(User_name_View,"0")==0) return;
		
		if (account_find_name(User_name_View)==NULL)
		{
			printf("This account doesn't exist!\n");  
			printf("Press any key to back!\n");
			fflush(stdin); getch();
			continue;
		}
		
		account_View=account_find_name(User_name_View);
		
		system("CLS");
		printf("User_name:%s\n",account_View->User_name);
		
		if (account_View->privilege==2)
		{
			printf("team_name:%s\n",account_View->team_name);
			printf("coach_name:%s\n",account_View->coach_name);
		}
		
		printf("\nPress any key to exit!\n");
		fflush(stdin); getch();
		return;
	}
}

//delete account
void account_delete()
{
	while(1)
	{
		char User_name_Delete[1000],new_filename[1000];
		struct account *temp,*pre,*Next,*account_Delete;
		temp=account_pHead->next;

		system("CLS");
		if (account_N==1)
		{
			printf("There is no account here,please sign in first!\n");
			printf("Press any key to continue!\n");
			getch();
			continue;
		}
		
		printf("Tip:press 0 to exit\n");
		printf("Here is user list\n\n");
		while(temp!=NULL)
		{
			printf("%s\n",temp->User_name);
			temp=temp->next;
		}
		
		printf("\nplease input the User_name you want to delete:\n");
		scanf("%s",User_name_Delete);
		
		if (strcmp(User_name_Delete,"0")==0) return;
		
		if (account_find_name(User_name_Delete)==NULL)
		{
			printf("This account doesn't exist!\n");  
			printf("Press any key to back!\n");
			fflush(stdin); getch();
			continue;
		}
		else if (strcmp(User_name_Delete,"admin")==0)
		{
			printf("admin can't be delete!\n");
			printf("Press any key to back!\n");
			fflush(stdin); getch();
			continue;			
		}
		
		account_Delete=account_find_name(User_name_Delete);
		printf("Are you sure to delete accout %s:(y/n)",User_name_Delete);
		fflush(stdin); 
		char ch=getchar();
		if (ch!='y'&&ch!='Y') continue;
		
		pre=account_pHead;
		while(pre->next!=account_Delete)
		{
			pre=pre->next;
		}
		Next=account_Delete->next;
		pre->next=Next;
		free(account_Delete);
		account_N--;
		
		
		strcpy(new_filename,User_name_Delete);
		strcat(new_filename,".dat");
		FILE *fp;
		fp=fopen(new_filename,"wt");
		fprintf(fp,"");
		fclose(fp);
		remove(new_filename);
		strcpy(new_filename,User_name_Delete);
		strcat(new_filename,"_inf.dat");
		remove(new_filename);
		
		save_account();
		printf("Finish!\n");
		printf("Press any key to exit!\n");
		fflush(stdin); getch();
		return;
	}
}

