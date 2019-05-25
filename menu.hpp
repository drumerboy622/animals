/***********************************************************************
Author: Matthew Solbrack
Date: 07/13/2018
Description: The Menu Class is a standard menu option that is
portably to other programs with little changes.
***********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include "checkInput.hpp"
using std::cout;
using std::cin;
using std::endl;

class menu
{
private:
	int choice; //Entry choice
	void menu1(); // Beginning Menu
	void menu2(); // Play again menu
public:
	menu(bool); // constructor to decide which menu to display
	int getChoice(); // returns the choice of the menu
};

#endif