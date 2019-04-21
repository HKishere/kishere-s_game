#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define max_row 10
#define max_col 10

int row=0, col=0;
char maps[max_row][max_col];
int mines_maps[max_row][max_col];

int menu() {
	int choise;
	while (1) {
		printf("***********\n");
		printf("**1.play***\n");
		printf("**2.exit***\n");
		printf("***********\n");
		scanf("%d", &choise);
		if (choise==1){
			return 1;
		}else if (choise==2){
			return 2;
		}
		else {
			printf("请输入正确的指令!\n");
		}
	}
}
void inti() {
	for (row = 0; row < max_col; ++row) {
		for (col = 0; col < max_col; ++col) {
			maps[row][col] = 'X';
			mines_maps[row][col] = 0;
		}
	}//初始化界面
	srand((unsigned int)time(0));
	for (int num_of_mines = 0; num_of_mines < 10; ++num_of_mines) {
		int col = rand() % 9 + 0;
		int row = rand() % 9 + 0;
		if (mines_maps[row][col] == 0) {
			mines_maps[row][col] = 9;
		}
		else {
			--num_of_mines;
		}
	}
	for (row = 0; row < max_col; ++row) {
				for (col = 0; col < max_col; ++col) {
					if (mines_maps[row][col] > 8){
						if (col == 0) {
							++mines_maps[row - 1][col];
							++mines_maps[row - 1][col + 1];
							++mines_maps[row][col + 1];
							++mines_maps[row + 1][col];
							++mines_maps[row + 1][col + 1];
						}
						else if (col == 9) {
							++mines_maps[row - 1][col - 1];
							++mines_maps[row - 1][col];
							++mines_maps[row][col - 1];
							++mines_maps[row + 1][col - 1];
							++mines_maps[row + 1][col];
						}
						else
						{
							++mines_maps[row - 1][col - 1];
							++mines_maps[row - 1][col];
							++mines_maps[row - 1][col + 1];
							++mines_maps[row][col - 1];
							++mines_maps[row][col + 1];
							++mines_maps[row + 1][col - 1];
							++mines_maps[row + 1][col];
							++mines_maps[row + 1][col + 1];
						}
				}
		}//初始化地雷
	}
}
void printmap() {
	printf(" | 0 1 2 3 4 5 6 7 8 9 |\n");
	printf("_______________________\n");
	for (row = 0; row < max_row; ++row) {
		printf("%d|", row);
		for (col = 0; col < max_col; ++col) {
			printf(" %c", maps[row][col]);
		}
		printf("\n");
	}
}
void dig(int row, int col) {
	if (row < 0 || row>9 || col < 0 || col>9) {
		return 0;
	}
		maps[row][col] = mines_maps[row][col]+'0';
				if (mines_maps[row][col] == 0) {
					if (col > 0 && col < 9){

						if ((mines_maps[row - 1][col - 1] == 0 )&& (maps[row - 1][col - 1] == 'X')) {
							dig(row - 1, col - 1);
						}
						maps[row - 1][col - 1] = mines_maps[row - 1][col - 1] + '0';
						
						if ((mines_maps[row - 1][col] == 0) && (maps[row - 1][col] == 'X')) {
							dig(row - 1, col);
						}maps[row - 1][col] = mines_maps[row - 1][col] + '0';
						
						if ((mines_maps[row - 1][col + 1]==0) && (maps[row - 1][col + 1] == 'X')){
							dig(row - 1, col + 1);
						}maps[row - 1][col + 1] = mines_maps[row - 1][col + 1] + '0';
						
						if ((mines_maps[row][col - 1] == 0) && (maps[row][col - 1] == 'X')){
							dig(row, col - 1);
						}maps[row][col - 1] = mines_maps[row][col - 1] + '0';
						
						if ((mines_maps[row][col + 1]==0) && (maps[row][col - 1] == 'X')){
							dig(row, col + 1);
						}maps[row][col + 1] = mines_maps[row][col + 1] + '0';
						
						if ((mines_maps[row + 1][col - 1]==0) && (maps[row + 1][col - 1] == 'X')){
							dig(row + 1, col - 1);
						}maps[row + 1][col - 1] = mines_maps[row + 1][col - 1] + '0';
						
						if ((mines_maps[row + 1][col] == 0) && (maps[row + 1][col] == 'X')) {
							dig(row + 1, col);
						}maps[row + 1][col] = mines_maps[row + 1][col] + '0';
						
						if ((mines_maps[row + 1][col + 1] == 0) && (maps[row + 1][col + 1] == 'X')) {
							dig(row + 1, col + 1);
						}maps[row + 1][col + 1] = mines_maps[row + 1][col + 1] + '0';
					}
					if (col == 0) {
						
						if (mines_maps[row - 1][col] == 0 && maps[row - 1][col] == 'X') {
							dig(row - 1, col);
						}maps[row - 1][col] = mines_maps[row - 1][col] + '0';
						
						if (mines_maps[row - 1][col + 1]==0 && maps[row - 1][col + 1] == 'X'){
							dig(row - 1, col + 1);
						}maps[row - 1][col + 1] = mines_maps[row - 1][col + 1] + '0';
						
						if (mines_maps[row][col + 1]==0 && maps[row][col - 1] == 'X'){
							dig(row, col + 1);
						}maps[row][col + 1] = mines_maps[row][col + 1] + '0';
						
						if (mines_maps[row + 1][col] == 0 && maps[row - 1][col] == 'X') {
							dig(row + 1, col);
						}maps[row + 1][col] = mines_maps[row + 1][col] + '0';
						
						if (mines_maps[row + 1][col + 1] == 0 && maps[row + 1][col + 1] == 'X') {
							dig(row + 1, col + 1);
						}maps[row + 1][col + 1] = mines_maps[row + 1][col + 1] + '0';
					}
					if (col == 9) {
						
						if (mines_maps[row - 1][col - 1]==0 && maps[row - 1][col - 1] == 'X'){
							dig(row - 1, col - 1);
						}maps[row - 1][col - 1] = mines_maps[row - 1][col - 1] + '0';
						
						if (mines_maps[row - 1][col] == 0 && maps[row - 1][col] == 'X') {
							dig(row - 1, col);
						}maps[row - 1][col] = mines_maps[row - 1][col] + '0';
						
						if (mines_maps[row][col - 1] == 0 && maps[row][col - 1] == 'X') {
							dig(row, col - 1);
						}maps[row][col - 1] = mines_maps[row][col - 1] + '0';
						
						if (mines_maps[row + 1][col - 1]==0 && maps[row + 1][col - 1] == 'X'){
							dig(row + 1, col - 1);
						}maps[row + 1][col - 1] = mines_maps[row + 1][col - 1] + '0';
						
						if (mines_maps[row + 1][col] == 0 && maps[row - 1][col] == 'X') {
							dig(row + 1, col);
						}maps[row + 1][col] = mines_maps[row + 1][col] + '0';
					}
				}
}
int lose_check() {
	if (mines_maps[row][col]>8){
		printf("\n*********\n");
		printf("*你输了!*\n");
		printf("*********\n\n");
		for (row = 0; row < max_row; ++row) {
			for (col = 0; col < max_col; ++col) {
				if (mines_maps[row][col]>8){
					maps[row][col] = '*';
				}
			}
		}
		printmap();
		return 0;//0 means lose
	}
	else {
		return 1;//1means not yet
	}
}
int WinCheck() {
	for (row = 0; row < max_row; ++row) {
		for (col = 0; col < max_col; ++col) {
			if (mines_maps[row][col] < 9 && maps[row][col]=='X') {
				goto jump;
			}
		}
	}
	jump:
	if (row == 10 && col == 10) {
		return 1;
	}
	else
		return 0;
}
int game() {
	inti();
	printmap();
	while (1) {
		printf("输入你想要挖掘的坐标（行，列），用 ','分隔:");
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		scanf("%d,%d", &row, &col);
		if (row >= 0 && row <= 9 || col >= 0 && col <= 9) {
			if (maps[row][col] == 'X') {
				dig(row, col);
			}
			else {
				printf("你已经挖过这里了！\n");
			}
		}
		else {
			printf("坐标非法！\n");
		}
		if (lose_check() == 0) {
			return 0;
		}
		if (WinCheck() == 1) {
			printf("\n********\n");
			printf("*你赢了!*\n");
			printf("********\n\n");
			return 0;
		}
	printmap();
	}
}
int main(){
	menu();
	game();
	system("pause");
	return 0;
}