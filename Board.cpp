#include "Board.hpp"

//Default constructor that fills the array to 20x20
Board::Board()
{
    row = 20; //By default
    col = 20; //By default

    //Creating the 20x20 dynamic 2d array below
    board = new char * [row];
    for(int count = 0; count < row; count++)
    {
        board[count] = new char[col];
    }

    //Filling the array below
    //I am filling the array with the char 'X' for debugging purposes
	for(int count = 0; count < row; count++)
	{
		for(int count2 = 0; count2 < col; count2++)
		{
			board[count][count2] = ' '; //This should print a space in the future
		}
	}

}

//This will print the board
void Board::printBoard()
{
    for(int count = -1; count < row + 1; count++)
    {
        std::cout << '|'; //left border
        for(int count2 =  0; count2 < col; count2++)
        {
            if((count != -1) && (count != row)) //This is to allow for a top and bottom border
            {
                std::cout << board[count][count2];

                //This if statement allows for the right border to not have a space
                if(count2 < (col - 1))
                {
                    std::cout << ' '; 
                }
            }

            else //This will add a dash at the top and bottom of the array
            {
                std::cout << '-' << ' ';
            }
        }
        std::cout << '|'; //right border
        std::cout<<std::endl; //Starting a new line for each row
    }
}

//This will delete the dynamic array
void Board::deleteArray()
{
    for(int count = 0; count < row; count++)
    {
        delete [] board[count];
    }
    delete [] board;
}
