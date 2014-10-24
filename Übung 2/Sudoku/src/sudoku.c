#include <stdio.h>
#include "include/sudoku.h"


int is_valid(int z, int i, int j, int sudoku[9][9])
{
   int x, y;
   int subfield_x_ind = (i / 3) * 3; /* check the 3x3 field containing (i,j) */
   int subfield_y_ind = (j / 3) * 3;
   if ((z < 1 || z > 9) || (sudoku[i][j] != 0)) return 0; /* if out of bounds or not free */
   for (x = 0; x < 9; x++) /* check row and column intersecting at (i,j) */
      if (sudoku[x][j] == z || sudoku[i][x] == z) return 0;
   for (x = subfield_x_ind; x < subfield_x_ind + 3; x++){
      for (y = subfield_y_ind; y < subfield_y_ind + 3; y++){
         if(sudoku[x][y] == z) return 0;
      }
   }
   return 1; /* if no probs found, success! */
}

int solve_sudoku(int i, int j, int sudoku[9][9])
{
   int z; /* the number to try */
   while (i < 9 && (sudoku[i][j] != 0)) 
   { /* find next free field */
      j++;
      if (j >= 9) 
      {
         j = 0;
         i++;
      }
   }

   if (i >= 9) return 1; /* no free fields? Already done. */
   else
   {
      for (z = 1; z <= 9; z++) /* try all numbers */
      {
         if (is_valid(z, i, j, sudoku)) /* if assignment valid ... */
         {
            sudoku[i][j] = z;
            if (!solve_sudoku(i, j, sudoku)) sudoku[i][j] = 0; /* ... continue and try with next field */
            else return 1; /* wenn the last field is to be set and it works, the function will jump here and bubble up true */
         }
      }
   }
   return 0; /* if control jumps here, it means no number was valid, so return false */
}

void print_sudoku(int sudoku[9][9])
{
   int i,j;
   printf("+-----+-------+-----+\n");
   for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
         if (j == 3 || j == 6) 
            printf("| %d ",sudoku[i][j]);
         else
            printf("%d ",sudoku[i][j]);
      }
      printf("\n");
      if (i == 2 || i == 5)
         printf("+-----+-------+-----+\n");
   }
   printf("+-----+-------+-----+\n");
}
/**
 * Main function to start the solver.
 * The sudoku is currently hardwired in the code.
 */
int main(void)
{

   if(solve_sudoku(0,0,field1)) print_sudoku(field1);
   else printf("Unsolvable.\n");
   return 0;
}
