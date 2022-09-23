#include <stdio.h>

#define SIZE 10

// This is a bad program
int main(void) {
    int numbers[SIZE];
    int i;
    i = 0;
    
    //initialise array
    while(i < SIZE){
        numbers[i] = i;
        i = i + 2;
    }    
    
    //print array
    i = 0;
    while(i < SIZE){
        printf("%d: %d\n",i, numbers[i]);
        i = i + 1;
    }  
       
    return 0;
}
