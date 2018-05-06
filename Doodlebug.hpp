#ifndef DOODLEBUG_HPP_INCLUDED
#define DOODLEBUG_HPP_INCLUDED
#include "Critter.hpp"

class Doodlebug : public Critter
{
private:
    int stepsSinceBreeding; //steps since breeding. Will set to 0 in the constructor.
    int stepsSinceEating; //steps since eating
    int stepsNeededToBreed = 8; //Doodlebug will breeed every 8 steps
    char gameBoardCharacter = 'X'; //The doodlebug will have this space in the game

public:
    Doodlebug(int, int, Critter***); //Empty constructor
    virtual void Move(int row, int col); //Virtual function
    void Breed(int row, int col);       //When the ant breeds
    void Starve();
    void step();
    //char getCharacter(); //Gets the character for the board

};

#endif // DOODLEBUG_HPP_INCLUDED
