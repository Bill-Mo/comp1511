//zID is z5305298
#include <stdio.h>
#define MAX_TIME 10
int main (void){
	int num = 0;
	printf("Input the number (Table to be calculated) : \n");
	scanf("%d", &num);
	for (int time = 1; time <= MAX_TIME; time = time + 1) {
		int result = num * time;
		printf("%d X %d = %d\n", num, time, result);
	}
	return 0;
}
