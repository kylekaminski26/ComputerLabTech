//
//  structTest.c
//
//  Created by Jacob Levy on 2/10/19.

/**A file to demonstrate how structure padding works in C structs.
 *And how to pack the structures efficiently.
 *- Jake Levy
 */

#include <stdio.h>
struct {

    char b;
    int a;
    char c;

} example;


int main(int argc, const char * argv[])
{
    if (argc > 1) {
        printf("This program takes no arguments");
        return 2;
    }


    int answerSize;
    char q = 'q';

    printf("Ints are %lu bytes\n", sizeof(answerSize) );
    printf("Chars are %lu bytes\n", sizeof(q) );


    printf("\n\nSo how big should a struct be, if it is comprised of a char, int, and a char, in that order?\n");

    char answer[10];
    fgets(answer, sizeof(answer), stdin);
    sscanf(answer, "%d", &answerSize);

    example.a = answerSize;
    example.b = q;
    example.c = q;

    if ( answerSize == sizeof(example) ) {

        printf("\nCorrect!");
        printf("\n\n-------------------------\n\n Size of Struct: %lu\n\n",
               sizeof(example) );
        return 0;
    }

    else {
        printf("\n\n-------------------------\n\n Size of Struct: %lu",
               sizeof(example) );
        printf("\n\n\nNope, looks like the answer is %lu bytes\n",
               sizeof(example) );

    }

    return 1;

}
