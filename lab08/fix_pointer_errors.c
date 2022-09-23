// A simple C program to help understand pointers
// Written 30/06/2019
// by Aarthi Natarajan


#include <stdio.h>
int main(void) {
    int i = 22;
    char *s;
    char foo[] = "Hello World";

    s = foo;
    printf("s is %s, address of i is %p, address of s is %p\n",s, &i, *s);
    s[0] = foo[0];
    printf("s[3] is %c, s+2 is %s, *(s+2) is %c\n",s[3], s+2, *(s+2));
    
    return 0;
}
