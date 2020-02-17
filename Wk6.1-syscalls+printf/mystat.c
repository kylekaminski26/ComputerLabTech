/* mystat.c - my version of stat(1)
 *
 * DFP & crew, 18 Oct 2011
 * (and man page writers)
 */

// These are for "stat()"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// This is for password info
#include <pwd.h>

// printing, as usual
#include <stdio.h>

// exit() so we can quit
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /* stat() takes a pointer as the second argument.
     * When a function takes a pointer as an argument,
     * the programmer has to allocate storage.
     */
    // This declaration has no star: we've declared an object
    // of type "struct stat".
    struct stat fileinfo;

    /* getpwuid() returns a pointer.
     * When a function returns a pointer, it will
     * allocate storage.
     */
    // This declaration has a star: we've declared a pointer
    // to an object of type "struct password".
    struct passwd *userinfo; // the star means this a pointer

    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    // fetch file information
    if ( stat(argv[1], &fileinfo) == -1 ) {
	perror(argv[1]);
	exit(1);
    }

    printf("Information about %s:\n", argv[1]);
    printf("   inode: %d\n", (int) fileinfo.st_ino);
    printf("     uid: %d\n", (int) fileinfo.st_uid);
    printf("    size: %d\n", (int) fileinfo.st_size);

    // fetch user information
    userinfo = getpwuid(fileinfo.st_uid);
    printf("   owner's name: %s\n", userinfo->pw_name);

    return 0;
}
