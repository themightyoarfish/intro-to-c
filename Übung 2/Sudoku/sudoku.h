int field1[][9] = {
   {0, 0, 0,  0, 0, 8,  0, 3, 0},
   {0, 3, 0,  5, 0, 0,  4, 7, 1},
   {2, 0, 0,  1, 0, 0,  6, 9, 0},

   {5, 0, 0,  0, 0, 2,  1, 0, 0},
   {1, 2, 4,  0, 0, 0,  9, 6, 3},
   {0, 0, 6,  4, 0, 0,  0, 0, 2},

   {0, 8, 9,  0, 0, 5,  0, 0, 7},
   {3, 5, 2,  0, 0, 9,  0, 4, 0},
   {0, 1, 0,  3, 0, 0,  0, 0, 0}
};

/**
  * Function to check whether an assignment for a given field is legal.
  *
  * @param z The number to be assigned.
  * @param i The row number of the field to be assigned.
  * @param j The column number of the field to be assigned.
  * @param sudoku the Sudoku field against which to check.
  * @return 1 on success, 0 on failure.
  */
int is_valid(int z, int i, int j, int sudoku[9][9]);

/**
 * Function to attempt solving a sudoku.
 *
 * @param i The row number at which to set the first number.
 * @param j The column number at which to set the first number.
 * @return 1 if a silution was found, 0 otherwise.
 */
int solve_sudoku(int i, int j, int sudoku[9][9]);

/**
 * Function to print a sudoku array on stdout.
 *
 * @param sudoku The puzzle to be printed.
 */
void print_sudoku(int sudoku[9][9]);
