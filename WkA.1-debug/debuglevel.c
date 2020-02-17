/* debuglevel.c - show debugging levels
 *
 * D Provine, 10 March 2015
 *
 * This program repeats its command-line arguments,
 * optionally with a newline, optionally in reverse order.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char bugaddress[]="kilroy@elvis.rowan.edu";

// version -- say which version this is and exit
// (note simple output; you could also print the rcsid too)
void version()
{
    fprintf(stderr, "debuglevel version 1\n");
    exit(0);
}

// usage -- print brief summary and instructions
void usage(char *progname)
{
    fprintf(stderr, "This program repeats is arguments.\n");
    fprintf(stderr, "Usage: %s [-rnDvh] \n", progname);
    fprintf(stderr, "  -r : reverse order\n");
    fprintf(stderr, "  -n : no newline at end\n");
    fprintf(stderr, "  -D : turn on debugging (more Ds = more messages) \n");
    fprintf(stderr, "       maximum debug level is 3 \n");
    fprintf(stderr, "  -v : show version information\n");
    fprintf(stderr, "  -h : this help message\n");
    fprintf(stderr, "report bugs to %s \n", bugaddress);
    exit (0);
}

int DebugLevel = 0;

int main(int argc, char *argv[])
{
    int letter;       // option character
    int reverse = 0;  // if nonzero, print in reverse order
    int newline = 1;  // if nonzero, add a new line
    int start;        // start printing with this word
    int end;          // end printing with this word
    int step;         // 1 if printing normal, -1 if reversing
    int i;
    int word;

    // loop through all the options; getopt() can handle together or apart
    while ( ( letter = getopt(argc, argv, "Dvhnr")) != -1 ) {
        switch (letter) {
        case 'n':  newline = 0;            break;
        case 'r':  reverse = 1;            break;
        case 'D':  DebugLevel ++;          break;
        case 'v':  version();              break;
        case 'h':  usage(argv[0]);         break;

        case '?':  // unknown flag; fall through to next case
        default:   // shouldn't happen, but Just In Case
            // note that getopt() warns about the unknown flag
            fprintf(stderr, "run \"%s -h\" for help\n", argv[0]);
            exit(1);
        }
    }
    // All the flags have been scanned.
    // "optind" is now the index of the first non-option item

    if (DebugLevel >= 3) {
        printf("All command-line arguments as scanned:\n");
        for (i = 0; i < argc; i++) {
            printf("   word %3d was '%s'\n", i, argv[i]);
        }
    }
 
    if (DebugLevel >= 2) {
        printf("variable 'newline': %d\n", newline);
        printf("variable 'reverse': %d\n", reverse);
    }

    // loop through the words
    if (optind < argc) {
        if (DebugLevel >= 1) {
            printf("# words to be printed: %d\n", argc - optind);
        }
        if (reverse) {
            start = argc - 1;
            end   =  optind;
            step  = -1;
        } else {
            start = optind;
            end   = argc - 1;
            step  = 1;
        }

        if (DebugLevel >= 2) {
            printf("starting at: %d\n", start);
            printf("stopping at: %d\n", end);
            printf("stepping by: %d\n", step);
        }

        for (word = start; word != end + step; word += step) {
            printf("%s ", argv[word]);
        }
        if (newline)
            printf("\n");

    } else {
        if (DebugLevel >= 1) {
            printf("No non-options on the command line.\n");
        }
    }

    return 0;
}
