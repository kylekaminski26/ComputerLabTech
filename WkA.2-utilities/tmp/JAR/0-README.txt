These files show how to use jar(1) to make a standalone executable
out of Java class files.

NOTE: the "manifest" file is very picky about format.  If you have
an extra blank at the end of your "Main-Class" line, it won't work.
It'll think the blank is part of the classname.
