/***********************************************************************
Author: Matthew Solbrack
Date: 07/13/2018
Description: The Animal class uses inheritance to connect with different
animals in the zoo. This header is for animal.cpp. 
***********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
using std::string;

class animal
{
public:
	int const BASE_FOOD_COST = 50; //Base food Constant
	string age; //Adult if age >= 3 days, Baby if age < 3 days
	int	cost, //Tiger cost $10,000, Penguin cost $1,000, Turtle cost $100
		numberOfBabies, // Tigers have 1 baby, Penguins have 5 babies, Turtles have 10 babies
		baseFoodCost, // Tigers have a feeding cost of 5 times the base cost
						//Penguins have a feeding cost that is the same as the base cost
						//Turtles have a feeding cost that is 50 % the base cost
		payOff; //A tiger’s payoff per day is 20% of their cost per animal. (not counting bonus)
				//A penguin’s payoff per day is 10 % of their cost per animal
				//A turtle’s payoff per day is 5 % of their cost per animal

	animal();
	string getAge(int); //Inherited function to get the age Baby or Adult
	void setAge(int);
	virtual void setCost();
	int getCost(); //Inherited function to get
	virtual void setNumberOfBabies();
	int getNumberOfBabies();
	virtual void setPayOff();
	int getpayOff();
	virtual void setBaseFoodCost();
	int getBaseFoodCost();
};
#endif 