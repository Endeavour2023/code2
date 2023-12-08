#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"geam.h"
void menu()
{
	printf("******************************\n");
	printf("****1三字棋****0退出游戏******\n");
	printf("******************************\n");
}
//游戏实现
void geam()
{
	char ret = 0;
	//数组-存放走出的棋盘信息
	char board[ROW][COL] = { 0 };//希望里面全部是空格-写个函数初始化数组
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DispiayBoard(board,ROW,COL);
	//下棋
	while (1)
	{
		//玩家下棋
		piayerMove(board, ROW, COL);
		DispiayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}

		//电脑下棋
		ComputerMove(board, ROW, COL);
		DispiayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("公主王子赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
	void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//随机数
	do
	{
		menu();
		printf("请选择");
			scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			geam();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误请重新选择\n");
			break;
		}

	} while (input);
}
int main()
{
	test();
	return 0;
}