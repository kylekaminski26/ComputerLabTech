/* exec.c -- run a different program
 *
 * D Provine, 27 April 2010
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("This is the program exec.\n");
    printf("I will now become ls(1) with the flags you gave.\n");

    // exec() and family replace this process with another program's
    // image.
    execv("/bin/ls", argv);

    printf("If you can read this, it didn't work.\n");

    return 0;
}
