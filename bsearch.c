/*
2/19/2024
A simple binary search using recursion
Herbe Chun
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bsch (int arr[], int target, int indexStart, int indexEnd, int count);

int main(int argc, char *argv[]) {
	int nums[] = {-1, 0, 3, 5, 9, 12, 15, 20, 24, 25, 51};
	int target = 9;
	int indexStart = 0;
	int indexEnd = sizeof(nums) - 1;
	int count = 0;
	
	int index = bsch(nums, target, indexStart, indexEnd, count);
	printf("index = %d \n", index);
}

int bsch (int arr[], int target, int indexStart, int indexEnd, int count) {
	int indexMid = round((indexStart + indexEnd) / 2);
	if (arr[indexMid] == target) {
		return indexMid;
	}
	else if (arr[indexMid] > target) {
		indexStart = 0;
		indexEnd = indexMid - 1;
	}
	else if (arr[indexMid] < target) {
		indexStart = indexMid + 1;
		indexEnd = indexEnd;
	};
	bsch(arr, target, indexStart, indexEnd, count);
}