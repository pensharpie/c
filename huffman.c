/***************************************************************************************
* This script compresses data utilizing Huffman's algorithrm
* For encoding purposes, a tree is used
* The tree is initially formed from two lowest freq items
* A node is then added with its freq as the leafs sum
* As the tree expands, higher freq items are placed on the right and lower
freq items on the left
* Once the tree is completed, the data steam is encoded as left branch-logic 0 
and right-logic 1
* Example Data
* Item 1 - A 1
* Item 2 - B 2
* Item 3 - D 3
* Item 4 - C 5

Date                Author                Revision              Notes
11/08/2023      Herbe Chun       v1                        None
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define FALSE 0
#define TRUE 1
#define N 25

struct node {
	char value;
	int freq;
	struct node * left;
	struct node * right;
};

typedef struct node leaf;

int preorder ( struct node * Ptr);
void veriList(int totalNum, char letter[N], int freq[N]);
		
int main(void) {
	int a = 0, num = 0, totalNum = 0, sum = 0, temp2 = 0, freq[10];
	char temp1 = 0, letter[10];
	bool even = FALSE;
	
	struct node **leafPtr = malloc(N * sizeof(struct node));
	struct node *headPtr;
	
/***************************************************************************************
Enter data stream
*/
	printf("Enter number of items: ");
	scanf("%d", &num);
	for (int a = 0; a < num; a++) {
		printf("Add data[%d]: \n", a);
		scanf("\n%c", &letter[a]);
		printf("Add freq[%d]: \n", a);
		scanf("\n%d", &freq[a]);
	}
	
/***************************************************************************************
Sorted data in decending order
*/
	totalNum = num;
	for (int b = 0; b < num; ++b) {
		for (int d = b + 1; d < num; ++d) {
			if (freq[b] > freq[d]) {
				temp1 = letter[b];
				temp2 = freq[b];
				letter[b] = letter[d];
				freq[b] = freq[d];
				letter[d] = temp1;
				freq[d] = temp2;
			}
		}
	}
	
/***************************************************************************************
Build tree
*/
	printf("\nTree\n");
	if (num <= 3) {
		num++;
		} else if (num > 3) {
		num += 2;
	}
	for (int d = 0; d <= num; d++) {
		leafPtr[d] = malloc(sizeof(struct node));
		if (d % 2 == 0) {
			even = TRUE; 
		} else {
			even = FALSE;
		}
		
/***************************************************************************************
Initial leafs
*/
		if (d < 2) {
			leafPtr[d]->value = letter[d];
			leafPtr[d]->freq = freq[d];
			leafPtr[d]->left = leafPtr[d]->right=NULL;
			printf("leaf [%d] - %d %c\n", d, leafPtr[d]->freq, leafPtr[d]->value);
		}
		
/***************************************************************************************
Add additional leaf
*/
		if ((d >= 2) && (!even)) {
			a++;
			leafPtr[d]->value = letter[d-a];
			leafPtr[d]->freq = freq[d-a];
			leafPtr[d]->left = leafPtr[d]->right=NULL;
			printf("leaf [%d] - %d %c\n", d, leafPtr[d]->freq, leafPtr[d]->value);
		}
		
/***************************************************************************************
Add additional node
*/
		if ((d >= 2) && (d <= 4) && (even)) {
			headPtr = leafPtr[d];
			leafPtr[d]->value = '\0';
			leafPtr[d]->freq = leafPtr[d-1]->freq  + leafPtr[d-2]->freq;
			printf("node [%d] - %d\n", d, leafPtr[d]->freq);
			if (leafPtr[d-1] <= leafPtr[d-2]) {
				leafPtr[d]->left = leafPtr[d-1];
				leafPtr[d]->right= leafPtr[d-2];
			} else {
				leafPtr[d]->right = leafPtr[d-1];
				leafPtr[d]->left= leafPtr[d-2];
			}
		} else if ((d >= 6) && (even)) {
			headPtr = leafPtr[d];
			leafPtr[d]->value = '\0';
			leafPtr[d]->freq = leafPtr[d-1]->freq  + leafPtr[d-2]->freq;
			printf("node [%d] - %d\n", d, leafPtr[d]->freq);
			if (leafPtr[d-1] <= leafPtr[d-2]) {
				leafPtr[d]->right = leafPtr[d-1];
				leafPtr[d]->left= leafPtr[d-2];
			} else {
				leafPtr[d]->left = leafPtr[d-1];
				leafPtr[d]->right= leafPtr[d-2];
			}
		}
		headPtr = leafPtr[d];
	}
	
	printf("\nTree traversal - (preorder)\n");
	if (preorder(headPtr) == 0) {
		return 0;
	}
}

/***************************************************************************************
Tree traversal
 ->>preorder - root, left, right<<-
 -inorder - left, root, right
 -postorder - left, right, root
*/
int preorder (struct node * Ptr) {
	if (Ptr == NULL)
		return 0;
	if (Ptr->value != '\0') {
		printf("Leaf freq: %d letter: %c\n", Ptr->freq, Ptr->value);
	} else if (Ptr->value == '\0') {
		printf("Node freq: %d\n", Ptr->freq);
	}
	printf("-left -> logic 0\n");
	preorder (Ptr->left);
	printf("-right -> logic 1\n");
	preorder (Ptr->right);
	
}
		
/***************************************************************************************
View encoded data 
*/
void veriList(int totalNum, char letter[N], int freq[N]) {
	printf("\nSorted Huffman Encoded data");
	printf("\nNum\tLetter\tFreq\tCode\n");
	for (int e = 0; e < totalNum; e++) {
		printf("%d\t%c\t%d\n", e, letter[e], freq[e]);
	}	
}
