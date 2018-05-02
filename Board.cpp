#include "Board.hpp"

//Default constructor that fills the array to 20x20
Board::Board()
{
    row = 20; //By default
    col = 20; //By default
    ant = 100; //Default number of ants
    doodle = 5; //Default number of doodles

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

//This will randomly place the ants and doodlebugs
//For now it will not be random
//I will add this near the end so we know that it works
void Board::placeRandom()
{

    //These two for loops will check to make sure that the spaces are not occupied for the doodlebugs
	for(int count = 0; count < row; count++)
	{
		for(int count2 = 0; count2 < col; count2++)
		{
            bool doodleFlag = true; //This will be used if a space is occupied;
            //Adding the doodle bugs to the array
            while(doodleFlag)
            {
                if(doodle == 0) //if there are no doodlebugs
                {
                    goto end;
                }

                //If the space can be occupied by a critter
    			if(board[count][count2] != 'O' && board[count][count2] != 'X')
                {
                    doodle--; //subtracting a doodlebug
                    doodleFlag = false;
                    board[count][count2] = 'X'; //setting the space as a doodlebug

                }
                else //The space is occupied
                {
                    //I will need to call the class to get a new random location
                    break;
                }
            }
		}
	}

    end:
    std::cout << "All of the doodlebugs have been placed" << std::endl;



     //These two for loops will check to make sure that the spaces are not occupied for the ants
	for(int count = 0; count < row; count++)
	{
		for(int count2 = 0; count2 < col; count2++)
		{
            bool antFlag = true; //This will be used if a space is occupied;
            //Adding the doodle bugs to the array
            while(antFlag)
            {
                //If there are no more ants
                if(ant == 0)
                {
                    goto end2;
                }

                //If the space can be occupied by a critter
    			if(board[count][count2] != 'O' && board[count][count2] != 'X')
                {
                    ant--; //Subtracting an ant;
                    antFlag = false;
                    board[count][count2] = 'O'; //Setting the space as an ant

                }
                else //The space is occupied
                {
                    //I will need to call the class to get a new random location
                    break;
                }
            }
		}
	} 

    end2:
    std::cout << "All of the ants have been placed" << std::endl;

}