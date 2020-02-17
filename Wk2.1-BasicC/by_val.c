/* by_val.c -- everything passed by value
 *
 * DFP
 */

#include <stdio.h>

void modify_wrong(int x)
{
    x *= 2;
}

void modify_right(int *x)
{
    *x *= 2;
}

int main()
{
    int i = 0;

    printf("Enter an integer: ");
    scanf("%d", &i);

    printf("You entered %d\n\n", i);

    modify_wrong(i);
    printf("modified wrong: %d\n", i);
    
    // note "address of"
    modify_right(&i);
    printf("modified right: %d\n", i);

    return 0;
}
