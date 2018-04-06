#include <stdio.h>
#include "Queens.h"

/*
 * Start placing first half of the queens from begin cell in right direction.
 * Start placing second half of the queens from end cell in left direction.
 * WARNING: If limit is not even number, there is a logical error in calling function
 **/
void placeQueens(posint size, posint limit, CELL beginCell, CELL endCell) {
  posint i1 = 1,
      i2 = limit+1;

  for(i1=1,i2=size-1; i1 <= limit; i1++,i2--) {
    beginCell = nextCell(beginCell, RIGHT_DIRECTION, size);
    endCell = nextCell(endCell, LEFT_DIRECTION, size);
    PRINT_CELL(beginCell);
    PRINT_CELL(endCell);
  }  
} /* void placeQueens(posint size, posint limit, CELL beginCell, CELL endCell) */
/*
 * Board size evenly even and also as powers of 2 from 2^2 ie 4, 8, 16, 32, ...
 *    - Place 2 queens one each at (1, N/2) and (N, (N/2)+1). Let us call them begin and end.
 *    - Divide queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (1, N/2) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N/2)+1) in left direction.
 ***/

void evenlyEven(posint size) {
  /* Place first Queen in beginCell */
  CELL beginCell = (CELL) { 1, (size/2) };

  /* Place last Queen in endCell */
  CELL endCell = (CELL) { size, (size/2)+1 };

  PRINT_CELL(beginCell);
  PRINT_CELL(endCell);
  placeQueens(size, (size-2)/2, beginCell, endCell);
} /* void evenlyEven(posint size) */

/*
 * Board size oddly even/singly even and also not divsible by 4
 *    - Divide queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (1,2) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N-1)) in left direction.
 ***/
 
void even(posint size) {
  /* Place first Queen in beginCell */
  CELL beginCell = (CELL) { 1, 2 };

  /* Place last Queen in endCell */
  CELL endCell = (CELL) { size, size-1 };

  PRINT_CELL(beginCell);
  PRINT_CELL(endCell);
  placeQueens(size, (size-2)/2, beginCell, endCell);
} /* void even(posint size) */
/*
 * Odd numbers divisible by 3 ie 9, 15, 21, ...
 *    - Place a queen at (1, N). Now even number of queens remain.
 *    - Divide remaining queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (2, 1) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N-1)) in left direction.
 ***/
void oddDivBy3(posint size) {
  CELL firstCell = (CELL) { 1, size };
  /* Construct dummy begin and end cells */
  CELL beginCell = (CELL) { 1, size-1 };
  CELL endCell = (CELL) { size+1, 1 };
  PRINT_CELL(firstCell);
  placeQueens(size, (size-1)/2, beginCell, endCell);
} /* void oddDivBy3(posint size) */

/*
 * All other odd numbers
 *    - Place a queen at (1,1). Now even number of queens remain.
 *    - Divide remaining queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (2, 3) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N-1)) in left direction.
 **/  
void odd(posint size) {
  CELL firstCell = (CELL) { 1, 1 };
  PRINT_CELL(firstCell);
  placeQueens(size, (size-1)/2, firstCell, firstCell);
} /* void odd(posint size) */

CELL nextCell(CELL cur, unsigned char direction, posint size) {
  if(direction == RIGHT_DIRECTION) {
    cur.row += 1;
    if(cur.row > size)
      cur.row = 1;
    cur.col += 2;
    if(cur.col > size)
      cur.col -= size;
    return cur;
  }
  if(direction == LEFT_DIRECTION) {
    cur.row -= 1;
    if(cur.row < 1)
      cur.row = size;
    /* Hacks !!! */
    if(cur.col == 2) {
      cur.col = size;
      return cur;
    }
    if(cur.col == 1) {
      cur.col = size-1;
      return cur;
    }
    cur.col -= 2;
    return cur;
  }
  return cur;
} /* CELL nextCell(CELL cur, unsigned char direction, posint size) */
