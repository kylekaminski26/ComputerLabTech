/* uhoh.c - when does time run out?
 *
 * DFP
 */

#include <stdio.h>
#include <time.h>
#include <limits.h>

int main()
{
    time_t time = INT_MAX;
    printf("Time in seconds (32-bit max): %ld\n", time);    
    fputs(ctime(&time), stdout);

    return 0;
}

