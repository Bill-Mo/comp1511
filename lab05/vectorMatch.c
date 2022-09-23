//zID is z5305298
#include <stdio.h>
#define MAX 10
int match (int one[], int two[]);
int main (void) {
	int i = 0, vector1[MAX], vector2[MAX];
	printf("Enter vector 1 of %d positive numbers: ", MAX);
	while (i <= MAX - 1) {
		scanf("%d", &vector1[i]);
		i ++;
	}
	i = 0;
	printf("Enter vector 2 of %d positive numbers: ", MAX);
	while (i <= MAX - 1) {
		scanf("%d", &vector2[i]);
		i ++;
	}
	int pos = match(vector1, vector2);
	printf("Vectors match in %d positions.\n", pos);
	return 0;
}

int match (int one[], int two[]) {
	int a = 0;
	int i = 0;
	while (i <= MAX - 1) {
		if (one[i] == two[i]) {
		a ++;	
		}
		i ++;
	}
	return a;
}
