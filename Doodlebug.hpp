/*********************************************************************
** Program name: Doodlebug.hpp
** Author: Group 4
** Date: 5-9-2018
** Description: This file declares the variables, constructor, and
** the functions used in the Doodlebug.cpp class.
*********************************************************************/

#ifndef DOODLEBUG_HPP_INCLUDED
#define DOODLEBUG_HPP_INCLUDED
#include "Critter.hpp"

class Doodlebug : public Critter
{
private:
    int stepsSinceBreeding = 0; //steps since breeding. Will set to 0 in the constructor.
    int stepsSinceEating = 0; //steps since eating
    int stepsNeededToBreed = 8; //Doodlebug will breeed every 8 steps
    char gameBoardCharacter = 'X'; //The doodlebug will have this space in the game
    bool breedLeft();
    bool breedRight();
    bool breedUp();
    bool breedDown();

public:
    Doodlebug(int, int, int, int, Critter***); //Empty constructor
    virtual void Move(); //Virtual function
    void Breed();       //When the ant breeds
    void Starve();
    void step();
};

#endif // DOODLEBUG_HPP_INCLUDED
