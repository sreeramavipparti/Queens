/*
 * Constants used in Queens program C++ implementation
 **/

// Board size nature
#define SINGLY_EVEN  0x01
#define DOUBLY_EVEN  0x02
#define ODD          0x04
#define ODD_DIV_BY_3 0x08
// Aliases for board size nature
#define EVEN        SINGLY_EVEN
#define EVENLY_EVEN DOUBLY_EVEN
#define POWER_OF_2  EVENLY_EVEN

typedef struct Nature {
	unsigned char data : 4;
} NATURE;