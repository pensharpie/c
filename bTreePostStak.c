/***************************************************************************************
This script is a BTree.  Duplicates can be ignored, placed on the left
branch or placed on the right branch.  In this case, duplicates are 
placed on the left branch.

There are various display methods including preorder, inorder and postorder.  
In this script, postorder is featured using a stack

Date                Author                Revision              Notes
12/12/2023      Herbe Chun       v1                        None
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define N 250

struct node {
	int key;
	struct node * l;
	struct node * r;
};

void add (struct node ** head, int key);
struct node * newNode (int key);
void postorder (struct node * head);  //Utilizes recurrsion - for test purposes
void postorderArr (struct node * head);  //Utilizes a stack
	
int main() {
	struct node * head = NULL;
	int num, key[N];

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
	for (int c = 0; c < num; c++) {
		add (&head, key[c]);
	}
	printf("Postorder keys\n");
	printf("Postorder (recurssion-for comparison): ");
	postorder (head);
	printf("NULL\n");

	printf("Postorder (stack): ");
	postorderArr(head);
	printf("NULL\n");
	printf("\n");
	return 0;
} //End main

struct node * newNode (int key) {
	struct node * p = (struct node *) malloc (sizeof(struct node));
	if (p == NULL) {
		printf("Error\n");
	}
	p -> key = key;
	p -> l = NULL;
	p -> r = NULL;
	return (p);
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
	if (head == NULL) {
		return;
	}
	if (head != NULL) {
		postorder(head -> l);
		postorder(head -> r);
		printf("%d, ", head-> key);
	}
} //End postorder 

void postorderArr (struct node * head) {
	int index = -1;
	struct node * tf = head;
	
	if (head == NULL) {
		return;
	} else {
		struct node * stack[N];
		do {
			while (tf) {
				if (tf -> r) {
					stack[++index] = tf -> r;
				}
				stack[++index] = tf;
				tf = tf -> l;
			}
			tf = stack[index--];
			if ((tf -> r) && (stack[index] == tf -> r)) {
				stack[ index--] = NULL;
				stack[++index] =  tf;
				tf = tf -> r;
			} else {
				printf("%d, ", tf -> key);
				tf = NULL;
			}
		} while (index >= 0);
	}
} //End postorderArr
