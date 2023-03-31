/*
 ============================================================================
 Name        : thread_functions2.c
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

#define TOTAL 50000000
#define BUFSIZE 15

struct textArgs {
    char fileName[20];
    char text[20];
};
typedef struct textArgs TextArgs;

pthread_t fileWrite[2];
pthread_t fileRead;
char *test[TOTAL];
pthread_mutex_t lock;

void* writing(void *args) {
	pthread_mutex_lock(&lock);

    TextArgs *TextArgsPtr = args;
    char *fileName = TextArgsPtr->fileName;
    char *text = TextArgsPtr->text;
    FILE *fp;
    fp = fopen(fileName, "w");
    fputs(text, fp);

    fclose(fp);

    pthread_mutex_unlock(&lock);
    return NULL;
}

void* reading(void *arg) {
	pthread_mutex_lock(&lock);

    char *fileName = (char *)arg;
    FILE *fp;
    fp = fopen(fileName, "r");
    int i = 0;
    test[i] = malloc(BUFSIZE);
    while(fgets(test[i], BUFSIZE, fp) != NULL) {
      strtok(test[i],"\n");
      i++;
      test[i] = malloc(BUFSIZE);
      if (i == TOTAL){
         break;
      }
   }

    fclose(fp);

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(void)
{
	if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("\n mutex init has failed\n");
		return 1;
	}


    TextArgs thread1Args;
    sprintf(thread1Args.fileName, "file.txt");
    sprintf(thread1Args.text, "Thread 1");
    TextArgs thread2Args;
    sprintf(thread2Args.fileName, "file.txt");
    sprintf(thread2Args.text, "Thread 2");

    pthread_create(&fileWrite[0], NULL, writing, (void *)&thread1Args);
    pthread_create(&fileWrite[1], NULL, writing, (void *)&thread2Args);

    pthread_create(&fileRead, NULL, reading, "file.txt");
    pthread_join(fileRead, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}
