/*
 * N - Queens problem
 * The challenge is to place N queens on an NxN chess board, so that no queen captures any other queen on board.
 * The task is divided into the following parts
 * 1. Board size evenly even and also as powers of 2 ie 4, 8, 16, 32, ...
 *    - Place 2 queens one each at (1, N/2) and (N, (N/2)+1). Let us call them begin and end.
 *    - Divide queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (1, N/2) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N/2)+1) in left direction.
 *  Function for this is evenlyEven()
 *
 * 2. All other even numbers
 *    - Divide queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (1,2) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N-1)) in left direction.
 *  Function for this is even()
 *
 * 3. Odd numbers divisible by 3 ie 9, 15, 21, ...
 *    - Place a queen at (1, N). Now even number of queens remain.
 *    - Divide remaining queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (2, 1) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N-1)) in left direction.
 *  Function for this is oddDivBy3()
 *
 * 4. All other odd numbers
 *    - Place a queen at (1,1). Now even number of queens remain.
 *    - Divide remaining queens into 2 halves.
 *    - Start placing first half of the queens fror begin cell (2, 3) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N-1)) in left direction.
 *  Function for this is odd()
 **/

#include "PositiveIntNature.h"

/* Place Queens in directions */
#define RIGHT_DIRECTION 'r'
#define LEFT_DIRECTION 'l'
#define MIN_BOARD_SIZE 4

typedef struct {
  posint row;
  posint col;
}CELL;
#define PRINT_CELL(cell) printf("(%8u,%8u)\n",cell.row,cell.col)
void placeQueens(posint size, posint limit, CELL beginCell, CELL endCell); /* Place queens on board */
void evenlyEven(posint size); /* Task 1 above */
void even(posint size); /* Task 2 above */
void oddDivBy3(posint size); /* Task 3 above */
void odd(posint size); /* Task 4 above */

/* Place Queen at the cell */
CELL nextCell(CELL, unsigned char, posint size);
