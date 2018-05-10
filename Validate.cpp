/*********************************************************************
** Program name: Lab 4
** Author: Zachary Khan
** Date: 4/29/2018
** Description: The input validation makes sure that correct integers 
** have been entered into other functions
*********************************************************************/


#include <iostream>
#include "Validate.hpp"
/*************************************************************
*This is my input validation function for integers
*This will pass the input by reference after it is correct
*The minimum is the smallest accecptable integer
*The maximum is the largest accecptable integer
***************************************************************/
void Validate(int &input, int minimum, int max)
{
    bool v = true; //Bool to keep the while loop running
    while(v)
    {
        //If the input is already accecptable
        for(int count = minimum ; count < max + 1 ; count++)
        {
            if(input == count)
            {
                v = false; //breaks out of the while loop
                std::cin.ignore();
                break;
            }

        }
        //If it is not an integer
		 if(std::cin.fail() )
		{
			std::cin.clear();
			std::cin.ignore(256,'\n');
			std::cout << "Not an Integer. Please enter a valid Integer" << std::endl;
			std::cin >> input;
		}

        //If the new integer is good for input
        else if(std::cin.good() && ( input >= minimum && input <= max))
        {
            v = false;
        }

		else
		{
			std::cout << "Invalid selection. Please enter a valid number" << std::endl;
			std::cin >> input;
		}
    }


}
