#include<stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    char *name;
    int id;
};

struct node *create_node(char *name, int id);
void print_list(struct node *head);
void insert_tail(struct node *head, struct node *n);
void insert_head(struct node *head, struct node *n);
void insert_middle(struct node *head, struct node *n, int id);
char *search(struct node *head, int id);
void delete_tail(struct node *head);
void delete_head(struct node *head);
void delete_middle(struct node *head, int id);

int main(void) {
    struct node *new = create_node("Jack", 1);
    print_list(new);
    return 0;
}

struct node *create_node(char *name, int id) {
    struct node *n = malloc(sizeof(struct node));
    n->name = name;
    n->id = id;
    return n;
}

void print_list(struct node *head) {
    struct node *n = head;
    while (n != NULL) {
        printf("name: %s, id: %d\n", n->name, n->id);
        n = n->next;
    }
}

void insert_tail(struct node *head, struct node *n) {
    
}
void insert_head(struct node *head, struct node *n);
void insert_middle(struct node *head, struct node *n, int id);
char *search(struct node *head, int id);
void delete_tail(struct node *head);
void delete_head(struct node *head);
void delete_middle(struct node *head, int id);