/***********************************************************************
Author: Matthew Solbrack
Date: 07/13/2018
Description: This class is for input validation.
***********************************************************************/
#ifndef CHECKINPUT_HPP
#define CHECKINPUT_HPP
#include <iostream>
#include <cstdlib>
//#include "menu.hpp"
using std::cout;
using std::cin;
using std::endl;

class checkInput
{
private:
	int *var; //variable that is being checked
public:
	checkInput(int*); // constructor to set variable
	void smallerThan1Check(); // Input smaller than 1
	void largerThan2Check(); // Input larger than 2
	void smallerThan1Largerthan3Check(); // Smaller than 1 or larger than 3
	void largerThan1Check(); // Input larger than 1
};

#endif