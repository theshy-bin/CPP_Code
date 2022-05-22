#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu() {
	printf("===========================\n");
	printf("====1.������ 0.�˳���Ϸ====\n");
	printf("===========================\n");

}
void game()
{
	//��ʼ������
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board,ROW,COL);
	//����
	while (1) 
	{
		PlayMove(board,ROW,COL);
		//�ж���Ӯ
		ret = Iswin(board,ROW,COL);
		if (ret != 'C') {
			break;
		}
		DisplayBoard(board, ROW, COL);
	
		ComputerMove(board, ROW, COL);
		//�ж���Ӯ
		ret = Iswin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		DisplayBoard(board, ROW, COL);
	
	}
		if (ret == '#') {
			printf("���Ӯ��\n");
		}
		else if (ret == '*') {
			printf("����Ӯ��\n");
		}
		else {
			printf("ƽ��\n");
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
			printf("�˳�����Ϸ\n");
			break;
		default:
			printf("��������ȷѡ��\n");
			break;

		}
	} while (input);
}