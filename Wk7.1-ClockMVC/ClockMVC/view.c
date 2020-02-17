/* view.c -- view module for clock project
 *
 * Darren Provine, 17 July 2009
 *
 * Copyright (C) Darren Provine, 2009-2019, All Rights Reserved
 */

#include "clock.h"

/* VIEW */

/* We get a pointer to a "struct tm" object, put it in a string, and
 * then send it to the screen.
 */
void show(struct tm *dateinfo, int ampm)
{
    char       timestring[9];

    // TODO: handle "ampm" setting
    //       You may want to create a new variable "hour",
    //       and possibly an "ampmstring", to hold the results
    //       of handling the ampm setting.

    sprintf(timestring,
            "%02d:%02d:%02d",
            dateinfo->tm_hour,
            dateinfo->tm_min,
            dateinfo->tm_sec);

    printf("\r%s ", timestring);
    fflush(stdout);
}



/* We get a pointer to a "struct tm" object, put it in a string, and
 * then send it to the screen.
 */
void ledshow(struct tm *dateinfo, int ampm)
{
    char       timestring[9];
    digit *where = get_display_location();
    int i;

    // TODO: handle "ampm" setting
    //       Write and test that part in show() before copying
    //       it here.


    /* Note that we have removed the colons from the format
     * string to make this part easier to write.
     */
    sprintf(timestring,
            "%02d%02d%02d",
            dateinfo->tm_hour,
            dateinfo->tm_min,
            dateinfo->tm_sec);

    for (i = 0; i < 6; i++) {
       switch ( timestring[i] ) {
       case ' ': where[i] = 0x00; break;
       case '1': where[i] = 0x42; break; 
       case '2': where[i] = 0x37; break;
       case '3': where[i] = 0x67; break;
       case '4': where[i] = 0x04; break;
       case '5': where[i] = 0x05; break;
       case '6': where[i] = 0x06; break;
       case '7': where[i] = 0x07; break;
       case '8': where[i] = 0x08; break;
       case '9': where[i] = 0x09; break;
       case '0': where[i] = 0xff; break;
       }
    }

    // colons + am/pm
    where[6] = 0x54;

    display();
    fflush(stdout);
}

