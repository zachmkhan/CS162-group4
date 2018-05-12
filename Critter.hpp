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
        char gameBoardCharacter;
        int row;
        int col;
        bool deleted = false;
        bool newCritter = true;
        Critter*** board;
        bool onboard(int, int);
       
    public:
        Critter(char, int, int, int, int, Critter***);
		virtual char getCritterType();
		int getCol();
		int getRow();
        virtual void step() = 0;
        void move(int oldRow, int oldCol, int newRow, int newCol);
        bool isDeleted();
        bool deleteCritter();
        bool isNew();
        bool setNew(bool);
};

#endif // CRITTER_HPP_INCLUDED
