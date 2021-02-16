#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int eq = 0;
int generateRandomNum()
{
	srand(time(NULL));
	return (rand() % 3);
}
void compTurn(int turn) // to print out Computer's Choice'
{
	if(turn == 0)
	printf("Computer :-\trock\n");
	else if(turn == 1)
	printf("Computer :-\tpaper\n");
	else if(turn == 2)
	printf("Computer :-\tscissors\n");
}
void inputCheck(char val[])
{
	if(strcmp(val,"rock") == 0)
	eq = 0;
	else if(strcmp(val,"paper") == 0)
	eq = 1;
	else if(strcmp(val,"scissors") == 0)
	eq = 2;
	else{
	printf("You have entered wrong value\nGAME OVER\n");
	eq = 404; // exiting the program  after wrong input
	}
}
int winCheck(int num) //to check win or draw //returns 1 for victory, -1 for a draw and 0 for defeat
{
	if(num == eq)
	return -1;
	else if(eq == 0) //user entered rock
	{
		if(num == 1) //computer chose paper
		return 0;
		else if(num == 2) //computer chose scissors
		return 1;
	}
	else if(eq == 1) //user entered paper
	{
		if(num == 0) //computer chose rock
		return 1;
		else if(num == 2) //computer chose scissors
		return 0;
	}
	else if(eq == 2) //user entered scissors
	{
		if(num == 0) //computer chose rock
		return 0;
		else if(num == 1) //computer chose paper
		return 1;
	}
}
int main(int argc, char *argv[]) 
{
	int scoreU = 0, gen, scoreC = 0;
	char name[50];
	printf("Welcome to the rock, paper, scissors game\nRules are as follows:- \nYou have to enter case sensitive words only to enjoy the game.\nEnter \"rock\" for rock.\nEnter \"paper\" for paper.\nEnter \"scissors\" for scissors.\nYou have 3 turns and for every win you get a point.\nYou need at least two points for winning. Let's start ...\nStart by entering your name\n");
	
	scanf("\n");
	scanf("%s",name);
	printf("%s vs Computer\n",name);
	char choice[9]; //size of scissors
	for(int i = 0; i <3; i++)
	{
		printf("Round %d :-\n",(i + 1));
		printf("%s\'s turn:- \n",name);
		scanf("\n");
		scanf("%s",choice);
		gen = generateRandomNum();
		inputCheck(choice);
		if(eq == 404)
		goto end;
		compTurn(gen);
		if(winCheck(gen) == -1)
		{
			printf("You have a draw\n");
		}
		else if(winCheck(gen) == 0)
		{
			printf("Computer won, you lose\n");
			scoreC++;
		}
		else if(winCheck(gen) == 1)
		{
			printf("You win, computer loses\n");
			scoreU++;
		}
		printf("%s :-\t%d\n",name,scoreU);
		printf("Computer :-\t%d\n",scoreC);
	}
	printf("%s scored %d points\n",name,scoreU);
	printf("Computer scored %d points\n",scoreC);
	if(scoreU > scoreC)
	{
		printf("Congratulations, %s has won by %d points.\n",name,(scoreU - scoreC));
	}
	else if(scoreC > scoreU)
	{
		printf("Sorry, %s lost by %d points.\nBetter luck, next time.\n",name,(scoreC - scoreU));
	}
	else
	printf("%s and Computer are tied.\nNo winner\n",name);
	return 0;
	end:
		printf("Thanks for playing\n");
		

}

