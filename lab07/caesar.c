//zID is z5305298
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 512
#define ALPHABET 26
int encrypt(int character, int shift);

int main (int argc, char*argv[]) {
    int shift = atoi(argv[1]) % ALPHABET;
    char line[MAX_LENGTH];
    char newLine[MAX_LENGTH];
    int i = 0;
    line[i] = getchar();
    while (line[i] != EOF) {
        newLine[i] = encrypt(line[i], shift);
        printf("%c", newLine[i]);
        i ++;
        line[i] = getchar();
    }
    return 0;
}

int encrypt(int character, int shift) {
    int result = character + shift;
    if (character >= 'a' && character <= 'z') {
        if (result >= 'a' && result <= 'z') {
            return result;
        } else {
            if (shift < 0) {
                return result + ALPHABET;
            } else {
                return result - ALPHABET;
            }
        }
    } else if (character >= 'A' && character <= 'Z') {
        if (result >= 'A' && result <= 'Z') {
            return result;
        } else {
            if (shift < 0) {
                return result + ALPHABET;
            } else {
                return result - ALPHABET;
            }
        }
    } else {
        return character;
    }
}

