#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
	
#define WIDTH 4
#define HEIGHT 4
#define WIN 1
#define LOSE 0 
#define CONTINUE 2
#define _debug

int board[ WIDTH ][HEIGHT ];
int boardOneBefore[WIDTH ][HEIGHT ];
int boardTwoBefore[WIDTH ][HEIGHT ];

int leftMove();
int rightMove();
int upMove();
int downMove();
int moveDir(char dir);
int initGame();
int randGenerate();
int updateView();
int winOrLose();
int moveFlag;

int updateView()
{
//	refresh();
	clear();
	printBoard();	

	return 0;
}
int randGenerate()
{
	int i,j,zeroCount=0;
	int locat;
	int num;
	srand(time(0));
	num = (rand()%2 + 1) * 2;

	for(i=0;i <WIDTH; i++)
		for(j=0;j<HEIGHT;j++)
			if(board[i][j]==0)
				zeroCount++;
//	printw("%d",zeroCount);	
	locat = rand()%zeroCount + 1;
	for(i=0,zeroCount=0;i < WIDTH; i++)
		for(j=0;j<HEIGHT;j++)
			if(board[i][j]==0)
			{
				zeroCount++;
				if(zeroCount==locat)
					board[i][j]=num;
			}
//	printw("%d",zeroCount);	
	return 0;
}
int winOrLose()
{
	return CONTINUE;
}
int initGame()
{
	moveFlag=0;
	randGenerate();
	randGenerate();
	updateView();
}


int leftMove(){
	int i,j;
	int loop=0;
   for(loop=0; loop<WIDTH-1; loop++)
	for( i = 0; i<WIDTH ;i++)
	{
		for( j = 0; j < HEIGHT-1 ; j++)
		 	if(board[i][j] == 0 && board[i][j+1] != 0)
			{
				board[i][j]=board[i][j+1];
				board[i][j+1]=0;
				moveFlag=1;	
			}
	}
	for(i = 0; i<WIDTH; i++)
	{
		if(board[i][1] == board[i][0]  && board[i][1]!=0)
		{
			board[i][0] *= 2;
			board[i][1] = 0;
			moveFlag=1;
		}
		if(board[i][2] == board[i][1]  && board[i][2]!=0)
		{
			board[i][1] *= 2;
			board[i][0] = 0;
			moveFlag=1;
		}
		if(board[i][3] == board[i][2]  && board[i][3]!=0)
		{
			board[i][2] *= 2;
			board[i][3] = 0;
			moveFlag=1;
		}
	}
   for(loop=0; loop<WIDTH-1; loop++)
	for( i = 0; i<WIDTH ;i++)
	{
		for( j = 0; j < HEIGHT-1 ; j++)
		 	if(board[i][j] == 0 && board[i][j+1] != 0)
			{
				board[i][j]=board[i][j+1];
				board[i][j+1]=0;
				moveFlag=1;	
			}
	}
}
int rightMove(){
	int i,j;
	int loop;
   for(loop=0; loop<WIDTH-1; loop++)
	for( i = 0; i<WIDTH ;i++)
	{
		for( j = HEIGHT-1; j>0; j--)
		 	if(board[i][j] == 0 && board[i][j-1] != 0)
			{
				board[i][j]=board[i][j-1];
				board[i][j-1]=0;
				moveFlag=1;	
			}
	}
	for(i = 0; i<WIDTH; i++)
	{
		if(board[i][3] == board[i][2]  && board[i][3]!=0)
		{
			board[i][3] *= 2;
			board[i][2] = 0;
			moveFlag=1;
		}
		if(board[i][2] == board[i][1]  && board[i][2]!=0)
		{
			board[i][2] *= 2;
			board[i][1] = 0;
			moveFlag=1;
		}
		if(board[i][1] == board[i][0]  && board[i][1]!=0)
		{
			board[i][1] *= 2;
			board[i][0] = 0;
			moveFlag=1;
		}
	}
   for(loop=0; loop<WIDTH-1; loop++)
	for( i = 0; i<WIDTH ;i++)
	{
		for( j = HEIGHT-1; j>0; j--)
		 	if(board[i][j] == 0 && board[i][j-1] != 0)
			{
				board[i][j]=board[i][j-1];
				board[i][j-1]=0;
				moveFlag=1;	
			}
	}
}
int upMove(){
	int i,j;
	int loop;
   for(loop=0; loop<WIDTH-1; loop++)
	for( i = 0; i<WIDTH ;i++)
	{
		for( j = 0; j<HEIGHT-1; j++)
		 	if(board[j][i] == 0 && board[j+1][i] != 0)
			{
				board[j][i]=board[j+1][i];
				board[j+1][i]=0;
				moveFlag=1;	
			}
	}
	for(i = 0; i<WIDTH; i++)
	{
		if(board[1][i] == board[0][i]  && board[0][i]!=0)
		{
			board[0][i] *= 2;
			board[1][i] = 0;
			moveFlag=1;
		}
		if(board[2][i] == board[1][i]  && board[1][i]!=0)
		{
			board[1][i] *= 2;
			board[2][i] = 0;
			moveFlag=1;
		}
		if(board[3][i] == board[2][i]  && board[2][i]!=0)
		{
			board[2][i] *= 2;
			board[3][i] = 0;
			moveFlag=1;
		}
	}
   for(loop=0; loop<WIDTH-1; loop++)
	for( i = 0; i<WIDTH ;i++)
	{
		for( j = 0; j<HEIGHT-1; j++)
		 	if(board[j][i] == 0 && board[j+1][i] != 0)
			{
				board[j][i]=board[j+1][i];
				board[j+1][i]=0;
				moveFlag=1;	
			}
	}
}
int downMove(){
	int i,j;
	int loop;
   for(loop=0; loop<WIDTH-1; loop++)
	for( i = 0; i<WIDTH ;i++)
	{
		for( j = HEIGHT-1; j>0 ; j--)
		 	if(board[j][i] == 0 && board[j-1][i] != 0)
			{
				board[j][i]=board[j-1][i];
				board[j-1][i]=0;
				moveFlag=1;	
			}
	}
	for(i = 0; i<WIDTH; i++)
	{
		if(board[3][i] == board[2][i]  && board[2][i]!=0)
		{
			board[3][i] *= 2;
			board[2][i] = 0;
			moveFlag=1;
		}
		if(board[2][i] == board[1][i]  && board[1][i]!=0)
		{
			board[2][i] *= 2;
			board[1][i] = 0;
			moveFlag=1;
		}
		if(board[1][i] == board[0][i]  && board[0][i]!=0)
		{
			board[1][i] *= 2;
			board[0][i] = 0;
			moveFlag=1;
		}
	}
   for(loop=0; loop<WIDTH-1; loop++)
	for( i = 0; i<WIDTH ;i++)
	{
		for( j = HEIGHT-1; j>0 ; j--)
		 	if(board[j][i] == 0 && board[j-1][i] != 0)
			{
				board[j][i]=board[j-1][i];
				board[j-1][i]=0;
				moveFlag=1;	
			}
	}
}
int moveDir(char dir)
{
	switch(dir)
	{
	case 'a': leftMove();	break;
	case 'd': rightMove();	break;
	case 's': downMove();	break;
	case 'w': upMove();	break;
	
	}	
}
int printBoard()
{
#ifdef _debug
	int i, j;
	for(i=0;i < WIDTH; i++){
		for(j = 0; j < HEIGHT; j++)
	       	{
			//printf("%8d", board[i][j]);
			printw("%8d", board[i][j]);
		}
		printw("\n");	
	}
#endif
}

int main()
{

	initscr();
	initGame();
//	system("clear");
	char ch;
	ch=getchar();
	int ret; 
	while(ch!='\x1b')
	{
		moveDir(ch);
		if(moveFlag)
		{
			randGenerate();
			updateView();
			moveFlag=0;
		}
		if(CONTINUE !=	winOrLose())
		{
			break;
		}	
		ch=getch();
	}
	
	endwin();
}
