/*
 ** Client Program to Queens On Board
 */
using namespace std;
#include <iostream>
#include "Constants.h"
#include "Board.h"

int main(int argc, char* argv[]) {
	unsigned long size = MIN_SIZE;
	if(argc > 1)
		size = strtoul(argv[1],NULL,10);
	cout << "Size of board given: " << size << endl;
	Board board(size);
	board.buildBoard();
	board.printBoard();
	return 0;
}