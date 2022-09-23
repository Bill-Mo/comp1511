#include <stdio.h>
#define ALPHABET_SIZE 26
int getLetterFrequencies(int letterCount[ALPHABET_SIZE]);
int letterIndex(int character);
void printFrequencies(int letterCount[ALPHABET_SIZE], int nLettersRead);

int main (void) {
	int letterCount[ALPHABET_SIZE] = {0};
	int num = getLetterFrequencies(letterCount);
	printFrequencies(letterCount, num);
	return 0;
}

int getLetterFrequencies(int letterCount[ALPHABET_SIZE]) {
    int character = getchar();
    int numLetters = 0;
    while (character != EOF) {
        int index = letterIndex(character);
        if (index != -1) {
            letterCount[index] = letterCount[index] + 1;
            numLetters = numLetters + 1;
        }
        character = getchar();
    }
    return numLetters;
}

int letterIndex(int character) {
	int i;
	if (character >= 'a' && character <='z') {
		i = character - 'a';
	} else if (character >= 'A' && character <='Z') {
		i = character - 'A';
	} else {
		i = -1;
	}
	return i;
}

void printFrequencies(int letterCount[ALPHABET_SIZE], int nLettersRead) {
	float frequency;
	int i = 0;
	while (i <= ALPHABET_SIZE - 1) {
		frequency = 1.0 * letterCount[i] / nLettersRead;
		printf("'%c' %f %d\n", i + 'a', frequency, letterCount[i]);
		i ++;
	}
	
}

