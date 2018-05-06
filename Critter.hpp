#ifndef CRITTER_HPP_INCLUDED
#define CRITTER_HPP_INCLUDED

class Critter
{
    protected:
        int xLocation;
        int yLocation;
        int stepsSinceEating;
        char gameBoardCharacter;
    public:
		char getCritterType();
		int getStepsSinceEating();
		void setCritterType(char);
        virtual void Move() = 0;
};

#endif // CRITTER_HPP_INCLUDED
