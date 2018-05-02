#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
    private:
        char ** board; //This will be used to dynamically allocate the array
        int row; //The number of rows (Y value)
        int col; //The number of cols (X value)
    public:
        Board(); //Default constructor. Will be set to 20x20 by default
        //Board(int row, int col); //This will possibly be used for the extra credit
        void printBoard(); //Prints the game board
        void deleteArray(); //Frees the dynamic memory
};
#endif
