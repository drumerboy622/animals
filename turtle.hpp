/***********************************************************************
Author: Matthew Solbrack
Date: 07/13/2018
Description: This class is for turtle.hpp. This class holds the turtle 
information for the zoo game. 
***********************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "animal.hpp"

class turtle : public animal //inherits the public methods from animal class
{
public:
	turtle();
	void setCost() override;
	void setNumberOfBabies() override;
	void setBaseFoodCost() override;
	void setPayOff() override;
};
#endif 