//zID is z5305298
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4
struct piece {
    char colour;
    char symbol;
};

typedef struct piece Piece;


//Returns 1 if p1 and p2 have the same colour and symbol
//Returns 0 otherwise
int areEqual(Piece p1,Piece p2);

// Prints out a piece in the following format
// colour/symbol eg. R/*
void printPiece(Piece p);

// Reads in a piece from stdin and checks it is valid
// If a valid piece was read in, it returns 1
// Returns 0 otherwise
void readPiece(Piece * p);

void printBoard(Piece p, int i);

void areSame(Piece a, Piece b, int *count);

int main (void) {
    Piece *board;
    board = malloc(16 * sizeof(Piece));
    printf("Enter pieces: ");
    int i = 0;
    while (i < SIZE * SIZE ) {
        readPiece(&board[i]);
        i ++;
    }
    i = 0;
    while (i < SIZE * SIZE) {
        printBoard(board[i], i);
        i ++;
    }
    int score = 0;
    int count = 0;
    int row = 0;
    int col = 0;
    while (row < SIZE * SIZE) {
        col = 0;
        while (col < SIZE - 1) {
            areSame(board[col + row], board[col + row + 1], &count);
            col ++;
        }
        if (count == 3) {
            score ++;
        }
        count = 0;
        row = row + SIZE;
    }
    row = 0;
    col = 0;
    count = 0;
    while (col < SIZE) {
        row = 0;
        while (row < SIZE * SIZE - SIZE) {
            areSame(board[col + row], board[col + row + SIZE], &count);
            row = row + SIZE;
        }
        if (count == 3) {
            score ++;
        }
        count = 0;
        col ++;
    }
    printf("Score is %d\n", score);
    return 0;
}

int areEqual(Piece p1,Piece p2) {
    if (p1.colour == p2.colour && p1.symbol == p2.symbol) {
        return 1;
    } else {
        return 0;
    }
}

void printPiece(Piece p) {
    printf("%c/%c", p.colour, p.symbol);
}

void readPiece(Piece * p) {
    p->colour = getchar();
    p->symbol = getchar();
    getchar();
}

void printBoard(Piece p, int i) {
    printPiece(p);
    printf(" ");
    if (i % SIZE == 3) {
        printf("\n");
    }
}

void areSame(Piece a, Piece b, int *count) {
    if (a.colour == b.colour && a.symbol == b.symbol) {
        *count = *count + 1;
    }
}
