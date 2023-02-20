/*
 ============================================================================
 Name        : reverse_string.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char str[]);

int main(void) {
	char str[20];
	puts("Enter a string to reverse:");
	gets(str);
	reverseString(str);

	return EXIT_SUCCESS;
}

void reverseString(char str[])
{
	int len = strlen(str);
	int i, temp;
	for(i=0; i<len/2; i++) {
		temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;
	}
	printf("Reversed version:\n%s\n", str);
}
