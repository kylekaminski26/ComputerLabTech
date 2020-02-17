/* qsort1.c -- sample program from qsort man page
 *
 */

#include <stdlib.h>
#include <stdio.h>

/* This function takes two pointers, treats them as pointers
 * to integer, and then returns a value based on whether they
 * are in order or not.
 *     negative = the first is lower than the second
 *         zero = they are the same
 *     positive = the first is higher than the second
 * This is what strcmp() does, and it's standard for all
 * comparison functions.
 */
static int
intcompare(const void *p1, const void *p2)
{
    int i = *((int *)p1);
    int j = *((int *)p2);

    if (i > j)
        return (1);
    if (i < j)
        return (-1);
    return (0);
}


int main()
{
    int i;
    int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    size_t nelems = sizeof (a) / sizeof (int);

    /* pointer to start of array, # items, item size, compare function */
    qsort((void *)a, nelems, sizeof (int), intcompare);

    for (i = 0; i < nelems; i++) {
        (void) printf("%d ", a[i]);
    }

    (void) printf("\n");
    return (0);
}
