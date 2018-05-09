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
<<<<<<< HEAD
	//Tries to go up to eat an ant
	if (onboard(xLocation, yLocation + 1) && board[xLocation][yLocation + 1] != nullptr && board[xLocation][yLocation + 1]->getCritterType() == 'O')
=======
	//Tries to go right to eat an ant
	if (colLocation < col - 1 && board[rowLocation][colLocation + 1] != nullptr && board[rowLocation][colLocation + 1]->getCritterType() == 'O')
>>>>>>> 802417ab49980fad9214752c660d96a8013eac96
	{
		board[rowLocation][colLocation + 1] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
		board[rowLocation][colLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		colLocation = colLocation + 1;								//The Doodlebug moves right
	}
<<<<<<< HEAD
	//Tries to go down to eat an ant
	else if (onboard(xLocation, yLocation - 1) && board[xLocation][yLocation - 1] != nullptr && board[xLocation][yLocation - 1]->getCritterType() == 'O')
=======
	//Tries to go left to eat an ant
	else if (colLocation > 0 && board[rowLocation][colLocation - 1] != nullptr && board[rowLocation][colLocation - 1]->getCritterType() == 'O')
>>>>>>> 802417ab49980fad9214752c660d96a8013eac96
	{
		board[rowLocation][colLocation - 1] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
		board[rowLocation][colLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		colLocation = colLocation - 1;								//The Doodlebug moves left
	}
<<<<<<< HEAD
	//Tries to go right to eat an ant
	else if (onboard(xLocation + 1, yLocation) && board[xLocation + 1][yLocation] != nullptr && board[xLocation + 1][yLocation]->getCritterType() == 'O')
=======
	//Tries to go down to eat an ant
	else if (rowLocation < row - 1 && board[rowLocation + 1][colLocation] != nullptr && board[rowLocation + 1][colLocation]->getCritterType() == 'O')
>>>>>>> 802417ab49980fad9214752c660d96a8013eac96
	{
		board[rowLocation + 1][colLocation] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
		board[rowLocation][colLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		rowLocation = rowLocation + 1;								//The Doodlebug moves down
	}
<<<<<<< HEAD
	//Tries to go up to left an ant
	else if (onboard(xLocation - 1, yLocation) && board[xLocation - 1][yLocation] != nullptr && board[xLocation - 1][yLocation]->getCritterType() == 'O')
=======
	//Tries to go up to up an ant
	else if (rowLocation > 0 && board[rowLocation - 1][colLocation] != nullptr && board[rowLocation - 1][colLocation]->getCritterType() == 'O')
>>>>>>> 802417ab49980fad9214752c660d96a8013eac96
	{
		board[rowLocation - 1][colLocation] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
		board[rowLocation][colLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		rowLocation = rowLocation - 1;								//The Doodlebug moves up
	}
	//There were no ants for the doodlebug to eat
	else
	{
		int randomMove = rand() % 4 + 1;					//Random number for the 4 different directions
		switch (randomMove)
		{
			//Moving Right
		case 1:
<<<<<<< HEAD
			if (onboard(xLocation, yLocation + 1) && board[xLocation][yLocation + 1] == nullptr)
=======
			if (colLocation < col - 1 && board[rowLocation][colLocation + 1] == nullptr)
>>>>>>> 802417ab49980fad9214752c660d96a8013eac96
			{
				board[rowLocation][colLocation + 1] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
				board[rowLocation][colLocation] = nullptr;

				colLocation += 1;														//The Doodlebug moves Right
			}
			break;
			//Moving Left
		case 2:
<<<<<<< HEAD
			if (onboard(xLocation, yLocation - 1) > 0 && board[xLocation][yLocation - 1] == nullptr)
=======
			if (colLocation > 0 && board[rowLocation][colLocation - 1] == nullptr)
>>>>>>> 802417ab49980fad9214752c660d96a8013eac96
			{
				board[rowLocation][colLocation - 1] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
				board[rowLocation][colLocation] = nullptr;
				colLocation -= 1;														//The Doodlebug moves Left
			}
			break;
			//Moving Down
		case 3:
<<<<<<< HEAD
			if (onboard(xLocation + 1, yLocation) && board[xLocation + 1][yLocation] == nullptr)
=======
			if (rowLocation < row - 1 && board[rowLocation + 1][colLocation] == nullptr)
>>>>>>> 802417ab49980fad9214752c660d96a8013eac96
			{

				board[rowLocation + 1][colLocation] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
				board[rowLocation][colLocation] = nullptr;
				rowLocation += 1;														//The Doodlebug moves Down
			}
			break;
			//Moving Up
		case 4:
<<<<<<< HEAD
			if (onboard(xLocation - 1, yLocation) && board[xLocation - 1][yLocation] == nullptr)
=======
			if (rowLocation > 0 && board[rowLocation - 1][colLocation] == nullptr)
>>>>>>> 802417ab49980fad9214752c660d96a8013eac96
			{
				board[rowLocation - 1][colLocation] = board[rowLocation][colLocation];		//The Doodlebug moves to the new space
				board[rowLocation][colLocation] = nullptr;
				rowLocation -= 1;														//The Doodlebug moves Up
			}
			break;
		default:
		{
			std::cout << "I didn't move this time" << std::endl;
		}
		}
		stepsSinceEating += 1;							//Increment how long since the doodlebug has eaten
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
	}
}

bool Doodlebug::breedDown()
{
<<<<<<< HEAD
	if(onboard(xLocation, yLocation + 1) && board[xLocation][yLocation + 1] == nullptr)
	{
		board[xLocation][yLocation + 1] = new Doodlebug(xLocation , yLocation + 1, row, col, board);
		return true;
		
	}
	return false;
	
=======
	if (rowLocation < row - 1 && board[rowLocation + 1][colLocation] == nullptr)
	{
		board[rowLocation + 1][colLocation] = new Doodlebug(rowLocation + 1, colLocation, row, col, board);
		return false;
	}

	return false;
>>>>>>> 802417ab49980fad9214752c660d96a8013eac96
}

bool Doodlebug::breedUp()
{
<<<<<<< HEAD
	if(onboard(xLocation, yLocation - 1) >= 0 && board[xLocation][yLocation - 1] == nullptr)
	{
		board[xLocation][yLocation - 1] = new Doodlebug(xLocation, yLocation - 1, row, col, board);
		return true;
	}
	return false;
	
=======
	if (rowLocation > 0 && board[rowLocation - 1][colLocation] == nullptr)
	{
		board[rowLocation - 1][colLocation] = new Doodlebug(rowLocation - 1, colLocation, row, col, board);
		return true;
	}

	return false;
>>>>>>> 802417ab49980fad9214752c660d96a8013eac96
}

bool Doodlebug::breedLeft()
{
<<<<<<< HEAD
	if(onboard(xLocation - 1, yLocation) && board[xLocation - 1][yLocation] == nullptr)
	{
		board[xLocation - 1][yLocation] = new Doodlebug(xLocation - 1, yLocation, row, col, board);
		return true;
	}
=======
	if (colLocation > 0 && board[rowLocation][colLocation - 1] == nullptr)
	{
		board[rowLocation][colLocation - 1] = new Doodlebug(rowLocation, colLocation - 1, row, col, board);
		return true;
	}

>>>>>>> 802417ab49980fad9214752c660d96a8013eac96
	return false;
}

bool Doodlebug::breedRight()
{
<<<<<<< HEAD
	if(onboard(xLocation + 1, yLocation) && board[xLocation + 1][yLocation] == nullptr)
	{
		board[xLocation + 1][yLocation] = new Doodlebug(xLocation + 1, yLocation, row, col, board);
		return true;
	}
	return false;
}
=======
	if (colLocation < col - 1 && board[rowLocation][colLocation + 1] == nullptr)
	{
		board[rowLocation][colLocation - 1] = new Doodlebug(rowLocation, colLocation + 1, row, col, board);
		return true;
	}
>>>>>>> 802417ab49980fad9214752c660d96a8013eac96

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
