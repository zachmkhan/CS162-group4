#include "Critter.hpp"

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
