#include <iostream>

#include "raylib.h"
#include "meep.h"

// Member function definitions including constructor and destructor
meep::meep()
{
	std::cout << "The object is being created!" << std::endl;
	texture = LoadTexture("keeb.png");
	enabled = false;
}

meep::meep(bool _enabled)
{
	if (enabled == false) {
		LoadSound("Alexis's song");
	}
}

meep::~meep()
{
	std::cout << "The object is being deleted!" << std::endl;
	UnloadTexture(texture);
}

void meep::refresh()
{
	DrawTexture(texture, 200, 200, WHITE);
}