#include "sortedlinkedlist.h"

void main(){
	//linked list 1: empty
	struct node *head = NULL;
	//linked list 2: 1 node
	struct node *head1 = NULL;
	insert_value(&head1, 5);
	//linked list 3: multiple nodes
	struct node *head2 = NULL;
	insert_value(&head2, 16);
	insert_value(&head2, 1);
	insert_value(&head2, 5);
	insert_value(&head2, 5);
	//print lists
	printf("List 1, empty:\n");
	print_list(head);
	printf("List 2, 1 node:\n");
	print_list(head1);
	printf("List 3, 4 nodes(two 5s):\n");
	print_list(head2);
	//delete 5s from lists
	delete_value(&head, 5);
	delete_value(&head1, 5);
	delete_value(&head2, 5);
	printf("DELETING ONE 5 FROM ALL LISTS\n\n");
	//print modified lists
	printf("List 1:\n");
	print_list(head);
	printf("List 2:\n");
	print_list(head1);
	printf("List 3:\n");
	print_list(head2);	
	delete_value(&head2, 1);
	delete_value(&head2, 16);
	delete_value(&head, 5);
}

void insert_value(struct node **head, int new_value){
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = new_value;
	new->next = NULL;
	if(*head == NULL){
		*head = new;
		return;
	}else if((*head)->next == NULL){
		if((*head)->data > new_value){
			new->next = *head;
    			*head = new;
			return;
		}else{
			(*head)->next = new;
			return;
		}
	}else{
		struct node *current_node = *head;
		while(current_node->next != NULL){
			if(current_node->next->data >= new_value){
				break;
			}
			current_node = current_node->next;
		}
		if(current_node->next == NULL){
			current_node->next = new;
			return;
		}else{
			new->next = current_node->next;
			current_node->next = new;
			return;
		}
	}
}		

void delete_value(struct node **head, int target_value){
	if(*head == NULL){
		return;
	}else if((*head)->next == NULL && (*head)->data == target_value){
		free(*head);
		*head = NULL;
		return;
	}else{
		struct node *current_node = *head;
		while(current_node->next != NULL && current_node->next->data != target_value){
			current_node = current_node->next;
		}
		if(current_node->next == NULL){
			return;
		}else{
			struct node *target_node = current_node->next;
			current_node->next = current_node->next->next;
			free(target_node);
			return;
		}
	}
}

void print_list(struct node *head){
	while(head != NULL){
		printf("%i\n", head->data);
		head = head->next;
	}
	printf("\n\n");
	return;
}
