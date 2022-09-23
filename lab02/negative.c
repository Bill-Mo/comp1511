#include <stdio.h>

int main (void){
int num = 0;
scanf("%d", &num);
if (num < 0){
printf("Don't be so negative!");
}else if(num == 0){
printf("You have entered zero.");
}else if( num > 0){
printf("You have entered a positive number.");
}
printf("\n");
return 0;
}
