/* myname.c - who am I?
 *
 * DFP & his posse, 18 Oct 2011
 * (and the man page writers)
 */

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    char *username;

    if ( (username = getlogin() ) == NULL ) {
        perror("Can't get username: ");
        exit(1);
    }
    printf("%s\n", username);

    return 0;
}
