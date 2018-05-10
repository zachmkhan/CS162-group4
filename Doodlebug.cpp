/*********************************************************************
** Program name: Doodlebug.cpp
** Author: Group 4
** Date: 5-9-2018
** Description: This file implements the Doodlebug constructor, step, 
** breed, and move functions.
*********************************************************************/

#include "Doodlebug.hpp"
#include <ctime>					// For time()
#include <cstdlib>					// For srand() and rand()
#include "Critter.hpp"
#include <iostream>
#include "util.hpp"

Doodlebug::Doodlebug(int x, int y, int r, int c, Critter*** board) : Critter('X', x, y, r, c, board)
{
 
}

/*
 * Calls the move, bread and starve method for this doodlebug
 */
void Doodlebug::step()
{
	Move();
	Breed();
	return Starve();
}

/*
* Makes the Doodlebug try to eat an ant that is directly next to it. If there are no ants next to it
* the Doodlebug will randomly try to move to another space. If it fails to move the first try, then the Doodlebug does not move.
*/
void Doodlebug::Move()
{
	std::cout << "ROW: " << rowLocation << "     COL: " << colLocation <<std::endl;
	if (onboard(rowLocation, colLocation + 1) && board[rowLocation][colLocation + 1] != nullptr && board[rowLocation][colLocation + 1]->getCritterType() == 'O')
	{
		board[rowLocation][colLocation + 1] = nullptr;
		board[rowLocation][colLocation + 1] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
		board[rowLocation][colLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		std::cout << "Doodlebug Old Row " << rowLocation << " Old Column " << colLocation << std::endl;
		colLocation = colLocation + 1;								//The Doodlebug moves right
		std::cout << "New Row " << rowLocation << " New Column " << colLocation << std::endl;
	}
	//Tries to go left to eat an ant
	else if (onboard(rowLocation, colLocation - 1) && board[rowLocation][colLocation - 1] != nullptr && board[rowLocation][colLocation - 1]->getCritterType() == 'O')
	{
		delete board[rowLocation][colLocation - 1];
		board[rowLocation][colLocation - 1] = nullptr;
		board[rowLocation][colLocation - 1] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
		board[rowLocation][colLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		std::cout << "Doodlebug Old Row " << rowLocation << " Old Column " << colLocation << std::endl;
		colLocation = colLocation - 1;								//The Doodlebug moves left
		std::cout << "New Row " << rowLocation << " New Column " << colLocation << std::endl;
	}
	//Tries to go down to eat an ant
	else if (onboard(rowLocation + 1, colLocation) && board[rowLocation + 1][colLocation] != nullptr && board[rowLocation + 1][colLocation]->getCritterType() == 'O')
	{
		delete board[rowLocation + 1][colLocation];
		board[rowLocation + 1][colLocation] = nullptr;
		board[rowLocation + 1][colLocation] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
		board[rowLocation][colLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		std::cout << "Doodlebug Old Row " << rowLocation << " Old Column " << colLocation << std::endl;
		rowLocation = rowLocation + 1;								//The Doodlebug moves down
		std::cout << "New Row " << rowLocation << " New Column " << colLocation << std::endl;
	}
	//Tries to go up to eat an ant
	else if (onboard(rowLocation - 1, colLocation) && board[rowLocation - 1][colLocation] != nullptr && board[rowLocation - 1][colLocation]->getCritterType() == 'O')
	{
		delete board[rowLocation - 1][colLocation];
		board[rowLocation - 1][colLocation] = nullptr;
		board[rowLocation - 1][colLocation] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
		board[rowLocation][colLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		std::cout << "Doodlebug Old Row " << rowLocation << " Old Column " << colLocation << std::endl;
		rowLocation = rowLocation - 1;								//The Doodlebug moves up
		std::cout << "New Row " << rowLocation << " New Column " << colLocation << std::endl;
	}
	//There were no ants for the doodlebug to eat
	else
	{
		std::cout << "no ants for doodlebug to eat " << std::endl;
		int randomMove = rand() % 4 + 1;					//Random number for the 4 different directions
		switch (randomMove)
		{
			//Moving Right
		case 1:
			if (onboard(rowLocation, colLocation + 1) && board[rowLocation][colLocation + 1] == nullptr)
			{
				board[rowLocation][colLocation + 1] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
				delete [] **board;
				board[rowLocation][colLocation] = nullptr;
				std::cout << "Doodlebug Old Row " << rowLocation << " Old Column " << colLocation << std::endl; 
				colLocation += 1;														//The Doodlebug moves Right
				std::cout << "New Row " << rowLocation << " New Column " << colLocation << std::endl;
			}
			else
			{
				std::cout << "Doodlebug can't move right" << std::endl;
			}
			break;
			//Moving Left
		case 2:
			if (onboard(rowLocation, colLocation - 1) > 0 && board[rowLocation][colLocation - 1] == nullptr)
			{
				board[rowLocation][colLocation - 1] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
				board[rowLocation][colLocation] = nullptr;
				std::cout << "Doodlebug Old Row " << rowLocation << " Old Column " << colLocation << std::endl;
				colLocation -= 1;														//The Doodlebug moves Left
				std::cout << "New Row " << rowLocation << " New Column " << colLocation << std::endl;
			}
			else
			{
				std::cout << "Doodlebug can't move left" << std::endl;
			}
			break;
			//Moving Down
		case 3:
			if (onboard(rowLocation + 1, colLocation) && board[rowLocation + 1][colLocation] == nullptr)
			{

				board[rowLocation + 1][colLocation] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
				board[rowLocation][colLocation] = nullptr;
				std::cout << "Doodlebug Old Row " << rowLocation << " Old Column " << colLocation << std::endl;
				rowLocation += 1;														//The Doodlebug moves Down
				std::cout << "New Row " << rowLocation << " New Column " << colLocation << std::endl;
			}
			else
			{
				std::cout << "Doodlebug can't move down" << std::endl;
			}
			break;
			//Moving Up
		case 4:
			if (onboard(rowLocation - 1, colLocation) && board[rowLocation - 1][colLocation] == nullptr)
			{
				board[rowLocation - 1][colLocation] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
				board[rowLocation][colLocation] = nullptr;
				std::cout << "Doodlebug Old Row " << rowLocation << " Old Column " << colLocation << std::endl;
				rowLocation -= 1;														//The Doodlebug moves Up
				std::cout << "New Row " << rowLocation << " New Column " << colLocation << std::endl;
			}
			else
			{
				std::cout << "Doodlebug can't move up" << std::endl;
			}
			break;
		}
		stepsSinceEating += 1;							//Increment how long since the doodlebug has eaten
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		std::cout << "Steps Since Eating " << stepsSinceEating << std::endl;
		std::cout << "Steps Since Breeding " << stepsSinceBreeding << std::endl;

	}
}

bool Doodlebug::breedDown()
{
	if(onboard(rowLocation + 1, colLocation) && board[rowLocation + 1][colLocation] == nullptr)
	{
		std::cout << "NEW ALLOCATION BREEDDOWN" << std::endl;
		board[rowLocation + 1][colLocation] = new Doodlebug(rowLocation + 1, colLocation, row, col, board);
		return true;
		
	}
	return false;
	
}

bool Doodlebug::breedUp()
{
	if(onboard(rowLocation - 1, colLocation) >= 0 && board[rowLocation - 1][colLocation] == nullptr)
	{
		std::cout << "NEW ALLOCATION BREEDUP" << std::endl;
		board[rowLocation - 1][colLocation] = new Doodlebug(rowLocation - 1, colLocation, row, col, board);
		return true;
	}
	return false;
}

bool Doodlebug::breedLeft()
{
	if(onboard(rowLocation, colLocation - 1) && board[rowLocation][colLocation - 1] == nullptr)
	{
		std::cout << "NEW ALLOCATION BREEDLEFT" << std::endl;
		board[rowLocation][colLocation - 1] = new Doodlebug(rowLocation, colLocation - 1, row, col, board);
		return true;
	}

	return false;
}

bool Doodlebug::breedRight()
{
	if(onboard(rowLocation, colLocation + 1) && board[rowLocation][colLocation + 1] == nullptr)
	{
		std::cout << "NEW ALLOCATION BREEDRIGHT" << std::endl;
		board[rowLocation][colLocation + 1] = new Doodlebug(rowLocation, colLocation + 1, row, col, board);
		return true;
	}

	return false;
}

/**********************************************************************************************************
** Description: Ant::Breed creates an ant in a random empty cell ajacent to the ant who calls the function
**********************************************************************************************************/
void Doodlebug::Breed()
{
	if(stepsSinceBreeding > 8)
	{
		std::cout << "DOODLEBUG BREED HAS BEEN CALLED" << std::endl;
		int randomMove = randomBetween(1, 4);										//Random number for the 4 different directions

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

/**********************************************************************************************************
** Description: Checks if the doddlebug has not eat in three days, if so it removes it from the board.
**********************************************************************************************************/
void Doodlebug::Starve()
{
	if(stepsSinceEating >=3)
	{
		std::cout<<"DOODLEBUG IS GOING TO DIE" << std::endl;
		std::cout << "Row " << rowLocation << " Column " << colLocation << std::endl;
		delete board[rowLocation][colLocation];
		board[rowLocation][colLocation] = nullptr;
		// delete this; causes error for some reason
	}

}
