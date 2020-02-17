/* model.c -- actual clock part of the clock project
 *
 * Darren Provine, 17 July 2009
 *
 * Copyright (C) Darren Provine, 2009-2019, All Rights Reserved
 */

#include "clock.h"


/* MODEL */

/* The offset and timezone are properly part of the model, so they
 * go in this module, with getters and setters.
 */

int offset = 0;

int get_offset()
{
    return offset;
}

void set_offset(int new_offset)
{
    offset = new_offset;
}


// If you do timezone stuff, it goes in here too.



/* This function is called when the timer ticks.
 * Then it calls the newtime() function in the controller.
 *
 * Note we ignore the argument!
 * sigaction() arranges to pass us the signal that caused the function
 * to be called, so you can use one signal handler for multiple signals.
 * But we only catch one signal, so no need to worry about it.
 */
void tick(int sig)
{
    time_t       now;
    struct tm   *dateinfo;  // localtime() returns a pointer, so it
                            // allocates space.  We just need a pointer.

    /* get current time into "struct tm" object */
    (void) time(&now);
    now += offset;
    dateinfo = localtime( &now );

    /* tell controller there's new time data */
    new_time(dateinfo);
}


/* Set up an interval timer for our clock.
 * This is the model; it's what actually measures real time passing.
 * When the interval is over, notify tick(), which is part of the
 * controller for this program.
 */
void start_timer()
{
    struct itimerval interval; // interval object
    struct sigaction new_action, old_action;  // signal actions

    /* See the manual entry for signal.h(0P) for a list of all
     * signals. */

    // blank out the signal mask
    sigemptyset( &new_action.sa_mask );
    // clear flags (our application is pretty simple)
    new_action.sa_flags = 0;
    // set tick() as the signal handler when we get the timer signal.
    new_action.sa_handler = tick;
 
    /* sigaction takes a pointer as an argument, so you have to
     * allocate space.  The declaration of new_action() up above
     * has no star - that's the actual object, not just a pointer.
     */
    if ( sigaction(SIGALRM, &new_action, &old_action) == -1 ) {
        perror("Could not set new handler for SIGALRM");
        exit(1);
    }


    /* set interval to 1.000 seconds. */
    interval.it_value.tv_sec = 1;
    interval.it_value.tv_usec = 0;
    interval.it_interval = interval.it_value;

    /* set a timer for the real time clock using the interval object */
    /* NOTE: takes a pointer, so no * in our declaration of "interval */
    setitimer(ITIMER_REAL, &interval, NULL);
}
