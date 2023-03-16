/*
 ============================================================================
 Name        : process_functions.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <signal.h>
#include <sys/wait.h>

#ifndef CHILD_EXIT_CODE
# define CHILD_EXIT_CODE 42
#endif
// Define a macro for the expected exit status
#define EXPECTED_CODE 42

void child_routine(pid_t pid);
void parent_routine(pid_t pid);
void kill_children(pid_t *pid);

int main(void) {

    time_t t;

    printf("Parent ID = %ld\n", (long)getppid());
    time(&t);
    printf("Process creation time: %s\n", ctime(&t));

    pid_t pid[3];
    int i;
    for(i=1; i<=3; i++) {
        pid[i] = fork();
    	if(pid[i] < 0)
	        printf("\nFork failed!");
	    if(pid[i] == 0) {
	        child_routine(pid[i]);
	        time(&t);
	        printf("Process creation time: %s\n", ctime(&t));
	    }
	    else {
	        parent_routine(pid[i]);
	        time(&t);
        	printf("Process creation time: %s\n", ctime(&t));
	    }
    }
    kill_children(pid);

	return 0;
}

// Child process routine:
void child_routine(pid_t pid) {
	printf("Child ID = %ld\n", (long)getpid());
	sleep(1);
	printf("\e[36mChild: Exiting with exit code %d.\e[0m\n", CHILD_EXIT_CODE);
	exit(CHILD_EXIT_CODE);
}

// Parent process routine:
void parent_routine(pid_t pid) {
	int	status;
	waitpid(pid, &status, 0); // Wait for child
}

void kill_children(pid_t *pid) {
    int	status;
    int	i;

    for(i=1; i<=3; i++) {
        kill(pid[i], SIGKILL);
    }

    for(i=1; i<=3; i++) {
        waitpid(pid[i], &status, 0);
        printf("Child [%d] was killed.\n", pid[i]);
    }
}
