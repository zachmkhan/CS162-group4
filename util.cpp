/*********************************************************************
* Description: util functions used to collect and validate user input,
* create and delete 2D arrays, generate random numbers
*********************************************************************/

#include <iostream> 
#include <algorithm>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include "util.hpp"

/*
 * Returns a random integer between the low and high value inclusive
 */
int randomBetween(int low, int high)
{
    return rand() % (high - low +1) + low;
}

/*
 * Checks if the user input was a valid integer, if not outputs an error message
 * to the user and returns false
 */
bool validIntInput()
{
    bool inputFailed = std::cin.fail();
    if(inputFailed)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "INVALID INPUT: Enter an integer value" << std::endl;
    }
    return !inputFailed;
}

/*
 * Checks if the user input was a valid number, if not outputs an error message
 * to the user and returns false
 */
bool validNumericInput()
{
    bool inputFailed = std::cin.fail();
    if(inputFailed)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "INVALID INPUT: Enter an valid number value" << std::endl;
    }
    return !inputFailed;
}

/*
 * Promts the user to enter an integer and validates the user input is valid. It
 * will continue to prompt the user until they enter a valid integer
 *
 * Inputs:
 *  prompt: message to display to user so they know what to enter
 */
int getIntInput(std::string prompt)
{
    int input;
    do
    {
        std::cout << prompt;
        std::cin >> input;
    }
    while(!validIntInput());
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}

/*
 * Checks if the integer input is greater than zero, if not it displays an error
 * message and returns false;
 */
bool validPositiveInt(int input)
{
    bool valid = (input > 0);
    if(!valid)
    {
        std::cout << "INVALID INPUT: Enter integer greater than 0" << std::endl;
    }
    return valid;
}

/*
 * Collects input from the user and validates the user input is positive. It will
 * retry until the user inputs a valid positive integer.
 *
 * Input:
 *  prompt: message to display to the user so they know what to enter.
 */
int getPositiveIntInput(std::string prompt)
{
    int input;
    do 
    {
        input = getIntInput(prompt);
    }
    while(!validPositiveInt(input));
    
    return input;
}

/*
 * Validates the given integer is with the given range. If not, an error message 
 * is displayed and false is returned
 *
 * Input:
 *  input: the integer to vaidate
 *  start: the bottom range value
 *  end: the top range value
 */
bool validIntInRange(int input, int start, int end)
{
    bool valid = validIntInput() && (input >= start && input <= end);
    if(!valid)
    {
        std::cout << "INVALID INPUT: Enter integer between " << start << " and " << end << std::endl;
    }
    return valid;
}

/*
 * Collects input from the user and validates the uder input is within the given
 * range. It will retry until the user inputs a valid positive integer.
 *
 * Input:
 *  prompt: message to display to the user so they know what to enter.
 *  start: the bottom range value
 *  end: the top range value
 */
int getIntInputInRange(std::string prompt, int start, int end)
{
    int input;
    do 
    {
        input = getIntInput(prompt);
    }
    while(!validIntInRange(input, start, end));
    
    return input;
}

/*
 * takes a string to changes it to all lowercase
 * 
 * Input:
 *  str: string to translate to lowercase
 */
std::string toLowerCase(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

/*
 * Compares an input string against a standard set of known english words for
 * yes and no
 * 
 * Input:
 *  input: string to check if boolean value
 */
bool validBooleanInput(std::string input)
{
    std::string lowerCaseString = toLowerCase(input);
    bool valid = (lowerCaseString == "y" || lowerCaseString == "yes"
        || lowerCaseString == "n" || lowerCaseString == "no");
    if(!valid)
    {
        std::cout << "INVALID INPUT: Enter y or n" << std::endl;
    }
    return valid;
}

/*
 * converts a string of y/yes/n/no to boolean
 * 
 * Input:
 *  input: string to convert to boolean value
 */
bool stringToBoolean(std::string input)
{
    std::string lowerCaseString = toLowerCase(input);
    return lowerCaseString == "y" || lowerCaseString == "yes";
}

/*
 * prompts the user to enter a boolean value, validates correct input and returns
 * a boolean version of the input
 * 
 * Input:
 *  prompt: prompt explaining to the user what to enter
 */
bool getBooleanInput(std::string prompt)
{
    std::string input;
    do
    {
        std::cout << prompt;
        std::getline(std::cin, input);
    }
    while(!validBooleanInput(input));
    return stringToBoolean(input);
}

/*
 * prompts the user to enter a string value, validates correct input and returns
 * the string
 * 
 * Input:
 *  prompt: prompt explaining to the user what to enter
 */
std::string getStringInput(std::string prompt)
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

/*
 * validates the number vaklue is in the given range
 * 
 * Input:
 *  prompt: prompt explaining to the user what to enter
 */
bool validNumericInRange(double input, double start, double end)
{
    bool valid = validIntInput() && (input >= start && input <= end);
    if(!valid)
    {
        std::cout << "INVALID INPUT: Enter number between " << start << " and " << end << std::endl;
    }
    return valid;
}

/*
 * promtps the user to enter a numeric value and validates the input
 * 
 * Input:
 *  prompt: prompt explaining to the user what to enter
 */
double getNumericInput(std::string prompt)
{
    double input;
    do
    {
        std::cout << prompt;
        std::cin >> input;
    }
    while(!validIntInput());
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}

/*
 * promtps the user to enter a numeric value in a given range and validates 
 * the input
 * 
 * Input:
 *  prompt: prompt explaining to the user what to enter
 */
double getNumericInputInRange(std::string prompt, int start, int end)
{
    double input;
    do 
    {
        input = getNumericInput(prompt);
    }
    while(!validNumericInRange(input, start, end));
    
    return input;
}