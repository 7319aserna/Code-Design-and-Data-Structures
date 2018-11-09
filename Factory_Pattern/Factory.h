#pragma once
#include <iostream>
#include "IBox.h"
#include "RedBox.h"
#include "BlueBox.h"
#include "IFactory.h"

// This next one will be our actual Factory class, here we ...
// are NOT implementing it as a Singleton, we will address ...
// this later.
class Factory :
	public IFactory {
public:
	IBox * create(std::string type);
};