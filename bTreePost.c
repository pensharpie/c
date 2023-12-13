/***************************************************************************************
This script is a BTree.  Duplicates can be ignored, placed on the left
branch or placed on the right branch.  In this case, duplicates were 
placed on the left branch.

There are various display methods including preorder, inorder and postorder.  
In this script, postorder is featured using recursion.

Date                Author                Revision              Notes
12/12/2023      Herbe Chun       v1                        None
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define N 25

int reg;

struct node {
	int key;
	struct node * l;
	struct node * r;
};

struct node * newNode (int key);
void add (struct node ** head, int key);
void postorder (struct node * head);
	
int main(void) {
	struct node *h;
	int num, key[N];
	
/***************************************************************************************
Enter data stream
*/
	printf("Test case\n");
	printf("Enter number of keys: ");
	scanf("%d", &num);
	for (int a = 0; a < num; a++) {
		printf("Enter key %d: \n", a + 1);
		scanf("\n%d", &key[a]);
	}
	printf("\nKeys\n");
	for (int b = 0; b < num; b++) {
		printf("add(tree, %d); \n", key[b]);
	}
	printf("\n");
	struct node * head = NULL;
	for (int c = 0; c < num; c++) {
		add (&head, key[c]);
	}
	printf("Postorder keys\n");
	printf("Postorder (tree): ");
	postorder (head);
	printf("NULL\n");
} //End main

struct node * newNode (int key) {
	struct node * nPtr = (struct node *) malloc (sizeof(struct node));
	nPtr -> key = key;
	nPtr -> l = NULL;
	nPtr -> r = NULL;
	return (nPtr);
} //End newNode

void add (struct node ** head, int key) {
	if (*head == NULL) {
		*head = newNode(key);
	} else {
		if (key <= (*head) -> key) {
			add (&((*head) -> l), key);
			} else if (key > (*head) -> key) {
				add (&((*head) -> r), key);
			}
		}
} //End add

void postorder (struct node * head) {

	if (head != NULL) {
		postorder(head -> l);
		postorder(head -> r);
		printf("%d, ", head -> key);
	}
	//printf("\n");
} //End postorder
	