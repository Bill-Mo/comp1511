#include <stdio.h>
#define MAX_LINE_LENGTH 4096
int main (void){
	char line[MAX_LINE_LENGTH];
	int i = 0;
	int j = 0;
	printf("Enter a string: ");
	while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
		while (line[i] != '\n' && line[i] != '\0') {
			i = i + 1;
 	       }

 	        i = i - 1;
		while (j <= i) {
			printf("%c\n", line[j]);
			j ++;
		}
	}
	return 0;
}
