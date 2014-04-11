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

int (*backTo)[WIDTH] = boardOneBefore;

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
int printBoardBlackWhite();
int printBoardWithColor();
void storeNow();
int log2_B(int value)
{
	int x = 0;
	while(value > 1)
	{
		value>>=1;
		x++;
	}
	return x;
}

typedef int printBoardFunc_T();
printBoardFunc_T *printBoard;
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
	num = (rand()%5;
	if (num != 4)
		num = 2;

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

int initBoard()
{
	int i,j;
	for(i=0; i<HEIGHT; i++)
		for(j=0; j<WIDTH; j++)
			board[i][j]=0;	
	randGenerate();
	randGenerate();
	backTo = boardOneBefore; 
	storeNow();
	return 0;
}
int initBoardColor()
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_RED );
	init_pair(3, COLOR_BLACK, COLOR_RED);
	init_pair(4, COLOR_BLACK, COLOR_GREEN);
	init_pair(5, COLOR_BLACK, COLOR_YELLOW);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);
	init_pair(9, COLOR_BLACK, COLOR_WHITE);
	init_pair(10, COLOR_BLACK, COLOR_WHITE);
	init_pair(11, COLOR_BLACK, COLOR_WHITE);
	init_pair(12, COLOR_BLACK, COLOR_WHITE);
	return 0;
}
int initGame()
{
	moveFlag=0;
	initBoard();
	if(TRUE == has_colors())
	{
		printBoard= printBoardWithColor;	
		initBoardColor();
	}
	else printBoard = printBoardBlackWhite;
	updateView();
	return 0;
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
void storeNow()
{
	int( *backNow )[WIDTH];
	if(backTo == boardOneBefore )
	{
		backNow = boardTwoBefore;
	}
	else
		backNow = boardOneBefore;
	int i,j;
	for(i=0; i < HEIGHT; i++)
		for(j=0; j < WIDTH; j++)
			backNow[i][j] = board[i][j];
}
void backMove()
{
	int i,j;
	for( i = 0; i < HEIGHT; i++)
		for( j = 0; j < WIDTH ; j++)
			board[i][j] = backTo[i][j];
	updateView();
			
}
int moveDir(char dir)
{
	storeNow();
	switch(dir)
	{
	case 'a': leftMove();	break;
	case 'd': rightMove();	break;
	case 's': downMove();	break;
	case 'w': upMove();	break;
	case 'b': backMove();break;	
	}	
	if(moveFlag)
	{
		if(backTo == boardOneBefore)
			backTo = boardTwoBefore;
		else
			backTo = boardOneBefore;	
	}
}
int printBoardBlackWhite()
{
#ifdef _debug
	int i, j;
	for(i=0;i < WIDTH; i++){
		for(j = 0; j < HEIGHT; j++)
	       	{
			//printf("%8d", board[i][j]);
			printw("%4d  ", board[i][j]);
		}
		printw("\n");	
	}
#endif
}

int printBoardWithColor()
{
//	printw("printBOardWithColor\n");
	int i, j;
	for(i=0;i < WIDTH; i++){
		for(j = 0; j < HEIGHT; j++)
	    {
			attron(COLOR_PAIR(log2_B( board[i][j] )+1));
			printw("%4d  ", board[i][j]);
			attroff(COLOR_PAIR(log2_B( board[i][j] )+1));
		}
		printw("\n");	
	}
}

int main()
{

	initscr();
	start_color();
	noecho();
	initGame();
//	system("clear");
	char ch;
	ch=getch();
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
