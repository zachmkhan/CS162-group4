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
	Move();
	Breed();
}

/*
 * Makes the Ant try to move in a random direction. If it fails to move the first try, then the ant does not move. 
 */
void Ant::Move()
{
	int randomMove = rand() % 4 + 1;										//Random number for the 4 different directions

	switch (randomMove)
	{

		//Moving Up
	case 1:
		if (yLocation < row - 1 && board[xLocation][yLocation + 1] == nullptr)
		{
			board[xLocation][yLocation + 1] = board[xLocation][yLocation];		//The Ant moves to the new space
			board[xLocation][yLocation] = nullptr;

			yLocation += 1;														//The Ant moves up
		}

		break;

		//Moving Down
	case 2:
		if (yLocation > 0 && board[xLocation][yLocation - 1] == nullptr)
		{
			board[xLocation][yLocation-1] = board[xLocation][yLocation];		//The Ant moves to the new space
			board[xLocation][yLocation] = nullptr;

			yLocation -= 1;														//The Ant moves down
		}

		break;

		//Moving Right
	case 3:
		if (xLocation < col - 1 && board[xLocation + 1][yLocation] == nullptr)
		{
			board[xLocation + 1][yLocation] = board[xLocation][yLocation];		//The Ant moves to the new space
			board[xLocation][yLocation] = nullptr;

			xLocation += 1;														//The Ant moves right
		}

		break;

		//Moving Left
	case 4:
		if (xLocation > 0 && board[xLocation - 1][yLocation] == nullptr)
		{
			board[xLocation - 1][yLocation] = board[xLocation][yLocation];		//The Ant moves to the new space
			board[xLocation][yLocation] = nullptr;

			xLocation -= 1;														//The Ant moves left
		}

		break;
	}

	stepsSinceBreeding += 1;											//Increment how long since the doodlebug had babies
}

bool Ant::breedUp()
{
	if(yLocation + 1 < col || board[xLocation][yLocation + 1] != nullptr)
	{
		return false;
	}
	
	board[xLocation][yLocation + 1] = new Ant(xLocation , yLocation + 1, row, col, board);
	return true;
}

bool Ant::breedDown()
{
	if(yLocation - 1 >= 0 || board[xLocation][yLocation - 1] != nullptr)
	{
		return false;
	}
	board[xLocation][yLocation - 1] = new Ant(xLocation, yLocation - 1, row, col, board);
	return true;
}

bool Ant::breedLeft()
{
	if((xLocation - 1) < 0 || board[xLocation - 1][yLocation] != nullptr)
	{
		return false;
	}

	board[xLocation - 1][yLocation] = new Ant(xLocation - 1, yLocation, row, col, board);
	return true;
}

bool Ant::breedRight()
{
	if(xLocation + 1 >= row || board[xLocation + 1][yLocation] != nullptr)
	{
		return false;
	}
	
	board[xLocation + 1][yLocation] = new Ant(xLocation + 1, yLocation, row, col, board);
	return true;
}


/**********************************************************************************************************
** Description: Ant::Breed creates an ant in a random empty cell ajacent to the ant who calls the function
**********************************************************************************************************/
void Ant::Breed()
{
	if(stepsSinceBreeding > 3)
	{
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
