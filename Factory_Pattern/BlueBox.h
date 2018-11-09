#pragma once
#include <iostream>
#include "IBox.h"

// The second derived class that our factory will be generating
class BlueBox : public IBox {
public:
	std::string color(void);
};