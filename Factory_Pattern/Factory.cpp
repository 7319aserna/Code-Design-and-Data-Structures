#include "Factory.h"

// The Create function is what we will call when we need an ...
// object created and returned to our calling code in Main.
IBox* Factory::create(std::string type) {
	if (type == "Red") {
		return new RedBox();
	}

	if (type == "Blue") {
		return new BlueBox();
	}
	return NULL;
}
