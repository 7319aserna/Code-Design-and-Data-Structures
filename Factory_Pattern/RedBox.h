#pragma once
#include <iostream>
#include "IBox.h"

// The first of our two derived classes
class RedBox : public IBox {
public:
	std::string color(void);
};