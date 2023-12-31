#define _CRT_SECURE_NO_WARNINGS 1
#include"geam.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DispiayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//打印一行数据
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
			//打印分割行
			if (i < row - 1)
			{
				for (j = 0; j < col; j++)
				{
					printf("---");
					if (j<col-1)
						printf("|");
				}
				printf("\n");
			}
				
		
	}
	/*int i = 0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
		if (i < row - 1)
			printf("---|---|---\n");
	}*/
}

void piayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("公主王子请下棋\n");
	while (1)
	{
       printf("输入坐标(两数字间加上空格)");
       scanf_s("%d%d", &x, &y);
	   //判断xy坐标的合法性
       if (x >= 1 && x <= row && y >= 1 && y <= col)
	   {
		   if (board[x - 1][y - 1] == ' ')
		   {
			   board[x - 1][y - 1] = '*';
			   break;
		   }
		   else
		   {
			   printf("该坐标被占用\n");
		   }
	   }
	   else
	   {
		printf("坐标非法,请公主王子重新输入\n"); 
	   }
	}
	
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走\n");
	while(1)
	{
           x = rand() % ROW;//%上row因为row=3,随机数只会是0,1,2
	       y = rand() % COL;

		   if (board[x][y] == ' ')
		   {
			   board[x][y] = '#';
			   break;
		  }
	}
	
	
}



//返回1表示棋盘满了,返回0表示没满
int IsFuil(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i == 0; i < row; i++)
	{
		for (j == 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
                return 0;
			}
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断横三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//判断竖三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//一个对角线判断
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	return board[0][0];
	//另一个对角线判断
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	return board[0][2];
	//判断是否平局
	if (1 == IsFuil(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}

