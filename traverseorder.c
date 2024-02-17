/*
2/17/2024
Demonstrates pre, post and inorder traversal
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node * left;
	struct node * right;
};

struct node * newNode (int val) {
	struct node * ptr = (struct node *) malloc (sizeof (struct node));
	if (ptr == NULL) {
		printf("Error\n");
	} else {
		ptr -> val = val;
		ptr -> left = NULL;
		ptr -> right = NULL;
	}
	return ptr;
};

/*
in-order - left, root, right
post-order - left, right, root
pre-order - root, left, right
*/

void inorder(struct node * head) {
	if (head == NULL) {
		return;
	} else {
		inorder(head->left);
		printf("%d \n", head -> val);
		inorder(head->right);
	}
};

void preorder(struct node * head) {
	if (head == NULL) {
		return;
	} else {
		printf("%d \n", head -> val);
		inorder(head->left);
		inorder(head->right);
	}
};

void postorder(struct node * head) {
	if (head == NULL) {
		return;
	} else {
		inorder(head->left);
		inorder(head->right);
		printf("%d \n", head -> val);
	}
};
		
int main() {
	struct node * head = newNode(2);
	struct node * n1 = newNode(1);
	struct node * n2 = newNode(2);
	struct node * n3 = newNode(3);
	struct node * n4 = newNode(4);
	head -> left = n1;
	head -> right = n3;
	n1 -> left = n4;
	n1 -> right = NULL;
	n3 -> left = NULL;
	n3 -> right = NULL;
	n4 -> left = NULL;
	n4 -> right = NULL;
	printf("inorder\n");
	inorder(head);
	printf("preorder\n");
	preorder(head);
	printf("postorder\n");
	postorder(head);
	return 0;
}