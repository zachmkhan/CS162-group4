#include "Ant.hpp"
#include <ctime>					// For time()
#include <cstdlib>					// For srand() and rand()


/*
 * Initialize new ant
 *	 x: starting x coordinate for the new ant
 *	 y: starting y coordinate for new ant
 *	 board: pointer the the game board
 */
Ant::Ant(int x, int y, Critter*** board) : Critter('O', x, y, board)
{
    stepsSinceBreeding = 0;
}

/*
 * Calls the move and bread method for this ant
 */
void Ant::step()
{
	//todo
	//move
	//breed
}

//Virtual function
void Ant::Move(int row, int col)
{
	int randomMove = rand() % 4 + 1;										//Random number for the 4 different directions

	switch (randomMove)
	{

		//Moving Up
	case 1:
		if (yLocation < row && board[xLocation][yLocation + 1] == nullptr)
		{
			board[xLocation][yLocation] = board[xLocation][yLocation + 1];		//The Doodlebug moves to the new space
			board[xLocation][yLocation] = nullptr;

			yLocation += 1;														//The Doodlebug moves up
		}

		break;

		//Moving Down
	case 2:
		if (yLocation > 0 && board[xLocation][yLocation - 1] == nullptr)
		{
			board[xLocation][yLocation] = board[xLocation][yLocation - 1];		//The Doodlebug moves to the new space
			board[xLocation][yLocation] = nullptr;

			yLocation -= 1;														//The Doodlebug moves up
		}

		break;

		//Moving Right
	case 3:
		if (xLocation < col && board[xLocation + 1][yLocation] == nullptr)
		{
			board[xLocation][yLocation] = board[xLocation + 1][yLocation];		//The Doodlebug moves to the new space
			board[xLocation][yLocation] = nullptr;

			xLocation += 1;														//The Doodlebug moves up
		}

		break;

		//Moving Left
	case 4:
		if (xLocation > 0 && board[xLocation - 1][yLocation] == nullptr)
		{
			board[xLocation][yLocation] = board[xLocation - 1][yLocation];		//The Doodlebug moves to the new space
			board[xLocation][yLocation] = nullptr;

			xLocation -= 1;														//The Doodlebug moves up
		}

		break;
	}

	stepsSinceBreeding += 1;											//Increment how long since the doodlebug had babies
}


/**********************************************************************************************************
** Description: Ant::Breed creates an ant in a random empty cell ajacent to the ant who calls the function
**********************************************************************************************************/
void Ant::Breed(int row, int col)
{
	int randomMove = rand() % 4 + 1;										//Random number for the 4 different directions
	bool bred = true;

	switch (randomMove)
	{

		//Breeding Up
	case 1:
		if (yLocation < row && board[xLocation][yLocation + 1] == nullptr)
		{
		// need to change the location to Ant by changing pointer to critter, not sure how yet
			board[xLocation][yLocation + 1]->setCritterType('X');		//Set critter type to X for new ant
		

		}

		break;

		//Breeding Down
	case 2:
		if (yLocation > 0 && board[xLocation][yLocation - 1] == nullptr)
		{
			// need to change the location to Ant by changing pointer to critter, not sure how yet
			board[xLocation][yLocation - 1]->setCritterType('X');		//Set critter type to X for new ant

		}

		break;

		//Moving Right
	case 3:
		if (xLocation < col && board[xLocation + 1][yLocation] == nullptr)
		{
			// need to change the location to Ant by changing pointer to critter, not sure how yet
			board[xLocation + 1][yLocation]->setCritterType('X');		//Set critter type to X for new ant

		}

		break;

		//Moving Left
	case 4:
		if (xLocation > 0 && board[xLocation - 1][yLocation] == nullptr)
		{
			// need to change the location to Ant by changing pointer to critter, not sure how yet
			board[xLocation - 1][yLocation]->setCritterType('X');	//Set critter type to X for new ant

		}

		break;
	}
}
