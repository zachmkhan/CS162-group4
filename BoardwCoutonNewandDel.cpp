/*********************************************************************
** Program name: Board.cpp
** Author: Group 4
** Date: 5-6-2018
** Description: This file implements the two constructors, destructor,
** and functions of the Board class.
*********************************************************************/

#include "Board.hpp"
#include "util.hpp"
#include <iostream>
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <vector>

/*
 * Default Board:
 *  rows: 20
 *  cols: 20
 *  ants: 100
 *  doodle: 5
 */
Board::Board() : Board(20, 20, 100, 5) { }

/*
 * Construct custom board
 *  row: number of rows on the board
 *  cols: number of columns on the board
 *  ants: number of ants to start the game with
 *  doodle: number of doddlebugs to start the game with
 */
Board::Board(int r, int c, int a, int d)
{
    row = r;
    col = c;
    ant = a;
    doodle = d;
   
    //Creating the rXc dynamic 2d array below
    board = new Critter ** [row];
    for(int count = 0; count < row; count++)
    {
        board[count] = new Critter*[col];
        for(int count2 = 0; count2 < col; count2++)
		{
			board[count][count2] = nullptr;
		}
    }
    
    placeRandom();
}

//Destructor for the Board class
Board::~Board()
{
    //delete all the critters
    std::vector<Critter*>* critters = getCritters();
	for(unsigned int c = 0; c < critters->size(); c++)
	{
	std::cout <<"value *critter to be deleted at c " << &(critters->at(c))<< std::endl;	
	std::cout <<"value critter to be deleted at c " << critters->at(c)<< std::endl;	
	delete critters->at(c);
	critters->at(c) = nullptr;
	std::cout <<"value *critter deleted at c " << &(critters->at(c))<< std::endl;	
	std::cout <<"value critter to be deleted at c " << critters->at(c)<< std::endl;	
	}
	delete critters;
    
    //delete board array
    deleteArray();
}

/*
 * Prints the current state of the board to the console
 */
void Board::printBoard()
{
    for(int count = -1; count < row + 1; count++)
    {
        std::cout << '|'; //left border
        for(int count2 =  0; count2 < col; count2++)
        {
            if((count != -1) && (count != row)) //This is to allow for a top and bottom border
            {
                Critter* critter = board[count][count2];
                if(critter != nullptr)
                {
                    std::cout << critter->getCritterType();
                }
                else
                {
                    std::cout << ' '; 
                }
                
            }

            else //This will add a dash at the top and bottom of the array
            {
                std::cout << '-';
            }
             
        }
        std::cout << '|'; //right border
        std::cout<<std::endl; //Starting a new line for each row
    }
}

//This will delete the dynamic array
void Board::deleteArray()
{
    //delete the board array
    for(int count = 0; count < row; count++)
    {
      std::cout << "board[count] before delete " <<  board[count] << std::endl;
	 delete [] board[count];
      board[count] = nullptr;
	std::cout << "board[count] after delete " <<  board[count] << std::endl;
    }
	std::cout << "board before delete " << board << std::endl;
    delete [] board;

	std::cout << "board after delete "<< board << std::endl;
}

/*
 * Place inital critters randomly on the board
 */
void Board::placeRandom()
{
    // Place all the initial ants at random locations
    for(int a = 0; a < ant; a++)
    {
        //find a random point that is not yet occupied
        int randomRow = -1;
        int randomCol = -1;
        do
        {
            randomRow = randomBetween(0, row-1);
            randomCol = randomBetween(0, col-1);
        }while(board[randomRow][randomCol] != nullptr); //nullprt means no critter is located at that coordinate
       
 
	std::cout << "value before Ant placed " << board[randomRow][randomCol] << std::endl;
        board[randomRow][randomCol] = new Ant(randomRow, randomCol, row, col, board);
	std::cout << "value after Ant placed " << board[randomRow][randomCol] << std::endl;
	    
}
    
    // Place all the initial doodlebugs at random locations
    for(int d = 0; d < doodle; d++)
    {
        //find a random point that is not yet occupied
        int randomRow = -1;
        int randomCol = -1;
        do
        {
            randomRow = randomBetween(1, row) - 1;
            randomCol = randomBetween(1, col) - 1;
        }while(board[randomRow][randomCol] != nullptr); //nullprt means no critter is located at that coordinate
        
	std::cout << "value before Doodle placed " << board[randomRow][randomCol] << std::endl;
        board[randomRow][randomCol] = new Doodlebug(randomRow, randomCol, row, col, board);
	std::cout << "after doodle placed " << board[randomRow][randomCol] << std::endl;
    }
}

/*
 * returns a vector of all critters currently on the board
 */
std::vector<Critter*>* Board::getCritters()
{
    std::vector<Critter*>* critters = new std::vector<Critter*>();
    for(int r= 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            Critter* critter = board[r][c];
            if(critter != nullptr)
            {
                critters->push_back(critter);
            }
        }
    }
    return critters;
}
