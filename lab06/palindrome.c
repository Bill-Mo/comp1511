#include<stdio.h>
#define MAX_SIZE 4096
int isPalindrome(int size, char c[size]);
int main (void) {
	int i = 0;
	char c[MAX_SIZE];
	printf("Enter a string: ");
	while (fgets(c, MAX_SIZE, stdin) != NULL) {
		while (c[i] != '\n' && c[i] != '\0') {
			i = i + 1;
 	    }
	}
	int size = i;
	if (isPalindrome(size, c) == 1) {
		printf("String is a palindrome\n");
	} else {
		printf("String is not a palindrome\n");
	}
	return 0;
}

int isPalindrome(int size, char c[size]) {
	int i = 0;
	int count = 0;
	if (size % 2 == 0) {
		while (i < size / 2) {
			if (c[i] == c[size - i]) {
				count ++;
			}
			i ++;
		}	
		if (count == i) {
			return 1;
		}
	} else {
		while (i <= (size - 1) / 2) {
			if (c[i] == c[size - (i + 1)]) {
				count ++;
			}
			i ++;
		}
		if (count == i) {
			return 1;
		}
	}
	return 0;
}
