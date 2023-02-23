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

int main(void) {
	// test array:
	int array[] = {24, 14, 15, 7, 4, 27, 1, 8};
	int len = sizeof(array)/sizeof(array[0]);

	bubbleSort(array, len);

	return EXIT_SUCCESS;
}


void bubbleSort(int arr[], int len) {

	int temp, i, j, k;

	for(i=0; i<len; i++)
	{
		int ordered = 1;			// to optimize the time complexity of the algorithm
		for(j=len-1; j>i; j--)
		{
			if(arr[j-1] > arr[j])
			{
				ordered = 0;
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
		if(ordered)
			break;
	}
	for(k=0; k<len; k++)
		{
			printf("%d ", arr[k]);
	}
}
