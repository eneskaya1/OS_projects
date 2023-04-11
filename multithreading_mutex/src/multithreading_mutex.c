/*
 ============================================================================
 Name        : multithreading_mutex.c
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

#define BUFSIZE 15

pthread_t fileWrite[2];
pthread_t fileRead;
pthread_mutex_t lock;

char *fileName = "file.txt";
static int cnt_write1=0, cnt_write2=0, cnt_read=0;

void* writing(void *arg) {

	pthread_mutex_lock(&lock);

    char *text = (char *)arg;
    FILE *fp;
    fp = fopen(fileName, "w");
    fputs(text, fp);
    printf("%s is written in %s.\n", text, fileName);

    fclose(fp);

    pthread_t currentid = pthread_self();
    if(pthread_equal(currentid, fileWrite[0])) {
        cnt_write1++;
    }
    else {
        cnt_write2++;
    }

    pthread_mutex_unlock(&lock);

    return NULL;
}

void* reading(void *arg) {

	pthread_mutex_lock(&lock);

    FILE *fp;
    fp = fopen(fileName, "r");
    if(fp == NULL) {
    	printf("File can't be opened \n");
    }

    printf("Content in %s:  ", fileName);
    char ch;
    do {
    	ch = fgetc(fp);
    	printf("%c", ch);

    } while(ch != EOF);
    puts("");

    fclose(fp);

    cnt_read++;

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void)
{
	if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("\n mutex init has failed\n");
		return 1;
	}

    char texts[2][10] = {"Thread 1", "Thread 2"};

    int i=0, j;
    while(i<1000) {
    	for(j=0; j<2; j++) {
    		pthread_create(&fileWrite[j], NULL, &writing, texts[j]);
    	}
    	pthread_create(&fileRead, NULL, &reading, NULL);
     	i++;
    }

    printf("%s\t%s\t%s\t%s\n", "Operations","Write Thread 1", "Write Thread 2", "Read");
    printf("%s\t%d\t\t%d\t\t%d", "Number of Op.:", cnt_write1, cnt_write2, cnt_read);

    pthread_join(fileWrite[0], NULL);
    pthread_join(fileWrite[1], NULL);
    pthread_join(fileRead, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}
