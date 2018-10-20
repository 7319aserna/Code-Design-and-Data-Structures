#include "button.h"
#include <iostream>
#include "raylib/raylib.h"

button::button()
{
}

button::button(const std::string * filename, const Vector2 & position, const int cellCount)
{
	x = position.x;
	y = position.y;

	// I dont want to animate them just yet, that would need...
	// ... to happen when the player clicks.
	for (int i = 1; i < cellCount; i++) {
		spriteCells[i];
	}
}

button::~button()
{
	delete[] spriteCells;
}

bool button::checkForClick()
{
	// Get the mouse position
	std::cout << GetMousePosition().x << std::endl;
	std::cout << GetMousePosition().y << std::endl;

	// check to see if the mouse's position is anywhere on the burrito
	if (CheckCollisionPointRec({ GetMousePosition().x, GetMousePosition().y }, rectangleButton)) {
		currentFrame = 1;
		DrawRectangle(x, y, 100, 222, GREEN);
	}
	
	// Once game starts, the texture will be loaded as not pressed.
	// ... Once the player cursor is on the button, the texture...
	// ... will load as it being pressed.
	// Have the check collision for pointer to mouse here.
	return false;
}

void button::draw()
{
	DrawRectangle(x, y, 52, 42, BLACK);
	//DrawTexture(spriteCells[currentFrame], x, y, WHITE);
}
