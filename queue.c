/***************************************************************************************
This script emmulates a queue using arrays.  The functions enqueue, size and
deque are featured.

Date                Author                Revision              Notes
12/03/2023      Herbe Chun       v1                        None
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUESIZE 100
#define ZERO 0

struct queue {
    int * arr;
	int size;
	int h;
	int t;
};

void enqueue (struct queue * h, int data);
void dequeue(struct queue * tPtr);
void printQue(struct queue * tPtr);
void size(struct queue * tPtr);

int main(void) {
	struct queue q;
	q.size = QUESIZE;
	q.h = q.t = ZERO;
	q.arr= (int * ) malloc (q.size * sizeof(int));
	if (q.arr == NULL) {
		printf("Error\n");
	} else {
		enqueue(&q, 1);
		printQue(&q);
		enqueue(&q, 2);
		printQue(&q);
		size(&q);
		enqueue(&q, 5);
		printQue(&q);
		enqueue(&q, 3);
		printQue(&q);
		enqueue(&q, 3);
		printQue(&q);
		enqueue(&q, 4);
		printQue(&q);
		enqueue(&q, 5);
		printQue(&q);
		size(&q);
		//printQue(&q);
		dequeue(&q);
		printQue(&q);
		dequeue(&q);
		printQue(&q);
		size(&q);
		
	}
		return ZERO;
}

void enqueue (struct queue * tPtr, int data) {
	tPtr->arr[tPtr->t] = data;
	tPtr->t++;
}

void size(struct queue * tPtr) {
	printf("s: %d\n", tPtr->t);
}

void printQue(struct queue * tPtr) {
	int qSize = tPtr->t;
	int count = ZERO;
	printf("q: ");
	while (count < qSize) {
		printf("%d, ", tPtr->arr[count]);
		count++;
	}
	printf("NULL\n");
}

void dequeue(struct queue * tPtr) {
	int tArr[QUESIZE];
	for (int i = 0; i < QUESIZE - 1; i++) {
		tArr[i] = tPtr->arr[i+1];
	}
	for (int i = 0; i < QUESIZE - 1; i++) {
		tPtr->arr[i] = tArr[i];
	}
	tPtr->t--;
}