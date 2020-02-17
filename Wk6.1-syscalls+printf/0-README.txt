Files In This Folder

       myname.c - print user's name

       mystat.c - print some stuff like stat(), but our own version

         exec.c - program becomes another program

         fork.c - program makes child process

   forkprint.c  - program makes child process, both copies run loop

   testSig.c - program makes a child process, starts loops, SIGILL to child

These three combine fork() to create a child process, and then
exec() to have the child process become another program (ls).
This is essentially what the shell does every time you run a
command:

   ls-shell-wait.c - parent process waits
  ls-shell-wait2.c - parent process waits; child finishes first
  ls-shell-wait3.c - parent process does not wait (similar to shell
                     background mode)


   printf_tricks.c - various things you can do to format output
                     printf() is quite flexible

        README.txt - this file
