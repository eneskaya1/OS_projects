/*
 ============================================================================
 Name        : merge_sort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int start, int finish);
void merge(int arr[], int start, int middle, int finish);
void printArray(int arr[], int len);

static int cnt = 1;

int main(void) {

	// sample test array
	int arrayToSort[] = {15, 19, 4, 3, 18, 6, 2, 12, 7, 9, 11, 16};
	int len = sizeof(arrayToSort)/sizeof(arrayToSort[0]);
	puts("Array to sort: ");
	printArray(arrayToSort, len);

	mergeSort(arrayToSort, 0, len-1);

	return EXIT_SUCCESS;
}

void mergeSort(int arr[], int start, int finish) {
	if(start<finish)
	{
		// index to separate 2 pieces with the same size
		int middle = start + (finish - start)/2;
		// left piece
		mergeSort(arr, start, middle);
		// right piece
		mergeSort(arr, middle+1, finish);
		// combine the pieces to form the sorted array
		merge(arr, start, middle, finish);
	}
}

void merge(int arr[], int start, int middle, int finish) {

	int len1 = middle - start + 1;
	int len2 = finish - middle;

	int left[len1], right[len2];

	int i, j;
	// form the left and right pieces of the array
	for (i = 0; i < len1; i++) {
		left[i] = arr[i + start];
	}
	for (j = 0; j < len2; j++) {
		right[j] = arr[middle + 1 + j];
	}

	// indexes to traverse over the pieces and the main array
	int index1=0, index2=0, indexArr=start;

	// compare corresponding indexes of the array pieces
	while(index1<len1 && index2<len2) {
		if(left[index1] <= right[index2])
		{
			arr[indexArr] = left[index1];
			index1++;
		}
		else
		{
			arr[indexArr] = right[index2];
			index2++;
		}
		indexArr++;
	}

	while(index1 < len1) {
		arr[indexArr] = left[index1];
		indexArr++;
		index1++;
	}
	while(index2 < len2) {
		arr[indexArr] = right[index2];
		indexArr++;
		index2++;
	}
	printf("Step %d: ", cnt);
	printArray(arr, finish-start+1);
	cnt++;
}

void printArray(int arr[], int len) {
	int k;
	for(k=0; k<len; k++)
	{
		printf("%d ", arr[k]);
	}
	printf("%s", "\n");
}
