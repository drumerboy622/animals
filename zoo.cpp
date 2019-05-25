
/***********************************************************************
Author: Matthew Solbrack
Date: 07/15/2018
Description: This Program is for Programming 162/400 Project 2. 
This file uses zoo.hpp and is the main class for playing
the game. The functions in this class use all other classes in this 
program. Specifically the class initializes the user to the game. 
initializes all the member functions. Displays all the inforomation
given to the user. There are a lot of use with inheretid functions 
through the animal.cpp. 
***********************************************************************/
#include "zoo.hpp"

zoo::zoo(bool menuOption) 
{
	//initilize member variables to appropriate amounts
	money = 100000;
	profit = 0;
	numOfTigers = 0;
	numOfPenguins = 0;
	numOfTurtles = 0;
	day = 1;

	//initialize the member pointer and put a -1 in the last array spot in order 
	//to recoginize the end of the array
	tigers = new int[11];
	tigers[10] = -1;

	penguins = new int[11];
	penguins[10] = -1;

	turtles = new int[11];
	turtles[10] = -1;

	//initialize function variables to hold the amount purchased per animal
	int initialTigers, initialPenguins, initialTurtles;

	//Welcome menu
	int choice = menu(menuOption).getChoice();
	
	//If no exit begin initialilzing the member pointers with user information
	if (choice == 1)
	{
		cout << "\n       Welcome to Zoo Typcon!" << endl;
		cout << "\nYour starting balance to begin your zoo adventure is "
			<< money << " dollars." << endl;
		cout << "Please choose 1 or 2 of each type of animal to begin."
			<< endl << endl;
		cout << "How many tigers would you like to purchase? (cost $10,000 ea.): ";
		cin >> initialTigers;

		//input validation for non-integers and negative integers 
		checkInput(&initialTigers).smallerThan1Largerthan3Check();

		//initialize each tiger to age 1 in the pointer array
		for (int count = 0; count < initialTigers; ++count)
			tigers[count] = 1;

		//Deduct the cost of the Tiger from the bank
		tigerPtr = new tiger();
		money = money - (initialTigers * tigerPtr->getCost());

		cout << "How many pinguins would you like to purchase? (cost $1,000): ";
		cin >> initialPenguins;

		//input validation for non-integers and negative integers 
		checkInput(&initialPenguins).smallerThan1Largerthan3Check();

		//initialize each penguin to age 1 in the pointer array
		for (int count = 0; count < initialPenguins; ++count)
			penguins[count] = 1;

		//Deduct the cost of the Penguins
		penguinPtr = new penguin();
		money = money - (initialPenguins * penguinPtr->getCost());

		cout << "How many turtles would you like to purchase? (cost $100): ";
		cin >> initialTurtles;

		//input validation for non-integers and negative integers 
		checkInput(&initialTurtles).smallerThan1Largerthan3Check();

		//initialize each turtle to age a in the pointer array
		for (int count = 0; count < initialTurtles; ++count)
			turtles[count] = 1;

		//subtract the initial cost of the turtle
		turtlePtr = new turtle();
		money = money - (initialTurtles * turtlePtr->getCost());

		//Initialize the main game play
		playGame();
	}	
}

/***********************************************************************
Description: This contstructor initializes the member variables
It includes the initial menu and sends the user to the main game play.
There are calls to inheritid functions in this constructor. 
***********************************************************************/

void zoo::playGame()
{
	//Find out how many tigers, penguins, turtles are in the zoo!
	while (tigers[numOfTigers] > 0) 
		numOfTigers++;
	while (penguins[numOfPenguins] > 0) 
		numOfPenguins++; 
	while (turtles[numOfTurtles] > 0)
		numOfTurtles++; 
	
	//Show End of day information
	cout << "\nSummary at the End of Day " << day << ":" << endl;
	
	//Calculate Food Costs
	cout << "Your food cost today is: $" << feedingCost() << endl;
	money = money - feedingCost();

	//Find out and output the Admission income for the day and add it to the profit
	cout << "Your Admission income is: $" << zooAdmissionIncome() << endl;
	profit = profit + zooAdmissionIncome();
	
	//Generate a random Event Number
	int random;
	if (day % 2 != 0)
		random = 2;
	else
		random = 3;

	//Call the reandomEvent function and Display the results
	cout << "Random Event day " << day << ": ";
	randomEvent(random);

	//Display the Zoo Profit for the day
	cout << "Your Profit for the day is: $" << profit << endl;

	
	//Diplay the amount of animals currently in the Zoo
	cout << "You have " << numOfTigers << " Tigers." << endl;
	cout << "You have " << numOfPenguins << " Penguins." << endl;
	cout << "You have " << numOfTurtles << " Turtles." << endl;

	//Add One year to these animals
	addOneYear();

	//Add profit to the bank and display
	money = money + profit;
	cout << "\nYour bank account is at: $" << money << endl;

	//Ask if the user would like to purchase additional Adult animals
	char choice;
	cout << "Would you like to purchase additional animals for your zoo? (y/n): ";
	cin >> choice;
	
	//input validation 
	while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N')
	{
		cout << "Try Again:  ";
		cin.clear();
		cin.ignore();
		cin >> choice;
	}

	if (choice == 'y' || choice == 'Y')
	{
		purchaseAdultAnimals();
		cout << "You now have " << numOfTigers << " Tigers." << endl;
		cout << "You now have " << numOfPenguins << " Penguins." << endl;
		cout << "You now have " << numOfTurtles << " Turtles." << endl;
	}

	//Check to see if the user has money
	cout << "\n Your bank account is now at: $" << money << endl;

	//If no money exit the program
	if (money <= 0)
	{
		cout << "You have run out of money." << endl;
	}
	else
	{
		//increment the day and readjust the tigers, pinguens and turtles
		++day;
		numOfTigers = 0;
		numOfPenguins = 0;
		numOfTurtles = 0;
		profit = 0;

		//Ask the User if they would like to continue to play
		if (menu(0).getChoice() == 1)
			playGame();
	}
}

/***********************************************************************
Description: This method is the main game-play. If displays the 
information the user see's. This is done inside the function and with
calls to other functions. There are calls to inheritid functions 
in this method. 
***********************************************************************/

void zoo::addOneYear()
{
	//add one Year for each Tiger
	for (int count = 0; count < numOfTigers; ++count)
		++tigers[count];
	
	//add one Year for each Penguins
	for (int count = 0; count < numOfPenguins; ++count)
		++penguins[count];
	
	//add one Year for each Tiger
	for (int count = 0; count < numOfTurtles; ++count)
		++turtles[count];
	
}

/***********************************************************************
Description: This method is specifically for adding one year to each
animal currently in the zoo. 
***********************************************************************/

int zoo::feedingCost()
{
	return (numOfTigers * tigerPtr->getBaseFoodCost()) + (numOfPenguins *
		 penguinPtr->getBaseFoodCost()) + (numOfTurtles * 
			turtlePtr->getBaseFoodCost());
}

/***********************************************************************
Description: This method uses inherited functions to help calculate 
the food cost for the zoo. 
***********************************************************************/

int zoo::zooAdmissionIncome()
{
	return (numOfTigers * tigerPtr->getpayOff()) + (numOfPenguins *
		penguinPtr->getpayOff()) + (numOfTurtles *
			turtlePtr->getpayOff());
}

/***********************************************************************
Description: This method usess inherited functions to help calculate
the food admission income.
***********************************************************************/

void zoo::randomEvent(int random)
{
	//A sickness occurs to an animal in the zoo:
	//Pick an animal at random that will die
	//Remove one animal of that type from the exhibit. (dynamic array in the zoo)
	if (random == 1)
	{
	random1:
		int randomPick = rand() % 5 + 1;
		if (randomPick == 1)
		{
			if (numOfTigers <= 0)
				goto diedpenguins;
			else
			{
				tigers[numOfTigers - 1] = 0;
				--numOfTigers;
				cout << "One of your tigers fell ill and died today." << endl;
			}
		}
		else if (randomPick == 2)
		{
		diedpenguins:
			if (numOfPenguins <= 0)
				goto diedturtles;
			penguins[numOfPenguins - 1] = 0;
			--numOfPenguins;
			cout << "One of your penguins fell ill and died today." << endl;
		}
		else
		{
		diedturtles:
			if (numOfTurtles <= 0)
				goto random2;
			turtles[numOfTurtles - 1] = 0;
			--numOfTurtles;
			cout << "One of your turtles fell ill and died today." << endl;
		}
	}
	
	//A boom in zoo attendance occurs:
	//Generate a random bonus for the day, 250 - 500 dollars for each tiger in the zoo
	//Add the bonus payoff for each tiger to the total payoff of the day as a reward

	else if (random == 2)
	{
	random2: 
		int bonus = rand() % 251 + 250;
		cout << "You have received a $" << bonus*numOfTigers << " bonus for the day." << endl;
		profit = profit + bonus*numOfTigers;
	}

	//A baby animal is born :
	//Pick an animal at random to have a baby
	//Check if there is an animal old enough to be a parent(age >= 3), add babies to
	//the zoo depending on the “number of babies” specific to the type of animal.If no 
	//animal is old enough of the randomly selected type, pick another type of animal.Baby 
	//animals start at age 0.  For simplicity, you don’t need to consider the gender of the 
	//adult animals in order to have babies.One adult animal is good enough to have babies.

	else
	{
		int randomNum = rand() % 3 + 1;
		
		if (tigers[0] >= 3 && randomNum == 1)
		{
			//Check the size of the array
			increaseSizeOfArray(1, tigerPtr->getNumberOfBabies());

			for (int count = 0; count < tigerPtr->getNumberOfBabies(); ++count)
				tigers[numOfTigers + count] = 1;
			numOfTigers = numOfTigers + tigerPtr->getNumberOfBabies();
			cout << "You have Recieved a Gift of " << tigerPtr->getNumberOfBabies()
				<< " newborn tigers!" << endl;
		}

		else if (penguins[0] >= 3 && randomNum == 2)
		{	
			//Check the size of the array
			increaseSizeOfArray(2, penguinPtr->getNumberOfBabies());

			for (int count = 0; count < penguinPtr->getNumberOfBabies(); ++count)
				penguins[numOfPenguins + count] = 1;
			numOfPenguins = numOfPenguins + penguinPtr->getNumberOfBabies();
			cout << "You have Recieved a Gift of " << penguinPtr->getNumberOfBabies()
				<< " newborn penguins!" << endl;
		}

		else if (turtles[0] >= 3 && randomNum == 3)
		{
			//Check the size of the array
			increaseSizeOfArray(3, turtlePtr->getNumberOfBabies());
			for (int count = 0; count < turtlePtr->getNumberOfBabies(); ++count)
				turtles[numOfTurtles + count] = 1;
			numOfTurtles = numOfTurtles + turtlePtr->getNumberOfBabies();
			cout << "You have Recieved a Gift of " << turtlePtr->getNumberOfBabies()
				<< " newborn turtles!" << endl;
		}
		else
			goto random1;
	}
}

/***********************************************************************
Description: This method is for the random events that happen in the zoo. 
Each random event uses the inherited functions and calculates new
numbers for the game. 
***********************************************************************/

void zoo::increaseSizeOfArray(int animalType, int additionalSpace)
{
	//If the animal is a tiger
	if (animalType == 1)
	{
		// Find the current size of the array
		int size = 0;
		while (tigers[size] != -1) 
			size++; 
	
		//If the current size isn't big enough double it or make it large enough to fit 
		//the incoming animals
		if (numOfTigers + additionalSpace > size)
		{
		
			size = (size * 2) + 1 + additionalSpace;
			reSize1 = new int[size];
			for (int count = 0; count < size; ++count)
				reSize1[count] = tigers[count];
			delete[] tigers;
			
			tigers = reSize1;
			tigers[size] = -1;
			size = 0;
			reSize1Y = 1;
		}
	}
	//If the animal is a Penguin
	else if (animalType == 2)
	{
		// Find the current size of the array
		int size = 0;
		while (penguins[size] != -1) 
			size++; 
		
		//If the current size isn't big enough double it or make it large enough to fit 
		//the incoming animals
		if (numOfPenguins + additionalSpace > size)
		{
			size = (size * 2) + 1 + additionalSpace;
			reSize2 = new int[size];
			for (int count = 0; count < size; ++count)
				reSize2[count] = penguins[count];
			delete[] penguins;
			penguins = reSize2;
			penguins[size] = -1;
			size = 0;
			reSize2Y = 1;
		}
	}
	//If the animal is a turtle
	else if (animalType == 3)
	{
		// Find the current size of the array
		int size = 0;
		while (turtles[size] != -1) 
			size++; 
		
		//If the current size isn't big enough double it or make it large enough to fit 
		//the incoming animals
		if (numOfTurtles + additionalSpace > size)
		{
			size = (size * 2) + 1 + additionalSpace;
			reSize3 = new int[size];
			for (int count = 0; count < size; ++count)
				reSize3[count] = turtles[count];
			delete[] turtles;
			turtles = reSize3;
			turtles[size] = -1;
			size = 0;
			reSize3Y = 1;
		}
	}
}
/***********************************************************************
Description: If the Number of Animals is bigger than the array, increase
the caupacity of the array. This is what the method is used for. 
***********************************************************************/

void zoo::purchaseAdultAnimals()
{
	int additionalTigers = 0;
	int additionalPenguins = 0;
	int additionalTurtles = 0;

	cout << "Would you like to purchase additional adult tiger(s)? (cost $10,000 ea.): ";
	cin >> additionalTigers;

	//input validation for non-integers and negative integers 
	checkInput(&additionalTigers).largerThan1Check();
	
	//Check the size of the array
	increaseSizeOfArray(1, additionalTigers);

	//initialize each tiger to age 3 in the pointer array
	for (int count = 0; count < additionalTigers; ++count)
		tigers[count+numOfTigers] = 3;

	//Increase the number of Tigers for the current day
	numOfTigers = numOfTigers + additionalTigers;

	//Deduct the cost of the Tiger
	money = money - (additionalTigers * tigerPtr->getCost());

	cout << "Would you like to purchase additional adult penguin(s)? (cost $1,000 ea.): ";
	cin >> additionalPenguins;
	
	//input validation for non-integers and negative integers 
	checkInput(&additionalPenguins).largerThan1Check();

	//Check the size of the array
	increaseSizeOfArray(2, additionalPenguins);

	//initialize each penguin to age 3 in the pointer array
	for (int count = 0; count < additionalPenguins; ++count)
		penguins[count+numOfPenguins] = 3;

	//Increase the number of Penguins for the current day
	numOfPenguins = numOfPenguins + additionalPenguins;

	//Deduct the cost of the Penguins
	money = money - (additionalPenguins * penguinPtr->getCost());

	cout << "Would you like to purchase additional turtle(s)? (cost $100 ea.): ";
	cin >> additionalTurtles;

	//input validation for non-integers and negative integers 
	checkInput(&additionalTurtles).largerThan1Check();

	//Check the size of the array
	increaseSizeOfArray(3, additionalTurtles);

	//initialize each turtle to age 3 in the pointer array
	for (int count = 0; count < additionalTurtles; ++count)
		turtles[count+numOfTurtles] = 3;

	//Increase the number of Turtles for the current day
	numOfTurtles = numOfTurtles + additionalTurtles;

	//subtract the initial cost of the turtle
	money = money - (additionalTurtles * turtlePtr->getCost());
}

/***********************************************************************
Description: If the user wants to increase the amount of adult animals
in the zoo, this method is called. This method will check the array for
size, call a function to have it increased if necessary, ass the 
new adults to the array and deduct the cost from the bank. 
***********************************************************************/

zoo::~zoo()
{
	if (reSize1Y != 1)
		delete[] tigers;		
	else 
		delete[] reSize1;
	tigers = NULL;

	if (reSize2Y != 1)
		delete[] penguins;
	else
		delete[] reSize2;
	penguins = NULL;

	if (reSize3Y != 1)
		delete[] turtles;
	else 
		delete[] reSize3;
	turtles = NULL;

	delete tigerPtr;
	tigerPtr = NULL;
	delete penguinPtr;
	penguinPtr = NULL;
	delete turtlePtr;
	turtlePtr = NULL;
	cout << "Thanks for Playing" << endl;
}

/***********************************************************************
Description: This is the constructor and it is used to eliminate any 
memory leaks. 
***********************************************************************/


int main()
{
	zoo(1);
	return 0;
}
/***********************************************************************
Description: This is the very short main function.
***********************************************************************/
