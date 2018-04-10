/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package queens;

/**
 *
 * @author admin
 */
public class Java {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int size = Integer.parseInt(args[0]);
        if(size < Constants.MIN_BOARD_SIZE)
            size = Constants.MIN_BOARD_SIZE;
        Board board = new Board(size);
        board.buildBoard();
        board.printBoard();
    }
    
}
