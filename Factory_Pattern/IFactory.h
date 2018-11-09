#pragma once
#include "IBox.h"
#include <iostream>

// Here we will create another base class this time for our...
// factory, again with a pure virtual function.
class IFactory {
public:
	// Make sure that all derived classes HAVE a create method
	virtual IBox* create(std::string type) = 0;
};