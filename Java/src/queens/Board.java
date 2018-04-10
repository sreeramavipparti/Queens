/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package queens;

import java.awt.Point;
import java.util.Vector;

/**
 *
 * @author admin
 */
public class Board {
    private final int size;
    private Vector<Point> board;
    
    public Board(int size) {
        this.size = size;
        this.board = new Vector<>(this.size);
        int i=0;
        for(i=0;i<this.size;i++){
            this.board.add(null);
        }
    }
    
    public void buildBoard() {
        this.placeAllQueens(this.nature());
    }
    
    public void printBoard() {
        String opStr = "(%"+
               Constants.OP_COL_WIDTH+"d, %"+
                Constants.OP_COL_WIDTH+"d)\n";
        this.board.forEach((pt)->{
            System.out.printf(opStr,pt.x,pt.y);
        });
    }
    
    private boolean isSinglyEven() {
        return this.size % 2 == 0;
    }
    private boolean isDoublyEven() {
        return this.isSinglyEven() && this.size % 4 == 0;
    }
    private boolean isOdd() {
        return !this.isSinglyEven();
    }
    private boolean isOddDivBy3() {
        return this.isOdd() && this.size % 3 == 0;
    }
    private short nature() {
        if(this.isDoublyEven()) return Constants.DOUBLY_EVEN;
        if(this.isSinglyEven()) return Constants.SINGLY_EVEN;
        if(this.isOddDivBy3()) return Constants.ODD_DIV_BY_3;
        return Constants.ODD;
    }
    private Point placeNextQueen(Point queen, char direction) {
        int row = queen.x;
        int col = queen.y;
        switch(direction) {
            case Constants.RIGHT: {
                row += Constants.ONE;
                col += Constants.TWO;
                if(row > this.size)
                    row = 1;
                if(col > this.size)
                    col -= this.size;
            }
            break;
            case Constants.LEFT: {
                row -= Constants.ONE;
                if(row < 1)
                    row = this.size;
                switch(col) {
                    case 2: col = this.size; break;
                    case 1: col = this.size-1; break;
                    default: col -= Constants.TWO; break;
                }
            }
            break;
        }
        return new Point(row, col);
    }
    
    private void placeQueens(int limit, 
        Point first, Point last, 
        int firstCtr, int lastCtr) {
        int i1;
        int i2;
        for(i1=firstCtr,i2=lastCtr;
            i1 <= limit;
            i1++, i2--) {
            first = this.placeNextQueen(first, Constants.RIGHT);
            last = this.placeNextQueen(last, Constants.LEFT);
            this.board.set(i1, first);
            this.board.set(i2, last);
        }
    }
    private void placeAllQueens(short nature) {
        switch(nature) {
            case Constants.DOUBLY_EVEN:
                this.performDoublyEven();
        }
    }
/*
 * Board size evenly/doubly even and also as powers of 2 from 2^2 ie 4, 8, 16, 32, ...
 *    - Place 2 queens one each at (1, N/2) and (N, (N/2)+1). Let us call them first and last.
 *    - Divide queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (1, N/2) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N/2)+1) in left direction.
 ***/   
    private void performDoublyEven() {
        Point first = new Point(1, this.size/2);
        Point last = new Point(this.size, 1+this.size/2);
        int firstCtr = 0;
        int lastCtr = this.size-1;
        this.board.set(firstCtr++, first);
        this.board.set(lastCtr--, last);
        this.placeQueens((this.size-2)/2, first, last, firstCtr, lastCtr);
    }
/*
 * Board size oddly even/singly even and also not divsible by 4
 *    - Divide queens into 2 halves.
 *    - Start placing first half of the queens from first cell (1,2) in right direction.
 *    - Start placing second half of the queens from last cell (N, (N-1)) in left direction.
 ***/
    private void performSinglyEven() {
        Point first = new Point(1, 2);
        Point last = new Point(this.size, this.size-1);
        int firstCtr = 0;
        int lastCtr = this.size-1;
        this.board.set(firstCtr++, first);
        this.board.set(lastCtr--, last);
        this.placeQueens((this.size-2)/2, first, last, firstCtr, lastCtr);
    }
/*
 * Odd numbers divisible by 3 ie 9, 15, 21, ...
 *    - Place a queen at (1, N). Now even number of queens remain.
 *    - Divide remaining queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (2, 1) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N-1)) in left direction.
 ***/
    private void performOddDivBy3() {
        Point intital = new Point(1, this.size);
        Point first = new Point(1, this.size-1);
        Point last = new Point(this.size+1, 1);
        int firstCtr = 0;
        int lastCtr = this.size-1;
        this.board.set(firstCtr++, intital);
        this.placeQueens((this.size-1)/2, first, last, firstCtr, lastCtr);
    }
/*
 * All other odd numbers
 *    - Place a queen at (1,1). Now even number of queens remain.
 *    - Divide remaining queens into 2 halves.
 *    - Start placing first half of the queens from begin cell (2, 3) in right direction.
 *    - Start placing second half of the queens from end cell (N, (N-1)) in left direction.
 **/
    private void performOdd() {
        Point first = new Point(1, 1);
        int firstCtr = 0;
        int lastCtr = this.size-1;
        this.board.set(firstCtr++,first);
        this.placeQueens((this.size-1)/2, first, first, firstCtr, lastCtr);
    }
}
