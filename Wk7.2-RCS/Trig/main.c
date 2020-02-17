/* main.c - main section of "trig" project
 *
 * DFP
 */

#include <stdlib.h>

static const char rcsid[] = "$Id$";

int main(int argc, char *argv[])
{
  double angle;
  void sine(double), cosine(double), tangent(double);

  if (argc < 2) {
      angle = 45.0;
  } else {
      //angle = (double) atof(argv[1]);
      angle = strtod(argv[1], NULL);
  }

  double angleRad = angle * (3.14159/180);
  sine(angleRad);
  cosine(angleRad);
  tangent(angleRad);

  return 0;
}
