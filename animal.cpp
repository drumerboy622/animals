/***********************************************************************
Author: Matthew Solbrack
Date: 07/15/2018
Description: The animal Class has a bunch of shared functions inherited
by each animal at the zoo. This inheritance saves time. These methods 
in the class specifically return numbers set in each animal class. 
***********************************************************************/
#include "animal.hpp"

animal::animal() 
{

}

void animal::setCost() {}
void animal::setBaseFoodCost() {}
void animal::setNumberOfBabies() {}
void animal::setPayOff() {}

void animal::setAge(int currentAge)
{
	if (currentAge < 3)
		age = "Baby";
	else
		age = "Adult";
}

/*********************************************************************
Description: Sets the age to either baby or adult. Every animal is 
the same and they will inherite this funciton.
*********************************************************************/

string animal::getAge(int ageOfAnimal) 
{
	setAge(ageOfAnimal);
	return age;
}

/*********************************************************************
Description: Returns the age Baby/Adult
*********************************************************************/

int animal::getCost() 
{
	setCost();
	return cost;
}

/*********************************************************************
Description: Returns the cost of the animal
*********************************************************************/

int animal::getNumberOfBabies() 
{
	setNumberOfBabies();
	return numberOfBabies;
}


/*********************************************************************
Description: Returns the number of babies per animal 
*********************************************************************/

int animal::getpayOff() 
{
	setPayOff();
	return payOff;
}

/*********************************************************************
Description: Returns the daily payoff for each animal
*********************************************************************/

int animal::getBaseFoodCost() 
{
	setBaseFoodCost();
	return baseFoodCost;
}

/*********************************************************************
Description: Returns the food cost per day 
*********************************************************************/
