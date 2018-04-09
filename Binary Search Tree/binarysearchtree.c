#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
	int value;
	struct node *right;
	struct node *left;
};

//checks if the right node of the current node is NULL, if not, makes current node said right node
bool move_right(struct node **current_node){
	if((*current_node)->right != NULL){
		(*current_node) = (*current_node)->right;
		return true;
	}
	return false;
}

//checks if the left node of the current node is NULL, if not, makes current node said left node
bool move_left(struct node **current_node){
	if((*current_node)->left != NULL){
		(*current_node) = (*current_node)->left;
		return true;
	}
	return false;
}

              
void insert_value(struct node **head, int new_value){
	//declare new node and allocate memory
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->value = new_value;
	new_node->right, new_node->left = NULL;

	//if there are no nodes in the tree, the new node becomes the first node
	if(!(*head)){
		(*head) = new_node;		
		return;
	}

	struct node *current_node = *head; // for searching

	//if there is at least one node in the tree, searches the tree for the correct location to put the new node in, then puts the node there
	while(current_node->right != new_node && current_node->left != new_node){
		if(new_value < current_node->value){ 
			if(move_left(&current_node) == false){
				current_node->left = new_node;
			}
		}else if(new_value > current_node->value){
			if(move_right(&current_node) == false){
				current_node->right = new_node;
			}
		}else{ //In the case of a duplicate value
			printf("Unable to find a location for the new value.");
			return;
		}	
	}
	return;
}

void main(){
	struct node *tree = NULL;
	insert_value(&tree, 16);
	insert_value(&tree, 4);
	insert_value(&tree, 20);
	insert_value(&tree, 17);
}

