#include "linkedlist.h"

void main(){
	struct node *head = (struct node*)malloc(sizeof(struct node));
	struct node *head1 = NULL;
	struct node *head2 = (struct node*)malloc(sizeof(struct node));
	head->data = 12;
	head->next = NULL;
	add_end_list(&head, 4);
	add_end_list(&head, 45);
	add_end_list(&head, 13);
	head2->data = 44;
	head2->next = NULL;
	printf("List with multiple nodes:\n");
	print_list(head);
	delete_front_list(&head);
	print_list(head);
	printf("Empty list: \n");
	print_list(head1);
	delete_front_list(&head1);
	print_list(head1);
	printf("List with 1 node: \n");
	print_list(head2);
	delete_front_list(&head2);
	print_list(head2);
	delete_front_list(&head);
	delete_front_list(&head);
	delete_front_list(&head);
	free(head);
	free(head2);
}

void print_list(struct node *head){
	while(head != NULL){
		printf("%i\n", head->data);
		head = head->next;
	}
	printf("\n\n");
	return;

}

void add_end_list(struct node **head, int new_data)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = new_data;
    new->next = NULL;
    if(!head)
    {
       *head = new;
       return;
    }
    struct node *ptr = *head;
    while(ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    return;
}

void add_front_list(struct node **head, int new_data)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = new_data;
    new->next = *head;
    *head = new;
    return;
}

void delete_end_list(struct node **head)
{
    if(!(*head))
    {
        return;
    }
    if(!(*head)->next)
    {
        free(*head);
        *head = NULL;
	return;
    }
    struct node *ptr = *head;
    while(ptr->next->next)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    return;
}


void delete_front_list(struct node **head){
	if(!(*head)){
		return;
	}
	if(!(*head)->next){
		free(*head);
		*head = NULL;
		return;
	}
	struct node *nextnode = (*head)->next;
	free(*head);
	*head = nextnode;
	
	return;
}
