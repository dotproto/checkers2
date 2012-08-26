#include "objects.h"

void PositionToCoordinate(Position pos, int& row, int& col){
  // Row and column converstion notes:
  // 
  // * Rows - distance from board's bottom edge.
  // * Cols - distance from board's left edge.
  //
  // Rows are straight forward, but columns have special rules that determine
  // the coordinates of valid positions.

  // Convert position to zer-based index
  pos -= 1;

  //// ROW CALCULATION
  // Row number = quotient of (position / positions per row)
  row = pos / 4;
  
  //// COL CALCULATION
  // Initial col value = remainder of (position / positions per row)
  col = pos % 4;

  // Col now represents a position offest from the right side, but we need the
  // column offset from the left side. To get this value we must 
  //
  // 1. Derive an offset of positions from the right side.
  // 2. Add additional spaces based on distance from right
  // 3. Adjust for odd/even row count.

  // Step 1. Derive offset from right (0..3)
  col = 3 - col;
  // Step 2. Adjust for additional spaces (2 spaces for every 1 unit from left)
  col *= 2;
  // Step 3. Adjust even rows (even board rows are odd due to zero-based index)
  if (row % 2 != 0) {
    col += 1;
  }
};

void CoordinatesToPosition(int& row, int& col, Position pos) {
  // 0,0     W,0
  //
  // 0,H     W,H
}
