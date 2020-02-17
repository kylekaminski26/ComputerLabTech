/* forkprint.c -- show parallel execution
 *
 * D Provine, 17 April 2012
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main()
{
    pid_t  child_pid;
    char   whoami[10];

    int i;

    printf("There is only one process now.\n");

    // fork() creates an exact copy of the running process,
    // except for the return value from fork()
    if ( (child_pid = fork()) == 0 ) {
        printf("This is the child process.\n");
	strcpy(whoami, "child");
    } else {
        printf("This is the parent process; the child is %d.\n",
               child_pid);
	strcpy(whoami, "parent");
    }

    for (i = 1; i <= 10; i++) {
        printf("%s %d\n", whoami, i);
    } 

    printf("%s exiting...\n", whoami);

    return 0;
}
