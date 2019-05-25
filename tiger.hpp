/***********************************************************************
Author: Matthew Solbrack
Date: 07/13/2018
Description: This class is for tiger.hpp. This class holds the tiger 
information for the zoo game. 
***********************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP
#include "animal.hpp"

class tiger : public animal //inherits the public methods from animal class
{
public:
	tiger();
	void setCost() override;
	void setNumberOfBabies() override;
	void setBaseFoodCost() override;
	void setPayOff() override;
};
#endif 