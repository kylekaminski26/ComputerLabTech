Using "paste" to connect files

Paste connects two files together, line by line, with a tab
between each line.
(Note "-e" flag to cat(1), showing no whitespace at end of lines.)

    % cat -e usernames.txt
    kristine$
    lister$
    ajr$
    % cat -e names.txt
    Kochanski, Kristine$
    Lister, Dave$
    Rimmer, Arnold$
    % paste usernames.txt names.txt
    kristine        Kochanski, Kristine
    lister  Lister, Dave
    ajr     Rimmer, Arnold

(Because 'kristine' is 8 characters, the tab inserted afterwards
pushes Lt Kochanski's name over to the next tab stop.)


The order that you put the files in determines which one appears
first on the line:

    % paste names.txt ranks.txt 
    Kochanski, Kristine     Lieutenant
    Lister, Dave    Technician (3rd)
    Rimmer, Arnold  Technician (2nd)
    % paste ranks.txt names.txt 
    Lieutenant      Kochanski, Kristine
    Technician (3rd)        Lister, Dave
    Technician (2nd)        Rimmer, Arnold
    %

(Again, notice that the tabs don't make neat columns when
the fields run past the length of a tab.)


With the "-d" flag, you can set the delimiter.
(Note backslash before pipe character, so shell doesn't
try to make a pipe out of the filenames.)

    % paste -d \| usernames.txt names.txt
    kristine|Kochanski, Kristine
    lister|Lister, Dave
    ajr|Rimmer, Arnold
    % 

If you want to create comma-separated strings, which is a
standard way to make data portable, you can use sed(1) to
add quotes and commas (note use of \ to break command so it
fits nicely in this file):

    % paste -d \| usernames.txt names.txt \
    ? | sed -e 's/^/"/' -e 's/|/","/' -e 's/$/"/'
    "kristine","Kochanski, Kristine"
    "lister","Lister, Dave"
    "ajr","Rimmer, Arnold"
    % 

paste(1) make the usernames, a pipe, and then the real names.
sed(1) replaces the beginning of the line with a quote, the pipe
character with ",", and then the end of the line with a quote.
(Remember that if you want sed to do multiple expressions, you have
to use the "-e" flag before each one.)


You can combine multiple files, using either the same delimiter:

    % paste -d '|' usernames.txt names.txt ranks.txt
    kristine|Kochanski, Kristine|Lieutenant
    lister|Lister, Dave|Technician (3rd)
    ajr|Rimmer, Arnold|Technician (2nd)
    %

Or, if you specify more than one character, using different
delimiters for each point where files join:

    % paste -d '|-' usernames.txt names.txt ranks.txt 
    kristine|Kochanski, Kristine-Lieutenant
    lister|Lister, Dave-Technician (3rd)
    ajr|Rimmer, Arnold-Technician (2nd)
    %

If you're after comma-separated values with multiple columns,
don't forget the trailing "g" option to sed ("g" for "global",
as in "along the entire length of this line"):

    % paste -d '|' usernames.txt names.txt ranks.txt | \
    ? sed -e 's/^/"/' -e 's/|/","/g' -e 's/$/"/'
    "kristine","Kochanski, Kristine","Lieutenant"
    "lister","Lister, Dave","Technician (3rd)"
    "ajr","Rimmer, Arnold","Technician (2nd)"
    % 



Now, with cut and paste, we can rearrange columns any way we like.

Using the "lnames.txt", "fnames.txt", and "ranks.txt" from the Cut
folder, create a list that looks like this, with only spaces between
the fields:

   Rank First Last
   Ensign Pavel Chekov
   Captain James Kirk
   Lt. Cdr. Leonard McCoy
   Yeoman Janice Rand
   Lieutenant Hikaru Sulu
   Lieutenant Nyota Uhura

