#define ROW 3
#define COL 3
#include<stdlib.h>//�����ͷ�ļ�
#include<time.h>//time����ͷ�ļ�
//����
void InitBoard(char board[ROW][COL], int row, int col);
void DispiayBoard(char board[ROW][COL], int row, int col);
void piayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);


//��������������Ϸ״̬
//���Ӯ *
//����Ӯ #
//ƽ��   Q
//����   C

char IsWin(char board[ROW][COL], int row, int col);