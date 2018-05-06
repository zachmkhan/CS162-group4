#include "Doodlebug.hpp"
#include <ctime>					// For time()
#include <cstdlib>					// For srand() and rand()


void Doodlebug::Move(Critter *** board,int row, int col)
{
	//Tries to go up to eat an ant
	if (board[xLocation][yLocation + 1]->getCritterType() == 'O')
	{
        	board[xLocation][yLocation] = board[xLocation][yLocation + 1];		//The Doodlebug moves to the new space
		board[xLocation][yLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		yLocation += 1;								//The Doodlebug moves up
	}
	//Tries to go down to eat an ant
	else if (board[xLocation][yLocation - 1]->getCritterType() == 'O')
	{
		board[xLocation][yLocation] = board[xLocation][yLocation - 1];		//The Doodlebug moves to the new space
		board[xLocation][yLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		yLocation -= 1;								//The Doodlebug moves down
	}
	//Tries to go right to eat an ant
	else if (board[xLocation + 1][yLocation]->getCritterType() == 'O')
	{
		board[xLocation][yLocation] = board[xLocation + 1][yLocation];		//The Doodlebug moves to the new space
		board[xLocation][yLocation] = nullptr;					//The Doodlebug's old space becomes null
		stepsSinceEating = 0;							//The counter is reset due to the eaten ant
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
		xLocation += 1;								//The Doodlebug moves right
	}
	//Tries to go up to left an ant
	else if (board[xLocation - 1][yLocation]->getCritterType() == 'O')
	{
		board[xLocation][yLocation] = board[xLocation][yLocation + 1];		//The Doodlebug moves to the new space
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
		stepsSinceEating += 1;							//Increment how long since the doodlebug has eaten
		stepsSinceBreeding += 1;						//Increment how long since the doodlebug had babies
	}
}

/**********************************************************************************************************
** Description: Ant::Breed creates an ant in a random empty cell ajacent to the ant who calls the function
**********************************************************************************************************/
void Doodlebug::Breed(Critter *** board, int row, int col)
{
	int randomMove = rand() % 4 + 1;										//Random number for the 4 different directions
	bool bred = true;

	switch (randomMove)
	{
		//Breeding Up
	case 1:
		if (yLocation < row && board[xLocation][yLocation + 1] == nullptr)
		{
			// need to change the location to Doodlebug by changing pointer to critter, not sure how yet
			board[xLocation][yLocation + 1]->setCritterType('O');		//Set critter type to O for new doodlebug
		}
		break;
		//Breeding Down
	case 2:
		if (yLocation > 0 && board[xLocation][yLocation - 1] == nullptr)
		{
			// need to change the location to Doodlebug by changing pointer to critter, not sure how yet

			board[xLocation][yLocation - 1]->setCritterType('O');		//Set critter type to O for new doodlebug
		}
		break;
		//Breeding Right
	case 3:

		if (xLocation < col && board[xLocation + 1][yLocation] == nullptr)
		{
			// need to change the location to Doodle bug by changing pointer to critter, not sure how yet
			board[xLocation + 1][yLocation]->setCritterType('O');		//Set critter type to O for new doodlebug
		}
		break;
		//Breeding Left
	case 4:

		if (xLocation > 0 && board[xLocation - 1][yLocation] == nullptr)
		{
			// need to change the location to Doodlebug by changing pointer to critter, not sure how yet
			board[xLocation - 1][yLocation]->setCritterType('O');	//Set critter type to O for new doodlebug
		}
		break;
	}
}

/**********************************************************************************************************
** Description: Function runs through the board objects and deletes any Doodlebugs whose StepsSinceEating
** is equal to 3.
**********************************************************************************************************/
void Doodlebug::Starve(Critter*** board)
{
    int arraySize = sizeof(board) / sizeof(*board);
    Critter* ptr;
    for(int x = 0; x < arraySize; x++)
    {
        ptr = *board[x];

        if(ptr->getCritterType() == 'X' && ptr->getStepsSinceEating() >= 3)
        {
            board[x] = nullptr;
        }
    }

    delete ptr;
}
