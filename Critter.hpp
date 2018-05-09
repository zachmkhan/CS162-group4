/*********************************************************************
** Program name: Critter.hpp
** Author: Group 4
** Date: 5-4-2018
** Description: This file declares the variables, constructor, and
** functions used in the Critter class.
*********************************************************************/

#ifndef CRITTER_HPP_INCLUDED
#define CRITTER_HPP_INCLUDED

class Critter
{
    protected:
        int rowLocation;
        int colLocation;
        int stepsSinceEating;
        char gameBoardCharacter;
        int row;
        int col;
        Critter*** board;
        bool onboard(int, int);
    public:
        Critter(char, int, int, int, int, Critter***);
		char getCritterType();
		int getStepsSinceEating();
		void setCritterType(char);
        virtual void Move() = 0;
        virtual void step() = 0;
};

#endif // CRITTER_HPP_INCLUDED
