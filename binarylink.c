 /***************************************************************************************
This script contains methods to compute the intersection and union of two 
ordered list.  

Date                Author                Revision              Notes
12/11/2023      Herbe Chun       v1                        None
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

struct node1 {
	int data;
	struct node1 * nPtr1;
	struct node1 * rPtr1;
};

struct node2 {
	int data;
	struct node2 * nPtr2;
	struct node2 * rPtr2;
};

struct node3 {
	int data;
	struct node3 * nPtr3;
	struct node3 * rPtr3;
};

struct node4 {
	int data;
	struct node4 * nPtr4;
	struct node4 * rPtr4;
};

struct node1 * push1 (struct node1 * p, int data);
struct node2 * push2 (struct node2 * p, int data);
struct node3 * push3 (struct node3 * p, int data);
struct node4 * push4 (struct node4 * p, int data);

struct node3 * listIntersection (struct node1 * p1, struct node2 * p2, struct node3 * p3);
struct node4 * listUnion (struct node1 * p1, struct node2 * p2, struct node4 * p4);

void printTree1(struct node1 * p);
void printTree2(struct node2 * p);
void printTree3(struct node3 * p);
void printTree4(struct node4 * p);

int main (void) {
	struct node1 * h1 = NULL;
	struct node1 * tl1;
	struct node1 * tr1;
	struct node1 stack1;
	
	struct node2 * h2 = NULL;
	struct node2 * tl2;
	struct node2 * tr2;
	struct node2 stack2;
	
	struct node3 * h3 = NULL;
	struct node3 * tl3;
	struct node3 * tr3;
	struct node3 stack3;
	
	struct node4 * h4 = NULL;
	struct node4 * tl4;
	struct node4 * tr4;
	struct node4 stack4;
	
/***************************************************************************************
 Test case 1
 */
 /*
	printf("case 1\n");
	h1 = push1(&stack1, 8);
	//printTree1(h1);

	tl1 = push1(&stack1, 4);
	tl1->nPtr1 = h1;
	tr1 = h1;
	h1->rPtr1 = tl1;
	h1 = tl1;
	tr1 = h1;
	//printTree1(h1);
	
	h1 = push1(&stack1, 3);
	h1->nPtr1 = tr1;
	tr1->rPtr1 = h1;
	tr1 = h1;
	//printTree1(h1);
	
	h1 = push1(&stack1, 1);
	h1->nPtr1 = tr1;
	tr1->rPtr1 = h1;
	tr1 = h1;
	printTree1(h1);

	h2 = push2(&stack2, 5);
	//printTree2(h2);

	tl2 = push2(&stack2, 2);
	tl2->nPtr2 = h2;
	tr2 = h2;
	h2->rPtr2 = tl2;
	h2 = tl2;
	tr2 = h2;
	printTree2(h2);

	if ((h1 != NULL) && (h2 != NULL)) {
		h3 = listIntersection (h1, h2, &stack3);
	}	
	if ((h3 != NULL) && ((h1 != NULL) && (h2 != NULL))) {
		printf("listIntersection(list1, list2): ");
		printTree3(h3);
	} else {
		printf("listIntersection(list1, list2): NULL\n");
	}
	
	h4 = listUnion (h1, h2, &stack4);
	if (h4 != NULL) {
		printf("listUnion(list1, list2): ");
		printTree4(h4);
	} else {
		printf("listUnion(list1, list2): NULL\n");
	}
} //End of Case 1
*/
/***************************************************************************************
 Test case 2
 */
 /*
 	printf("case 2\n");
	h1 = push1(&stack1, 8);
	//printTree1(h1);

	tl1 = push1(&stack1, 4);
	tl1->nPtr1 = h1;
	tr1 = h1;
	h1->rPtr1 = tl1;
	h1 = tl1;
	tr1 = h1;
	//printTree1(h1);
	
	h1 = push1(&stack1, 3);
	h1->nPtr1 = tr1;
	tr1->rPtr1 = h1;
	tr1 = h1;
	//printTree1(h1);
	
	h1 = push1(&stack1, 1);
	h1->nPtr1 = tr1;
	tr1->rPtr1 = h1;
	tr1 = h1;
	printTree1(h1);
	
	h2 = push2(&stack2, 5);
	//printTree2(h2);

	tl2 = push2(&stack2, 4);
	tl2->nPtr2 = h2;
	tr2 = h2;
	h2->rPtr2 = tl2;
	h2 = tl2;
	tr2 = h2;
	//printTree2(h2);
	
	h2 = push2(&stack2, 3);
	h2->nPtr2 = tr2;
	tr2->rPtr2 = h2;
	tr2 = h2;
	//printTree2(h2);
	
	h2 = push2(&stack2, 2);
	h2->nPtr2 = tr2;
	tr2->rPtr2 = h2;
	tr2 = h2;
	printTree2(h2);
	
	if ((h1 != NULL) && (h2 != NULL)) {
		h3 = listIntersection (h1, h2, &stack3);
	}	
	if ((h3 != NULL) && ((h1 != NULL) && (h2 != NULL))) {
		printf("listIntersection(list1, list2): ");
		printTree3(h3);
	} else {
		printf("listIntersection(list1, list2): NULL\n");
	}
	
	h4 = listUnion (h1, h2, &stack4);
	if (h4 != NULL) {
		printf("listUnion(list1, list2): ");
		printTree4(h4);
	} else {
		printf("listUnion(list1, list2): NULL\n");
	}
} //End of Case 2
*/
/***************************************************************************************
 Test case 3
 */ 	
 /*
	printf("case 3\n");
	h1 = push1(&stack1, 12);
	//printTree1(h1);

	tl1 = push1(&stack1, 10);
	tl1->nPtr1 = h1;
	tr1 = h1;
	h1->rPtr1 = tl1;
	h1 = tl1;
	tr1 = h1;
	//printTree1(h1);
	
	h1 = push1(&stack1, 5);
	h1->nPtr1 = tr1;
	tr1->rPtr1 = h1;
	tr1 = h1;
	//printTree1(h1);
	
	h1 = push1(&stack1, 4);
	h1->nPtr1 = tr1;
	tr1->rPtr1 = h1;
	tr1 = h1;
	//printTree1(h1);
	
	h1 = push1(&stack1, 2);
	h1->nPtr1 = tr1;
	tr1->rPtr1 = h1;
	tr1 = h1;
	//printTree1(h1);
	
	h1 = push1(&stack1, 1);
	h1->nPtr1 = tr1;
	tr1->rPtr1 = h1;
	tr1 = h1;
	printTree1(h1);
	
	h2 = push2(&stack2, 8);
	//printTree2(h2);

	tl2 = push2(&stack2, 7);
	tl2->nPtr2 = h2;
	tr2 = h2;
	h2->rPtr2 = tl2;
	h2 = tl2;
	tr2 = h2;
	//printTree2(h2);
	
	h2 = push2(&stack2, 6);
	h2->nPtr2 = tr2;
	tr2->rPtr2 = h2;
	tr2 = h2;
	//printTree2(h2);
	
	h2 = push2(&stack2, 5);
	h2->nPtr2 = tr2;
	tr2->rPtr2 = h2;
	tr2 = h2;
	//printTree2(h2);
	
	h2 = push2(&stack2, 4);
	h2->nPtr2 = tr2;
	tr2->rPtr2 = h2;
	tr2 = h2;
	//printTree2(h2);
	
	h2 = push2(&stack2, 3);
	h2->nPtr2 = tr2;
	tr2->rPtr2 = h2;
	tr2 = h2;
	//printTree2(h2);
	
	h2 = push2(&stack2, 2);
	h2->nPtr2 = tr2;
	tr2->rPtr2 = h2;
	tr2 = h2;
	//printTree2(h2);
	
	h2 = push2(&stack2, 1);
	h2->nPtr2 = tr2;
	tr2->rPtr2 = h2;
	tr2 = h2;
	printTree2(h2);
	
	if ((h1 != NULL) && (h2 != NULL)) {
		h3 = listIntersection (h1, h2, &stack3);
	}	
	if ((h3 != NULL) && ((h1 != NULL) && (h2 != NULL))) {
		printf("listIntersection(list1, list2): ");
		printTree3(h3);
	} else {
		printf("listIntersection(list1, list2): NULL\n");
	}
	
	h4 = listUnion (h1, h2, &stack4);
	if (h4 != NULL) {
		printf("listUnion(list1, list2): ");
		printTree4(h4);
	} else {
		printf("listUnion(list1, list2): NULL\n");
	}
}  //End of Case 3
*/
/***************************************************************************************
 Test case 4
 */
	printf("case 4\n");
	h1 = push1(&stack1, 12);
	//printTree1(h1);

	tl1 = push1(&stack1, 10);
	tl1->nPtr1 = h1;
	tr1 = h1;
	h1->rPtr1 = tl1;
	h1 = tl1;
	tr1 = h1;
	//printTree1(h1);
	
	h1 = push1(&stack1, 5);
	h1->nPtr1 = tr1;
	tr1->rPtr1 = h1;
	tr1 = h1;
	//printTree1(h1);
	
	h1 = push1(&stack1, 4);
	h1->nPtr1 = tr1;
	tr1->rPtr1 = h1;
	tr1 = h1;
	//printTree1(h1);
	
	h1 = push1(&stack1, 2);
	h1->nPtr1 = tr1;
	tr1->rPtr1 = h1;
	tr1 = h1;
	//printTree1(h1);
	
	h1 = push1(&stack1, 1);
	h1->nPtr1 = tr1;
	tr1->rPtr1 = h1;
	tr1 = h1;
	printTree1(h1);
	
	h2 = NULL;

	if ((h1 != NULL) && (h2 != NULL)) {
		h3 = listIntersection (h1, h2, &stack3);
	}	
	if ((h3 != NULL) && ((h1 != NULL) && (h2 != NULL))) {
		printf("listIntersection(list1, list2): ");
		printTree3(h3);
	} else {
		printf("listIntersection(list1, list2): NULL\n");
	}
	
	h4 = listUnion (h1, h2, &stack4);
	if (h4 != NULL) {
		printf("listUnion(list1, list2): ");
		printTree4(h4);
	} else {
		printf("listUnion(list1, list2): NULL\n");
	}
} //End of Case 4

/***************************************************************************************
 Test case 5
 */
 /*
	printf("case 5\n");
	h2 = push2(&stack2, 12);

	tl2 = push2(&stack2, 10);
	tl2->nPtr2 = h2;
	tr2 = h2;
	h2->rPtr2 = tl2;
	h2 = tl2;
	tr2 = h2;
	
	h2 = push2(&stack2, 5);
	h2->nPtr2 = tr2;
	tr2->rPtr2 = h2;
	tr2 = h2;
	
	h2 = push2(&stack2, 4);
	h2->nPtr2 = tr2;
	tr2->rPtr2 = h2;
	tr2 = h2;
	
	h2 = push2(&stack2, 2);
	h2->nPtr2 = tr2;
	tr2->rPtr2 = h2;
	tr2 = h2;
	
	h2 = push2(&stack2, 1);
	h2->nPtr2 = tr2;
	tr2->rPtr2 = h2;
	tr2 = h2;
	printTree2(h2);
	
	h1 = NULL;

	if ((h1 != NULL) && (h2 != NULL)) {
		h3 = listIntersection (h1, h2, &stack3);
	}	
	if ((h3 != NULL) && ((h1 != NULL) && (h2 != NULL))) {
		printf("listIntersection(list1, list2): ");
		printTree3(h3);
	} else {
		printf("listIntersection(list1, list2): NULL\n");
	}
	
	h4 = listUnion (h1, h2, &stack4);
	if (h4 != NULL) {
		printf("listUnion(list1, list2): ");
		printTree4(h4);
	} else {
		printf("listUnion(list1, list2): NULL\n");
	}
} //End of Case 5
*/

struct node1 * push1 (struct node1 * p, int data) {
	struct node1 * n = (struct node1 *) malloc(sizeof(struct node1));
	if (n == NULL) {
		printf("Error\n");
	} else
		{
			n->data = data;
			n->nPtr1 = NULL;
			n->rPtr1 = NULL;
			return (n);
		}
}

struct node2 * push2 (struct node2 * p, int data) {
	struct node2 * n = (struct node2 *) malloc(sizeof(struct node2));
	if (n == NULL) {
		printf("Error\n");
	} else
		{
			n->data = data;
			n->nPtr2 = NULL;
			n->rPtr2 = NULL;
			return (n);
		}
}

struct node3 * push3 (struct node3 * p, int data) {
	struct node3 * n = (struct node3 *) malloc(sizeof(struct node3));
	if (n == NULL) {
		printf("Error\n");
	} else
		{
			n->data = data;
			n->nPtr3 = NULL;
			n->rPtr3 = NULL;
			return (n);
		}
}

struct node4 * push4 (struct node4 * p, int data) {
	struct node4 * n = (struct node4 *) malloc(sizeof(struct node4));
	if (n == NULL) {
		printf("Error\n");
	} else
		{
			n->data = data;
			n->nPtr4 = NULL;
			n->rPtr4 = NULL;
			return (n);
		}
}

void printTree1(struct node1 * p) {
	printf("list1: ");
	while (p != NULL) {
		printf("%d, ", p->data);
		p=p->nPtr1;
	}
	if (p == NULL) {
		printf("NULL\n");
	}
}

void printTree2(struct node2 * p) {
	printf("list2: ");
	while (p != NULL) {
		printf("%d, ", p->data);
		p=p->nPtr2;
	}
	if (p == NULL) {
		printf("NULL\n");
	}
}

void printTree3(struct node3 * p) {
	while (p != NULL) {
		printf("%d, ", p->data);
		p=p->nPtr3;
	}
	if (p == NULL) {
		printf("NULL\n");
	}
}

void printTree4(struct node4 * p) {
	while (p != NULL) {
		printf("%d, ", p->data);
		p=p->nPtr4;
	}
	if (p == NULL) {
		printf("NULL\n");
	}
}

struct node3 * listIntersection (struct node1 * p1, struct node2 * p2, struct node3 * p3) {
	struct node1 * h1 = p1;
	struct node2 * h2 = p2;
	struct node3 * h3 = p3;
	struct node3 * tl3;
	struct node3 * tr3;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	
	if (p1 != NULL) {
		count1++;
	}
	if (p2 != NULL) {
		count2++;
	}
	while (p1->nPtr1 != NULL) {
		count1++;
		p1 = p1->nPtr1;
	}
	while (p2->nPtr2 != NULL) {
		count2++;
		p2 = p2->nPtr2;
	}
	p1 = h1; p2 = h2; p3 = h3;
	if ((count1 > 0) && (count2 > 0)) {
		for (int j = 1; j <= count1; j++) {
			p2 = h2;
			for (int i = 1; i <= count2; i++) {		
				if (p1->data == p2->data) {
					count3++;
					if (count3 == 1) {
						h3 = push3(p3, p1->data);
						} 
					if (count3 == 2) {
						tl3 = push3(p3, p1->data);
						tl3->nPtr3 = h3;
						tr3 = h3;
						h3->rPtr3 = tl3;
						h3 = tl3;
						tr3 = h3;
						} 
					if (count3 > 2) {
						h3 = push3(p3, p1->data);
						h3->nPtr3 = tr3;
						tr3->rPtr3 = h3;
						tr3 = h3;
						} 	
					}
					if (p2->nPtr2 != NULL) {
						p2 = p2->nPtr2;	
					}
				}
				if (p1->nPtr1 != NULL) {
					p1 = p1->nPtr1;
				}
			}
	}	
	if (count3 == 0) {
		h3 = NULL;
	}
	return (h3);
}

struct node4 * listUnion (struct node1 * p1, struct node2 * p2, struct node4 * p4) {	
	struct node1 * h1 = p1;
	struct node2 * h2 = p2;
	struct node4 * h4 = p4;
	struct node4 * tl4;
	struct node4 * tr4;
	int count1 = 0;
	int count2 = 0;
	int count4 = 0;
	int reg = 0;
	
	if (p1 != NULL) {
		count1++;
	}
	if (p2 != NULL) {
		count2++;
	}
	if (count1 != 0) {
		while ((p1->nPtr1 != NULL) && (count1 > 0)) {
			count1++;
			p1 = p1->nPtr1;
		}
	}
	if (count2 != 0) {
		while ((p2->nPtr2 != NULL) && (count2 > 0)) {
			count2++;
			p2 = p2->nPtr2;
		}
	}
	
	p1 = h1; p2 = h2; p4 = h4;
	if (count1 > 0) {
		for (int k = 1; k <= count1; k++) {
			count4++;
			if (count4 == 1) {
				h4 = push4(p4, p1->data);
			} 
			if (count4 == 2) {
				tl4 = push4(p4, p1->data);
				tl4->nPtr4 = h4;
				tr4 = h4;
				h4->rPtr4 = tl4;
				h4 = tl4;
				tr4 = h4;
			} 
			if (count4 > 2) {
				h4 = push4(p4, p1->data);
				h4->nPtr4 = tr4;
				tr4->rPtr4 = h4;
				tr4 = h4;
			}
			if (p1->nPtr1 != NULL) {
				p1 = p1->nPtr1;
			} 
		}
	}
	
	p1 = h1; p2 = h2; p4 = h4;
	if ((count1 > 0) && (count2 > 0)) {
		for (int j = 1; j <= count2; j++) {
			p1 = h1;
			for (int i = 1; i <= count1; i++) {		
				if (p2->data == p1->data) {
					reg = 1;
				}			
				if ((p1->nPtr1 == NULL) && (reg != 1)) {
					if (count4 == 1) {
						h4 = push4(p4, p2->data);
					} 
					if (count4 == 2) {
						tl4 = push4(p4, p2->data);
						tl4->nPtr4 = h4;
						tr4 = h4;
						h4->rPtr4 = tl4;
						h4 = tl4;
						tr4 = h4;
					}	 
					if (count4 > 2) {
						h4 = push4(p4, p2->data);
						h4->nPtr4 = tr4;
						tr4->rPtr4 = h4;
						tr4 = h4;
					}
				}			
				if (p1->nPtr1 != NULL) {
					p1 = p1->nPtr1;	
				}
			}
			if ((p1->nPtr1 == NULL) && (reg == 1)) {
				reg = 0;
			}
			if (p2->nPtr2 != NULL) {
			p2 = p2->nPtr2;
			}
		}
	}	
	
	p1 = h1; p2 = h2; p4 = h4;
	if ((count2 > 0) && (count1 == 0)) {
		for (int k = 1; k <= count2; k++) {
			count4++;
			if (count4 == 1) {
				h4 = push4(p4, p2->data);
			} 
			if (count4 == 2) {
				tl4 = push4(p4, p2->data);
				tl4->nPtr4 = h4;
				tr4 = h4;
				h4->rPtr4 = tl4;
				h4 = tl4;
				tr4 = h4;
			} 
			if (count4 > 2) {
				h4 = push4(p4, p2->data);
				h4->nPtr4 = tr4;
				tr4->rPtr4 = h4;
				tr4 = h4;
			}
			if (p2->nPtr2 != NULL) {
				p2 = p2->nPtr2;
			} 
		}
	}

	if (count4 == 0) {
		h4 = NULL;
	}
	return (h4);
}
	

