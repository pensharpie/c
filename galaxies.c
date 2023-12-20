/********************************************************************************************
Description:  Script reads records from a file into a data structure and finds the neighbor 
that is nearest to Earth. To store the records, a Btree data structure is implemented. 

The data structure also supports insertion and deletion of records and supports an 
operation to print the record to the nearest neighbor.

Name                  Rev             Date                   Note
Herbe Chun         v1              12/18/2023          None
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define N 10

struct node {
	char name[N];
	double x;
	double y;
	double z;
	double d;
	double t;
	struct node * l;
	struct node * r;
};

struct node * readFile(char fileName[]);
void insert (struct node ** head, char name[N], double x, double y, double z);
struct node * newNode (char name[N], double x, double y, double z);
void postorder(struct node * head);
double dist(double x1, double y1, double z1, double x2, double y2, double z2);
double near(struct node * head, int reset);
void getMinDist(struct node * head, double d);

int main() {
	double disto = INT_MAX;
	double distance = INT_MAX;
	struct node * head;
	int reset = 0;
	char fileName[] = "Galaxies.txt";
	head = readFile(fileName);
	reset = 1;
	distance = near(head, reset);
	getMinDist(head, distance);
	
	reset = 0;
	return 0;
}

struct node * readFile(char fileName[]) {	
	char name[N];
	double x;
	double y;
	double z;
	struct node * head = NULL;
		
    FILE * p = fopen(fileName, "r");
    if (p == NULL) {
        printf("Error\n");
    } else {
		printf("Nodes:\n");
		while (fscanf(p, "%s %lf %lf %lf", name, &x, &y, &z) != EOF) {
			printf("%s %lf %lf %lf\n", name, x, y, z);
			insert(&head, name, x, y, z);
		}
		printf("\nPostorder (tree): \n");
		postorder(head);
		printf("NULL\n");
		fclose(p);
		return (head);
	}
}

void insert (struct node ** head, char name[N], double x, double y, double z) {
	if (*head == NULL) {
		*head = newNode(name, x, y, z);
	} else { 
		if (x <= (*head) -> x) {
			insert (&((*head) -> l), name, x, y, z);
		} else if (x > (*head) -> x) {
			insert(&((*head) -> r), name, x, y, z);
		}
	}
}

struct node * newNode (char name[N], double x, double y, double z) {
	struct node * p = (struct node *) malloc (sizeof (struct node));
	if (p == NULL) {
		printf("Error\n");
	} else {
		//p -> name[N] = name[N];
		for (int i = 0; i < N; i++) 
			p -> name[i] = name[i];
		p -> x = x;
		p -> y = y;
		p -> z = z;
		p -> l = NULL;
		p -> r = NULL;
		p -> d = 0;
		p -> t = 0;
		return (p);
	}
} 	

void postorder(struct node * head) {
	double x0;
	double y0;
	double z0;
	double dist0;
	
	clock_t begin = clock();
	if (head != NULL) {
		postorder(head -> l);
		postorder(head -> r);
		if (head -> name == "Earth") {
			x0 = head ->x;
			y0 = head -> y;
			z0 = head -> z;
		}
		if (head -> name != "Earth") {
			dist0 = dist(head ->x, head -> y, head -> z, x0, y0, z0);
			clock_t end = clock();
			double t = (double) (end - begin);
			head -> t = t;
			head -> d = dist0;
			printf("%s %f %f %f, Distance: %f Time: %f \n", head -> name, head -> x, head -> y, head -> z, dist0, t);
		}
	}
}

double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt ((x2 - x1) * (x2 - x1)+ (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}

double near(struct node * head, int reset) {
	double distro0;
	char galaxy[N] = "";
	double x1;
	double y1;
	double z1;
	double t;
	
	if (reset) 
		distro0 = INT_MAX;
	
	if (head != NULL) {
		near(head -> l, 0);
		near(head -> r, 0);
		if (head -> d < distro0) {
			distro0 = head -> d;
			galaxy[N] = head -> name[N];
			x1 = head -> x;
			y1 = head -> y;
			z1 = head -> z;
			t = head -> t;
		}
	}
/*
	if (distro0 > 0) {
		printf("\nMin distance:\n");
		printf("Galaxy: %s\n", galaxy);
		printf("x: %f\n", x1);
		printf("y: %f \n", y1);
		printf("z: %f \n", z1);
		printf("Distance:  %f\n", distro0);
		printf("Time: %f\n", t);
	}
*/
	return distro0;
}

void getMinDist(struct node * head, double d) {
	if (head != NULL) {
		getMinDist(head -> l, d);
		getMinDist(head -> r, d);
		if (head -> d == d) {
			printf("\nMin distance:\n");
			printf("Galaxy: %s\n", head -> name);
			printf("x: %f\n", head -> x);
			printf("y: %f \n", head -> y);
			printf("z: %f \n", head -> z);
			printf("Distance:  %f\n", head -> d);
			printf("Time: %f\n", head -> t);
		}
	}
}