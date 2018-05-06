#ifndef CRITTER_HPP_INCLUDED
#define CRITTER_HPP_INCLUDED

class Critter
{
    protected:
        int xLocation;
        int yLocation;
        int stepsSinceEating;
        char gameBoardCharacter;
        Critter*** board;
    public:
        Critter(char, int, int, Critter***);
		char getCritterType();
		int getStepsSinceEating();
		void setCritterType(char);
        virtual void Move(int row, int col) = 0;
        virtual void step() = 0;
};

#endif // CRITTER_HPP_INCLUDED
