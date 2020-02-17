/* view.h -- #defines for view options
 *
 * D Provine, 17 October 2017
 * 
 * Copyright (C) Darren Provine, 2009-2019, All Rights Reserved
 */

/* VIEW OPTIONS
 *
 * AMPM / 24-hour -------------+
 * unused -------------------+ |
 * date -------------------+ | |
 * LED mode--------------+ | | |
 *                       | | | |
 * test -----------+     | | | |
 *                 |     | | | |
 *                 |     | | | |
 *                 V     V V V V
 *           0 0 0 0     0 0 0 0
 */
#define  AM_PM     0x01
#define  DATE      0x04
#define  LED_MODE  0x08
#define  TEST      0x10

// set packed bits for what you want
void set_view_properties( int );
int get_view_properties( void );

void show(struct tm *);

