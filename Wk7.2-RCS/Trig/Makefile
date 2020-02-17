# Makefile for abprint project
#
# DFP

.SUFFIXES:
.SUFFIXES: .c .o

SOURCES = main.c sine.c cosine.c tangent.c
OBJECTS = main.o sine.o cosine.o tangent.o
PROGRAM = trig
COMPILE = gcc
CFLAGS  = -g
LIBRARY = -lm

.c.o:; $(COMPILE) $(CFLAGS) -c $<

$(PROGRAM) : $(OBJECTS)
	$(COMPILE) -o $@ $(CFLAGS) $(OBJECTS) $(LIBRARY)

clean:; /bin/rm -f $(PROGRAM) $(OBJECTS) core

depend: $(SOURCES)
	makedepend $(SOURCES)


# DO NOT DELETE

