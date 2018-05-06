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

	bool playAgain = true;
	while(playAgain) //allows the user to play again at the end of the game
	{

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
			cout << "Press enter for step " << step << ": " << endl;
			cin.ignore();
			board->printBoard();
			cout<<endl;
			cout<<endl;
		}
		
		delete board;

		/*
 		* Prompts the user if they would like to play again
		*/
		int input;
		cout<<endl;
		cout << "Would you like to play again?" <<endl;
		cout << "1) Yes" << endl;
		cout << "2) No" << endl;
		cin >> input;
		Validate(input,1,2);
		if(input == 1)
		{
			playAgain = true;
			cout << "The game is now starting over" << endl;
		}
		else
		{
			for(int count = 0; count<100; count++)
			{
				cout<<endl;
			}
			playAgain = false;
			cout << "**********************Goodbye**********************" <<endl;
		}

	}
}

/*
 * Prompts the user to enter all the game parameters and validates input
 */
Board* getBoard()
{
	//EXTRA CREDIT
	cout << "Press y for the extra credit portion of the project" << endl;
	bool customizeGame = getBooleanInput("Would you like to choose the board size, number of Ants and number of doodle bugs? [y/n]");
	if(customizeGame)
	{
		int rows = getIntInputInRange("Number of Rows: ", 2, 100);
		int cols = getIntInputInRange("Number of Columns: ", 2, 100);
		
		//Number of ants cannot be greater than slots on board
		int numberOfSlots = rows * cols;
		int ants = getIntInputInRange("Number of Ants: ", 1, numberOfSlots - 1); 
		
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