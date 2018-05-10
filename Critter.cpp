/*********************************************************************
** Program name: Critter.cpp
** Author: Group 4
** Date: 5-4-2018
** Description: This file implements the constructor and functions
** of the Critter class.
*********************************************************************/
#include <iostream>
#include "Critter.hpp"

Critter::Critter(char type, int x, int y, int r, int c, Critter*** board)
{
    this->board = board;
    gameBoardCharacter = type;
    rowLocation = x;
    colLocation = y;
    row = r;
    col = c;
}

char Critter::getCritterType()
{
	return gameBoardCharacter;
}

bool Critter::onboard(int r, int c)
{
    return r >= 0 && c >= 0 &&
        r < row && c < col;
}

int Critter::getCol()
{
    return colLocation;
}

int Critter::getRow()
{
    return rowLocation;
}

void Critter::move(int oldRow, int oldCol, int newRow, int newCol)
{
    if(board[newRow][newCol] != nullptr)
    {
        board[newRow][newCol] = nullptr;
    }
    board[newRow][newCol] = board[oldRow][oldCol];
    board[oldRow][oldCol] = nullptr;
    rowLocation = newRow;
    colLocation = newCol;
}