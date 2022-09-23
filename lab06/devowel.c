#include <stdio.h>
int is_vowel(int character);

int main (void){
	int line = getchar();
	while (line != EOF) {
		if ( is_vowel(line) == 1) {
			putchar(line);
		}
		line = getchar();
	}
	
	return 0;
}

int is_vowel(int character) {
	if (character != 'a' && character != 'e' && character != 'i' && character != 'o' && character != 'u') {
		return 1;
	} else {
		return 0;
	}

}
