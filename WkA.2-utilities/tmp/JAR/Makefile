# Makefile for automatically making JAR files
#          and wrapping them in BASH scripts
#
# Darren Provine, 3 February 2007
#                 9 November 2017

PROGRAM = jartest
JARFILE = jartest.jar
SOURCES = jartest.java
CLASSES = jartest.class
MANIFEST= jartest.manifest
WRAPPER = stub.bash

.SUFFIXES:
.SUFFIXES: .java .class

$(PROGRAM) : $(CLASSES) $(MANIFEST)
	jar cmf $(MANIFEST) $(JARFILE) $(CLASSES)
	cat $(WRAPPER) $(JARFILE) > $(PROGRAM)
	chmod +x $(PROGRAM)


.java.class: ; javac $<

clean:; /bin/rm -f $(CLASSES) $(PROGRAM)
