/* math2.c
 */

#include <stdio.h>

int main()
{
    int a = 4, b = 5;
    int addem(int, int);

    printf("Sum: %d\n", addem(a, b));

    return 0;
}

int addem(int x, int y)
{
    return x + y;
}
