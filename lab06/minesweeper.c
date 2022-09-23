// Assignment 1 20T1 COMP1511: Minesweeper
// minesweeper.c
//
// This program was written by Tianwei MO (z5305298)
// on 18th June, 2020
//
// Version 1.0.0 (2020-03-08): Assignment released.
// Version 1.0.1 (2020-03-08): Fix punctuation in comment.
// Version 1.0.2 (2020-03-08): Fix second line of header comment to say minesweeper.c

#include <stdio.h>
#include <stdlib.h>

// Possible square states.
#define VISIBLE_SAFE    0
#define HIDDEN_SAFE     1
#define HIDDEN_MINE     2
#define VISIBLE_MINE    3

// The size of the starting grid.
#define SIZE 8
#define MAX_MINE 64

// The possible command codes.
#define DETECT_ROW              1
#define DETECT_COL              2
#define DETECT_SQUARE           3
#define REVEAL_SQUARE           4
#define GAMEPLAY_MODE           5
#define DEBUG_MODE              6
#define REVEAL_RADIAL           7

// Add any extra #defines here.
#define LEFT -1
#define RIGHT 1
#define UP -1
#define DOWN 1
#define MID 0

void initialise_field(int minefield[SIZE][SIZE]);
void print_debug_minefield(int minefield[SIZE][SIZE]);
void print_gameplay_minefield(int minefield[SIZE][SIZE]);
int isSurroundingMines(int row, int col, int minefield[SIZE][SIZE]);
void revealSquare(int row, int col, int minefield[SIZE][SIZE]);
// Place your function prototyes here.

int main(void) {
	int i = 0;
	int j = 0;
	int num;
    int minefield[SIZE][SIZE];
    initialise_field(minefield);
    printf("Welcome to minesweeper!\n");
    printf("How many mines? ");
	scanf("%d", &num);
	int mines[MAX_MINE][2];
    // TODO: Scan in the number of pairs of mines.

    printf("Enter pairs:\n");
	while (i <= num - 1) {
		scanf("%d %d", &mines[i][0], &mines[i][1]);
		i ++;
	}
	i = 0;
	while (i <= num - 1) {
		if (mines[i][0] >= 0 && mines[i][0] <= SIZE - 1 && mines[i][1] >= 0 && mines[i][1] <= SIZE - 1) {
			minefield[mines[i][0]][mines[i][1]] = HIDDEN_MINE;
		}
		i ++;
	}
    // TODO: Scan in the pairs of mines and place them on the grid.

    printf("Game Started\n");
    print_debug_minefield(minefield);
	int option;
	i = 0;
	int helpTimes = 1;
	int times = 1;
	int mode = 0;
	int isFirstTime = 0;
	int isWon = 1;
	int isLost = 0;
	while (isWon != 0 || isLost == 0) {
		scanf("%d", &option);
		if (option == DETECT_ROW || option == DETECT_COL || option == DETECT_SQUARE) {
			if (helpTimes <= 3) {
				if (option == DETECT_ROW || option == DETECT_COL) {
					helpTimes ++;
					int testMines;
					int count = 0;
					i = 0;
					scanf("%d", &testMines);
					if (option == DETECT_ROW) {
						while (i <= SIZE - 1) {
							if (minefield[testMines][i] == HIDDEN_MINE) {
								count ++;
							}
							i ++;
						}
						printf("There are %d mine(s) in row %d\n", count, testMines);
					} else if (option == DETECT_COL) {
						i = 0;
						while (i <= SIZE - 1) {
							if (minefield[i][testMines] == HIDDEN_MINE) {
								count ++;
							}
							i ++;
						}
						printf("There are %d mine(s) in column %d\n", count, testMines);
					}
				} else if (option == DETECT_SQUARE) {
					helpTimes ++;
					int row, col, size, edge;
					int count = 0;
					scanf("%d %d %d", &row, &col, &size);
					edge = (size - 1) / 2;
					j = 0;
					while (j < size) {
						i = 0;
						while (i < size) {
							if (minefield[row - edge + j][col - edge + i] == HIDDEN_MINE) {
								count ++;
								i ++;
							} else {
								i ++;
							}
						}
						j ++;
					}
					printf("There are %d mine(s) in the square centered at row %d, column %d of size %d\n", count, row, col, size);
				} 
			} else {
				int noUse[3];
				if (option == DETECT_ROW || option == DETECT_COL) {
					scanf("%d", &noUse[0]);
				} else if (option == DETECT_SQUARE) {
					scanf("%d %d %d", &noUse[0], &noUse[1], &noUse[2]);
				}

				printf("Help already used\n");
			}
		} else {
			if (option == REVEAL_SQUARE) {
				isFirstTime ++;
				int row, col;
				scanf("%d %d", &row, &col);
				if (minefield[row][col] == HIDDEN_MINE) {
					if (isFirstTime == 1) {
						int theRow[SIZE];
						while (minefield[row][col] == HIDDEN_MINE) {
							i = 1;
							j = 0;
							int loopTime = 0;
							while (j <= SIZE - 1) {
								theRow[j] = minefield[row][j];	
								j ++;
							}
							while (loopTime <= SIZE - 1) {
								if (row - i == -1) {
									j = 0;
									while (j <= SIZE - 1) {
										minefield[0][j] = minefield[SIZE - 1][j];
										j ++;
									}
								} else {
									if (row - i < 0) {
										i = i - 8;
									}
									j = 0;
									while (j <= SIZE - 1) {
										minefield[row - i + 1][j] = minefield[row - i][j];
										j ++;
									}
								}
								i ++;
								loopTime ++;
							}
							j = 0;
							while (j <= SIZE - 1) {
								minefield[row + 1][j] = theRow[j];
								j ++;
							}
						}
						minefield[row][col] = VISIBLE_SAFE;
					} else {
						printf("Game over\n");
						i = 0;
						j = 0;
						while (i <= SIZE - 1) {
							j = 0;
							while (j <= SIZE - 1) {
								if (minefield[i][j] == HIDDEN_MINE) {
									minefield[i][j] = VISIBLE_MINE;
								}
								j ++;
							}
							i ++;
						}
					}
				} else {
					if (isSurroundingMines(row, col, minefield) == 0) {
						revealSquare(row, col, minefield);
					} else {
						minefield[row][col] = VISIBLE_SAFE;
					}
				}
			} else if (option == GAMEPLAY_MODE) {
				printf("Gameplay mode activated\n");
			} else if (option == DEBUG_MODE) {
				printf("Debug mode activated\n");
			} else if (option == REVEAL_RADIAL) {
				isFirstTime ++;
				int row, col, rowStart, colStart, rowEnd, colEnd;
				scanf("%d %d", &row, &col);
				if (minefield[row][col] == HIDDEN_MINE) {
					if (isFirstTime == 1) {
						int theRow[SIZE];
						while (minefield[row][col] == HIDDEN_MINE) {
							i = 1;
							j = 0;
							int loopTime = 0;
							while (j <= SIZE - 1) {
								theRow[j] = minefield[row][j];
								j ++;
							}
							while (loopTime <= SIZE - 1) {
								if (row - i == -1) {
									j = 0;
									while (j <= SIZE - 1) {
										minefield[0][j] = minefield[SIZE - 1][j];
										j ++;
									}
								} else {
									if (row - i < 0) {
										i = i - 8;
									}
									j = 0;
									while (j <= SIZE - 1) {
										minefield[row - i + 1][j] = minefield[row - i][j];
										j ++;
									}
								}
								i ++;
								loopTime ++;
							}
							j = 0;
							while (j <= SIZE - 1) {
								minefield[row + 1][j] = theRow[j];
								j ++;
							}
						}
						minefield[row][col] = VISIBLE_SAFE;
					} else {
						printf("Game over\n");
						i = 0;
						while (i <= SIZE - 1) {
							j = 0;
							while (j <= SIZE - 1) {
								if (minefield[i][j] == HIDDEN_MINE) {
									minefield[i][j] = VISIBLE_MINE;
								}
								j ++;
							}
							i ++;
						}
					}
				} else {
					if (isSurroundingMines(row, col, minefield) == 0) {
						if (row == 0 && col == 0) {
							rowStart = MID;
							rowEnd = DOWN;
							colStart = MID;
							colEnd = RIGHT;
						} else if (row == 0 && col == SIZE - 1) {
							rowStart = LEFT;
							rowEnd = MID;
							colStart = MID;
							colEnd = DOWN;
						} else if (row == SIZE - 1 && col == 0) {
							rowStart = UP;
							rowEnd = MID;
							colStart = MID;
							colEnd = RIGHT;
						} else if (row == SIZE - 1 && col == SIZE - 1) {
							rowStart = UP;
							rowEnd = MID;
							colStart = LEFT;
							colEnd = MID;
						} else if (row == 0) {
							rowStart = MID;
							rowEnd = DOWN;
							colStart = LEFT;
							colEnd = RIGHT;
						} else if (col == 0) {
							rowStart = UP;
							rowEnd = DOWN;
							colStart = MID;
							colEnd = RIGHT;
						} else if (row == SIZE - 1) {
							rowStart = UP;
							rowEnd = MID;
							colStart = LEFT;
							colEnd = RIGHT;
						} else if (col == SIZE - 1) {
							rowStart = UP;
							rowEnd = DOWN;
							colStart = LEFT;
							colEnd = MID;
						} else {
							rowStart = UP;
							rowEnd = DOWN;
							colStart = LEFT;
							colEnd = RIGHT;
						}
						i = rowStart;
						while (i <= rowEnd) {
							j = colStart;
							while (j <= colEnd) {
								times = 1;
								minefield[row + times * i][col + times * j] = VISIBLE_SAFE;
								int radialRow = row + times * i;
								int radialCol = col + times * j;
								while ((radialRow != 0) && (radialRow != SIZE - 1) && (radialCol != 0) && (radialCol != SIZE - 1) && isSurroundingMines(radialRow, radialCol, minefield) == 0) {
									if (i == MID && j == MID) {
										j ++;
									}
									times ++;
									radialRow = row + times * i;
									radialCol = col + times * j;
									minefield[radialRow][radialCol] = VISIBLE_SAFE;
								}
								j ++;
							}
							i ++;
						}
					} else {
						minefield[row][col] = VISIBLE_SAFE;
					}
				}
			}
		}
		if (option == GAMEPLAY_MODE || option == DEBUG_MODE) {
			mode = option;
		}
		if (mode == GAMEPLAY_MODE) {
			i = 0;
			j = 0;
			int count = 0;
			while (i <= SIZE - 1) {
				j = 0;
				while (j <= SIZE - 1) {
					if (minefield[i][j] == 3) {
						count ++;
					}
					j ++;
				}
				i ++;
			}
			if (count == 0) {
				printf("..\n\\/\n");
			} else {
				printf("xx\n/\\\n");
				isLost ++;
			}
			print_gameplay_minefield(minefield);
		} else {
			print_debug_minefield(minefield);
		}
		isWon = 0;
		i = 0;
		while (i <= SIZE - 1) {
			j = 0;
			while (j <= SIZE - 1) {
				if (minefield[i][j] == HIDDEN_SAFE) {
					isWon ++;
				}
				j ++;
			}
			i ++;
		}
	}
    // TODO: Scan in commands to play the game until the game ends.
    // A game ends when the player wins, loses, or enters EOF (Ctrl+D).
    // You should display the minefield after each command has been processed.

    return 0;
}

// Set the entire minefield to HIDDEN_SAFE.
void initialise_field(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            minefield[i][j] = HIDDEN_SAFE;
            j++;
        }
        i++;
    }
}

// Print out the actual values of the minefield.
void print_debug_minefield(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", minefield[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

void print_gameplay_minefield(int minefield[SIZE][SIZE]) {
	printf("    00 01 02 03 04 05 06 07\n   -------------------------\n");
	int i = 0;
    while (i < SIZE) {
        int j = 0;
		printf("0%d |", i);
        while (j < SIZE) {
            if (minefield[i][j] == HIDDEN_SAFE || minefield[i][j] == HIDDEN_MINE) {
				if (j == SIZE - 1) {
					printf("##");
				} else {
					printf("## ");
				}
			} else if (minefield[i][j] == VISIBLE_SAFE) {
				if (isSurroundingMines(i, j, minefield) == 0) {
					if (j == SIZE - 1) {
						printf("  ");
					} else {
						printf("   ");
					}
				} else {
					if (j == SIZE - 1) {
						printf("0%d", isSurroundingMines(i, j, minefield));
					} else {
						printf("0%d ", isSurroundingMines(i, j, minefield));
					}
				}
			} else if (minefield[i][j] == VISIBLE_MINE) {
				if (j == SIZE - 1) {
					printf("()");
				} else {
					printf("() ");
				}
			}
            j++;
        }
        printf("|\n");
        i++;
    }
	printf("   -------------------------\n");
}
int isSurroundingMines(int row, int col, int minefield[SIZE][SIZE]) {
	int i, j, rowStart, colStart, rowEnd, colEnd;
	int count = 0;
	if (row == 0 && col == 0) {
		rowStart = MID;
		rowEnd = DOWN;
		colStart = MID;
		colEnd = RIGHT;
	} else if (row == 0 && col == SIZE - 1) {
		rowStart = MID;
		rowEnd = DOWN;
		colStart = LEFT;
		colEnd = MID;
	} else if (row == SIZE - 1 && col == 0) {
		rowStart = UP;
		rowEnd = MID;
		colStart = MID;
		colEnd = RIGHT;
	} else if (row == SIZE - 1 && col == SIZE - 1) {
		rowStart = UP;
		rowEnd = MID;
		colStart = LEFT;
		colEnd = MID;
	} else if (row == 0) {
		rowStart = MID;
		rowEnd = DOWN;
		colStart = LEFT;
		colEnd = RIGHT;
	} else if (col == 0) {
		rowStart = UP;
		rowEnd = DOWN;
		colStart = MID;
		colEnd = RIGHT;
	} else if (row == SIZE - 1) {
		rowStart = UP;
		rowEnd = MID;
		colStart = LEFT;
		colEnd = RIGHT;
	} else if (col == SIZE - 1) {
		rowStart = UP;
		rowEnd = DOWN;
		colStart = LEFT;
		colEnd = MID;
	} else {
		rowStart = UP;
		rowEnd = DOWN;
		colStart = LEFT;
		colEnd = RIGHT;
	}
	i = rowStart;
	while (i <= rowEnd) {
		j = colStart;
		while (j <= colEnd) {
			if (minefield[row + i][col + j] == HIDDEN_MINE) {
				count ++;
			}
			j ++;
		}
		i ++;
	}
	return count;
}

void revealSquare(int row, int col, int minefield[SIZE][SIZE]) {
	int i, j, rowStart, colStart, rowEnd, colEnd;
	if (row == 0 && col == 0) {
		rowStart = MID;
		rowEnd = DOWN;
		colStart = MID;
		colEnd = RIGHT;
	} else if (row == 0 && col == SIZE - 1) {
		rowStart = LEFT;
		rowEnd = MID;
		colStart = MID;
		colEnd = DOWN;
	} else if (row == SIZE - 1 && col == 0) {
		rowStart = UP;
		rowEnd = MID;
		colStart = MID;
		colEnd = RIGHT;
	} else if (row == SIZE - 1 && col == SIZE - 1) {
		rowStart = UP;
		rowEnd = MID;
		colStart = LEFT;
		colEnd = MID;
	} else if (row == 0) {
		rowStart = MID;
		rowEnd = DOWN;
		colStart = LEFT;
		colEnd = RIGHT;
	} else if (col == 0) {
		rowStart = UP;
		rowEnd = DOWN;
		colStart = MID;
		colEnd = RIGHT;
	} else if (row == SIZE - 1) {
		rowStart = UP;
		rowEnd = MID;
		colStart = LEFT;
		colEnd = RIGHT;
	} else if (col == SIZE - 1) {
		rowStart = UP;
		rowEnd = DOWN;
		colStart = LEFT;
		colEnd = MID;
	} else {
		rowStart = UP;
		rowEnd = DOWN;
		colStart = LEFT;
		colEnd = RIGHT;
	}
	i = rowStart;
	while (i <= rowEnd) {
		j = colStart;
		while (j <= colEnd) {
			minefield[row + i][col + j] = VISIBLE_SAFE;
			j ++;
		}
		i ++;
	}
}
