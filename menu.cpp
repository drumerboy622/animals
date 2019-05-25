/***********************************************************************
Author: Matthew Solbrack
Date: 07/13/2018
Description: The Menu Class is a standard menu option that is
portably to other programs with little changes.
***********************************************************************/
#include "menu.hpp"

menu::menu(bool menuOption)
{
	//Initial menu options
	if (menuOption == 1)
		menu1();
	else if (menuOption == 0)
		menu2();
}

/***********************************************************************
Description: This constructor helps decide which menu to open. Either
the initial menu or the play again menu
***********************************************************************/

void menu::menu1()
{
	cout << "Zoo Tycoon		by Matthew Solbrack" << endl << endl;
	cout << "MENU	" << endl;
	cout << "1. Play Game" << endl;
	cout << "2. Exit Game" << endl << endl;
	cout << "Please choose one option from above: ";
	cin >> choice;

	//input validation for non-integers and negative integers 
	checkInput(&choice).smallerThan1Largerthan3Check();
}
/***********************************************************************
Description: This method is the intial menu. It validates input with the
checkInput class.
***********************************************************************/

void menu::menu2()
{

	cout << "\n1. Continue to the next Day" << endl;
	cout << "2. Exit Game" << endl << endl;
	cout << "Please choose one option from above: ";
	cin >> choice;

	//input validation for non-integers and negative integers 
	checkInput(&choice).smallerThan1Largerthan3Check();
}

/***********************************************************************
Description: This method is the play again menu. It validates input with
the checkInput class.
***********************************************************************/

int menu::getChoice()
{
	return choice;
}

/***********************************************************************
Description: This method returns the result of the intial or play again
menu.
***********************************************************************/
