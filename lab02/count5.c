#include <stdio.h>

int main (void){
int integer = 0;
printf("Please enter an integer: ");
scanf("%d", &integer);
if (integer < 1){
	printf("You entered a number less than one.");
}else if (integer > 5){
	printf("You entered a number greater than five.");
}else{
	if (integer == 1){
	printf("You entered one.");
	}else if (integer == 2){
	printf("You entered two.");
	}else if (integer == 3){
	printf("You entered three.");
	}else if (integer == 4){
	printf("You entered four.");
	}else if (integer == 5){
	printf("You entered five.");
	}
}
printf("\n");
return 0;
}
