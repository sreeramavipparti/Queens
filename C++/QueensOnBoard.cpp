using namespace std;

#include "Constants.h"
#include "Board.h"
#include <cassert>
#include <iostream>

// Board ctors
Board::Board(unsigned long size) {
	assert(size >= (unsigned long) MIN_SIZE);
	this->size = size;
	board = vector<tuple<unsigned long, unsigned long>>(this->size);
} // Board(unsigned long size)
Board::~Board() {
} // Board::~Board

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
	if(this->isDoublyEven()) n.data = DOUBLY_EVEN;
	else if(this->isSinglyEven()) n.data = SINGLY_EVEN;
	else if(this->isOddDivBy3()) n.data = ODD_DIV_BY_3;
	else n.data = ODD;
	return n;
} // Board::nature()

tuple<unsigned long, unsigned long> Board::placeNextQueen(tuple<unsigned long, unsigned long> queen, char direction) {
	unsigned long row = get<0>(queen);
	unsigned long col = get<1>(queen);
	switch(direction) {
		case RIGHT: {
			row += MOVE_VERT;
			col += MOVE_HORIZ;
			if(row > this->size)
				row = 1;
			if(col > this->size)
				col -= this->size;
		}
		break;
		case LEFT: {
			row -= MOVE_VERT;
			if(row < 1)
				row = this->size;
			switch(col) {
				case 2: col = this->size; break;
				case 1: col = this->size-1; break;
				default: col -= MOVE_HORIZ; break;
			}
		}
		break;
	}
	return tuple<unsigned long, unsigned long>(row, col);
} // Board::placeNextQueen

void Board::placeAllQueens(NATURE nature) {
	if(nature.data & DOUBLY_EVEN) {
		this->performDoublyEven();
		return;
	}
	if(nature.data & SINGLY_EVEN) {
		this->performSinglyEven();
		return;
	}
	if(nature.data & ODD_DIV_BY_3) {
		this->performOddDivBy3();
		return;
	}
	if(nature.data & ODD) {
		this->performOdd();
		return;
	}
	// throw an exception "How is it possible?"
} // Board::placeAllQueens

/*
 * Board size evenly/doubly even and also as powers of 2 from 2^2 ie 4, 8, 16, 32, ...
 *    - Place 2 queens one each at (1, N/2) and (N, (N/2)+1). Let us call them first and last.
 *    - Divide queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (1, N/2) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N/2)+1) in left direction.
 ***/

void Board::performDoublyEven() {
	tuple<unsigned long, unsigned long> first(1, this->size/2);
	tuple<unsigned long, unsigned long> last(this->size, 1+this->size/2);
	unsigned long firstCtr = 0;
	unsigned long lastCtr = this->size-1;
	board[firstCtr++] = first;
	board[lastCtr--] = last;
	this->placeQueens((this->size-2)/2, first, last, firstCtr, lastCtr);
}
/*
 * Board size oddly even/singly even and also not divsible by 4
 *    - Divide queens into 2 halves.
 *    - Start placing first half of the queens from first cell (1,2) in right direction.
 *    - Start placing second half of the queens from last cell (N, (N-1)) in left direction.
 ***/
void Board::performSinglyEven() {
	tuple<unsigned long, unsigned long> first(1, 2);
	tuple<unsigned long, unsigned long> last(this->size, this->size-1);
	unsigned long firstCtr = 0;
	unsigned long lastCtr = this->size-1;
	board[firstCtr++] = first;
	board[lastCtr--] = last;
	this->placeQueens((this->size-2)/2, first, last, firstCtr, lastCtr);	
}
/*
 * Odd numbers divisible by 3 ie 9, 15, 21, ...
 *    - Place a queen at (1, N). Now even number of queens remain.
 *    - Divide remaining queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (2, 1) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N-1)) in left direction.
 ***/
void Board::performOddDivBy3() {
	tuple<unsigned long, unsigned long> intital(1, this->size);
	tuple<unsigned long, unsigned long> first(1, this->size-1);
	tuple<unsigned long, unsigned long> last(this->size+1, 1);
	unsigned long firstCtr = 0;
	unsigned long lastCtr = this->size-1;
	board[firstCtr++] = intital;
	this->placeQueens((this->size-1)/2, first, last, firstCtr, lastCtr);
}
/*
 * All other odd numbers
 *    - Place a queen at (1,1). Now even number of queens remain.
 *    - Divide remaining queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (2, 3) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N-1)) in left direction.
 **/
void Board::performOdd() {
	tuple<unsigned long, unsigned long> first(1, 1);
	unsigned long firstCtr = 0;
	unsigned long lastCtr = this->size-1;
	board[firstCtr++] = first;
	this->placeQueens((this->size-1)/2, first, first, firstCtr, lastCtr);
}

void Board::placeQueens(unsigned long limit, 
	tuple<unsigned long, unsigned long>first, 
	tuple<unsigned long, unsigned long>last,
	unsigned long firstCtr, 
	unsigned long lastCtr) {
	for(unsigned long i1=1, i2=this->size-1;
		i1 <= limit;
		i1++, i2--) {
		first = placeNextQueen(first, RIGHT);
		last = placeNextQueen(last, LEFT);
		board[firstCtr++] = first;
		board[lastCtr--] = last;
	}
}

void Board::printBoard() {
	for(auto brd = this->board.cbegin(); brd != this->board.cend(); ++brd) {
		cout << "(" << get<0>(*brd) << ", " << get<1>(*brd) << ")" << endl;
	}
}
void Board::buildBoard() {
	this->placeAllQueens(this->nature());
}