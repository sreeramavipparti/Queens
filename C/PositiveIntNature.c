#include "PositiveIntNature.h"

bool isEven(posint number) {
  return (bool) (number % 2 == 0);
} /* bool isEven(posint number) */

bool isOdd(posint number) {
  return (bool) !isEven(number);
} /* bool isOdd(posint number) */

bool isDivBy3(posint number) {
  return (bool) (number % 3 == 0);
} /* bool isDivBy3(posint number) */

bool isEvenlyEven(posint number) {
  return (bool) (number % 4 == 0);
} /* bool isEvenlyEven(posint number) */

posint_nature intNature(posint number) {
  if(isOdd(number)) {
    if(isDivBy3(number)) {
      #ifdef DIAGNOSTICS
      ODD_DIV_BY_3_TEXT(number);
      #endif
      return (posint_nature) ODD_DIV_BY_3;
    }
    #ifdef DIAGNOSTICS
    ODD_TEXT(number);
    #endif
    return (posint_nature) ODD;
  }
  if(isEven(number)) {
    if(isEvenlyEven(number)){
      #ifdef DIAGNOSTICS
      EVENLY_EVEN_TEXT(number);
      #endif
      return (posint_nature) EVENLY_EVEN;
    }
    #ifdef DIAGNOSTICS
    EVEN_TEXT(number);
    #endif
    return (posint_nature) EVEN;
  }
  #ifdef DIAGNOSTICS
  EVEN_TEXT(number);
  #endif
  return (posint_nature) EVEN;
} /* posint_nature intNature(posint number) */
