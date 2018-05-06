#include "Critter.hpp"

Critter::Critter(char type, int x, int y, Critter*** board)
{
    board = board;
    gameBoardCharacter = type;
    xLocation = x;
    yLocation = y;
}

char Critter::getCritterType()
{
	return gameBoardCharacter;
}

void Critter::setCritterType(char typeChar)
{
	gameBoardCharacter = typeChar;
}

int Critter::getStepsSinceEating()
{
    return stepsSinceEating;
}