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
	//Tries to go up to eat an ant
	if (onboard(xLocation, yLocation + 1) && board[xLocation][yLocation + 1] != nullptr && board[xLocation][yLocation + 1]->getCritterType() == 'O')
	{
        board[xLocation][yLocation + 1] = board[xLocation][yLocation];		//The Doodlebug moves to the new space
		board[xLocation][yLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		yLocation += 1;								//The Doodlebug moves up
	}
	//Tries to go down to eat an ant
	else if (onboard(xLocation, yLocation - 1) && board[xLocation][yLocation - 1] != nullptr && board[xLocation][yLocation - 1]->getCritterType() == 'O')
	{
		board[xLocation][yLocation - 1] = board[xLocation][yLocation];		//The Doodlebug moves to the new space
		board[xLocation][yLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		yLocation -= 1;								//The Doodlebug moves down
	}
	//Tries to go right to eat an ant
	else if (onboard(xLocation + 1, yLocation) && board[xLocation + 1][yLocation] != nullptr && board[xLocation + 1][yLocation]->getCritterType() == 'O')
	{
		board[xLocation + 1][yLocation] = board[xLocation][yLocation];		//The Doodlebug moves to the new space
		board[xLocation][yLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		xLocation += 1;								//The Doodlebug moves right
	}
	//Tries to go up to left an ant
	else if (onboard(xLocation - 1, yLocation) && board[xLocation - 1][yLocation] != nullptr && board[xLocation - 1][yLocation]->getCritterType() == 'O')
	{
		board[xLocation - 1][yLocation] = board[xLocation][yLocation];		//The Doodlebug moves to the new space
		board[xLocation][yLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		xLocation -= 1;								//The Doodlebug moves left
	}
	//There were no ants for the doodlebug to eat
	else
	{
		int randomMove = rand() % 4 + 1;					//Random number for the 4 different directions
		switch (randomMove)
		{
		//Moving Up
		case 1:
			if (onboard(xLocation, yLocation + 1) && board[xLocation][yLocation + 1] == nullptr)
			{
				board[xLocation][yLocation + 1] = board[xLocation][yLocation];		//The Doodlebug moves to the new space
				board[xLocation][yLocation] = nullptr;

				yLocation += 1;														//The Doodlebug moves up
			}
			break;
		//Moving Down
		case 2:
			if (onboard(xLocation, yLocation - 1) > 0 && board[xLocation][yLocation - 1] == nullptr)
			{
				board[xLocation][yLocation - 1] = board[xLocation][yLocation];		//The Doodlebug moves to the new space
				board[xLocation][yLocation] = nullptr;
				yLocation -= 1;														//The Doodlebug moves down
			}
			break;
		//Moving Right
		case 3:
			if (onboard(xLocation + 1, yLocation) && board[xLocation + 1][yLocation] == nullptr)
			{
		
				board[xLocation + 1][yLocation] = board[xLocation][yLocation];		//The Doodlebug moves to the new space
				board[xLocation][yLocation] = nullptr;
				xLocation += 1;														//The Doodlebug moves right
			}
			break;
		//Moving Left
		case 4:
			if (onboard(xLocation - 1, yLocation) && board[xLocation - 1][yLocation] == nullptr)
			{
				board[xLocation - 1][yLocation] = board[xLocation][yLocation];		//The Doodlebug moves to the new space
				board[xLocation][yLocation] = nullptr;
				xLocation -= 1;														//The Doodlebug moves left
			}
			break;
		}
		stepsSinceEating += 1;							//Increment how long since the doodlebug has eaten
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
	}
}

bool Doodlebug::breedUp()
{
	if(onboard(xLocation, yLocation + 1) && board[xLocation][yLocation + 1] == nullptr)
	{
		board[xLocation][yLocation + 1] = new Doodlebug(xLocation , yLocation + 1, row, col, board);
		return true;
		
	}
	return false;
	
}

bool Doodlebug::breedDown()
{
	if(onboard(xLocation, yLocation - 1) >= 0 && board[xLocation][yLocation - 1] == nullptr)
	{
		board[xLocation][yLocation - 1] = new Doodlebug(xLocation, yLocation - 1, row, col, board);
		return true;
	}
	return false;
	
}

bool Doodlebug::breedLeft()
{
	if(onboard(xLocation - 1, yLocation) && board[xLocation - 1][yLocation] == nullptr)
	{
		board[xLocation - 1][yLocation] = new Doodlebug(xLocation - 1, yLocation, row, col, board);
		return true;
	}
	return false;
}

bool Doodlebug::breedRight()
{
	if(onboard(xLocation + 1, yLocation) && board[xLocation + 1][yLocation] == nullptr)
	{
		board[xLocation + 1][yLocation] = new Doodlebug(xLocation + 1, yLocation, row, col, board);
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
		board[xLocation][yLocation] = nullptr;
		// delete this; causes error for some reason
	}

}
