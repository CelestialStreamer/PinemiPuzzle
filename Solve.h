#pragma once

#include <iostream>
#include <iomanip>
#include <algorithm>

//int board[10][10] = { // board 1
// {  0,  -4,   0,  -8,  -7,  -8,   0,  -6,  -6,   0},
// { -2,  -6,  -8,   0,   0,   0, -10,   0,   0,  -7},
// { -3,   0,   0,   0,   0,   0,   0,   0,   0,  -8},
// {  0,   0,   0,  -6,  -8,   0,  -8,  -9,   0,   0},
// {  0,   0, -11,   0,  -8,  -8,   0,   0,  -7,  -6},
// { -9, -11,   0,   0,  -9,   0,   0,  -8,  -6,   0},
// {  0,   0, -13,   0,   0,  -7,  -8,   0,   0,  -5},
// { -8,   0,   0, -10,   0,   0,  -7,   0,  -8,   0},
// {  0, -10,   0,  -8,   0,   0,   0,  -9,   0,   0},
// {  0,   0,  -2,  -5,   0,  -8,   0,   0,   0,  -4}
//};
//int board[10][10] = { // board 2
// { -7,   0,  -7,  -5,   0,  -6,   0,  -6,   0,   0},
// {  0,   0, -11,   0,   0,   0,  -6,   0,  -8,  -5},
// {  0, -10,   0,   0, -11,  -7,   0,  -6,   0,   0},
// { -4, -10,   0,   0, -11,   0,   0,  -6,  -6,   0},
// {  0,  -6,   0, -11,   0,   0,   0,   0,   0,  -9},
// { -6,   0, -10,   0,  -7,  -7,   0,  -9,   0,   0},
// {  0,   0,   0,  -6,   0,  -8,  -9,   0, -12,  -9},
// {  0,  -9,  -6,  -5,  -8,   0,   0,   0,   0,   0},
// {  0,   0,  -5,   0,  -9,   0,   0, -12,   0,   0},
// {  0,  -5,   0,   0,   0,  -7,  -8,   0,  -6,   0}
//};
//int board[10][10] = { // board 3
// {  0,  -5,   0,  -5,   0,   0,  -7,   0,   0,   0},
// { -8,   0,  -9,   0,  -9,  -8,   0,  -9,   0,  -5},
// {  0,   0, -10,   0,   0,  -7,  -6,   0,  -8,   0},
// {  0, -10,   0,  -9,   0,   0,  -7,  -8,   0,   0},
// { -3,   0,   0,   0,   0,   0,   0,  -8,   0,  -8},
// { -6,  -9,   0,   0, -10,   0, -10,   0,  -7,   0},
// {  0,   0, -10, -11,   0,  -9,   0,   0,  -8,  -5},
// { -6, -10,   0,   0, -10,   0,   0,  -8,   0,   0},
// {  0,  -8,   0,  -9,   0,   0, -10,   0, -10,   0},
// { -4,   0,  -6,   0,   0,  -6,   0,  -8,   0,  -4}
//};
//int board[10][10] = {
// {0, 0, 0, -7, 0, 0, 0, 0, -7, 0},
// {-4, 0, 0, 0, -6, -7, -11, 0, 0, -5},
// {0, -12, 0, 0, -5, 0, 0, 0, -11, 0},
// {0, 0, -6, -7, -8, 0, 0, 0, 0, 0},
// {0, -8, -4, 0, 0, -11, -9, -10, 0, 0},
// {0, -6, -8, 0, -12, 0, 0, -10, 0, -8},
// {-5, 0, 0, 0, 0, -11, -12, 0, 0, -4},
// {0, 0, 0, 0, -11, 0, 0, 0, -7, -5},
// {0, 0, -9, 0, 0, 0, 0, -7, 0, 0},
// {-4, 0, -5, 0, 0, -7, -4, 0, -7, 0}
//};
//int board[10][10] = {
// {-2, -5, 0, 0, -7, 0, 0, 0, -6, 0},
// {0, 0, -8, -9, 0, 0, -11, 0, 0, 0},
// {-4, 0, 0, 0, 0, 0, 0, 0, 0, 0},
// {-5, 0, -11, 0, 0, 0, 0, 0, -9, 0},
// {0, 0, 0, 0, -11, 0, -9, -8, -8, 0},
// {0, -10, 0, 0, 0, -7, 0, 0, 0, -7},
// {-6, 0, 0, 0, 0, 0, -8, 0, 0, 0},
// {0, 0, -10, -9, 0, -7, 0, 0, 0, -6},
// {0, 0, 0, 0, 0, -8, -8, -10, 0, -5},
// {0, -9, 0, -6, -5, 0, 0, 0, -4, 0}
//};
int board[10][10] = {
 {0, -11, 0, 0, -5, -2, 0, 0, -3, 0},
 {0, 0, 0, 0, 0, -7, -6, -7, 0, -5},
 {0, -1, 0, -8, 0, 0, 0, -9, 0, 0},
 {-6, 0, -6, 0, -9, 0, 0, 0, 0, 0},
 {0, -8, -7, 0, 0, 0, 0, 0, -9, 0},
 {0, 0, -6, -6, 0, 0, 0, -9, 0, 0},
 {-5, 0, 0, -9, 0, 0, -10, 0, 0, 0},
 {0, -9, 0, 0, 0, -5, -8, 0, -12, 0},
 {0, 0, -8, 0, 0, 0, -8, 0, 0, -7},
 {-2, -2, -4, -7, 0, 0, 0, -8, 0, 0}
};

namespace Solve {

   void inc(int &r, int &c) {
      c++;
      if (c == 10) {
         c = 0;
         r++;
      }
   }

   void dec(int &r, int &c) {
      c--;
      if (c < 0) {
         c = 9;
         r--;
      }
   }

   int rowVal(int r) {
      int sum = 0;
      for (int c = 0; c < 10; c++)
         sum += std::max(0, board[r][c]);
      return sum;
   }

   /*
   * Number of jambs in the column
   */
   int colVal(int c) {
      int sum = 0;
      for (int r = 0; r < 10; r++)
         sum += std::max(0, board[r][c]);
      return sum;
   }

   /*
   * Numbr of jambs in the row
   */
   int gridVal(int r, int c) {
      int sum = 0;
      for (int u = std::max(0, r - 1); u <= std::min(9, r + 1); u++)
         for (int v = std::max(0, c - 1); v <= std::min(9, c + 1); v++)
            sum += std::max(0, board[u][v]);
      return sum;
   }

   /*
   * False if there is a jamb cell that has not been filled yet in the row.
   * This does not mean that the row has 10 jambs, just that
   * there are no empty jamb guesses.
   */
   bool rowFull(int r) {
      for (int c = 0; c < 10; c++)
         if (board[r][c] == 0)
            return false;
      return true;
   }

   /*
   * False if there is a jamb cell that has not been filled yet in the column.
   * This does not mean that the column has 10 jambs, just that
   * there are no empty jamb guesses.
   */
   bool colFull(int c) {
      for (int r = 0; r < 10; r++)
         if (board[r][c] == 0)
            return false;
      return true;
   }

   /*
   * False if there is an adjacent jamb cell that has not yet been filled.
   * This does not mean that the hint has the correct number of jambs, but
   * that all jamb cells have been at least guessed.
   */
   bool gridFull(int r, int c) {
      for (int u = std::max(0, r - 1); u <= std::min(9, r + 1); u++)
         for (int v = std::max(0, c - 1); v <= std::min(9, c + 1); v++) {
            if (u == r && v == c)
               continue;
            if (board[u][v] == 0)
               return false;
         }
      return true;
   }

   /*
   * Returns true if all of the following are true:
   * - Every   finished row must have exactly   10 jambs.
   * - Every unfinished row must have less than 10 jambs.
   */
   bool invalidatesRow(int r) {
      int val = rowVal(r);
      if (val > 10) // row adds up to too much
         return true;
      else if (rowFull(r)) {
         if (val != 10) // row finished, but does not add up to 10
            return true;
      } else {
         if (val == 10) // row not finished, but adds up to 10
            return true;
      }
      return false;
   }

   /*
   * Returns true if all of the following are true:
   * - Every   finished column must have exactly   10 jambs.
   * - Every unfinished column must have less than 10 jambs.
   */
   bool invalidatesCol(int c) {
      int val = colVal(c);
      if (val > 10) // column adds up to too much
         return true;
      else if (colFull(c)) {
         if (val != 10) // column finished, but does not add up to 10
            return true;
      } else {
         if (val == 10) // column not finished, but adds up to 10
            return true;
      }
      return false;
   }

   /*
   * Returns true if all of the following are true:
   * - Every   finished hint must have exactly   (hint) number of jambs adjacent.
   * - Every unfinished hint must have less than (hint) number of jambs adjacent.
   */
   bool invalidatesHint(int r, int c) {
      int sum = gridVal(r, c);
      if (sum > -board[r][c]) // too many jambs around hint
         return true;
      else if (gridFull(r, c)) {
         if (sum != -board[r][c]) // hint finished, but wrong number of jambs
            return true;
      } else {
         if (sum == -board[r][c]) // hint not finished, but right number of jambs
            return true;
      }
      return false;
   }

   /*
   * Returns true if the guess at the given cells
   *  1) invalidates the row
   *  or
   *  2) invalidates the column
   *  or
   *  3) invalidates any hint surrounding it
   */
   bool invalidGuess(int r, int c) {
      // Check if it invalidates row
      if (invalidatesRow(r))
         return true;

      // Check if it invalidates col
      if (invalidatesCol(c))
         return true;

      // check if it invalidates any of the surrounding hints
      for (int u = std::max(0, r - 1); u <= std::min(9, r + 1); u++)
         for (int v = std::max(0, c - 1); v <= std::min(9, c + 1); v++) {
            if (u == r && v == c || board[u][v] >= 0) // skip center cell, skip non-hint cells
               continue;

            // Check if it invalidates hint
            if (invalidatesHint(u, v))
               return true;
         }

      // Guess is fine, does not break anything
      return false;
   }

   /*
   * Counts the number of solutions (sort of)
   * Returns
   *  - 0 for no solutions, (probably won't happen if you generated a puzzle)
   *  - 1 for only one solution,
   *  - 2 for more than one solution. (stops counting more if this is true)
   */
   int countSolutions() {
      int r = 0, c = 0;

      int numSolutions = 0;

      do {
         if (r == 10) { // end of puzzle (r went off end of board)
            numSolutions++;
            if (numSolutions > 1)
               return 2;
            // If only one solution has been found, go back and check for more
            do {
               dec(r, c);
            } while (board[r][c] < 0);
            continue;
         }

         if (board[r][c] < 0) { // skip hints
            inc(r, c);
            continue;
         }

         board[r][c]++; // make guess
         if (board[r][c] > 3) { // quick check if guess is invalid
            board[r][c] = 0; // if so, reset...
            dec(r, c); // and go back one
            if (r < 0)
               return numSolutions; // no solution if we end up at the start
         }

         if (invalidGuess(r, c)) {
            // roll back and remove any maxed out guesses and keep rolling back
            while (board[r][c] == 3) {
               board[r][c] = 0; // remove guess
               do {
                  dec(r, c);
                  if (r < 0)
                     return numSolutions; // no solution if we end up at the start
               } while (board[r][c] < 0); // go back over hints
            }
         } else // Guess looks good so far, move ahead and guess some more
            inc(r, c);

      } while (true);
   }

   /*
   * Very similar to countSolutions(), except that it stops if it finds just one
   */
   bool findSolution() {
      int r = 0, c = 0;
      do {
         if (r == 10)
            return true; // no more guesses, puzzle must be solved

         if (board[r][c] < 0) { // skip hints
            inc(r, c);
            continue;
         }

         board[r][c]++; // make guess
         if (board[r][c] > 3) { // quick check if guess is invalid
            board[r][c] = 0; // if so, reset...
            dec(r, c); // and go back one
            if (r < 0)
               return false; // no solution if we end up at the start
         }

         if (invalidGuess(r, c)) {
            // roll back and remove any maxed out guesses and keep rolling back
            while (board[r][c] == 3) {
               board[r][c] = 0; // remove guess
               do {
                  dec(r, c);
                  if (r < 0)
                     return false; // no solution if we end up at the start
               } while (board[r][c] < 0); // go back over hints
            }
         } else // Guess looks good so far, move ahead and guess some more
            inc(r, c);

      } while (true);
   }
}
