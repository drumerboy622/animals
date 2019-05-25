/***********************************************************************
Author: Matthew Solbrack
Date: 07/15/2018
Description: This class uses specific data to its individual needs. 
This class inherits the functions/variables in the animal class. 
They work together to provide data about the animals to the zoo 
class.
***********************************************************************/
#include "turtle.hpp"

turtle::turtle() {}

void turtle::setCost()
{
	cost = 100;
}

/*********************************************************************
Description: Sets the Cost per turtle
*********************************************************************/

void turtle::setNumberOfBabies()
{
	numberOfBabies = 10;
}

/*********************************************************************
Description: Sets the number of babies per litter for the turtle
*********************************************************************/

void turtle::setBaseFoodCost()
{
	baseFoodCost = .5 * BASE_FOOD_COST;
}

/*********************************************************************
Description: Sets the base food cost price/day for the turtle
*********************************************************************/

void turtle::setPayOff()
{
	payOff = .1 * 100;
}
/*********************************************************************
Description: Sets the Payoff price/day for the turtle 
*********************************************************************/
