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
int ret1,ret2;

void* myThread(void *arg)
{
    pthread_t currentid = pthread_self();

    if(pthread_equal(currentid, tid[0])) {
        printf("First thread processing done\n");
        ret1  = 100;
        pthread_exit(&ret1);
    }
    else {
        printf("Second thread processing done\n");
        ret2  = 200;
        pthread_exit(&ret2);
    }

    return NULL;
}

int main(void)
{
    int i;
    int err;
    int *ptr[2];

    for (i = 0; i < 2; i++) {
        err = pthread_create(&(tid[i]), NULL, &myThread, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
            printf("Thread %d created successfully\n", i+1);
    }

    pthread_join(tid[0], (void**)&(ptr[0]));
    pthread_join(tid[1], (void**)&(ptr[1]));

    printf("Return value from first thread is [%d]\n", *ptr[0]);
    printf("Return value from second thread is [%d]\n", *ptr[1]);

    return 0;
}
