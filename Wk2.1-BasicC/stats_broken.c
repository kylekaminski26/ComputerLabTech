/* stats_broken.c - show brittle input system
 *
 * D Provine (with help) 28 Jan 2014
 *
 * THIS PROGRAM IS BROKEN!
 *
 * (based on example by GAM, April 1991, Senior Project program)
 *
 * See also "stats_discard.c" and "stats_safest.c".
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

        // we can get stuck in infinite loop if there's
        // garbage on the input
        // this code shows that loop happening
        if (itemsread == 0) {
            printf("bad input");
        }
    }

    printf("# numbers: %d\n", howmany);

    return 0;
}
