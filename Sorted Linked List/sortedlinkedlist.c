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
	delete_value(&head2, 5);
	delete_value(&head2, 16);
}

void insert_value(struct node **head, int new_value){
	//allocating memory for new node.
	struct node *new = (struct node*)malloc(sizeof(struct node));
	//set node data to new value. 
	new->data = new_value;
	new->next = NULL;
	if(*head == NULL){ //If there are no nodes in the linked list, adds the new node as the head.
		*head = new;
		return;
	}else if((*head)->next == NULL){ //If there is one node in the list, adds the new node before or after the existing node depending on the nodes' data values.
		if((*head)->data > new_value){
			new->next = *head;
    			*head = new;
			return;
		}else{
			(*head)->next = new;
			return;
		}
	}else{ //If there is more than one node in the list, searches the list for the correct place then inserts new node.
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
	return;
}		

void delete_value(struct node **head, int target_value){
	if(*head == NULL){ //Returns if there are no nodes in the list.
		return;
	}else if((*head)->next == NULL && (*head)->data == target_value){ //Deletes node if there is one node in the list and its data value is the target_value.
		free(*head);
		*head = NULL;
		return;
	}else{
		struct node *current_node = *head;
		if(current_node->data == target_value){ //Deletes current_node if its data value matches the target_value.
			*head = current_node->next;
			free(current_node);
			return;
		}
		while(current_node->next != NULL && current_node->next->data != target_value){ //Looks for the node with the target_value, stops at the ende of the list if the target is not found.
			current_node = current_node->next;
		}
		if(current_node->next == NULL){ //returns if all nodes have been searched and target value was not found.
			return;
		}else{ // delets the next node if its datat value matches the target_value.
			struct node *target_node = current_node->next;
			current_node->next = current_node->next->next;
			free(target_node);
			return;
		}
	}
	return;
}

void print_list(struct node *head){
	while(head != NULL){
		printf("%i\n", head->data);
		head = head->next;
	}
	printf("\n\n");
	return;
}
