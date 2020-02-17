MISCELLANEOUS NETWORK AND OTHER UTILITIES

FTP - file transfer protocol.  Directly connect to another machine and
      send files using sftp.

TAR - tape archiver.  Take an entire directory tree, preserve filetimes
      and permissions, bundle it up into a single file.

JAR - Java archiver.  Turn a Java progam into an executable that can
      be run from the command line, or into an app that can be run from
      a GUI just by double-clicking.


SAMPLE OF USING LIBRARY PACKAGES

qsort - program to sort data using the qsort() library function.


Directories for making samples:

dropoff, tmp - should be empty at start of lab


COMMAND SAMPLES

1) to make a tar file of the qsort folder:

     tar czvf qsort.tgz Qsort

   Bundles the "Qsort" folder into the file "qsort.tgz".
   Commands: "c" - Create new
             "z" - compress with gZip
             "v" - Verbose (list all files as added)
             "f" - use a File, not a tape drive

   Usually, tar files end with ".tar", and gnuzip files end with ".gz".
   You may sometimes see ".tar.gz" on the end of a file, or ".tgz" as
   the shorthand version.


2) to send the file to another server (we'll just send it to Elvis):

     sftp USERNAME@elvis.rowan.edu
     (enter password)

     cd LABTECH/Wk9.2-utilities/dropoff

     put qsort.tgz

     quit


3) to unpack the file:

     cd dropoff
     tar xzvf qsort.tgz

     Unpacks "qsort.tgz".  Commands are the same as for packing, except
     "x" means eXtract, where "c" means "create".



