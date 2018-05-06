#include <string>
#ifndef UTIL_HPP
#define UTIL_HPP

int randomBetween(int low, int high);
bool validIntInput();
int getIntInput(std::string prompt);
bool validPositiveInt(int input);
int getPositiveIntInput(std::string prompt);
bool validIntInRange(int input, int start, int end);
int getIntInputInRange(std::string prompt, int start, int end);
bool getBooleanInput(std::string prompt);
std::string getStringInput(std::string prompt);
double getNumericInputInRange(std::string prompt, int start, int end);

#endif