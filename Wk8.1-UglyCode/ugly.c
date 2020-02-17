 /* N. L. Tinkham, September 2003

   http://elvis.rowan.edu/~nlt/sigcse/ugly/

   Example of ugly coding style.  (Never, never, never write this way!)

   Problem:  Find and print the most frequently occurring character in
             the input.
   Input is a sequence of characters in standard input, ending in ^D
             on a line by itself.
   There is no prompt, making it easier to take input from a pipe or file.
   The output is
	     Most frequent character: _
       where _ is the most frequent character that was found.
   All characters (except the terminating ^D) are counted, including
             spaces, tabs, and newlines.

*/
   

#include <stdio.h>
 
struct cf
{
	char ch;	/* ch is a character */
	int fr;		/* a number */
};

int process_data(char lc, struct cf cc[], int s);
void ss(struct cf cc[], int s);

int main()
{
	int s = 0;
	struct cf cc[200];
	char lc;
	int i, l;

	/* Loop until end of file */
	while ((lc = getchar()) != EOF)
	{
		l = process_data(lc, cc, s);
		if (l >= 0) {
			cc[l].ch = lc;
			cc[l].fr++;	/* Increment fr */
		} else
		{
			cc[s].ch = lc;
			cc[s].fr = 1;
		s++;
	} }

	/* Call ss function */
 	ss(cc, s); 

	/* Print answer */
	printf("Most frequent character: %c\n", cc[0].ch); 

	return 0;
}

int process_data(char lc, struct cf cc[], int s)
{
	int i;
	for (i = 0; i < s; i++)   
		if (cc[i].ch  == lc)	/* Compare cc[i].ch to lc */
			return i;
			return -1;
}

void ss(struct cf cc[], int s)
{
	int f, i, x;
	struct cf X;

	for (f = 0; f < s - 1; f++) {
		/* Get next x */
		x = f;
		for (i = f + 1; i < s; i++)
			if (cc[i].fr > cc[x].fr)
				x = i;           /* set x to i
				y = i - 1;                        */

			/* Swap values */
			X = cc[f];
			cc[f] = cc[x];
			cc[x] = X;
		}
}
