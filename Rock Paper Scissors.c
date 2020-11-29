#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int eq = 0;
int generateRandomNum(int n)
{
	srand(time(NULL));
	return (rand() % n);
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
	goto end;
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
int main(int argc, char *argv[]) //will be updated soon
{
	
	return 0;
}
end{
	printf("Thanks for playing\n");
}
