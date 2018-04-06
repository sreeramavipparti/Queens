/*
 * N - Queens problem
 * The challenge is to place N queens on an NxN chess board, so that no queen captures any other queen on board.
 *
 * The task is divided into the following parts
 * 1. Board size evenly even and also as powers of 2 ie 4, 8, 16, 32, ...
 *    - Place 2 queens one each at (1, N/2) and (N, (N/2)+1). Let us call them begin and end.
 *    - Divide queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (1, N/2) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N/2)+1) in left direction.
 *
 * 2. All other even numbers
 *    - Divide queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (1,2) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N-1)) in left direction.
 *
 * 3. Odd numbers divisible by 3 ie 9, 15, 21, ...
 *    - Place a queen at (1, N). Now even number of queens remain.
 *    - Divide remaining queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (2, 1) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N-1)) in left direction.
 *
 * 4. All other odd numbers
 *    - Place a queen at (1,1). Now even number of queens remain.
 *    - Divide remaining queens into 2 halves.
 *    - Start placing first half of the queens fror begin cell (2, 3) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N-1)) in left direction.
 **/

/*
 * Chess board class with operations
 */
#define MIN_SIZE  4 // Minimum board size. Boards below this size have no solution

// Queen movement quantums
#define MOVE_HORIZ 2
#define MOVE_VERT  1

class Board {
	private:
		unsigned long size;

	public:
		// ctors
		Board(unsigned long size = (unsigned long) MIN_SIZE);

		// methods
		void placeAllQueens(NATURE);

	private:
		// methods
		NATURE nature();
		inline bool isSinglyEven();
		inline bool isDoublyEven();
		inline bool isOdd();
		inline bool isOddDivBy3();
		tuple<unsigned long, unsigned long>placeNextQueen(tuple<unsigned long, unsigned long> queen);
		tuple<unsigned long, unsigned long>nextQueen(DIRECTION dir);
}; // class Board

