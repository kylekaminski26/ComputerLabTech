Simple jobs with awk

"awk" is a complete programming language, and you can get 500+ page
books on programmign with it.

Fortunately, you can do some simple things with it in just a few
keystrokes.

An awk program can be put in a file, or it can appear on the command
line.

The program consists of lines like this:

  pattern { action }

where, if the line matches the pattern, then the action is taken.
If no pattern is given, the action is run on every line.  If no
action is given, then the line is printed.

Patterns are boolean expressions.  Slashes can be used if you're
interested in a particular regular expression.

So, for example, these two commands are the same:

  grep '^[Zz].*[Zz]$' /usr/share/dict/words

  awk '/^[Zz].*[Zz]$/' /usr/share/dict/words

(Except that grep is much faster.)


For the action, awk has a number of builtin variables which make it
easy to work with text.

  $0 - entire line
  $1, $2, $3 . . . - first, second, third . . . field on line
  NF - number of fields on line
  $NF - last field on line
  NR - line number

The default delimiter is whitespace, but can be specified with the
"-F" flag.

You can get some of the functionality of cut; these two commands are
the same:

  cut -f 1,3 crew-tabs.txt
    
  % awk '{print $1 "\t" $3}' crew-tabs.txt
  Last	Rank
  Kirk	Captain
  McCoy	Lt.
  Rand	Yeoman
  Uhura	Lieutenant


(Note that awk, left to itself, would stick fields 1 and 3 together
with no spaces or anything in between.)

However, where cut wants to keep things in order, awk doesn't care:

  % awk '{print $3 "\t" $1}' crew-tabs.txt
  Rank	Last
  Captain	Kirk
  Lt.         McCoy
  Yeoman	Rand
  Lieutenant	Uhura

so you can rearrange the fields however you like.  This can be useful
if you have a CSV file exported from a spreadsheet and want the columns
in a different order:

  % awk -F, '{print $3 "," $2 "," $1}' crew.csv
  "Rank","First","Last"
  "Ensign","Pavel","Chekov"
  "Captain","James","Kirk"
  "Lt. Cdr.","Leonard","McCoy"
  "Yeoman","Janice","Rand"
  "Lieutenant","Hikaru","Sulu"
  "Lieutenant","Nyota","Uhura"


Because awk has some built-in variables, you can add columns:

  % awk '{print NR " " $0}' crew-tabs.txt
  1 Last	First	Rank
  2 Kirk	James	Captain
  3 McCoy	Leonard	Lt. Cdr.
  4 Rand	Janice	Yeoman
  5 Uhura	Nyota	Lieutenant

Except that we just counted the line with the column headings.
We only want to count the crew.  So we can take advantage of the
boolean patterns:

  % awk 'NR > 1 {print NR - 1 " " $0}' crew-tabs.txt
  1 Kirk	James	Captain
  2 McCoy	Leonard	Lt. Cdr.
  3 Rand	Janice	Yeoman
  4 Uhura	Nyota	Lieutenant

This command means "if the line number (NR) is greater than 1,
then print the line number minus 1, and then a space, and then
the whole line".

Unfortunately, we lost the column headings.  But we can fix that,
since semicolons separate commands in our program:

  % awk 'NR == 1 {print "# " $0} ; NR > 1 {print NR - 1 " " $0}' crew-tabs.txt
  # Last	First	Rank
  1 Kirk	James	Captain
  2 McCoy	Leonard	Lt. Cdr.
  3 Rand	Janice	Yeoman
  4 Uhura	Nyota	Lieutenant

For line one, print a number sign and then the line.  For all the
other lines, print the line number minus one, and then the entire line.


Also, you can use NF to look for missing data in a file; suppose there's
a crewmember whose first name is missing:

  % cat crew-error.csv
  "Last","First","Rank"
  "Chekov","Pavel","Ensign"
  "Kirk","James","Captain"
  "McCoy","Leonard","Lt. Cdr."
  "Rand","Janice","Yeoman"
  "Sulu","Hikaru","Lieutenant"
  "Uhura","Nyota","Lieutenant"
  "Spock","Commander"
  % awk -F, 'NF != 3 { print NR ": " $0 }' crew-error.csv
  8: "Spock","Commander"

The only line without three fields is #8, because we didn't have Spock's
first name.

However, we can still rearrange the fields we have, because NF is the
number of fields, so $NF is the last field on the line.

  % awk -F, '{ print $NF "," $1 }' crew-error.csv
  "Rank","Last"
  "Ensign","Chekov"
  "Captain","Kirk"
  "Lt. Cdr.","McCoy"
  "Yeoman","Rand"
  "Lieutenant","Sulu"
  "Lieutenant","Uhura"
  "Commander","Spock"

Since the rank is the last field, and the last name is the first one,
we can still make "rank lastname" columns, even where the first name
is missing.

(NOTE: it is a common error to use $NF when you want NF.)


Using awk, create a list like this:

   Rank First Last
   Ensign Pavel Chekov
   Captain James Kirk
   Lt. Cdr. Leonard McCoy
   Yeoman Janice Rand
   Lieutenant Hikaru Sulu
   Lieutenant Nyota Uhura

