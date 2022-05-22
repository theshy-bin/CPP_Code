#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu() {
	printf("===========================\n");
	printf("====1.三子棋 0.退出游戏====\n");
	printf("===========================\n");

}
void game()
{
	//初始化棋盘
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board,ROW,COL);
	//下棋
	while (1) 
	{
		PlayMove(board,ROW,COL);
		//判断输赢
		ret = Iswin(board,ROW,COL);
		if (ret != 'C') {
			break;
		}
		DisplayBoard(board, ROW, COL);
	
		ComputerMove(board, ROW, COL);
		//判断输赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		DisplayBoard(board, ROW, COL);
	
	}
		if (ret == '#') {
			printf("玩家赢了\n");
		}
		else if (ret == '*') {
			printf("电脑赢了\n");
		}
		else {
			printf("平局\n");
		}
		DisplayBoard(board, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出了游戏\n");
			break;
		default:
			printf("请输入正确选项\n");
			break;

		}
	} while (input);
}