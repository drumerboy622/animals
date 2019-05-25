/***********************************************************************
Author: Matthew Solbrack
Date: 07/13/2018
Description: This class is for penguin.hpp. This class holds the penguin 
information for the zoo game. 
***********************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "animal.hpp"

class penguin : public animal //inherits the public methods from animal class
{
public:
	penguin();
	void setCost() override;
	void setNumberOfBabies() override;
	void setBaseFoodCost() override;
	void setPayOff() override;
};
#endif 