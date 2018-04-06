#include <stdio.h>
/* Nature of a positive integer */
typedef unsigned char posint_nature;

/* For a 'modern' programmer :) */
typedef unsigned char bool;

/* Considering only positive integers. May be redefined to long double on supported OS */
typedef unsigned long posint;

/* Nature of Positive number as required by this program. */
#define EVEN          '0'
#define ODD           '1'
#define POWER_OF_2    '2'
#define THRESHOLD     4 /* Use when checking for POWER OF 2  to reduce call stack */
#define ODD_DIV_BY_3  '3'
#define EVENLY_EVEN   '4'

#ifdef DIAGNOSTICS
/* Nature of positive number in textual form, for diagnostic purposes */
/* Colors for displaying text */
#define ESC     "\x1B"  /* = 27 */

#define END     "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
/* Positive integer nature in textual form */
#define EVEN_TEXT(x) printf("%s%ld%s is an %s'EVEN'%s number.\n",(x),YELLOW,END,GREEN,END)
#define ODD_TEXT(x) printf("%s%ld%s is an %s'ODD'%s number.\n",(x),YELLOW,END,GREEN,END)
#define ODD_DIV_BY_3_TEXT(x) printf("%s%ld%s is an %s'ODD'%s number divisible by 3.\n",(x),YELLOW,END,GREEN,END)
#define EVENLY_EVEN_TEXT(x) printf("%s%ld%s is an %s'EVENLY EVEN'%s number.\n",(x),YELLOW,END,GREEN,END)
#endif /* DIAGNOSTICS */
/* Boolean value !!! */
#define FALSE 0
/* Please do not define TRUE. It will be risky in C, if not careful */
/*  Well, if you insist ... */
#define TRUE(x) ((x) != FALSE)

bool isEven(posint number);
bool isOdd(posint number);
bool isDivBy3(posint number);
bool isEvenlyEven(posint number);

posint_nature intNature(posint number);
