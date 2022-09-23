//zID is z5305298
#include <stdio.h>

int main (void){
	int size;
	int row = 1;
	int col = 1;
	printf("Enter size: ");
	scanf("%d", &size);
	while (row < size) {
		while (col <= row) {
			if (col == 1 || col == row) {
				printf("*");
				col = col + 1;
			} else {
				printf(" ");
				col = col + 1;
			}
		}
		printf("\n");
		row = row + 1;
		col = 1;
	}
	for (int stars = 1; stars <= size; stars++) {
		printf("*");
	}
	printf("\n");
	return 0;
}
