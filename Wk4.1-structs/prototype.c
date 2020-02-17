/* prototype.c - function prototype examples
 *
 * d provine
 */

#include <stdio.h>

/* A function looks like this:
 *
 *     return_type function_name (args_list) { statements }
 *
 * The compiler has to know the return type and the arguments
 * in order to ensure the function is called correctly, so either
 * you define the function before you use it (as in "print_hi()"
 * below, or you give it a prototype, which looks like this:
 *
 *     return_type function_name (list_of_argument_types);
 */

/* This function is declared before it is used, so when the compiler
 * finds the call, it'll already know what to do.
 */
void print_hi() { printf("Hi!\n"); }

int main()
{
    int drops;
    int drops_per_acre;
    /*
     * function prototypes are here; the compiler uses them
     * to ensure the calls are correct.
     */
    int do_something( int );
    int count_raindrops( void );

    print_hi();

    drops = count_raindrops();

    drops_per_acre = do_something(drops);

    printf("Drops per acre: %d\n", drops_per_acre);

    return 0;
}

// These functions are declared after they are used, so there has
// to be a prototype up above.
int count_raindrops() 
{
    return 5; /* not very rainy today */
}

int do_something(int drops)
{
    return drops / 1; /* assume one acre */
}
