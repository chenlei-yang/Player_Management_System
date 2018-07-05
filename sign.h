// change char to * and return length 
int input_password(char *Password)
{
	int len=0;
	while(1)
	{
		char ch=getch();
		if (ch=='\r'&&len!=0)
		{
			Password[len++]='\0';
			break;
		}
		else if (ch=='\b')
		{
			if (len<=0)
			{
				printf("\a");
				continue;
			}
			printf("\b \b");
			len--;
			continue;
		}
		else
		{
			if (len>=16) continue;
			Password[len++]=ch;
			printf("*");
		}
	}		
	return len; 
}

// the main program of sign in
void sign_in()
{
	int i;
	char User_name[100],Password[100];
	while(1)
	{
		system("CLS"); fflush(stdin);
		printf("Tip:press 0 to back\n");
		printf("User_name:\n");
		scanf("%s",User_name);
		
		if (strcmp(User_name,"0")==0) return;
		
		if (account_find_name(User_name)==NULL)
		{
			printf("This User_name doesn't exist!\n");  
			printf("Press any key to back!\n");
			fflush(stdin); getch();
			continue;
		}
		
		break;
	}
	while(1)
	{
		system("CLS"); fflush(stdin);
		printf("Tip:press 0 to back\n");
		
		struct account *now_account;
		now_account=account_find_name(User_name);
		
		if (now_account->wrong_time)
		{
			if (now_account->wrong_time>=5)
			{
				while(now_account->sleep_time>0)
				{
					now_account->sleep_time--;
					system("CLS"); fflush(stdin);
					
					printf("You have wrong %d times!\n",now_account->wrong_time);
					printf("You can try after %ds!\n",now_account->sleep_time);
					
					sleep(1);
					save_account(); fflush(stdin);
				}
				
			}
			else
			{
				printf("You have wrong %d times!\n",now_account->wrong_time);
				printf("You only try %d times!\n",5-now_account->wrong_time);
			}
		}
		
		printf("Password:\n");
		//scanf("%s",Password);
		fflush(stdin);
		int len;
		len=input_password(&Password);
		
		if (strcmp(Password,"0")==0) return;
		
		if (account_pascmp(User_name,Password))
		{
			now_account->wrong_time=0;
			save_account();
			printf("\nPress any key to continue!\n");
			fflush(stdin); getchar();
			
			if (now_account->privilege==2) menu_management_coach(now_account);
			else if (now_account->privilege==1) menu_management_admin(now_account);
			else menu_management_normal(now_account);
			return;
		}
		else
		{
			now_account->wrong_time++;
			if (now_account->wrong_time>100) now_account->wrong_time=100;
			now_account->sleep_time=(now_account->wrong_time-4)*60;
			save_account();
			
			printf("Wrong password!\n");
			printf("Press any key to back!\n");
			fflush(stdin); getch();
			continue;
		}
	}
}

// the main program of sign up
void sign_up()
{
	int i;
	char User_name[100],Password[100],Password_for_sure[100];
	while(1)
	{
		system("CLS"); fflush(stdin);
		printf("Tip:press 0 to back\n");
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
		printf("Tip:press 0 to back\n");
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
			printf("Press any key to back!\n");
			fflush(stdin); getch();
			continue;
		}
		
		while(1)
		{
			system("CLS"); fflush(stdin);
			printf("Tip:press 0 to back\n");
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
				temp.privilege=3; temp.sleep_time=temp.wrong_time=0;
				strcpy(temp.team_name,"NULL");
				strcpy(temp.coach_name,"NULL");
				account_add(temp); account_N++;
				//printf("account_N=%d\n",account_N); getch();
				
				save_account();
				
				printf("\nFinish!\n");
				printf("Press any key to continue!\n");
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


