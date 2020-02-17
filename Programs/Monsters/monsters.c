/* monsters.c - monster abilities and vulnerabilities.
0;136;0c *
 * D Provine and a cast of dozens, 5 Feb 2013
 */

#include <stdio.h>
#include <string.h>
#include <strings.h>

/* MONSTER ATTACKS AND BIT POSITIONS
 *
 * fire -------------------+
 * bite -----------------+ |
 * claw ---------------+ | |
 * acid -------------+ | | |
 * frost --------+   | | | |
 * poison -----+ |   | | | |
 *             | |   | | | |
 *             V V   V V V V
 *         0 0 0 0   0 0 0 0
 */
#define  FIRE    0x01
#define  BITE    0x02
#define  CLAW    0x04
#define  ACID    0x08
#define  FROST   0x10
#define  POISON  0x20

/* MONSTER TYPES
 * (note use of bitwise OR; each bit is a different kind of attack)
 */
#define WOLF    ( BITE )
#define COUGAR  ( BITE | CLAW )
#define TIGER   ( BITE | CLAW )
#define COBRA   ( BITE | POISON )
#define DRAGON  ( FIRE | BITE | CLAW )
#define YETI    ( BITE | CLAW | FROST )
#define ALIEN   ( BITE | ACID )

/* DEFENSES
 * (again; "|" means defense protects against all things listed)
 */
#define  NONE        ( 0x00 )
#define  INSULATION  ( FIRE | FROST )
#define  ARMOR       ( BITE | CLAW )
#define  AMULET      ( POISON | ACID )


// for input buffer reading monsters and equipment
#define BUFSIZE 64

/* INPUT FORMAT: monster name followed by equipment name(s).
 * Examples:
 *   dragon
 *   tiger none
 *   wolf armor amulet
 *   cobra insulation
 * Equipment can be in any order.
 * WARNING: does minimal error-checking!  Bogus input may cause
 * random results!
 */

/* This main routine just has driver code: it runs values
 * through the report_danger() function.
 * You have to write that function (at the bottom), but
 * don't make any changes to main().
 */
int main()
{
    void report_danger(int, int); // function prototype
    int  equipment;
    int  monster;
    int  itemsread;
    char monster_name[20];
    char equipment_name[20];
    char line[BUFSIZE];
    int  offset; // for multiple sscanf() calls on one line
    char *data;  // pointer to where on line we want to read

    while ( fgets(line, BUFSIZE, stdin) != NULL ) {
        // reset for start of loop
        offset = 0;
        data = &line[0]; // beginning of line

        itemsread = sscanf(line, "%s%n", monster_name, &offset);

        if ( ! strncasecmp(monster_name, "wolf", 4) ) {
            monster = WOLF;
        } else if ( ! strncasecmp(monster_name, "cougar", 6) ) {
            monster = COUGAR;
        } else if ( ! strncasecmp(monster_name, "tiger",  5) ) {
            monster = TIGER;
        } else if ( ! strncasecmp(monster_name, "cobra",  5) ) {
            monster = COBRA;
        } else if ( ! strncasecmp(monster_name, "dragon", 6) ) {
            monster = DRAGON;
        } else if ( ! strncasecmp(monster_name, "yeti",   4) ) {
            monster = YETI;
        } else if ( ! strncasecmp(monster_name, "alien",  5) ) {
            monster = ALIEN;
        } else {
            monster = NONE;
        }

        // move our start point ahead to the next part of the line
        data += offset;
        
        // blank out all the bits to start
        equipment = NONE;
        while ( (itemsread = sscanf(data, "%s%n", equipment_name, &offset) )
                != EOF ) {
            if ( ! strncasecmp(equipment_name, "insulation", 10) ) {
                equipment |= INSULATION;
            } else if ( ! strncasecmp(equipment_name, "armor",  5) ) {
                equipment |= ARMOR;
            } else if ( ! strncasecmp(equipment_name, "amulet", 6) ) {
                equipment |= AMULET;
            }
            data += offset;
        }

        // get rid of newline from input
        line[strcspn(line, "\n")] = '\0';

        printf("%35s - ", line);
        
        report_danger(equipment, monster);
    }
    
    return 0;
}



/* void function - does not return anything
 *
 * report_danger takes two arguments:
 *   1) What defenses the user has
 *   2) What kind of monster it is (which attacks it has)
 *
 * report_danger should print out what things the
 * user has to worry about.
 */

void report_danger(int defenses, int monster)
{
  printf("beware of: ");

  int output = defenses | monster;
  //OR operation on defenses and monster.
  
  int beware = output ^ defenses;
  //XOR operation on output and defenses.

 for (int i = 5; i >= 0; i--){
   // For all bits from the 5th bit to the 0th bit.
    if (beware & (1 << i)) {
      // If beware ANDed with i equals 1.
      switch (i) { // Switch statement for value of i.
    case 5: printf("poison ");
      break;
    case 4: printf("frost ");
      break;
    case 3: printf("acid ");
      break;
    case 2: printf("claw ");
      break;
    case 1: printf("bite ");
      break;
    case 0: printf("fire ");
      break;
      default: printf("");
      break;
    }
    }
  }

 printf("\n");
 return;
}
