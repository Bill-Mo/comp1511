//zID is z5305298
#include <stdio.h>

int main (void){
	int num;
	int factor = 2;
	int position = 1;
	printf("Enter number: ");
	scanf("%d", &num);
	int prime = num;
	while (factor < prime) {
		if (num % factor == 0) {
			position = position + 1;
			num = num / factor;
		} else {
			factor ++;
		}
	}
	num = prime;
	factor = 2;
	if (position != 1) {
		position = 1;
		printf("The prime factorization of %d is:\n", num);
		while (factor < prime) {
			if (num % factor == 0) {
				if (position == 1) {
					printf("%d", factor);
					position = position + 1;
				} else {
					printf(" * %d", factor);
					position = position + 1;
				}
				num = num / factor;
			} else {
				factor ++;
			}
		}
		printf(" = %d\n", prime);
	} else {
		printf("%d is prime\n", prime);
	}
	return 0;
}
