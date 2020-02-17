/* printf_tricks.c - fun with printf()
 *
 * D Provine, 21 Nov 2014
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char    string[] = "test";
    int     value    = 123;
    float   pi       = 3.14159265;
    double  e        = 2.718281828459045;
    double  huge     = 9.876543e21;
    
    printf("Percent: %%\n\n");

    printf("Strings\n");
    printf("       default: %%s         |%s|\n", string);
    printf("         width: %%8s        |%8s|\n", string);
    printf("     too small: %%2s        |%2s|\n", string);
    printf("      truncate: %%.2s       |%.2s|\n", string);
    printf("          left: %%-8s       |%-8s|\n", string);
    printf("         right: %%8s        |%8s| (default)\n", string);
    printf("variable space: %%*s (6)    |%*s|\n", 6, string);//Right-aligned
    printf("variable space: %%-*s (9)   |%-*s|\n", 9, string);//Left-aligned

    /* To center, you divide the space in two parts.
     * The left has room for some spaces and the string.
     * The right has room for the extra spaces.
     * You print the string in the left part.
     * You print nothing in the right part.
     */
    {
        int width = 9;
        int leftspace  = (width + strlen(string)) / 2;
        int rightspace = (width - strlen(string)) / 2;

        if (leftspace + rightspace < width) {
            rightspace ++; // can't center perfectly with odd numbers
        }//rightspace is a random choice
	
        // Note: next two lines use auto string concatenation!
        // String literals with no punctuation between are automatically
        // combined by the compiler.
        printf("     centering: %%*s%%*s (9) |%*s%*s|"
               " (tricky - read source)\n",
               leftspace, string, // the string goes in the left side
               rightspace, "");   // the right side gets the empty string
    }

    printf("\nIntegers\n");
    printf("       default: %%d       |%d|\n", value);
    printf("         width: %%8d      |%8d|\n", value);
    printf("     too small: %%2d      |%2d|\n", value);
    printf("          left: %%-8d     |%-8d|\n", value);
    printf("variable space: %%*d  (6) |%*d|\n", 6, value);
    printf("variable space: %%*d  (9) |%*d|\n", 9, value);
    printf(" pad with zero: %%08d     |%08d|\n", value);//padded to 8 spaces
    printf("  var. padding: %%0*d (6) |%0*d|\n", 6, value);

    printf("\nFloats and doubles\n");
    printf("       default: %%f              |%f|\n", pi);
    printf("         width: %%15f            |%15f|\n", e);
    printf("     precision: %%15.4f          |%15.4f|\n", pi);
    printf("     too small: %%2f             |%2f|\n", e);
    printf("          left: %%-15f           |%-15f|\n", pi);
    printf("variable space: %%*f   (6)       |%*f|\n", 6, e);
    printf("variable space: %%*.*f (15, 10)  |%*.*f|\n", 15, 10, pi);
    printf("variable space: %%*.*f (18, 11)  |%*.*f|\n", 18, 11, e);
    printf("variable space: %%-*.*f (18, 11) |%-*.*f|\n", 18, 11, pi);
    
    printf("\n note: '17.9f' means 17 total spaces, 9 after decimal,"
           " one for decimal\n");
    printf("                    |<-- 17 spaces -->|\n");
    printf("precision: %%17.9f   |%17.9f| (padding with spaces)\n", pi);
    printf("precision: %%017.9lf |%017.9lf| (padding with zeros)\n", e);
    printf("                    |<seven>|< nine  >|\n");

    printf("\nBig Numbers:\n");
    printf("    default: %%lf         |%lf|\n", huge);
    printf("exp. widths: %%.3e        |%.3e|\n", huge);//e-use Sci Notation
    printf("exp. widths: %%.3f        |%.3f|\n", huge);//f-use float form
    printf("exp. widths: %%.6e        |%.6e|\n", huge);
    printf("exp. widths: %%.6f        |%.6f|\n", huge);

    printf("\nWidths using 'e':\n");
    printf("      width: %%12.3e      |%12.3e|\n", huge);
    printf("      width: %%12e        |%12e|\n", huge);    
    printf("      width: %%32.3e      |%32.3e|\n", huge);
    printf("      width: %%32e        |%32e|\n", huge);
    printf("      width: %%64.32e     |%44.32e|\n", huge);

    
    printf("\n 'g' uses 'f' style if the number is small and 'e' if big:\n");
    printf("    default: %%g        |%.6g|\n", huge);
    printf("    default: %%g        |%.6g|\n", pi);
    printf("exp. widths: %%.6g      |%.6g|\n", huge);
    printf("exp. widths: %%.6g      |%.6g|\n", pi);

    printf("\nWidths using 'g':\n");
    printf("      width: %%12.3g      |%12.2g|\n", huge);
    printf("      width: %%12.3g      |%12.2g|\n", pi);    
    printf("      width: %%32.3g      |%32.2g|\n", huge);
    printf("      width: %%32.3g      |%32.2g|\n", pi);        
    printf("      width: %%64.32g     |%44.32g|\n", huge);    
    printf("      width: %%64.32g     |%44.32g|\n", pi);
    
    printf("\n");
    printf("Escape Chars (read source)\n");
    printf("TAB:      \\t:   a\tb\n");
    printf("ALARM:    \\a:   a\ab\n");
    printf("BACKSPACE \\b:   a\bb\n");
    printf("RETURN    \\r:   a\rb\n");

    return 0;
}
