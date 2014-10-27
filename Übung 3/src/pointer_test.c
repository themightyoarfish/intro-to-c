#include <stdio.h>
int main(void)
{
   int feld[5];
   int *p, *p1, *p2;
   int i;

   p = feld; /* a) Geht, pointer kann immer auf array zeigen */
   /* feld = p; */ /* b) Geht nicht, da arrays nicht neu zugewiesen werden koennen */
   p = &feld[3]; /* c) geht, p zeigt dann auf 4. element von feld */
   feld[2] = p[5]; /* d) trivial */
   p1 = p2 + i; /* e) pointer koennen vor- oder zurueckgerueckt werden */
   p1 = i + p2; /* f) s.o. */
   /* i = p1 * p2; */ /* g) geht nicht, adressen zu multipliziern, ist sinnlos */
   i = p1 - p2; /* h) einzige erlaubte arithmetische operation auf 2 pointern. Damit kann bestimmt werden, wie weit zwei dinge auseinander liegen*/
   /* i = p1 + p2; */ /* i) geht nicht, ist sinnlos */

   /* Addition ist kommutativ */
   feld[i]; /* syntactic sugar fuer *(feld + i) */
   i[feld]; /* syntactic sugar fuer *(i + feld) */
   printf("huu\n");
   return 0;
}
