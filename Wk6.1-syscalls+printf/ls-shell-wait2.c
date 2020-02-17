/* ls-shell-wait2.c -- a tiny shell that forks off a child to run ls
 *                     But the child finishes before the parent waits.
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

        printf("This is the child process.\n");
        printf("I will now become ls(1) with the flags you gave.\n");

        // exec replaces a process with another program
        execv("/bin/ls", argv);

    } else {

        // the parent can find out out the child
        printf("This is the parent process; the child is %d.\n",
               child_pid);
        printf("I will wait for it to finish.\n");

        // make sure the child finishes before we check on it.
        sleep(2);

        finished = wait(&child_status);
        /* The completed child process info is kept by the OS
         * until we call for it.  The child is still in the
         * process table, but isn't running.
         */

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

