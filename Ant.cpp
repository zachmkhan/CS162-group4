/*********************************************************************
** Program name: Ant.cpp
** Author: Group 4
** Date: 5-4-2018
** Description: This file implements the Ant constructor, step, breed,
** and move functions.
*********************************************************************/

#include "Ant.hpp"
#include <ctime>					// For time()
#include <cstdlib>					// For srand() and rand()
#include "util.hpp"
#include <string>
#include <iostream>
/*
 * Initialize new ant
 *	 x: starting x coordinate for the new ant
 *	 y: starting y coordinate for new ant
 *	 board: pointer the the game board
 */
Ant::Ant(int x, int y,int r, int c, Critter*** board) : Critter('O', x, y, r, c, board)
{
    stepsSinceBreeding = 0;
}

/*
 * Calls the move and bread method for this ant
 */
void Ant::step()
{
	//ant was eaten do not move just return
	if(board[rowLocation][colLocation]->getCritterType() == 'X') 
	{
		return;
	}
	Move();
	Breed();
}

/*
 * Makes the Ant try to move in a random direction. If it fails to move the first try, then the ant does not move. 
 */
void Ant::Move()
{
	int randomMove = rand() % 4 + 1;				//Random number for the 4 different directions

	switch (randomMove)
	{

		//Moving Right
	case 1:
		if (onboard(rowLocation, colLocation + 1) && board[rowLocation][colLocation + 1] == nullptr)
		{
			move(rowLocation, colLocation, rowLocation, colLocation + 1);//The Ant moves right
		}

		break;

		//Moving Left
	case 2:
		if (onboard(rowLocation, colLocation - 1)  && board[rowLocation][colLocation - 1] == nullptr)
		{
			move(rowLocation, colLocation, rowLocation, colLocation - 1);//The Ant moves left
		}

		break;

		//Moving Down
	case 3:
		if (onboard(rowLocation + 1, colLocation)  && board[rowLocation + 1][colLocation] == nullptr)
		{
			move(rowLocation, colLocation, rowLocation + 1, colLocation);//The Ant moves down
		}

		break;

		//Moving Up
	case 4:
		if (onboard(rowLocation - 1, colLocation)  && board[rowLocation - 1][colLocation] == nullptr)
		{
			move(rowLocation, colLocation, rowLocation - 1, colLocation );//The Ant moves up
		}

		break;
	}

	stepsSinceBreeding += 1;					//Increment how long since the doodlebug had babies
}

/**********************************************************************************************************
** Description: Ant::breedDown() tests the location above the Ant to see if the Ant can produce
** a new Ant in that location. If it is null, a new ant is created at the location.
**********************************************************************************************************/
bool Ant::breedDown()
{
	if(onboard(rowLocation, colLocation + 1)  && board[rowLocation][colLocation + 1] == nullptr) //yLoc +1 row -1 cancel each other out using straight values
	{
		board[rowLocation][colLocation + 1] = new Ant(rowLocation , colLocation + 1, row, col, board);
		return true;
	}
	
	return false;
}

/**********************************************************************************************************
** Description: Ant::breedUp() tests the location below the Ant to see if the Ant can produce
** a new Ant in that location. If it is null, a new ant is created at the location.
**********************************************************************************************************/
bool Ant::breedUp()
{
	if(onboard(rowLocation, colLocation - 1)  && board[rowLocation][colLocation - 1] == nullptr)
	{
		board[rowLocation][colLocation - 1] = new Ant(rowLocation, colLocation - 1, row, col, board);
		return true;
	}
	return false;
}

/**********************************************************************************************************
** Description: Ant::breedLeft() tests the location to the left of the Ant to see if the Ant can produce
** a new Ant in that location. If it is null, a new ant is created at the location.
**********************************************************************************************************/
bool Ant::breedLeft()
{
	if(onboard(rowLocation - 1, colLocation)  && board[rowLocation - 1][colLocation] == nullptr)
	{
		board[rowLocation - 1][colLocation] = new Ant(rowLocation - 1, colLocation, row, col, board);
		return true;
	}
	return false;
}

/**********************************************************************************************************
** Description: Ant::breedRight() tests the location to the right of the Ant to see if the Ant can produce
** a new Ant in that location. If it is null, a new ant is created at the location.
**********************************************************************************************************/
bool Ant::breedRight()
{

	if(onboard(rowLocation + 1, colLocation)  && board[rowLocation + 1][colLocation] == nullptr) //xLoc+1 col-1 cancel each other out using straight values
	{
		board[rowLocation + 1][colLocation] = new Ant(rowLocation + 1, colLocation, row, col, board);
		return true;
	}
	
	return false;
}


/**********************************************************************************************************
** Description: Ant::Breed creates an ant in a random empty cell ajacent to the ant who calls the function
**********************************************************************************************************/
void Ant::Breed()
{
	if(stepsSinceBreeding > 3)
	{
		int randomMove = randomBetween(1, 4);			//Random number for the 4 different directions

		switch (randomMove)
		{
			case 1:
				breedUp() || breedDown() || breedLeft() || breedRight();
				break;
			case 2:
				breedDown() || breedLeft() || breedRight() || breedUp();
				break;
			case 3:
				breedLeft() || breedRight() || breedUp() || breedDown();
				break;
			case 4:
				breedRight() || breedUp() || breedDown() || breedLeft();
				break;
		}
		stepsSinceBreeding = 0;
	}
	
}
