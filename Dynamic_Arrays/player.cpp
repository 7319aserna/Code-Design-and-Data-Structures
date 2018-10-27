#include <iostream>
#include "player.h"
#include "raylib/raylib.h"
#include "tQueue.h"
#include "tVector.h"

player::player() {
	texture = LoadTexture("knight_f_idle_anim_f0.png");
}

player::~player() {
	UnloadTexture(texture);
}

void player::draw()
{
	DrawTextureEx(texture, position, 0, 3.0f, WHITE);
}

void player::update(float deltaTime)
{
	std::cout << GetTime() << std::endl;
	// When the player clicks a certain position...
	// ... the character moves to that place.
	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
		std::cout << "x: " << GetMouseX() << " y: " << GetMouseY() << std::endl;
		position.x = GetMouseX();
		position.y = GetMouseY();
		// Make the player move by frame or so, not instantly
	}
}
