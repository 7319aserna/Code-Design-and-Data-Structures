#include <iostream>
#include "raylib/raylib.h"
#include "wizard.h"

wizard::wizard(const std::string &fileName): player(fileName) {

}

wizard::~wizard() {

}

bool wizard::moveTo(const Vector2 & dest)
{
	// For the wizard:
	// Wherever the player clicks in any area...
	// ... we will get the mouse's position...
	// ... and then move (teleport) the player...
	// ... to that position.
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		GetMousePosition();
		std::cout << GetMouseX << std::endl;
		std::cout << GetMouseY << std::endl;
	}
	return true;
}
