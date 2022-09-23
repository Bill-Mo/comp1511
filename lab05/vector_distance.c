//zID is z5305298
#include <stdio.h>
#include <math.h>
double distance (int length,int one[length],int two[length]);
int main (void) {
	int length;
	printf("Enter vector length: ");
	scanf("%d", &length);
	int vector1[length], vector2[length];
	int i = 0;
	printf("Enter vector 1: ");
	while (i <= length - 1) {
		scanf("%d", &vector1[i]);
		i ++;
	}
	i = 0;
	printf("Enter vector 2: ");
	while (i <= length - 1) {
		scanf("%d", &vector2[i]);
		i ++;
	}
	printf("Euclidean distance = %lf\n", distance(length, vector1, vector2));
	return 0;
}
double distance (int length,int one[],int two[]) {
	int i = 0;
	int sum = 0;
	while (i <= length - 1) {
		sum = sum + (one[i] - two[i]) * (one[i] - two[i]);
		i ++;
	}
	double result = sqrt(sum);
	return result;
}
