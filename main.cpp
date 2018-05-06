#include <iostream>
#include "Board.hpp"
#include "Validate.hpp"

using std::cout;
using std::cin;
using std::endl;



int main()
{
	int stepsToRun;
	
	cout << "How many time steps would you like to run?" << endl;
	cin >> stepsToRun;
	Validate(stepsToRun, 1, 1000);

	//cout << "Would you like to choose the board size, number of Ants and number of doodle bugs?" << endl; // for extra credit

	//create board
	Board board;





    
    board.printBoard();
    board.placeRandom();
    board.printBoard();
    board.deleteArray();
}


