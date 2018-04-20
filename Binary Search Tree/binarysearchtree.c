#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct node{
	int count;
	int data;
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
	new_node->data = new_value;
	new_node->count = 1;
	new_node->right = NULL;
	new_node->left = NULL;

	//if there are no nodes in the tree, the new node becomes the first node
	if(!(*head)){
		(*head) = new_node;		
		return;
	}

	struct node *current_node = *head; // for searching

	//if there is at least one node in the tree, searches the tree for the correct location to put the new node in, then puts the node there
	while(current_node->right != new_node && current_node->left != new_node){
		if(new_value < current_node->data){ 
			if(!(move_left(&current_node))){
				current_node->left = new_node;
			}
		}else if(new_value > current_node->data){
			if(!(move_right(&current_node))){
				current_node->right = new_node;
			}
		}else{ //In the case of a duplicate values
			current_node->count++;
			free(new_node);
			return;
		}	
	}
	return;
}

void delete_value(struct node **head, int target_value){
	//search for node with target value
	struct node *current_node = *head;
	struct node *parent_node = NULL;
	//if there are no nodes in the tree
	if(*head == NULL) return;
	while(current_node->data!=target_value){
		parent_node = current_node;	
		if(target_value < current_node->data){ 
			if(move_left(&current_node)==false){
				return;
			}
		}else if(target_value > current_node->data){
			if(move_right(&current_node)==false){
				return;
			}
		}
	}
	if(current_node->count > 1){
		current_node->count--;
		return;
	}
	//if the node to be deleted has no children
	if(current_node->right == NULL && current_node->left == NULL){
		if(parent_node != NULL && parent_node->right == current_node){
			parent_node->right = NULL;
		}else if(parent_node != NULL){
			parent_node->left = NULL;
		}else if(current_node = *head){
			*head = NULL;
		}	
		free(current_node);
		return;
	}
	//if the current node has a right child and no left child
	if(current_node->right != NULL && current_node->left == NULL){
		if(parent_node != NULL && parent_node->right == current_node){
			parent_node->right = current_node->right;
		}else if(parent_node != NULL){
			parent_node->left = current_node->right;
		}else if(current_node == *head){
			*head = current_node->right;
		}
		free(current_node);
		return;
	}
	//if the current child has a left child and no right child
	if(current_node->left != NULL && current_node->right == NULL){
		if(parent_node != NULL && parent_node->right == current_node){
			parent_node->right = current_node->left;
		}else if(parent_node != NULL){
			parent_node->left = current_node->left;
		}else if(current_node == *head){
			*head =current_node->left;
		}

		free(current_node);
		return;
	}
	//if the current node has two child nodes
	if(current_node->left != NULL && current_node != NULL){
		parent_node = current_node;
		struct node *probe = current_node->right;
		//finds the leftmost node.
		while(probe->left != NULL){
			parent_node = probe;
			probe = probe->left;
		}
		current_node->data = probe->data;
		if(probe->right != NULL){
			if(parent_node != NULL && parent_node->right == probe){
				parent_node->right = probe->right;
			}else if(parent_node != NULL){
				parent_node->left = probe->right;
			}
		}else{
			if(parent_node != NULL && parent_node->right == probe){
				parent_node->right = NULL;
			}else if(parent_node != NULL){
				parent_node->left = NULL;
			}		
		}
		free(probe);
		return;
		

	}

}

//print_tree() code provided by https://github.com/matoro
void print_tree(struct node *bst, int indent)
{
    for(int i = 0; i < indent; i++)
    {
                        printf( "\t");
    }
    fprintf(stdout,"%i\n", bst->data);
    if(bst->left)
    {
                print_tree(bst->left, indent + 1);
    }
    if(bst->right)
    {
            print_tree(bst->right, indent + 1);
    }
}

void main(){
	//testing for memory leaks with 1000 random values.
	srand(time(NULL));
	int values[1000];
	struct node *head = NULL;
	for(int i = 0; i < 1000; i++)
	{
	    values[i] = rand() % 100;
	    insert_value(&head, values[i]);
	}
	for(int i = 0; i < 1000; i++)
	{
		delete_value(&head, values[i]);
	}
}
