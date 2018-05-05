#include "Doodlebug.hpp"
#include <ctime>					// For time()
#include <cstdlib>					// For srand() and rand()

void Doodlebug::Move(Critter *** board,int row, int col) 
{
	//Tries to go up to eat an ant
	if (board[xLocation][yLocation + 1]->getCritterType() == 'O')
	{
		board[xLocation][yLocation] = board[xLocation][yLocation + 1];		//The Doodlebug moves to the new space
		board[xLocation][yLocation] = nullptr;								//The Doodlebug's old space becomes null

		stepsSinceEating = 0;												//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;											//Increment how long since the doodlebug had babies
		yLocation += 1;														//The Doodlebug moves up
	}
	//Tries to go down to eat an ant
	else if (board[xLocation][yLocation - 1]->getCritterType() == 'O')
	{
		board[xLocation][yLocation] = board[xLocation][yLocation - 1];		//The Doodlebug moves to the new space
		board[xLocation][yLocation] = nullptr;								//The Doodlebug's old space becomes null

		stepsSinceEating = 0;												//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;											//Increment how long since the doodlebug had babies
		yLocation -= 1;														//The Doodlebug moves down
	}
	//Tries to go right to eat an ant
	else if (board[xLocation + 1][yLocation]->getCritterType() == 'O')
	{
		board[xLocation][yLocation] = board[xLocation + 1][yLocation];		//The Doodlebug moves to the new space
		board[xLocation][yLocation] = nullptr;								//The Doodlebug's old space becomes null

		stepsSinceEating = 0;												//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;											//Increment how long since the doodlebug had babies
		xLocation += 1;														//The Doodlebug moves right
	}
	//Tries to go up to left an ant
	else if (board[xLocation - 1][yLocation]->getCritterType() == 'O')
	{
		board[xLocation][yLocation] = board[xLocation][yLocation + 1];		//The Doodlebug moves to the new space
		board[xLocation][yLocation] = nullptr;								//The Doodlebug's old space becomes null

		stepsSinceEating = 0;												//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;											//Increment how long since the doodlebug had babies
		xLocation -= 1;														//The Doodlebug moves left
	}
	//There were no ants for the doodlebug to eat
	else
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

		stepsSinceEating += 1;												//Increment how long since the doodlebug has eaten
		stepsSinceBreeding += 1;											//Increment how long since the doodlebug had babies

	}
}
