Reading binary data from files using command-line tools.

The program "od" stands for "octal dump", but can also use
other formats.

It is probably least confusing to use the flags "-ctx1".  The "c"
flag means "show ASCII characters", and the "tx1" means use the format
"one hexadecimal byte at a time".
You will get output like this (note two shell commands are here):

% cat file1.txt 
This is file1.txt.

This is line 3.
% od -ctx1 file1.txt
0000000   T   h   i   s       i   s       f   i   l   e   1   .   t   x
         54  68  69  73  20  69  73  20  66  69  6c  65  31  2e  74  78
0000020   t   .  \n  \n   T   h   i   s       i   s       l   i   n   e
         74  2e  0a  0a  54  68  69  73  20  69  73  20  6c  69  6e  65
0000040       3   .  \n
         20  33  2e  0a
0000044
% 

Looking in the ASCII table, you can see 0x54 is "T", and 0x68 is "h",
and so on.


The output from the "person_write.c" program, "pope.dat", looks like
this:

% od -ctx1 pope.dat
0000000  \n 001  \0  \0   F   r   a   n   c   i   s  \0  \0  \0  \0  \0
         0a  01  00  00  46  72  61  6e  63  69  73  00  00  00  00  00
0000020 020  \a   @  \0  \0  \0  \0  \0
         10  07  40  00  00  00  00  00
0000030
% 

The Pope's number (266) is stored in four bytes, 0x0000010a
(0x10a = 256 + 10 = 266).  Because Elvis has a little-endian CPU,
the bytes are reversed, which is why the output is 0a 01 00 00.

As with the "file1.txt", the rest of the output can be looked up in
the ASCII table: 0x46 is "F", 0x72 is "r", and so on.  Note that the
string ends with a null character, \0, and everything after the null
character is just random garbage.  It might be different every time
the program is run.

When the string is declared, it's all random garbage (C does not
clear the array automatically).  When we put "Francis" in it, those
positions are set, and then a null is appended.  But that only sets
those 8 positions in the array.  The other 12 are left as they were
when the program started, and whatever that is gets written to the
disk.
