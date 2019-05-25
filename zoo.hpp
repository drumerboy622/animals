/***********************************************************************
Author: Matthew Solbrack
Date: 07/13/2018
Description: 
***********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP
#include "menu.hpp"
#include "checkInput.hpp"
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include <new>
#include <iostream>
#include <stdlib.h> 
using std::cout;
using std::cin;
using std::endl;


class zoo //: public Die //inherits the public methods from die class
{
private:
	int *tigers, //dynamic array for tigers
		*penguins, //dynamic array for pinguins
		*turtles, //dynamic array for turtles
		*reSize1, //dynamic reSize tigers
		*reSize2,//dynamic reSize penguins
		*reSize3;//dynamic reSize turtles
	bool reSize1Y,//dynamic reSize triger tigers
		reSize2Y,//dynamic reSize triger penguins
		reSize3Y;//dynamic reSize triger turtles
	int money, // the bank
		numOfTigers, // keep track of number of tigers
		numOfPenguins, // keep track of number of penguins
		numOfTurtles, // keep track of number of turtles
		day, // keep track of the day
		profit; // keep track of the profit
	animal* tigerPtr; //  pointer to tiger Class
	animal* penguinPtr; // pointer to penguin class
	animal* turtlePtr; // pointer to turtle class

	void playGame();
	void addOneYear();
	void randomEvent(int);
	void increaseSizeOfArray(int, int);
	void purchaseAdultAnimals();
	int feedingCost();
	int zooAdmissionIncome();

public:
	zoo(bool);
	~zoo();
};
#endif 
