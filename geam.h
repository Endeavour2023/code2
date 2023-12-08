#define ROW 3
#define COL 3
#include<stdlib.h>//随机数头文件
#include<time.h>//time函数头文件
//声明
void InitBoard(char board[ROW][COL], int row, int col);
void DispiayBoard(char board[ROW][COL], int row, int col);
void piayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);


//告诉我们四种游戏状态
//玩家赢 *
//电脑赢 #
//平局   Q
//继续   C

char IsWin(char board[ROW][COL], int row, int col);