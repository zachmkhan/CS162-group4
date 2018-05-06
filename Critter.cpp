#include "Critter.hpp"

Critter::Critter(char type, int x, int y, int r, int c, Critter*** board)
{
    board = board;
    gameBoardCharacter = type;
    xLocation = x;
    yLocation = y;
    row = r;
    col = c;
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