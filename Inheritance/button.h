#include "sprite.h"
#pragma once

class button :
	public sprite
{
public:
	button();
	button(const std::string *filename, const Vector2 & position, const  int cellCount = 1);
	~button();

	Rectangle rectangleButton;

	bool checkForClick();
	void draw(); // This Draw function will override the base classes Draw.
};

