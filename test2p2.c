

/********************************************************************************************
Description:  Test 2, Problem 2
This script implements a BTree implemented with a key, value pair.  Keys greater 
than or equal to the keys stored in the left sub-tree and keys less than keys stored \
in the right.

Herbe Chun
12/21/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 20

struct node {
	long long int key;
	struct node *l;
	struct node *r;
	char name[N];
};

void put (struct node ** head, long long int key, char name[N]);
struct node * newNode (long long int key, char name[N]);
void get (struct node * head); 
void order (struct node * head);

int main() {
	struct node * head = NULL;
	int num;
	long long int key;
	double total = 0;
	char space[N] = " ";
	char lname[N];
	char fname[N];
	
	char fileName1[] = "case1.txt";
	char fileName2[] = "case2.txt";
	char fileName3[] = "case3.txt";
	char fileName4[] = "case4.txt";
	char fileName5[] = "case5.txt";

/*
	printf("Example 1 - read from case1.txt \n");
	FILE * p = fopen(fileName1, "r");
	
	printf("Example 2 - read from case2.txt \n");
	FILE * p = fopen(fileName2, "r");
	
	printf("Example 3 - read from case3.txt \n");
	FILE * p = fopen(fileName3, "r");
	
	printf("Example 4 - read from case4.txt \n");
	FILE * p = fopen(fileName4, "r");
*/	
	printf("Example 5 - read from case5.txt \n");
	FILE * p = fopen(fileName5, "r");
	
    if (p == NULL) {
        printf("Error\n");
    } else {
		printf("Nodes\n");
		fscanf(p, "%d", &num);
		struct node **pt = malloc (num * sizeof(struct node));
		printf("Number of nodes: %d\n", num);
		
		if (pt == NULL) {
			printf("Error\n");
		} else {
			for (int i = 0; i < num; ++i) {
				fscanf(p, "%lld %s %s", &key, fname, lname);
				strcat(fname, space);
				strcat(fname, lname);
				printf("put(tree, %lld, %s); ", key, fname);
				clock_t begin = clock();
				put(&head, key, fname);
				clock_t end = clock();
				double t = (double) (end - begin);
				printf("Run time: %f; \n", t);
				total = total + t;
			}
			printf("Total run time: %f\n", total);
			printf("\nPost order tree\n");
			clock_t begin1 = clock();
			get (head);
			clock_t end1 = clock();
			double t1 = (double) (end1 - begin1);
			printf("Total run time: %f \n", t1);
		}
		printf("\nOrdered tree\n");
		clock_t begin2 = clock();
		order(head);
		clock_t end2 = clock();
		double t2 = (double) (end2 - begin2);
		printf("Total run time: %f \n", t2);
	}
	return 0;
}

/* 
Key's greater than or equal to are stored in the left and keys less 
than are stored on the right
*/
void put (struct node ** head, long long int key, char name[N]) {
	if (*head == NULL) {
		*head = newNode(key, name);
	} else {
		if (key >= (*head) -> key) {
			put (&((*head) -> l), key, name);
			} else if (key < (*head) -> key) {
				put (&((*head) -> r), key, name);
			}
		}
}

struct node * newNode (long long int key, char name[N]) {
	struct node * p = (struct node *) malloc (sizeof(struct node));
	if (p == NULL) {
		printf("Error\n");
	}
	p -> key = key;
	strcat(p -> name, name);
	p -> l = NULL;
	p -> r = NULL;
	return (p);
}

void get (struct node * head) {
	if (head == NULL) {
		return;
	}
	if (head != NULL) {
		get(head -> l);
		get(head -> r);
		printf("%lld, %s\n", head -> key, head -> name);
	}
} 

void order (struct node * head) {
	if (head != NULL) {
		order(head -> l);
		printf("%lld, %s\n", head -> key, head -> name);
		order(head -> r);
	}
}
