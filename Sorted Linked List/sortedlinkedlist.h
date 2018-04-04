#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *next;
};

void insert_value(struct node **head, int new_value);

void delete_value(struct node **head, int target_value);

void print_list(struct node *head);
