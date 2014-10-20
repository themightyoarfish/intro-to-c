#include <stdio.h>
#include <stdlib.h>
/*
 * Reads a year from stdin and calculates the date of easter for that year,
 * which it prints on stdout. This is done until EOF is read.
 * @return 0 on success
 */
int main(void)
{
   int year, golden_year, century,
       leap_years_skipped, moon_coor_fact, 
       D, epact, day;
   char * month = malloc(6 * sizeof(char));
   /* User interaction */
   /* printf("Please enter year: "); */
   
   while (scanf("%d", &year) != EOF)
   {

      if (year < 0) 
      {
         printf("Can't work with years B.C.\n");
         continue;
      }

      golden_year = (year % 19) + 1;
      century = (year / 100) + 1;
      leap_years_skipped = (3 * century / 4) - 12;
      moon_coor_fact = ((8 * century + 5) / 25) - 5;
      D = (5 * year / 4) - leap_years_skipped - 10; /* what should I call this? */
      epact = (11 * golden_year + 20 + moon_coor_fact - leap_years_skipped) % 30;
      if ((epact == 25 && golden_year > 11) || epact == 24) epact++;
      day = 44 - epact;
      if (day < 21) day += 30;
      day += 7 - ((D + day) % 7);
      if (day > 31) {
         month = "April";
         day = day - 31;
      }
      else month = "March";
      printf("%d - %s %d\n", year, month, day);
   }
   return 0;
}
