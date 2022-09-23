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
    int j = 1;
    int letterPosition = 0;
    line[i] = getchar();
    while(line[i] != EOF) {
        j = 0;
        if (line[i] >= 'a' && line[i] <= 'z') {
            while (j <= ALPHABET) {
                if (line[i] == mapping[j]) {
                    letterPosition = j;
                }
                j ++;
            }
            newLine[i] = 'a' + letterPosition;
        } else if (line[i] >= 'A' && line[i] <= 'Z') {
            line[i] = line[i] + 'a' - 'A';
            while (j <= ALPHABET) {
                if (line[i] == mapping[j]) {
                    letterPosition = j;
                }
                j ++;
            }
            newLine[i] ='A' + letterPosition;
        } else {
            newLine[i] = line[i];
        }
        printf("%c", newLine[i]);
        i ++;
        line[i] = getchar();
    }
    return 0;
}
