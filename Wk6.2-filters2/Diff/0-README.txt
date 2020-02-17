Using diff(1) to compare files.


diff takes two filenames and shows the differences.

    % diff hello.c hello2.c
    5a6
    >
    8c9
    <     printf("hello world!\n");
    ---
    >   printf("Hello world!\n");
    10c11
    <     return 0;
    ---
    >   return 0;

"5a6" means "after line 5, add the line below" (which is just a blank
line), and "8c9" means "change line 8 in this file to line 9 in that
file.

The "<" symbol is supposed to be an arrow pointing left, for the file
named first on the command line, and ">" is an arrow pointing right.

Here, it's telling us that the two "return" lines are different because
they have different numbers of spaces.  For programs, that's not usually
important.

You can tell it to ignore different numbers of blanks with -b:

    % diff -b hello.c hello2.c
    5a6
    >
    8c9
    <     printf("hello world!\n");
    ---
    >   printf("Hello world!\n");


These lines still come out because of the h/H difference; you can tell it
to ignore case with -i:

    % diff -bi hello.c hello2.c
    5a6
    >

At this point, we can be pretty sure that these two are the same program.
(Sometimes this is referred to as "diff identical".)



There are some different formats; for context, you can use -c:

    % diff -bic hello.c hello2.c
    *** hello.c	2018-10-09 19:00:14.765628950 -0400
    --- hello2.c	2018-10-09 19:00:14.765628950 -0400
    ***************
    *** 3,8 ****
    --- 3,9 ----

      #include <stdio.h>

    +
      int main()
      {
        printf("Hello world!\n");

So instead of "5a6", meaning "after line 5, add line 6", you just
get the file with a "+", meaning this line was added.


For side-by-side, you can use "-y" (with "-W" to limit width):

    % diff -yW 80 hello.c hello2.c
    /* hello.c				/* hello.c
     */					 */

    #include <stdio.h>			#include <stdio.h>

    				      >
    int main()				int main()
    {					{
        printf("hello world!\n");     |   printf("Hello world!\n");

        return 0;		      |	  return 0;
    }					}

The left is the file named on the left, and the right is what's
been added (">") or what's been changed ("|") to make the file on the
right.


This works with all the other flags too; if we add -b and -i, we get
just the one added line flagged:

    % diff -biyW 80 hello.c hello2.c
    /* hello.c				/* hello.c
     */					 */

    #include <stdio.h>			#include <stdio.h>

    				      >
    int main()				int main()
    {					{
        printf("hello world!\n");	  printf("Hello world!\n");

        return 0;			  return 0;
    }					}




Note that diff is pretty smart: instead of doing a simple line-by-line
comparison, which would report lots of different lines between two
nearly identical programs, it figures out that one line has been added,
and the "int main()" and so on are the same except that it's been moved
down one line in the second file.

It's not super smart, though; two programs which are identical except
that blocks of code have been moved will show some of the blocks as
insertions and deletions, instead of flagging that the lines are the
same but have been moved.

    % diff math1.c math2.c
    1c1
    < /* math1.c
    ---
    > /* math2.c
    6,11d5
    <
    < int addem(int x, int y)
    < {
    <     return x + y;
    < }
    <
    21a16,19
    > int addem(int x, int y)
    > {
    >     return x + y;
    > }
