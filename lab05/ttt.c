//zID is z5305298
#include <stdio.h>

#define SIZE 3
#define NOUGHT 0
#define CROSS 1
#define NO_WINNER 2
#define DRAW 4
void readBoard(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE]);
int winner(int board[SIZE][SIZE]);

int main(void) {
	int board[SIZE][SIZE];
	printf("Please enter the board: \n");
	readBoard(board);
	printf("Here is the board:\n\n");
	printBoard(board);
	if (winner(board) == NOUGHT) {
		printf("Noughts win");
	} else if (winner(board) == CROSS) {
		printf("Crosses win");
	} else if (winner(board) == NO_WINNER) {
		printf("There are no winners");
	} else {
		printf("It is a draw");
	}
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
	printf("\n");
}

int winner(int board[SIZE][SIZE]) {
	int i = 0;
	int j = 0;
	int dots = 0;	
	int result = 9;
	while (j <= SIZE - 1) {
		if (board[i][j] == board[i + 1][j]) {
			i ++;
			if (board[i][j] == board[i + 1][j]) {
				if (board[i][j] == 0) {
					result = NOUGHT;
				} else if (board[i][j] == 1) {
					result = CROSS;
				}
			}
		} else {
			i ++;
		}
		j ++;
		i = 0;
	}
	i = 0;
	j = 0;
	while (i <= SIZE - 1) {
		if (board[i][j] == board[i][j + 1]) {
			j ++;
			if (board[i][j] == board[i][j + 1]) {
				if (board[i][j] == 0) {
					result = NOUGHT;
				} else if (board[i][j] == 1) {
					result = CROSS;
				}
			} else {
				j ++;
			}
		}
		i ++;
		j = 0;
	}
	i = 0;
	j = 0;
	if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0])) {
		if (board[1][1] == 0) {
			result = NOUGHT;
		} else if (board[1][1] == 1) {
			result = CROSS;
		}
	}
	i = 0;
	j = 0;
	if (result == NOUGHT || result == CROSS) {
	} else { 
		while (j <= SIZE - 1) {
			i = 0;
			while (i <= SIZE - 1) {
				if (board[i][j] == 2) {
					dots = dots + 1;
					i ++;
				} else {
					i ++;
				}
			}
			j ++;
		}

	}
	if (result == NOUGHT || result == CROSS) {
	} else {
		if (dots == 0) {
			result = DRAW;
		} else {
			result = NO_WINNER;
		}
	}
	return result;
}











