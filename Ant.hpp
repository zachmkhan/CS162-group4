#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"

class Ant : public Critter
{
    private:
        int stepsSinceBreeding; //steps since breeding. Will set to 0 in the constructor.
        int stepsNeededToBreed = 3; //Ant will breeed every three steps
        char gameBoardCharacter = 'O'; //The ant will have this space in the game
    public:
        Ant(int, int, Critter***); //Empty constructor
        void Move(int row, int col);
        void Breed(int row, int col);       //When the ant breeds
        void step();
        //char getCharacter(); //Gets the character for the board
};
#endif
