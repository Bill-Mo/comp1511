#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_LEN 50

struct node {
    struct node *next;
    int          data;
};

void print(struct node *head);
struct node *strings_to_list(int len, int num_array[]);

int main(void) {
    // create linked list from input
    int input_arr[MAX_LEN] = {0};
    int total_num = 0;
    int input_num;
    while (scanf(" %d", &input_num) == 1) {
        input_arr[total_num] = input_num;
        total_num++;
    }
    struct node *head = strings_to_list(total_num, input_arr);

    print(head);

    return 0;
}

// Solution \/
////////////////////////////////////////////////////////////////////////////////
//  print a linked list in this format:
// 17 -> 34 -> 51 -> 68 -> X
void print(struct node *head) {
    struct node *n = head;
    while (n != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("X\n");
}
////////////////////////////////////////////////////////////////////////////////

// create linked list from array of strings
struct node *strings_to_list(int len, int num_array[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = num_array[i];
        head = n;
    }
    return head;
}