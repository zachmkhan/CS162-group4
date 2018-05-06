#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include "Critter.hpp"
#include <vector>

class Board
{
    private:
        Critter*** board; //This will be used to dynamically allocate the array
        int row; //The number of rows (Y value)
        int col; //The number of cols (X value)
        int ant; //The number of ants
        int doodle; //The number of doodlebugs
        void placeRandom(); //Randomly Places ants and doodle bugs
    public:
        Board(); //Default constructor. Will be set to 20x20 by default
        Board(int, int, int, int);
        ~Board();
        //Board(int row, int col, int doodle, int ant); //This will possibly be used for the extra credit
        void printBoard(); //Prints the game board
        void deleteArray(); //Frees the dynamic memory
        std::vector<Critter*>* getCritters();
};
#endif
