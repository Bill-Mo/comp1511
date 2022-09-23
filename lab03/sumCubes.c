//zID = z5305298
#include <stdio.h>

int main (void){
	int num = 1;
	int sum = 0;
	printf(" k  cubes\n\n");
	while (num <= 20) {
		sum = sum + num;
		int cube = sum * sum;
		if (num <= 2) {
			printf(" %d      %d\n", num, cube);
		} else if (num <= 3) {
			printf(" %d     %d\n", num, cube);
		} else if (num <= 7) {
			printf(" %d    %d\n", num, cube);
		} else if (num <= 9) {
			printf(" %d   %d\n", num, cube);
		} else if (num <= 13) {
			printf("%d   %d\n", num, cube);
		} else {
			printf("%d  %d\n", num, cube);
		}
		num = num + 1;
	}
	return 0;
}
