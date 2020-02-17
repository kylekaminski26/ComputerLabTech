/* qsort2.c -- sample qsort program
 *
 * D Provine, 30 Mar 2017
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char           inits[5];
    unsigned char  num;
} prezinfo;


/* This function takes two pointers, treats them as pointers
 * to "prezinfo", and then returns a value based on whether they
 * are in order or not.
 *
 * Note that because "what is returned" is based on strcmp(), we
 * can just call strcmp() for any string-related sorting.
 */
static int
prezcompare(const void *p1, const void *p2)
{
    prezinfo *A = (prezinfo *)p1;
    prezinfo *B = (prezinfo *)p2;

    return strcmp( A->inits, B->inits);
}


int main()
{
    /* stick in some initials and numbers */
    prezinfo  person[] =
        { { "GW", 1 }, { "JM", 4 }, { "WHH", 9 },
          { "AL", 16 }, { "WM", 25 }, { "LBJ", 36 } };
    int i;
    size_t nelems = 6;

    /* pointer to start of array, # items, item size, compare function */
    qsort((void *)person, nelems, sizeof (prezinfo), prezcompare);

    for (i = 0; i < nelems; i++) {
        (void) printf("%4s - %2d\n", person[i].inits, person[i].num);
    }

    return (0);
}
