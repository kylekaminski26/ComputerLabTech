STRUCTURE READING HOMEWORK

The file "pres-SQ.dat" was created this way:

    [elvis 62] ./multiprez pres-SQ.dat
    1 GW
    4 JM
    9 WHH
    16 AL
    25 WM
    36 LBJ
    0       <- that's the sentinel value which ended input
    1
    1
    1
    1
    1
    1       <- this is a "1" for every president as written


The file "pres1980.dat" was created this way:

    [elvis 62] ./multiprez pres1980.dat
    39 JEC
    40 RWR
    41 GHWB
    0       <- that's the sentinel value again
    1
    1
    1       <- three presidents, three "1"s.


To see what's in the files, you can use "od"

    [elvis 71] od -ctx1 pres-SQ.dat
    0000000   G   W  \0   ? 377 001   J   M  \0  \0  \0 004   W   H   H  \0
             47  57  00  3f  ff  01  4a  4d  00  00  00  04  57  48  48  00
    0000020 230  \t   A   L  \0 177  \0 020   W   M  \0   8   1 031   L   B
             98  09  41  4c  00  7f  00  10  57  4d  00  38  31  19  4c  42
    0000040   J  \0 302   $
             4a  00  c2  24
    0000044
    [elvis 72]


The struct for a person in the program has 5 bytes for characters
(4 initials and a null) and one byte for the number.  So the first
two lines of output:
   
  0000000   G   W  \0   ? 377 001   J   M  \0  \0  \0 004   W   H   H  \0
           47  57  00  3f  ff  01  4a  4d  00  00  00  04  57  48  48  00

shows you the first 16 bytes, starting at 0.  If you look up the
values of the characters in the ASCII table (available on Elvis by
typing "man ascii", or on various websites), you'll see that 0x47
is the hex value of "G", and 0x57 is the hex value of "W".  The
next byte, 0x00, printed "\0", is the null character that ends the
strings.  The next two bytes are random garbage, because the array
for characters is five bytes long and we only used three of them.
C does not clear arrays, so those bytes were never changed.  When the
file was written, those bytes were copied to the disk.  The next byte
is the value 1, because Washington was President #1.

The next six bytes: 4a 4d 00 00 00 04

are "J", "M", null, two bytes of garbage, and then value 4.

The next four bytes: 57 48 48 00

are WHH, a null, and that's the first 16 bytes of the file.

The next pair of lines:

    0000020 230  \t   A   L  \0 177  \0 020   W   M  \0   8   1 031   L   B
             98  09  41  4c  00  7f  00  10  57  4d  00  38  31  19  4c  42

picks up with: 98 09, which is one byte of garbage (we only used 4 bytes
of the 5-byte array for initials) and the number 9, because William
Henry Harrison was President #9.  (Notice that it prints out "\t" for
the 0x09; the ASCII value for the tab character is 0x09, and the "-c"
flag says we want the character values for each byte.  The program is
just reading bytes, and has no way of knowing which ones are used as
numbers by whatever other program might read the data.)

The rest of the file is similar, but note that when we get to
Lincoln, President #16, his byte is "10", because this is in
hexadecimal, not decimal, and the same applies to President 25
and 36.


For the 1980s file, the same thing applies:

    [elvis 72]  od -ctx1 pres1980.dat
    0000000   J   E   C  \0 377   '   R   W   R  \0  \0   (   G   H   W   B
             4a  45  43  00  ff  27  52  57  52  00  00  28  47  48  57  42
    0000020  \0   )
             00  29
    0000022

4a 45 43 are "JEC", there's a null, "ff" is just garbage, and "27"
means "2 * 16 + 7", which is 39.  (As with the tab character, od
prints the single quote because it sees these bits as just bits.
It has no way of knowing which ones are characters and which ones
are numeric data.)

When you write a file, that's what actually happens: the bits go on
the disk.


For the homework, you have to use "fread()" and the correct data
structure to read the bits off the disk and print out the values.


Here is the output of my program on the three files in this folder
(presidents from the 1980s, presidents whose numbers are perfect
squares, and presidents from Massachusetts), plus error-checking
for a file that doesn't exist:

    [elvis 81] ./multiread pres1980.dat
    Num  Inits
     39   JEC
     40   RWR
     41   GHWB
    End of data
    [elvis 82] ./multiread pres-SQ.dat
    Num  Inits
     1   GW
     4   JM
     9   WHH
     16   AL
     25   WM
     36   LBJ
    End of data
    [elvis 83] ./multiread presMA.dat
    Num  Inits
     2   JA
     6   JQA
     30   JCC
     35   JFK
    End of data
    [elvis 84] ./multiread foo
    foo: No such file or directory
    [elvis 85]

