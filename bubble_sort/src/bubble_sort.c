/*
 ============================================================================
 Name        : bubble_sort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int len);
void printArray(int arr[], int len);

int main(void) {
	// test array:
	int array[] = {24, 14, 15, 7, 4, 27, 1, 8};
	int len = sizeof(array)/sizeof(array[0]);
	printf("%s", "Before Bubble Sort: ");
	printArray(array, len);

	bubbleSort(array, len);

	return EXIT_SUCCESS;
}


void bubbleSort(int arr[], int len) {

	int temp, i, j, cnt = 1;

	for(i=len-1; i>=0; i--)
	{
		int ordered = 1;			// to optimize the time complexity of the algorithm
		for(j=0; j<i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				ordered = 0;
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
				printf("Step %d: ", cnt);
				printArray(arr, len);
				cnt++;
			}
		}
		if(ordered)
			break;
	}
}

void printArray(int arr[], int len) {
	int k;
	for(k=0; k<len; k++)
	{
		printf("%d ", arr[k]);
	}
	printf("%s", "\n");
}
