#include <stdio.h>

#define MAX_LENGTH 20

void tnirp(char s[]);

int main(int argc, char * argv[]){
    char s[MAX_LENGTH];

    printf("Enter String\n");
    // fgets returns NULL if it gets only a ctrl ^d
    if( fgets(s,MAX_LENGTH,stdin) != NULL ){
        tnirp(s);
    }
    return 0;
}

void tnirp(char s[]) {
	int i = 0;
	int count = -1;
	while (i < MAX_LENGTH) {
		if (s[i] == '\n') {
			break;
		} else {
			count ++;
		}
		i ++;
	}
	if (count == 19) {
		count = count - 1;
	}
	while (count >= 0) {
		putchar(s[count]);
		count = count - 1;
	}
	printf("\n");
}
