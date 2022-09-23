//zID = z5305298
#include <stdio.h>

int main (void){
	int num = 0;
	int factor = 1;
	int sum = 0;
	printf("Enter number: ");
	scanf("%d", &num);
	printf("The factors of %d are:\n", num);
	while (factor <= num) {
		if (num % factor == 0) {
			printf("%d\n", factor);
			sum = sum + factor;
		}
		factor = factor + 1;
	}	
	printf("Sum of factors = %d\n", sum);
	if (sum - num == num) {
		printf("%d is a perfect number\n", num);
	} else {
		printf("%d is not a perfect number\n", num);
	}

	return 0;
}
