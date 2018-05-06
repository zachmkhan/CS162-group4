#include <iostream>
#include "Board.hpp"
#include "Validate.hpp"
#include "util.hpp"
#include <vector>

using std::cout;
using std::cin;
using std::endl;

Board* getBoard();

int main()
{
	cout << "*********************************" << endl;
	cout << "* Predator-Prey Game v1.0 "		<< endl;
	cout << "*********************************" << endl;

	Board* board = getBoard();

	//Initial Board
    cout << "Initial Board: " << endl;
    board->printBoard();
    
    int stepsToRun = getIntInputInRange("How many time steps would you like to run? ", 1, 1000);
    for(int step = 1; step <= stepsToRun; step++)
    {
    	//iterate through all the critters for each turn
    	std::vector<Critter*>* critters = board->getCritters();
    	for(unsigned int c = 0; c < critters->size(); c++)
    	{
    		critters->at(c)->step();
    	}
    	delete critters;
    	
    	//Display the board for each step
    	cout << "Step " << step << ": " << endl;
    	board->printBoard();
    }
    
    delete board;
}

/*
 * Prompts the user to enter all the game parameters and validates input
 */
Board* getBoard()
{
	//EXTRA CREDIT
	bool customizeGame = getBooleanInput("Would you like to choose the board size, number of Ants and number of doodle bugs? [y/n] ");
	if(customizeGame)
	{
		int rows = getIntInputInRange("Number of Rows: ", 1, 100);
		int cols = getIntInputInRange("Number of Columns: ", 1, 100);
		
		//Number of ants cannot be greater than slots on board
		int numberOfSlots = rows * cols;
		int ants = getIntInputInRange("Number of Ants: ", 1, numberOfSlots); 
		
		//Number of doodlebugs cannot be greater than slots left on board
		numberOfSlots -= ants;
		int doodles = getIntInputInRange("Number of Doodlebugs: ", 1, numberOfSlots);
		
		return new Board(rows, cols, ants, doodles);
	}
	else
	{
		return new Board(); //default board
	}
}