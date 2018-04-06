/*
 * Program to place n-Queens so that no one queen captures any other
 * Currently dealing with 2^n boards.
 * Using 1-based indices for a change ;).
 *
 * This program expects a command line input of unsigned long number.
 * It expects input greater or equal to MIN_BOARD_SIZE.
 * This is written as a pipeable program for another program that checks the output, 
 *  whether all the queens are placed properly.
 **/
#include <stdio.h>
#include <stdlib.h>
#include "Queens.h"
#include "PositiveIntNature.h"

void main(int argc, char *argv[]) {
  posint size = (posint) MIN_BOARD_SIZE;
  if(argc > 1) {
    posint tmp = strtoul(argv[1],NULL,10);
    if(tmp > size)
      size = tmp;
  }
  /*
  printf("Sizes of unsigned integers on this m/c:\n");
  printf("\t\t                 int - %u\n",sizeof(int));
  printf("\t\t        unsigned int - %u\n",sizeof(unsigned int));
  printf("\t\t                long - %u\n",sizeof(unsigned long));
  printf("\t\t       unsigned long - %u\n",sizeof(unsigned long));
  printf("\t\t         long double - %u\n",sizeof(long double));
  */
  printf("Size of board: %u\n",size);
  printf("BEGIN:\n");
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
  } /* switch(intNature(size)) */
      printf(":END\n");
} /* void main(int argc, char *argv[]) */