#include "Ant.hpp"

//Default constructor
Ant::Ant()
{
    stepsSinceBreeding = 0;
}

//Virtual function
void Ant::Move(Critter *** board, int row, int col)
{
	int randomMove = rand() % 4 + 1;										//Random number for the 4 different directions
	bool moved = true;

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
			board[xLocation][yLocation] = board[xLocation 1 1][yLocation];		//The Doodlebug moves to the new space
			board[xLocation][yLocation] = nullptr;

			xLocation -= 1;														//The Doodlebug moves up
		}

		break;
	}

	stepsSinceBreeding += 1;											//Increment how long since the doodlebug had babies
}
