/* fnptr.c - show function pointers
 *
 * I recommend "http://cdecl.org" to see what is being declared.
 *
 * DFP
 */

#include <stdio.h>

/* These are two functions that take an int argument and return an
 * int value.  Because the arguments and return are the same, we
 * can declare a pointer which can point to either of them.
 */ 
int foo (int x)
{
    printf("foo()\n");
    return 0 - x * x;
}

int bar (int x)
{
    printf("bar()\n");
    return x * 3;
}


int main()
{
    int i;
    int (*run_it)(int);
    /* "run_it()" is a pointer to a function taking int returning int.
     * So it can point at either of the two functions above.
     */

    i = 9;
    
    run_it = &foo;
    printf("%d\n", run_it(i));

    run_it = &bar;
    printf("%d\n", run_it(i));

    return 0;
}

