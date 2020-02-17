Selecting Columns with "cut"

The cut(1) command allows you to select portions of lines from
files, by either character position or by field.  This file has
last name, first name, and rank, on 7-space columns (using
spaces, not tabs):

    % cat crew.txt
    Last   First   Rank
    Kirk   James   Captain
    McCoy  Leonard Lt. Cdr.
    Rand   Janice  Yeoman
    Uhura  Nyota   Lieutenant
    %

If you just want the initials, you can select byte 1 and byte 8:

    % cut -b1,8 crew.txt
    LF
    KJ
    ML
    RJ
    UN
    %

If you want them in the other order, you might try to reverse
the list:

    % cut -b8,1 crew.txt
    LF
    KJ
    ML
    RJ
    UN
    %

But it doesn't do that.  You might also try to make more than one
specification:

    % cut -b8 -b1 crew.txt
    cut: only one type of list may be specified
    Try 'cut --help' for more information.
    %

But it doesn't do that either.


You can specify byte ranges; if you want last name and rank:

    % cut -b1-7,15-22 crew.txt
    Last    Rank
    Kirk    Captain
    McCoy   Lt. Cdr
    Rand    Yeoman
    Uhura   Lieuten
    %

Note that we only got 7 letters for the rank, cutting some of them
off.  Being more careful, we can grab more characters:

    % cut -b1-7,15-25 crew.txt
    Last    Rank
    Kirk    Captain
    McCoy   Lt. Cdr.
    Rand    Yeoman
    Uhura   Lieutenant
    %

Also note that this only works because the fields were exactly spaced
out.  If tabs had been used to make our columns, the "-b" flag would
get us strange results, because it counts exact bytes:

    % cat crew-tabs.txt 
    Last    First   Rank
    Kirk    James   Captain
    McCoy   Leonard Lt. Cdr.
    Rand    Janice  Yeoman
    Uhura   Nyota   Lieutenant
    % cut -b1-7,15-22 crew-tabs.txt 
    Last    Fik
    Kirk    Jatain
    McCoy   LLt. Cdr.
    Rand    Jaoman
    Uhura   Neutenant
    %


Fortunately, cut(1) can also work on fields with delimeters, solving
both the problem of "chopping off part of a longer entry" and "grabbing
wrong characters".  The default delimiter is tab, so we can do this:

    % cut -f 1,3 crew-tabs.txt
    Last    Rank
    Kirk    Captain
    McCoy   Lt. Cdr.
    Rand    Yeoman
    Uhura   Lieutenant
    %

And it gets columns 1 and 3, regardless of length.


A standard format, used because it's simple and highly portable,
is comma-separated values:

    % cat crew.csv 
    "Last","First","Rank"
    "Kirk","James","Captain"
    "McCoy","Leonard","Lt. Cdr."
    "Rand","Janice","Yeoman"
    "Uhura","Nyota","Lieutenant"
    %

This lets us have spaces in our fields, and make our fields any
length.  Many spreadsheet programs can automatically import CSV
files, or export data in CSV format.  There are also library
packages for many programming languages to make working with CSV
files easy on the programmer.

To work with this format in cut(1), you just specify that the
delimiter is a comma:

    % cut -d ',' -f1,2 crew.csv
    "Last","First"
    "Kirk","James"
    "McCoy","Leonard"
    "Rand","Janice"
    "Uhura","Nyota"
    % cut -d ',' -f1,3 crew.csv
    "Last","Rank"
    "Kirk","Captain"
    "McCoy","Lt. Cdr."
    "Rand","Yeoman"
    "Uhura","Lieutenant"
    % cut -d ',' -f1 crew.csv
    "Last"
    "Kirk"
    "McCoy"
    "Rand"
    "Uhura"
    % 

If you decide you don't want the quotes, those are easy to clean up
with sed(1).  Remember the "g" option, which causes substitions to
happen globally across the line, not just on the first occurrence:

    % cut -d, -f1 crew.csv | sed 's/"//g'
    Last
    Kirk
    McCoy
    Rand
    Uhura
    %



However, we still can't rearrange our fields.  But we can with another
tool, called "paste".  In order to that, though, we'll need to cut
this data into separate files.


Using cut, make "lnames.txt" with the last names, "fnames.txt" with
the first names, and "ranks.txt" with the ranks of the crewmembers.

