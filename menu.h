// the menu which shows the sign in interface
void menu_sign()
{
	char ch;
	while(1)
	{
		//clear the screen
		system("CLS");
		
		printf("************************\n");
		// press 1 to sign in
		printf("*      1. sign up      *\n"); 
		// press 2 to sign up
		printf("*      2. sign in      *\n");
		// press 0 to exit the management system
		printf("*      0. exit         *\n");
		printf("************************\n\n");
		// tip
		printf("please input the number:\n");
		
		fflush(stdin);
		ch=getchar();
		//printf("%c\n",ch);
		
		if (ch=='1')
			sign_up();
		else if (ch=='2')
			sign_in();
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

void menu_board(struct account *now_account)
{
	char ch;
	while(1)
	{
		system("CLS");
		
		printf("******************************\n");
		printf("*       1. Score  Board      *\n");
		printf("*       2. Goal   Board      *\n");
		printf("*       3. Pass   Board      *\n");
		printf("*       4. Card   Board      *\n");
		printf("*       5. Weight Board      *\n");
		printf("*       6. Height Board      *\n");
		printf("*       7. Value  Board      *\n");
		printf("*       0. exit              *\n");
		printf("******************************\n\n");
		printf("please input the number:\n");
		
		fflush(stdin);
		ch=getchar();
		
		if (ch=='1')
			score_board(now_account);
		else if (ch=='2')
			goal_board(now_account);
		else if (ch=='3')
			pass_board(now_account);
		else if (ch=='4')
			card_board(now_account);
		else if (ch=='5') 
			weight_board(now_account);
		else if (ch=='6')
			height_board(now_account);
		else if (ch=='7')
			value_board(now_account);
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

void menu_management_coach(struct account *now_account)
{
	char ch;
	while(1)
	{
		system("CLS");
		printf("%s,welcome!\n\n",now_account->User_name);
		
		printf("***********************************\n");
		printf("*        1. Team information      *\n");
		printf("*        2. Add Player            *\n");
		printf("*        3. Edit Player           *\n");
		printf("*        4. View Player           *\n");
		printf("*        5. Delete Player         *\n");
		printf("*        6. Board                 *\n");
		printf("*        7. Edit match            *\n");
		//printf("*        8. Statistics            *\n");
		printf("*        0. exit                  *\n");
		printf("***********************************\n\n");
		printf("please input the number:\n");
		
		fflush(stdin);
		ch=getchar();
		
		if (ch=='1')
			player_inf(now_account);
		else if (ch=='2')
			player_add(now_account);
		else if (ch=='3')
			player_edit(now_account);
		else if (ch=='4')
			player_view(now_account);
		else if (ch=='5') 
			player_delete(now_account);
		else if (ch=='6')
			menu_board(now_account);
		else if (ch=='7')
			match_edit(now_account);
		//else if (ch=='8')
		//	player_statistics(now_account);
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


void menu_management_admin(struct account *now_account)
{
	char ch;
	while(1)
	{
		system("CLS");
		printf("Admin,welcome!\n\n");
		
		printf("******************************\n");
		printf("*      1. Create account     *\n");
		printf("*      2. Edit account       *\n");
		printf("*      3. View account       *\n");
		printf("*      4. Delete account     *\n");
		//printf("5. Add match\n");
		printf("*      0. exit               *\n");
		printf("******************************\n\n");
		printf("please input the number:\n");

		fflush(stdin);
		ch=getchar();
		
		if (ch=='1')
			account_create();
		else if (ch=='2')
			account_edit();
		else if (ch=='3')
			account_view();
		else if (ch=='4') 
			account_delete();
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

void menu_management_normal(struct account *now_account)
{
	char ch;
	while(1)
	{
		system("CLS");
		printf("%s,welcome!\n\n",now_account->User_name);
		
		printf("******************************\n");
		printf("*     1. Team information    *\n");
		printf("*     2. View Player         *\n");
		printf("*     3. Board               *\n");
		printf("*     0. exit                *\n");
		printf("******************************\n\n");
		printf("please input the number:\n");
		
		fflush(stdin);
		ch=getchar();
		
		if (ch=='1')
			player_inf(now_account);
		else if (ch=='2')
			player_view(now_account);
		else if (ch=='3')
			menu_board(now_account);
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

