/* pitfalls.c -- illustrating some things that can go wrong
 *
 * D. Provine, using examples from _C Traps and Pitfalls_
 */

#include <stdio.h>

int main()
{
    int a, b, c, d, e, f, g, h, i=5;
    int *ip;

    a = 4;
    b = 10;

    printf("a : %d;   b : %d\n", a, b);
    printf("a+++b : %d\n", a+++b);
    printf("a : %d;   b : %d\n", a, b);


    printf("i is %d\n", i);

    if ( i > 6 )
        if ( i < 25 )
            printf("i between 6 and 25, inclusive\n");
    else
        printf("i less than six\n");

    printf("if block for 'i' completed\n");

    c = 7;
    printf("c : %d\n", c);
    if ( c = 9 ) {
         printf("Nine!\n");
    } else {
         printf("Not nine!\n");
    }
    printf("c : %d\n", c);

    d = 2;
    ip = &d;

    e = 8/*ip   /* should give 4 */ ;

    printf("e: %d\n", e);

    f = 0x02;
    g = 0x03;

    h = f << 4 + g;  /* should give 0x23 */

    printf("h: %x\n", h);


    return 0;
}
