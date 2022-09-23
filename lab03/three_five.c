#include <stdio.h>

int main (void){
	int num = 0;
	int printNum = 1;
	printf("Enter number: ");
	scanf("%d", &num);
	while (printNum < num) {
		if (printNum % 3 == 0 || printNum % 5 == 0) {
			printf("%d\n", printNum);
		}
		printNum = printNum + 1;

	}
	return 0;
}
