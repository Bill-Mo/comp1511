#include <stdio.h>
#include <math.h>

int main (void){
double side_1 = 0.0;
double side_2 = 0.0;
double side_3 = 0.0;
printf("Enter side 1: ");
scanf("%lf", &side_1);
printf("Enter side 2: ");
scanf("%lf", &side_2);
printf("Enter side 3: ");
scanf("%lf", &side_3);
if (side_1 + side_2 <= side_3){
	printf("Error: triangle inequality violated.");
}else if (side_2 + side_3 <= side_1){
	printf("Error: triangle inequality violated.");
}else if (side_1 + side_3 <= side_2){
	printf("Error: triangle inequality violated.");
}
else {double s = (side_1 + side_2 + side_3)/2.0;
	double area = sqrt(s * (s - side_1) * (s - side_2) * (s - side_3));
	printf("Area = %lf",area);
}
printf("\n");
return 0;
}
