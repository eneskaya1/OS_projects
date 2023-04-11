/*
 ============================================================================
 Name        : thread_functions.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
static int count1=0, count2=0;

void* myThread(void *arg)
{
    pthread_t currentid = pthread_self();

    if(pthread_equal(currentid, tid[0])) {
        printf("First thread processing done\n");
        count1++;
    }
    else {
        printf("Second thread processing done\n");
        count2++;
    }

    return NULL;
}

int main(void)
{
    int i, j =0;
    while(j<5) {
    	for (i = 0; i < 2; i++) {
    		pthread_create(&(tid[i]), NULL, &myThread, NULL);
    	}
    	j++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    printf("Thread1: %d \t\tThread2: %d", count1, count2);

    return 0;
}
