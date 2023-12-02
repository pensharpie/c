/***************************************************************************************
This script emmulates a stack which features push, pop and peak.

Date                Author                Revision              Notes
12/01/2023      Herbe Chun       v1                        None
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * nPtr;
};

struct node * push (struct node * p, int data);
void peek(struct node * p);
struct node * pop (struct node * p);
void printTree(struct node * p);

int main(void) {
	struct node * h;
	struct node * t;
	struct node stack;

	h = push(&stack, 1);
	printTree(h);
	t = push(&stack, 2);
	t->nPtr = h;
	h = t;
	printTree(h);
	peek(h);
	t = push(&stack, 5);
	t->nPtr = h;
	h = t;
	printTree(h);
	t = push(&stack, 3);
	t->nPtr = h;
	h = t;
	printTree(h);
	t = push(&stack, 3);
	t->nPtr = h;
	h = t;
	printTree(h);
	t = push(&stack, 4);
	t->nPtr = h;
	h = t;
	printTree(h);
	t = push(&stack, 5);
	t->nPtr = h;
	h = t;
	printTree(h);
	h = pop (h);
	printTree(h);
	h = pop (h);
	printTree(h);
	peek(h);
	h = pop (h);
	printTree(h);
	h = pop (h);
	printTree(h);
	peek(h);
	h = pop (h);
	printTree(h);
	h = pop (h);
	printTree(h);
	h = pop (h);
	printTree(h);
	h = pop (h);
	return 0;
}

struct node * pop (struct node * p) {
	if (p != NULL) {
		p = p->nPtr;
		return p;
	} else {
		printf("Error message\n");
		return p;
	}
}
	
struct node * push (struct node * p, int data) {
	struct node * n = (struct node *) malloc(sizeof(struct node));
	if (n == NULL) {
		printf("Error\n");
	} else
		{
			n->data = data;
			n->nPtr = NULL;
			return (n);
		}
}

void peek(struct node * p) {
	printf("%d\n", p->data);
}

void printTree(struct node * p) {
	printf("s: ");
	while (p != NULL) {
		printf("%d, ", p->data);
		p=p->nPtr;
	}
	if (p == NULL) {
		printf("NULL\n");
	}
}


	