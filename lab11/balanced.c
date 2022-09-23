#include <stdio.h>

#define MAX_LENGTH 32

void isOpenBracket(char line, int *round, int *square, int *curly);
void isCloseBracket(char line, int *round, int *square, int *curly);
int isBalanced(int round, int square, int curly);
void conclusion(int result);
int main (void) {
    char line[MAX_LENGTH];
    fgets(line, MAX_LENGTH, stdin);
    //printf("%s", line);
    int round = 0;
    int square = 0;
    int curly = 0;
    int i = 0;
    int result;
    while (line[i] != '\0') {
        isOpenBracket(line[i], &round, &square, &curly);
        isCloseBracket(line[i], &round, &square, &curly);
        i++;
    }
    result = isBalanced(round, square, curly);
    conclusion(result);
    return 0;
}

void isOpenBracket(char line, int *round, int *square, int *curly) {
    if (line == '(') {
        *round = *round + 1;
    } else if(line == '[') {
        *square = *square + 1;
    } else if (line == '{') {
        *curly = *curly + 1;
    }
}

void isCloseBracket(char line, int *round, int *square, int *curly) {
    if (line == ')') {
        *round = *round - 1;
    } else if(line == ']') {
        *square = *square - 1;
    } else if (line == '}') {
        *curly = *curly - 1;
    }
}

int isBalanced(int round, int square, int curly) {
    if (round == 0 && square == 0 && curly == 0) {
        return 1;
    } else {
        return 0;
    }
}

void conclusion(int result) {
    if (result == 1) {
        printf("Yes, balanced.\n");
    } else {
        printf("No, not balanced.\n");
    }
}
