#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <vector>
#include <ctime>

#include "Solve.h"
//#define NDEBUG // turns off 'assert'

#define REQUIRE_HINT_BY_JAMB

void reset() {
   for (int r = 0; r < 10; r++)
      for (int c = 0; c < 10; c++)
         board[r][c] = 0;
}

/*
* True if given row has 10 jambs
*/
bool rowFull(int r) {
   int sum = 0;
   for (int c = 0; c < 10; c++)
      sum += board[r][c];
   assert(sum <= 10);
   return sum == 10;
}

/*
* True if given column has 10 jambs
*/
bool colFull(int c) {
   int sum = 0;
   for (int r = 0; r < 10; r++)
      sum += board[r][c];
   assert(sum <= 10);
   return sum == 10;
}

/*
* Prints puzzle.
* Jambs are printed as numbers.
* Hints are printed in parentheses.
* Blanks are non hint cells with no jambs
*/
void print() {
   std::cout << "    0   1   2   3   4   5   6   7   8   9" << std::endl << std::endl;
   for (int r = 0; r < 10; r++) {
      std::cout << r << " ";
      for (int c = 0; c < 10; c++) {
         if (board[r][c] < 0)
            std::cout << (-board[r][c] < 10 ? " (" : "(") << -board[r][c] << ")";
         else if (board[r][c] == 0)
            std::cout << " " << "  " << " ";
         else
            std::cout << " " << std::setw(2) << board[r][c] << " ";
      }
      std::cout << std::endl;
   }
}

/*
* Returns a vector filled with integers a through b, inclusive.
*/
std::vector<int> range(int a, int b) {
   std::vector<int> v(b - a + 1);
   int i = a;
   std::generate(v.begin(), v.end(), [&i] { return i++; });
   return v;
}

/*
* Attempts to build a pinemi puzzle by placing in 100 jambs randomly.
* For each jamb, select from all remaining cells that are
* - not part of a column that is filled,
* - not part of a column that is filled,
* - not a cell that has three jambs already.
* In some cases, this routine will run out of available spaces
* before placing the 100 jambs.
* The routine returns true if all 100 jambs have been placed.
*/
bool addJambs() {
   int cell, r, c;
   std::vector<int> cells = range(0, 99);

   for (int i = 0; i < 100; i++) {
      if (cells.size() == 0)
         return false; // prematurely ran out of cells to fill.
      // randomly choose from one of the remaining valid cells
      cell = std::rand() % cells.size();
      r = cells[cell] / 10;
      c = cells[cell] % 10;

      // add a jamb to the cell
      board[r][c]++;
      // update list of valid cells
      if (board[r][c] == 3) // Cell is full
         cells.erase(cells.begin() + cell);
      if (rowFull(r)) // row is full
         cells.erase(std::remove_if(cells.begin(), cells.end(), [&r](int m) { return m / 10 == r; }), cells.end());
      if (colFull(c)) // column is full
         cells.erase(std::remove_if(cells.begin(), cells.end(), [&c](int m) { return m % 10 == c; }), cells.end());
   }
   return true; // it's not definitely a bad puzzle, yet
}

/*
* - With a board having only jambs placed in it, this routine
*   generates the hints by setting every non-jamb cell to the
*   number of jambs surrounding it. The value is negated to
*   differentiate it from the jambs.
* - Hints are negative. Jambs are non-negative.
* - Returns false if there would be a hint cell with zero adjacent jambs.
*/
bool generateHints() {
   // For every cell in the puzzle
   for (int r = 0; r < 10; r++)
      for (int c = 0; c < 10; c++)
         if (board[r][c] == 0) { // If there are no jambs placed here,
            // Count number of jambs in neighboring cells
            int sum = 0;
            for (int u = std::max(0, r - 1); u <= std::min(9, r + 1); u++)
               for (int v = std::max(0, c - 1); v <= std::min(9, c + 1); v++)
                  sum += std::max(0, board[u][v]);
            if (sum == 0) // Hint cell cannot be zero. (Conflicts with solver assuming zero jambs at start)
               return false;
            // Set hint to number of jambs. Negative to signal that this is a hint and not a jamb cell.
            board[r][c] = -sum;
         }
   return true;
}

/*
* Remove all jamb cells from puzzle to leave
* just hint cells.
*/
void removeJambs() {
   for (int r = 0; r < 10; r++)
      for (int c = 0; c < 10; c++) {
         assert(board[r][c] != 0);
         if (board[r][c] > 0)
            board[r][c] = 0;
      }
}

/*
* After clearing jambs from generated puzzle,
* check if there are any jamb cells with no
* hint cells nearby. It's perfectly valid to
* have this the other way if you want, just
* remove REQUIRE_HINT_BY_JAMB
*/
bool checkHints() {
#ifndef REQUIRE_HINT_BY_JAMB
   return true;
#else
   // For every cell in the puzzle
   for (int r = 0; r < 10; r++)
      for (int c = 0; c < 10; c++)
         if (board[r][c] == 0) { // for non-hint cells
            // count the hint values
            int sum = 0;
            for (int u = std::max(0, r - 1); u <= std::min(9, r + 1); u++)
               for (int v = std::max(0, c - 1); v <= std::min(9, c + 1); v++)
                  sum += board[u][v];
            // zero means that jamb cell has no hint nearby.
            if (sum == 0)
               return false;
         }
   return true;
#endif // REQUIRE_HINT_BY_JAMB
}

/*
*
* Generates 10,000 Pinemi puzzles.
* Generating a puzzle has the following steps.
* If any step fails, start over.
*  1) reset puzzle
*  2) add 100 jambs where each row and each column has 10 jambs
*     -possible that generate routine failed to add 100 jambs before conficts arose.
*  3) generate hints
*     -possible that
*  4) Remove jambs from puzzle and check for valid configuration
*     -if REQUIRE_HINT_BY_JAMB is defined, then there might be a jamb with no hint by it
*  5) Check that puzzle has unique solution
*     -number of solutions is more than 1
*  Finally, a unique, valid puzzle is this. Print it and try again.
*/
int main() {
   std::srand((unsigned)std::time(NULL));
   for (int i = 0; i < 10000; i++) {
      do {
         do {
            do {
               do {
                  reset();
               } while (!addJambs());
            } while (!generateHints());
            removeJambs();
         } while (!checkHints()); // used if you define REQUIRE_HINT_BY_JAMB
      } while (Solve::countSolutions() != 1);
      Solve::findSolution();
      print();
      std::cout << std::endl;
   }
   std::cout << "Finished" << std::endl;
}