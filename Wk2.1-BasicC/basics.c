/* basics.c -- basic C program
0;136;0c *
 * D Provine, 3 September 2009
 */
#include <stdio.h>

int main()
{
   int i, *p;
   int j = 4;
   int arr[5] = {3, 4, 5, 6, 7};
   char name[20] = "Homer Simpson";

   printf("C Strings Are A Little Different\n");
   printf("%s\n", name);

   printf("\nLoops should look familiar.\n");
   for (i = 0; i < 5; i++)
   {
      printf("%d:  %d\n", i, arr[i]);
   }

   printf("\nBit Manipulation Works Directly On Binary Values\n");
   printf("j = %d\n", j);
   j <<= 1;  // shift j one bit to the left; was "0100", now "1000"
   printf("j shifted left one bit; now j = %d\n", j);
   j >>= 2;  // shift j two bits to the right; was "1000", now "0010"
   printf("j shifted right two bits; now j = %d\n", j);

   printf("\nA Pointer Is An Address\n");
   printf(" '&' means \"address of\"\n");
   printf(" '*' means \"what's stored at\"\n");

   i = 45;
   p = &i;
   printf("i is stored at: 0x%x\n", p);
   // note use of "%u" for unsigned int
   printf("p holds the value: %d\n", p);
   printf("p holds the unsigned value: %u\n", p);
   printf("i holds the value: %d\n", *p);

   printf("\nArray References Are Truned Into Pointer References\n");
   printf(" a[i] -> *(a + i) \n");
   printf("Array bounds are not checked.\n");

   arr[0] = 5;
   arr[6] = 87;

   printf("zero has: %d   six has: %d \n", arr[0], arr[6]);

   printf("\nAddition is Commutative, which has crazy results:\n");
   printf("  a[i]  =>   *(a + i)  ==  *(i + a)  =>  i[a] \n");

   printf("Test for crazy: %d\n", 2[arr]);
   printf("2nd crazy test: %c\n", 2["abef"]);

   return 0;
}
