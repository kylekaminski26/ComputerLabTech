/* stats_discard.c
 *
 * D Provine 28 Jan 2014
 *
 * scanf() will ignore input that doesn't match what it expects.
 * This can cause a program to get stuck in an infinite loop.
 *
 * A way to protect against this is to check and see how many
 * things scanf() was able to match before processing, and to
 * discard anything on the line scanf() couldn't manage.
 *
 * This avoids infinite loops, but can still have other problems.
 * 
 * See also "stats_broken.c" and "stats_safest.c".
 */

#include <stdio.h>

int main()
{
    int    itemsread = 0;
    double item;
    int    howmany = 0;
    int    c;

    while ( (itemsread = scanf("%lf", &item)) != EOF && item != 0) {
        // check to see if we got valid input
        if (itemsread == 1) {
            howmany++;
        }

        // discard remaining input on line
        while ( (c = getchar()) != '\n' )
            ; // do nothing
    }

    printf("# numbers: %d\n", howmany);

    return 0;
}

