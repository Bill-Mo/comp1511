#include <stdio.h>

int main (void){
int diceSide = 0;
int diceNumber = 0;
printf("Enter the number of sides on your dice:");
scanf("%d", &diceSide);
printf(" Enter the number of dice being rolled: ");
scanf("%d", &diceNumber);
if (diceSide <= 0){
	printf("These dice will not produce a range.");
}
else if (diceNumber <= 0){
	printf("These dice will not produce a range.");
}
else{
	int min = diceNumber * 1;
	int max = diceSide * diceNumber;
	double avg = (min + max)/2.0;
	printf("Your dice range is %d to %d.\nThe average value is %lf", min, max, avg);
}
printf("\n");
return 0;
}
