/*
 ============================================================================
 Name        : multithreading_semaphore.c
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
#include<semaphore.h>

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
sem_t mutex;

void* writing(void *args) {
	sem_wait(&mutex);

    TextArgs *TextArgsPtr = args;
    char *fileName = TextArgsPtr->fileName;
    char *text = TextArgsPtr->text;
    FILE *fp;
    fp = fopen(fileName, "w");
    fputs(text, fp);

    fclose(fp);

    sem_post(&mutex);
    return NULL;
}

void* reading(void *arg) {
	sem_wait(&mutex);

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

    sem_post(&mutex);
    return NULL;
}

int main(void)
{
	sem_init(&mutex, 0, 1);

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

    sem_destroy(&mutex);

    return 0;
}
