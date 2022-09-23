//zID is z5305298
#include <stdio.h>

#define SIZE 3

void readBoard(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE]);

int main(void) {
	int board[SIZE][SIZE];
	printf("Please enter the board: \n");
	readBoard(board);
	printf("Here is the board:\n\n");
	printBoard(board);
	printf("\n");
	return 0;
}
void readBoard(int board[SIZE][SIZE]) {
	int i = 0;
	int j = 0;
	while (j <= SIZE - 1) {
		while (i <= SIZE - 1) {
			scanf("%d", &board[i][j]);
			i ++;
		}
		i = 0;
		j ++;
	}
}

void printBoard(int board[SIZE][SIZE]) {
	int i = 0;
	int j = 0;
	while (j <= SIZE - 1) {
		while (i <= SIZE - 1) {
			if (board[i][j] == 0) {
				printf("O ");
				i ++;
			} else if (board[i][j] == 1) {
				printf("X ");
				i ++;
			} else {
				printf(". ");
				i ++;
			}
		}
		i = 0;
		printf("\n");
		j ++;
	}
}
