//zID is z5305298
#include <stdio.h>
#include <string.h>
#define ALPHABET 26
#define MAX_LENGTH 512
int main (int argc, char*argv[]) {
    char mapping[ALPHABET + 1];
    strcpy(mapping, argv[1]);
    char line[MAX_LENGTH], newLine[MAX_LENGTH];
    int i = 0;
    int letterPosition;
    line[i] = getchar();
    while(line[i] != EOF) {
        if (line[i] >= 'a' && line[i] <= 'z') {
            letterPosition = line[i] - 'a';
            newLine[i] = mapping[letterPosition];
        } else if (line[i] >= 'A' && line[i] <= 'Z') {
            letterPosition = line[i] - 'A';
            newLine[i] = mapping[letterPosition] - 'a' + 'A';
        } else {
            newLine[i] = line[i];
        }
        printf("%c", newLine[i]);
        i ++;
        line[i] = getchar();
    }
    return 0;
}
