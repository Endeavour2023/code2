#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"geam.h"
void menu()
{
	printf("******************************\n");
	printf("****1������****0�˳���Ϸ******\n");
	printf("******************************\n");
}
//��Ϸʵ��
void geam()
{
	char ret = 0;
	//����-����߳���������Ϣ
	char board[ROW][COL] = { 0 };//ϣ������ȫ���ǿո�-д��������ʼ������
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DispiayBoard(board,ROW,COL);
	//����
	while (1)
	{
		//�������
		piayerMove(board, ROW, COL);
		DispiayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}

		//��������
		ComputerMove(board, ROW, COL);
		DispiayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��������Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
	void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//�����
	do
	{
		menu();
		printf("��ѡ��");
			scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			geam();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}

	} while (input);
}
int main()
{
	test();
	return 0;
}