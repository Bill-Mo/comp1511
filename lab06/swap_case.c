//zID is z5305298
#include <stdio.h>
int caseSwap(int c);
int main (void){
	int c = getchar();
	while (c != EOF) {
		c = caseSwap(c);
		putchar(c);
		c = getchar();
	}
	return 0;
}

int caseSwap(int c) {
	if (c >= 'a' && c <= 'z') {
		c = c - 32;
	} else if (c >= 'A' && c <= 'Z') {
		c = c + 32;
	}
	return c;
}
