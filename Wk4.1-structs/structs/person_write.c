/* person_write.c - sample program to write structs
 *
 * dfp
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// our type holds one number and one name
typedef struct {
	int  number;
	char name[20];
} person;

int main()
{
	person Pontiff;
	FILE   *datafile;
	int    howmany;

        // Elements of structs are accessed just as objects
        // in C++ or Java, except that C does not support string
        // assignment.  We have to use "strcpy()".
	Pontiff.number = 266;  // got this from Wikipedia
	strcpy(Pontiff.name, "Francis");

        // Open the file "pope.dat" as a file stream for writing.
        // Quit if the returned pointer is null.
	if ( ( datafile = fopen("pope.dat", "w") ) == NULL ) {
		perror("pope.dat");
		exit(1);
	}

        // From the memory location "Pontiff", copy the number
        // of bytes for one "person", times only 1 entry, onto
        // the stream "datafile".
	howmany = fwrite(&Pontiff, sizeof(person), 1, datafile);

        // Print out how many things we were able to write.
	printf("Wrote %d items of size %d bytes.\n",
               howmany, (int) sizeof(person));

        // Close the file stream.
	fclose(datafile);
	return 0;
}
