//zID is z5305298
#include <stdio.h>

int main (void){
	int size = 1;
	int row = 1;
	int col = 1;
	printf("Enter size: ");
	scanf("%d", &size);
	while (row <= (size - 1) / 2) {
		while (col <= (size - 1) / 2) {
			if (col == row) {
				printf("*");
				col = col + 1;
			}
			if (col == size / 2 || col == size) {
			}
			else {
				printf("-");
				col = col + 1;
			}
		}
		printf("*");
		col = col + 1;
		while (col <= size) {
			if (col == size + 1 - row) {
				printf("*");
				col = col + 1;
			}
			if (col == size / 2 || col == size) {
			}
			else {
				printf("-");
				col = col + 1;
			}
		}
		printf("\n");
		row = row + 1;
		col = 1;
	}
	for (int star = 1; star <= size; star = star + 1) {
		printf("*");
	}
	row = row + 1;
	printf("\n");
	while (row <= size) {
		while (col <= (size - 1) / 2) {
			if (col == size + 1 - row) {
				printf("*");
				col = col + 1;
			}
			if (col == size / 2 || col == size) {
			}
			else {
				printf("-");
				col = col + 1;
			}
		}
		printf("*");
		while (col < size) {
			if (col == row) {
				printf("*");
				col = col + 1;
			}
			if (col == size / 2 || col == size) {
			}
			else {
				printf("-");
				col = col + 1;
			}
		}
		row = row + 1;
		col = 1;
		printf("\n");
	}
	return 0;
}
