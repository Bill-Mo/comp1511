//zID is z5305298
#include <stdio.h>

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
int readPiece(Piece * p);

int main (void) {
    Piece p1, p2;
    printf("Enter 2 pieces: ");
    if (readPiece(&p1) == 1 && readPiece(&p2) == 1) {
        if (areEqual(p1, p2) == 1) {
            printPiece(p1);
            printf(" equals ");
            printPiece(p2);
            printf("\n");
        } else {
            printPiece(p1);
            printf(" does not equal ");
            printPiece(p2);
            printf("\n");
        }
    } else {
        fprintf(stderr, "Invalid Input\n");
    }
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

int readPiece(Piece * p) {
    p->colour = getchar();
    p->symbol = getchar();
    getchar();
    if ( (p->colour == 'R' || p->colour == 'B' || p->colour == 'Y' || p->colour == 'G') && (p->symbol == '*' || p->symbol == '^' || p->symbol == '#' || p->symbol == '$')) {
        return 1;
    } else {
        return 0;
    }
}
