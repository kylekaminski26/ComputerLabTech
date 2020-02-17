/* view.c -- view module for clock project
 *
 * Darren Provine, 17 July 2009
 *
 * Copyright (C) Darren Provine, 2009-2019, All Rights Reserved
 */

#include "clock.h"
#include "view.h"

/* VIEW */

int view_props = 0x01; // default is 24-hour mode, plain text

// returns old properties so you can save them if needed
void set_view_properties(int viewbits)
{
    view_props = viewbits;
}

int get_view_properties()
{
    return view_props;
}


void do_test(struct tm *dateinfo)
{
    // turn bits on and off
    
    display();
    fflush(stdout);
}



/* We get a pointer to a "struct tm" object, put it in a string, and
 * then send it to the screen.
 */
void show_led(struct tm *dateinfo)
{
    char       timestring[9];
    digit *where = get_display_location();
    int i;
    digit  bitvalues = 0;
    int hour;
    int indicator;

    if ( view_props & TEST ) {
        do_test(dateinfo);
        return;
    }

    // check date mode
    if ( view_props & DATE ) {
        // put the right "dateinfo->" stuff into timestring
        // turn on date indicator
    } else {
        // must be regular time
    
        hour=dateinfo->tm_hour;
        if ( view_props & AM_PM ) {
            indicator = 0x01;  // assume AM
            if (hour >= 12) {
                hour -= 12;
                indicator = 0x02;
            }
            if (hour == 0)
                hour = 12;
            sprintf(timestring,
                    "%2d%02d%02d",
                    hour,
                    dateinfo->tm_min,
                    dateinfo->tm_sec);
        } else {
            indicator = 0x04;
            sprintf(timestring,
                    "%02d%02d%02d",
                    hour,
                    dateinfo->tm_min,
                    dateinfo->tm_sec);
        }
        // do something with colons
        where[7] = indicator;
    }

    for (i = 0; i < 6; i++) {
        switch ( timestring[i] ) {
            case ' ': bitvalues = 0x00; break;
            case '1': bitvalues = 0x42; break;
            case '2': bitvalues = 0x37; break;
            case '3': bitvalues = 0x67; break;
            case '4': bitvalues = 0x4b; break;
            case '5': bitvalues = 0x6d; break;
            case '6': bitvalues = 0x7d; break;
            case '7': bitvalues = 0x46; break;
            case '8': bitvalues = 0x7f; break;
            case '9': bitvalues = 0x6f; break;
            case '0': bitvalues = 0x7e; break;
        }
        where[i] = bitvalues;
    }
    display();
    fflush(stdout);
}

void show_text(struct tm *dateinfo)
{
    char   timestring[15];
    char   ampmstring[3] = "am"; // assume AM
    int    hour;

    hour=dateinfo->tm_hour;
    if ( view_props & AM_PM ) {
        if (hour > 12) {
            hour -= 12;
            ampmstring[0] = 'p';
        }
        if (hour == 0)
            hour = 12;
        sprintf(timestring,
                "%2d:%02d:%02d %s",
                hour,
                dateinfo->tm_min,
                dateinfo->tm_sec,
                ampmstring);
    } else {
        sprintf(timestring,
                "%02d:%02d:%02d",
                hour,
                dateinfo->tm_min,
                dateinfo->tm_sec);
    }

    //AM/PM logic

    int hourAMPM = dateinfo->tm_hour;
    int ampmstringAMPM = dateinfo->tm_hour;

    //if (ampm) { // If 12 hour clock
      if (hourAMPM > 12) // If 1PM or later
        hourAMPM %= 12; // Round back to 1 o'clock
      if (hourAMPM == 0) // If midnight
        hourAMPM = 12; // Change 0 o'clock to 12 o'clock
      sprintf(timestring, // Print time
            "%02d:%02d:%02d",
            hourAMPM,
            dateinfo->tm_min,
            dateinfo->tm_sec);
      printf("\r%s ", timestring);
    //}
    
    //else { // If 24 hour clock
    //sprintf(timestring, // Print time
    //        "%02d:%02d:%02d",
    //        dateinfo->tm_hour,
    //        dateinfo->tm_min,
    //        dateinfo->tm_sec);
   //printf("\r%s ", timestring);
    //}

    printf("\r%s ", timestring);
    fflush(stdout);
}

void show(struct tm *dateinfo)
{
    if ( view_props & LED_MODE )
        show_led(dateinfo);
    else
        show_text(dateinfo);        
}
