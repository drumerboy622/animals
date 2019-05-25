/***********************************************************************
Author: Matthew Solbrack
Date: 07/15/2018
Description: This class uses specific data to its individual needs. 
This class inherits the functions/variables in the animal class. 
They work together to provide data about the animals to the zoo 
class.
***********************************************************************/
#include "penguin.hpp"

penguin::penguin() {}

void penguin::setCost()
{
	cost = 1000;
}

/*********************************************************************
Description: Sets the Cost per penguin
*********************************************************************/

void penguin::setNumberOfBabies()
{
	numberOfBabies = 5;
}

/*********************************************************************
Description: Sets the number of babies per litter for the penguin
*********************************************************************/

void penguin::setBaseFoodCost()
{
	baseFoodCost = BASE_FOOD_COST;
}

/*********************************************************************
Description: Sets the base food cost price/day for the penguin
*********************************************************************/

void penguin::setPayOff()
{
	payOff = .1 * 1000;
}

/*********************************************************************
Description: Sets the Payoff price/day for the penguin
*********************************************************************/
