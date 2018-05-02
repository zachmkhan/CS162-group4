#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "Critter.hpp"

class Doodlebug : public Critter
{
    private:
        int stepsSinceBreeding; //steps since breeding. Will set to 0 in the constructor.
        int stepsNeededToBreed = 8; //Doodlebug will breeed every 8 steps
        char gameBoardCharacter = 'X'; //The doodlebug will have this space in the game
    public:
        Doodlebug(); //Empty constructor
        virtual void Move(); //Virtual function
        void Breed();       //When the ant breeds
        char getCharacter(); //Gets the character for the board
};
#endif