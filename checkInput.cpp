/***********************************************************************
Author: Matthew Solbrack
Date: 07/13/2018
Description: These Methods help with input validation for integers. 
I thought itwas a good idea to sperate this into its own class. I use 
it a lot in multiple programs and in different classes.
***********************************************************************/
#include "checkInput.hpp"


checkInput::checkInput(int *variable)
{
	var = variable;
}

/***********************************************************************
Description: Takes in the input variable
***********************************************************************/

void checkInput::smallerThan1Check()
{
	while (!cin || *var < 1)
	{
		cout << "Try Again:  ";
		cin.clear();
		cin.ignore();
		cin >> *var;
	}
}

/****************************************************************************************
Description: This method checks the input to make sure it is an int and greater or
equal to one. If it is not the previously entered data is cleared and you are prompted
to enter another option.
****************************************************************************************/

void checkInput::largerThan2Check()
{
	while (!cin || *var < 3)
	{
		cout << "Try Again (Must be larger than 2):  ";
		cin.clear();
		cin.ignore();
		cin >> *var;
	}
}

/****************************************************************************************
Description: This method checks the input to make sure it is an int and greater or
equal to three. If it is not the previously entered data is cleared and you are prompted
to enter another option.
****************************************************************************************/

void checkInput::smallerThan1Largerthan3Check()
{
	while (!cin || *var < 1 || *var > 2)
	{
		cout << "Try Again:  ";
		cin.clear();
		cin.ignore();
		cin >> *var;
	}
}

/****************************************************************************************
Description: This method checks the input to make sure it is an int and greater or
equal than three or less than 1. If it is not the previously entered data is cleared and
you are prompted to enter another option.
****************************************************************************************/

void checkInput::largerThan1Check()
{
	while (!cin || *var < 0)
	{
		cout << "Try Again:  ";
		cin.clear();
		cin.ignore();
		cin >> *var;
	}
}

/****************************************************************************************
Description: This method checks the input to make sure it is an int and greater or
equal than three or less than 1. If it is not the previously entered data is cleared and
you are prompted to enter another option.
****************************************************************************************/
