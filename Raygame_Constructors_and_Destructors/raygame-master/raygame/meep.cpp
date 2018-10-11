#include <iostream>

#include "raylib.h"
#include "meep.h"

// Member function definitions including constructor and destructor
meep::meep()
{
	std::cout << "The texture is being created!" << std::endl;
}

meep::meep(bool _enabled)
{
}

meep::~meep()
{
	std::cout << "The texture is being deleted!" << std::endl;
}

void meep::refresh()
{
}
