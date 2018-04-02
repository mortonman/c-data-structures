#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void print_list(struct node *head);

void add_end_list(struct node **head, int new_data);

void add_front_list(struct node **head, int new_data);


void delete_front_list(struct node **head);
