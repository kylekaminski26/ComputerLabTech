/* uhoh2.c - when does time run out?
 *
 * DFP
 *
 * NOTE: localtime() returns a pointer, so it allocates space
 *       and returns a pointer telling you where it is.  If a
 *       function returns a pointer, it allocates space.
 *
 * See the man page for localtime for more details.
 */

#include <stdio.h>
#include <time.h>
#include <limits.h>

int main()
{
    time_t time = INT_MAX;
    struct tm     *result = localtime(&time);

    printf("struct tm size is: %d\n", sizeof(struct tm));

    /* "result" is a pointer to a struct, not a struct.
     * We use the arrow notation "->" because it's a pointer;
     * this means the same thing as the dot notation you're
     * already used to, but it's for pointers.
     */
    printf("Year: %d\n", result->tm_year);
    printf("Month: %d\n", result->tm_mon);
    printf("Day: %d\n", result->tm_mday);

    return 0;
}

