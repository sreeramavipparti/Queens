#include "Constants.h"
#include "Board.h"
#include <cassert>

// Board ctors
Board::Board(unsigned long size) {
	assert(size >= (unsigned long) MIN_SIZE);
	this->size = size;
} // Board(unsigned long size)

// Board methods
bool Board::isSinglyEven() {
	return this->size % 2 == 0;
}
bool Board::isDoublyEven() {
	return this->isSinglyEven() && this->size % 4 == 0;
}
bool Board::isOdd() {
	return !this->isSinglyEven();
}
bool Board::isOddDivBy3() {
	return this->isOdd() && this->size % 3 == 0;
}

NATURE Board::nature() {
	NATURE n;
	if(this->isSinglyEven()) n.data = DOUBLY_EVEN;
	else if(this->isSinglyEven()) n.data = SINGLY_EVEN;
	else if(this->isOddDivBy3()) n.data = ODD_DIV_BY_3;
	else n.data = ODD;
	return n;
}