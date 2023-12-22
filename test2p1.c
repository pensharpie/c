

/********************************************************************************************
Description:  Test 2, Problem 1 - addNew() is a caching linked list strategy
that reads characters from a file and inserts them to the front of a list.  To 
demonstrate the concept, characters are added as addNew("a") also.
instead.

Herbe Chun
12/21/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

struct node {
	char data;
	struct node * p;
};

void addNew(struct node ** head, char data);
void prtList(struct node * head);
void readFile(struct node ** head, char fileName[]);

int main() {
	struct node * linkedList = NULL;
	char fileName1[] = "file1.txt";
	char fileName2[] = "file2.txt";
	char fileName3[] = "file3.txt";
	char fileName4[] = "file4.txt";
	char fileName5[] = "file5.txt";
	char fileName6[] = "file6.txt";
	
/*
	printf("Example 1 - a b c d c b\n");
	addNew(&linkedList, 'a');
	prtList(linkedList);
	addNew(&linkedList, 'b');
	prtList(linkedList);
	addNew(&linkedList, 'c');
	prtList(linkedList);
	addNew(&linkedList, 'd');
	prtList(linkedList);
	addNew(&linkedList, 'c');
	prtList(linkedList);
	addNew(&linkedList, 'b');
	prtList(linkedList);

	printf("Example 2 - a b c c c d c b \n");
	addNew(&linkedList, 'a');
	prtList(linkedList);
	addNew(&linkedList, 'b');
	prtList(linkedList);
	addNew(&linkedList, 'c');
	prtList(linkedList);
	addNew(&linkedList, 'c');
	prtList(linkedList);
	addNew(&linkedList, 'c');
	prtList(linkedList);
	addNew(&linkedList, 'd');
	prtList(linkedList);
	addNew(&linkedList, 'c');
	prtList(linkedList);
	addNew(&linkedList, 'b');
	prtList(linkedList);
*/

	printf("Example 3 - read from file1.txt \n");
	readFile(&linkedList, fileName1);
	prtList(linkedList);

	printf("\nExample 4 - read from file2.txt\n");
	readFile(&linkedList, fileName2);
	prtList(linkedList);

	printf("\nExample 5 - read from file3.txt\n");
	readFile(&linkedList, fileName3);
	prtList(linkedList);

	printf("\nExample 6 - read from file4.txt\n");
	readFile(&linkedList, fileName4);
	prtList(linkedList);

	printf("\nExample 7 - read from file5.txt\n");
	readFile(&linkedList, fileName5);
	prtList(linkedList);

	printf("\nExample 8 - read from file6.txt\n");
	readFile(&linkedList, fileName6);
	prtList(linkedList);

	return 0;
}

void addNew(struct node ** head, char data) {
	struct node * tf = *head;
	struct node * tr = NULL;

	struct node * ptr = (struct node *) malloc (sizeof(struct node));
	
	while ((tf != NULL) && (tf -> data != data)) {
		tr = tf;
		tf = tr -> p;
	}
	
	if (tf != NULL) {
		if (tr == NULL) {
			*head = tf -> p;
			} else {
				tr -> p = tf -> p;
				} 
		}
	ptr -> data = data;
	ptr -> p = *head;
	*head = ptr;
}

void prtList(struct node * head) {
	if (head == NULL) {
		printf("NULL\n");
	} else {
		while (head != NULL) {
			printf("%c ", head -> data);
			head = head -> p;
		}
	}
	printf("\n");
}

void readFile(struct node ** head, char fileName[]) {	
	char name[N];
	int numTestCases;
		
    FILE * p = fopen(fileName, "r");
    if (p == NULL) {
        printf("Error\n");
    } else {
		printf("Nodes\n");
		fscanf(p, "%d", &numTestCases);
		printf("Number of nodes: %d\n", numTestCases);
		char arr[numTestCases];
		for (int i = 0; i < numTestCases; i++) {
			arr[i] = 'a';
		}
		if (fgets(arr, numTestCases, p) == NULL) {
			printf("Error\n");
		}
		printf("Nodes: ");
		for (int i = 0; i < numTestCases; i++) {
			fscanf(p, "%c", &arr[i]);
			printf("%c", arr[i]);
			addNew(head, arr[i]);
		}
		printf("\n");
		fclose(p);
	}
}


	


	