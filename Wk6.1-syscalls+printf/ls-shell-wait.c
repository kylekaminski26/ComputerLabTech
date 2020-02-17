/* ls-shell-wait.c -- a tiny shell that forks off a child to run ls
 *                    and waits for it to finish
 *
 * D Provine, 27 April 2010
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 

int main(int argc, char *argv[])
{
    pid_t child_pid;
    pid_t finished;
    int   child_status;

    printf("There is only one process now.\n");

    // fork() clones this process except for the return value
    if ( (child_pid = fork()) == 0 ) {

        // ensure the parent process will get to "wait()" before
        // the child finishes
        sleep(2);

        printf("This is the child process.\n");
        printf("I will now become ls(1) with the flags you gave.\n");

        // exec replaces a process with another program
        execv("/bin/ls", argv);

    } else {

        // the parent can find out out the child
        printf("This is the parent process; the child is %d.\n",
               child_pid);
        printf("I will wait for it to finish.\n");

        finished = wait(&child_status);
        // Always always always check all return values for error
        // codes.
        if ( finished != -1 ) {
            printf("Process %d has exited.\n", finished);
            printf("Process %d status was %x.\n", child_pid, child_status);

            // DO NOT try to unpack process status yourself!
            // Use the macros and functions provided!
            if ( WIFEXITED(child_status) ) {
                printf("Process ended normally.\n");
            } else {
                printf("Process ended for some other reason.\n");
            } 
        } else {
            printf("Wait failed.\n");
            perror("ls-shell");
        }
    }

    return 0;
}

