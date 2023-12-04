/***************************************************************************************
This script emulates a queue using two stacks.

Date                Author                Revision              Notes
12/04/2023      Herbe Chun       v1                        None
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUESIZE 100
#define ZERO 0
#define ONE 1

struct queue1 {
    int * arr;
	int size;
	int h;
	int t;
};

struct queue2 {
    int * arr;
	int size;
	int h;
	int t;
};

void enqueue(struct queue1 * h, int data);

int dequeue(struct queue1 * tPtr1, struct queue2 * tPtr2, int empty2);
void dequeue1(struct queue1 * tPtr1);
void dequeue2(struct queue2 * tPtr2);

void printQue1(struct queue1 * tPtr1);
void printQue2(struct queue2 * tPtr2);

void size(struct queue1 * tPtr1, struct queue2 * tPtr2);
void size1(struct queue1 * tPtr1);
void size2(struct queue2 * tPtr2);

int is_empty2(struct queue2 * tPtr2);

int main(void) {
	int empty2;
	struct queue1 q1;
	struct queue2 q2;
	q1.size = QUESIZE;
	q2.size = QUESIZE;
	q1.h = q1.t = ZERO;
	q2.h = q2.t = ZERO;
	q1.arr=(int *) malloc (q1.size * sizeof(int));
	q2.arr= (int * ) malloc (q2.size * sizeof(int));
	printf("key - queue: q, size: s\n\n");
	
	if ((q1.arr == NULL) || (q2.arr == NULL)){
		printf("Error\n");
	} else {
		enqueue(&q1, 1);
		printQue1(&q1);
		enqueue(&q1, 2);
		printQue1(&q1);
		size1(&q1);
		size2(&q2);
		size(&q1, &q2);
		enqueue(&q1, 5);
		printQue1(&q1);
		enqueue(&q1, 3);
		printQue1(&q1);
		enqueue(&q1, 3);
		printQue1(&q1);
		enqueue(&q1, 4);
		printQue1(&q1);
		enqueue(&q1, 5);
		printQue1(&q1);
		size1(&q1);
		size2(&q2);
		size(&q1, &q2);
		printf("--dequeue 1--\n");
		printf("s2 returned: %d\n", dequeue(&q1, &q2, is_empty2(&q2)));
		//dequeue(&q1, &q2, is_empty2(&q2));
		size1(&q1);
		size2(&q2);
		size(&q1, &q2);
		printQue1(&q1);
		printQue2(&q2);
		printf("--dequeue 2--\n");
		printf("s2 returned: %d\n", dequeue(&q1, &q2, is_empty2(&q2)));
		//dequeue(&q1, &q2, is_empty2(&q2));
		size1(&q1);
		size2(&q2);
		size(&q1, &q2);
		printQue1(&q1);
		printQue2(&q2);
		if ((is_empty2(&q2)) == 0) {
			printf("is s2 empty: TRUE\n");
		} else {
				printf("is s2 empty:  FALSE\n");
			}
		size1(&q1);
		size2(&q2);
		size(&q1, &q2);
	}
		return ZERO;
}

/***************************************************************************************
Function pushes data on stack 1
*/
void enqueue (struct queue1 * tPtr1, int data) {
	tPtr1->arr[tPtr1->t] = data;
	tPtr1->t++;
}

/***************************************************************************************
Returns the sum of stack 1 size and stack 2 size
*/
void size(struct queue1 * tPtr1, struct queue2 * tPtr2) {
	printf(", s1 + s2: %d\n", tPtr1->t + tPtr2->t);
}

/***************************************************************************************
Returns stack1 size - for debug purposes
*/
void size1(struct queue1 * tPtr1) {
	printf("s1: %d", tPtr1->t);
}

/***************************************************************************************
Returns stack2 size - for debug purposes
*/
void size2(struct queue2 * tPtr2) {
	printf(", s2: %d", tPtr2->t);
}

/***************************************************************************************
Returns queue 1 stack - for debug purposes
*/
void printQue1(struct queue1 * tPtr1) {
	int qSize = tPtr1->t;
	int count = ZERO;
	printf("q1: ");
	while (count < qSize) {
		printf("%d, ", tPtr1->arr[qSize-1]);
		qSize--;
	}
	printf("NULL\n");
}

/***************************************************************************************
Returns queue 2 stack - for debug purposes
*/
void printQue2(struct queue2 * tPtr2) {
	int qSize = tPtr2->t;
	int count = ZERO;
	printf("q2: ");
	while (count < qSize) {
		printf("%d, ", tPtr2->arr[qSize-1]);
		qSize--;
	}
	printf("NULL\n");
}

/***************************************************************************************
If stack 2 is empty and while stack 1 isnt empty, value from stack 1 is pushed to
stack 2 and the value at the top of the stack is returned
*/
int dequeue(struct queue1 * tPtr1, struct queue2 * tPtr2, int empty2) {
	int topS2;
	if (empty2 == ZERO) {
		while (tPtr1->t > ZERO) {
			tPtr2->arr[tPtr2->t] = tPtr1->arr[tPtr1->t - 1]; 
			tPtr1->t--;
			tPtr2->t++;
		}
	}
	topS2 = tPtr2->arr[tPtr2->t - 1];
	tPtr2->t--;
	return (topS2);
}

/***************************************************************************************
Dequeue for stack 1 only - for debug purposes
*/
void dequeue1(struct queue1 * tPtr1) {
	int tArr[QUESIZE];
	for (int i = ZERO; i < QUESIZE - 1; i++) {
		tArr[i] = tPtr1->arr[i+1];
	}
	for (int i = ZERO; i < QUESIZE - 1; i++) {
		tPtr1->arr[i] = tArr[i];
	}
	tPtr1->t--;
}

/***************************************************************************************
Dequeue for stack 2 only - for debug purposes
*/
void dequeue2(struct queue2 * tPtr2) {
	int tArr[QUESIZE];
	for (int i = ZERO; i < QUESIZE - 1; i++) {
		tArr[i] = tPtr2->arr[i+1];
	}
	for (int i = ZERO; i < QUESIZE - 1; i++) {
		tPtr2->arr[i] = tArr[i];
	}
	tPtr2->t--;
}

/***************************************************************************************
Returns true (1) if stack 2 is empty
*/
int is_empty2(struct queue2 * tPtr2) {
	if (tPtr2->t == ZERO) {
		return ZERO;
	}
		else {
			return ONE;
		}
}
