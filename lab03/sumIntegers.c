//zID is 5305298//
#include <stdio.h>

int main (void){
	int value = 1;
	int sum = 1;
	printf(" k  sum\n");
	printf("\n");
	while (value <= 20) {
		if (value <= 3) {
			printf(" %d    %d\n", value, sum);
		} else if (value <= 9) {
			printf(" %d   %d\n", value, sum);
		} else if (value <= 13) {
			printf("%d   %d\n", value, sum);
		} else {
			printf("%d  %d\n", value, sum);
		}
		value = value + 1;
		sum = sum + value;
	}
	return 0;
}
