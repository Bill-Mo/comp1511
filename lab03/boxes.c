//zID is z5305298
#include <stdio.h>

int main (void){
	int num, maxCol, maxRow;
	int col = 1;
	int row = 1;
	printf("How many boxes: \n");
	scanf("%d", &num);
	maxCol = 3 + 4 * (num - 1);
	maxRow = 3 + 4 * (num - 1);
	while (row <= maxRow / 2) {
		if (row % 2 != 0) {
			while (col <= maxCol+10) {
				if ((col % 2 ==0 && col < row) || ((maxCol - col) % 2 == 0 && (maxCol - col) < row)) {
				printf(" ");
				col = col + 1;
				} else {
				printf("#");
				col = col + 1;
				}
			}
		col = 1;
		row = row + 1;
		}
		else if (row % 2 == 0) {
			if ((col % 2 != 0 && col < row) || ((maxCol - col) % 2 != 0 && (maxCol - col)) < row) {
				printf("#");
				col = col + 1;
			} else {
				printf(" ");
				col = col + 1;
			}
		col = 1;
		row = row + 1;
		}
	}
	printf("\n");
	return 0;
}
