#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter
{
    protected:
        int xLocation;
        int yLocation;
        char gameBoardCharacter;
    public:
		char getCritterType();
		void setCritterType(char);
        virtual void Move() = 0;
};
#endif
