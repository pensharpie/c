/*
2/18/2024
A simple bubble sort using pointers
*/

#include <stdio.h>
#include <stdlib.h>

int * swap (int *arr, int j);

int main(int argc, const char * argv[]) {
	int m = 4;
	int arr[] = {5,2,3,1};

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (arr[j + 1] < arr[j]) {
				swap(arr, j);
			}
		}
	}
	for (int j = 0; j < 4; j++) {
		printf("%d, ", arr[j]);
	}
	return 0;
}

int * swap (int *arr, int j) {
	int temp;
	temp = arr[j + 1];
	arr[j + 1] = arr[j];
	arr[j] = temp;
	return arr;
}