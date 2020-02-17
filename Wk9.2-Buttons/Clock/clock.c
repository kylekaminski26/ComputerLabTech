/* clock.c -- controller part of the clock project
 *
 * Darren Provine, 17 July 2009
 *
 * Copyright (C) Darren Provine, 2009-2019, All Rights Reserved
 */

#include "clock.h"

/* CONTROLLER */

static char bugaddress[]="kilroy@elvis.rowan.edu";

// version -- say which version this is and exit
// (note simple output; you could also print the rcsid too)
void version()
{
    fprintf(stderr, "simple clock version 3\n");
    exit(0);
}

// usage -- print brief summary and instructions
void usage(char *progname)
{
    fprintf(stderr, "This program displays a realtime clock.\n");
    fprintf(stderr, "Usage: %s [-avh] [-o number]\n", progname);
    fprintf(stderr, "  -a    : am/pm instead of 24 hour\n");
    fprintf(stderr, "  -l    : use simulated LED display\n");
    fprintf(stderr, "  -o #  : offset the time by # seconds \n");
    fprintf(stderr, "  -v    : show version information\n");
    fprintf(stderr, "  -h    : this help message\n");
    fprintf(stderr, "report bugs to %s \n", bugaddress);
    exit (0);
}

// These store when the different modes end
int test_count = 0;
int date_count = 0;
int mode_cycles = 20;

void process_key(keybits KeyCode)
{
    void stop_clock(void);
    int KeyRow, KeyCol;
    int view_props;
    
    if ( ( KeyCode & 0xff00 ) == 0 ) {  // no ASCII code, so mouse hit

        // TODO: figure out KeyRow and KeyCol

        KeyRow = 0; KeyCol = 0; // right now any click goes to 24hr mode

        if (KeyRow == 0) {
            switch (KeyCol) {
                case 0: // 24-hour mode
                    view_props = get_view_properties();
                    view_props &= ( ~ AM_PM );
                    set_view_properties (view_props);
                    break;
                case 1:
                    view_props = get_view_properties();
                    view_props |= ( AM_PM );
                    set_view_properties (view_props);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    stop_clock();
                    break;
            }
        } else if (KeyRow == 1) {
            switch (KeyCol) {
                case 0:
                    break;
            }
        }        
    } else { // keystroke
        // figure out ASCII value from first 8 bits
        // right now any key goes to 24-hour mode
        KeyCode = '2';
        switch( KeyCode ) {
            case '2':
                view_props = get_view_properties();
                view_props &= ( ~ AM_PM );
                set_view_properties (view_props);
                break;
            case 'a':
                view_props = get_view_properties();
                view_props |= ( AM_PM );
                set_view_properties (view_props);
                break;
            case 'd':
                break;
            case 't':
                break;
            case 'q':
                stop_clock();
                break;
        }
    }

    // force update when keys are hit
    tick(0);
}

void stop_clock()
{
    end_display();
    exit(0);
}

int main(int argc, char *argv[])
{
    int letter;  // option character

    // next three are for setting view properties
    int view_props;
    int ampm = 0;     // default to 24hr
    int LED  = 0;     // default to text

    // loop through all the options; getopt() can handle together or apart
    while ( ( letter = getopt(argc, argv, "alo:vh")) != -1 ) {
        switch (letter) {
            case 'a':  ampm = 1;               break;
            case 'l':  LED  = 1;               break;
            case 'o':  set_offset (atoi(optarg));  break;
            case 'v':  version();              break;
            case 'h':  usage(argv[0]);         break;

            case '?':  // unknown flag; fall through to next case
            default:   // shouldn't happen, but Just In Case
                       // note that getopt() warns about the unknown flag
                  fprintf(stderr, "run \"%s -h\" for help\n", argv[0]);
                  exit(1);
        }
    }

    // All the flags have been scanned.
    // "optind" is now the index of the first non-option item

    // set view properties; default is "24 hour text mode"
    view_props = 0;  // all bits off
    if ( ampm )
        view_props = AM_PM;
    if ( LED )
        view_props |= LED_MODE; // note |= to switch on a bit

    set_view_properties (view_props);

    if (LED) { // set up the fancy display
        start_display();
        // has to be exactly 78 chars
        set_title_bar("----------------------------"
                      " kilroy was here at: "
                      "----------------------------");
        register_keyhandler(process_key);

        // turn on some keys in row 2
        set_key_text(0, "blurfl");
        set_key_text(1, "foobar");
    }

    /* get the model running */
    start_timer();

    while (1) {
        if ( LED )
            get_key(); /* read keys if in LED mode */
        else
            pause();
    }

    /* no return because never reached */
}


/* This function is called is called by the model when a new
 * time is ready for display.
 *
 * Note we ignore the argument!
 * sigaction() arranges to pass us the signal that caused the function
 * to be called, so you can use one signal handler for multiple signals.
 * But we only catch one signal, so no need to worry about it.
 */
void new_time(struct tm *dateinfo)
{
    int view_props;

    // handle date mode
    if ( date_count > 0 ) {
        date_count -= 1;
    }
    if ( date_count <= 0 ) {
        // put in code to turn off DATE bit
    }
    show(dateinfo);
}
