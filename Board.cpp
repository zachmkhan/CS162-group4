#include "Board.hpp"

//Default constructor that fills the array to 20x20
Board::Board()
{
    row = 20; //By default
    col = 20; //By default

    //Creating the 20x20 dynamic 2d array below
    board = new char * [row];
    for(int count = 0; count < row; ++count)
    {
        board[count] = new char[col];
    }

    //Filling the array below
    //I am filling the array with the char 'X' for debugging purposes
    for(int count = 0; count < row; ++count)
    {
        for(int count2 = 0; count2 < col; ++count2);
        {
            board[row][col] = 'X'; //This would normally be the space character
        }
    }

}

//This will print the board
void Board::printBoard()
{
    for(int count = 0; count < row; ++count)
    {
        for(int count2 = 0; count2 < col; ++count2)
        {
            std::cout << board[row][col] << std::endl;
        }
    }
}

//This will delete the dynamic array
void Board::deleteArray()
{
    for(int count = 0; count < row; ++count)
    {
        delete [] board[count];
    }
    delete [] board;
}
