# Makefile for AB Project
#
# D Provine and a room of sleepy people
# 30 October 2018

# Makefile contents:
#
#    TARGET : WHAT YOU NEED
#     - TAB -> shell commands

PROGRAM = abprint
SOURCES = aprint.c bprint.c main.c
OBJECTS = aprint.o bprint.o main.o
INCLUDE = -I/usr/lib/gcc/x86_64-redhat-linux/3.4.6/include
CFLAGS  = -Wall -O

.SUFFIXES:
.SUFFIXES: .c .o

.c.o : ; cc $(CFLAGS) -c $<

$(PROGRAM) : $(OBJECTS)
	cc -o $@ $(CFLAGS) $(OBJECTS)

clean : ; /bin/rm -f $(PROGRAM) $(OBJECTS)

depend : $(SOURCES)
	@ echo 
	@ echo "Ignore warning about bits/libc-header-start.h"
	@ echo
	makedepend $(INCLUDE) $(SOURCES)

# DO NOT DELETE

aprint.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
aprint.o: /usr/include/features.h /usr/include/stdc-predef.h
aprint.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
aprint.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
aprint.o: /usr/lib/gcc/x86_64-redhat-linux/3.4.6/include/stddef.h
aprint.o: /usr/lib/gcc/x86_64-redhat-linux/3.4.6/include/stdarg.h
aprint.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
aprint.o: /usr/include/bits/types/__fpos_t.h
aprint.o: /usr/include/bits/types/__mbstate_t.h
aprint.o: /usr/include/bits/types/__fpos64_t.h
aprint.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
aprint.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
aprint.o: /usr/include/bits/sys_errlist.h
bprint.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
bprint.o: /usr/include/features.h /usr/include/stdc-predef.h
bprint.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
bprint.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
bprint.o: /usr/lib/gcc/x86_64-redhat-linux/3.4.6/include/stddef.h
bprint.o: /usr/lib/gcc/x86_64-redhat-linux/3.4.6/include/stdarg.h
bprint.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
bprint.o: /usr/include/bits/types/__fpos_t.h
bprint.o: /usr/include/bits/types/__mbstate_t.h
bprint.o: /usr/include/bits/types/__fpos64_t.h
bprint.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
bprint.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
bprint.o: /usr/include/bits/sys_errlist.h
