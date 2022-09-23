#include <stdio.h>

int main (void){
int length = 0;
int width = 0;
printf("Please enter the length of the rectangle:");
scanf("%d", &length);
printf("Please enter the width of the rectangle:");
scanf("%d", &width);
int area = length * width;
printf("Area = %d\n", area);
return 0;
}
