/*
 * Program to place n-Queens so that no one queen captures any other
 * Using 1-based indices for a change ;).
 *
 * The program prompts for input.
 * It expects input greater or equal to MIN_BOARD_SIZE.
 * Values less than MIN_BOARD_SIZE will terminate the program.
 * As far as I know, this program cannot be piped to other programs.
 **/
#include <stdio.h>
#include "Queens.h"
#include "PositiveIntNature.h"

void main(int argc, char *argv[]) {
  posint size = (posint) MIN_BOARD_SIZE;
  posint ctr = 0;

  printf("\nEnter a number less than %d to exit!", MIN_BOARD_SIZE);
  printf("\nEnter size of board (Current size: %u): ", size);
  scanf("%u", &size);

  while(size >= MIN_BOARD_SIZE) {
    switch(intNature(size)) {
      case ODD_DIV_BY_3:
        oddDivBy3(size);
        break;
      case ODD:
        odd(size);
        break;
      case EVENLY_EVEN:
        evenlyEven(size);
        break;
      case EVEN:
        even(size);
        break;
    }
    ctr++;
    printf("\nEnter a number less than %d to exit!", MIN_BOARD_SIZE);
    printf("\nEnter size of board (Current size: %u): ",size);
    scanf("%u", &size);   
  }
  printf("\n\nYou have analyzed a total of %d boards.",ctr);
  printf("\nTHANK YOU FOR USING ME.");
} /* void main(int argc, char *argv[]) */