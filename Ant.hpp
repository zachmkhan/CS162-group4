/*********************************************************************
** Program name: Ant.hpp
** Author: Group 4
** Date: 5-4-2018
** Description: This file declares the variables, constructor, and
** the functions used in the Ant.cpp class.
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"

class Ant : public Critter
{
    private:
        int stepsSinceBreeding = 0; //steps since breeding. Will set to 0 in the constructor.
        int stepsNeededToBreed = 3; //Ant will breeed every three steps
        char gameBoardCharacter = 'O'; //The ant will have this space in the game
        bool breedLeft();
        bool breedRight();
        bool breedUp();
        bool breedDown();
    public:
        Ant(int, int, int, int, Critter***); //Empty constructor
        void Move();
        void Breed();       //When the ant breeds
        void step();
        //char getCharacter(); //Gets the character for the board
};
#endif
