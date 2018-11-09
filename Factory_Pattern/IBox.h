#pragma once
#include <iostream>

// Here we will start off with a base class for our objects ...
// which we want the factory to create. A simple box object ...
// with a single Pure Virtual Function for retrieving a color, ...
// this ensures that all derived classes will have this function.
class IBox {
public:
	virtual std::string color(void) = 0;
};