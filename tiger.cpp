/***********************************************************************
Author: Matthew Solbrack
Date: 07/15/2018
Description:This class uses specific data to its individual needs. 
This class inherits the functions/variables in the animal class. 
They work together to provide data about the animals to the zoo 
class.
***********************************************************************/
#include "tiger.hpp"

tiger::tiger() : animal() {}
void tiger::setCost()
{
	cost = 10000;
}

/*********************************************************************
Description: Sets the Cost per tiger
*********************************************************************/

void tiger::setNumberOfBabies()
{
	numberOfBabies = 1;
}

/*********************************************************************
Description: Sets the number of babies per litter for the tiger
*********************************************************************/

void tiger::setBaseFoodCost()
{
	baseFoodCost = 5 * BASE_FOOD_COST;
}

/*********************************************************************
Description: Sets the base food cost price/day for the tiger
*********************************************************************/

void tiger::setPayOff()
{
	payOff = .2 * 10000;
}
/*********************************************************************
Description: Sets the Payoff price/day for the tiger
*********************************************************************/
